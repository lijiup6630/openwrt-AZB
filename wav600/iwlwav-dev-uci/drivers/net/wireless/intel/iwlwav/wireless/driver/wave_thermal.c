/******************************************************************************
  Copyright (c) 2020, MaxLinear, Inc.

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

The source code contained or described herein and all documents related to the
source code ("Material") are owned by Intel Corporation or its suppliers or
licensors. Title to the Material remains with Maxlinear Inc. or its suppliers
and licensors. The Material contains trade secrets and proprietary and
confidential information of Maxlinear or its suppliers and licensors. The
Material is protected by worldwide copyright and trade secret laws and treaty
provisions. No part of the Material may be used, copied, reproduced, modified,
published, uploaded, posted, transmitted, distributed, or disclosed in any way
without Maxlinear's prior express written permission.

No license under any patent, copyright, trade secret or other intellectual
property right is granted to or conferred upon you by disclosure or delivery of
the Materials, either expressly, by implication, inducement, estoppel or
otherwise. Any license under such intellectual property rights must be express
and approved by Maxlinear in writing.

******************************************************************************/

#include "mtlkinc.h"
#include "hw_mmb.h"
#include "core_config.h"
#include "mtlk_df_priv.h"

#ifdef CONFIG_THERMAL
#include <linux/thermal.h>
#endif
#include <linux/of.h>
#include <linux/units.h>

#define LOG_LOCAL_GID   GID_THERMAL
#define LOG_LOCAL_FID   1

#ifdef CONFIG_THERMAL
typedef enum {
  COOLING_TYPE_FIRST,
  COOLING_TYPE_TX_DUTY_CYCLE = COOLING_TYPE_FIRST,
  COOLING_TYPE_ANTENNA,
  COOLING_TYPE_MAX
} cooling_type_e;

typedef struct cooling_method {
  uint32 type;
  uint32 param;
} cooling_method_t;

#define DEFAULT_NUM_COOLING_STATE 3
#define MAX_NUM_COOLING_STATE 100
#define MAX_STATE_PER_METHOD 3
struct wave_thermal {
  struct thermal_zone_device *tzd;
  struct thermal_cooling_device *cd;
  unsigned long cooling_state;
  unsigned long max_cooling_state;
  cooling_method_t *cooling_state_params;
  uint32 cooling_state_cnt[COOLING_TYPE_MAX];
};

void __MTLK_IFUNC
wave_hw_set_thermal_mgmt_data (mtlk_hw_t *hw, struct wave_thermal *thermal_mgmt);

struct wave_thermal*  __MTLK_IFUNC
wave_hw_get_thermal_mgmt_data (mtlk_hw_t *hw);

int __MTLK_IFUNC
wave_thermal_zone_get_temp (void *data, int *temperature)
{
  uint8 card_idx;
  int temp = 0;
  mtlk_core_t* master_core;
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_hw_t *hw;
  mtlk_df_t *master_df;
  mtlk_handle_t lhandle = MTLK_INVALID_HANDLE;
  mtlk_temperature_sensor_t *temperature_cfg;
  uint32 data_size;

  if (!data || !temperature) {
    ELOG_PP("Thermal: Invalid input params, data %p temperature %p", data, temperature);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  hw = ((mtlk_hw_t*) data);
  card_idx = mtlk_hw_mmb_get_card_idx(hw);

  /* Query the temperature sensor value when core state is connected */
  master_core = wave_hw_get_first_radio_master_vap_core(hw);
  if (mtlk_core_get_net_state(master_core) != NET_STATE_CONNECTED) {
    ILOG3_D("Thermal: CID-%02x Failed to read temperature, core not ready", card_idx);
    res = MTLK_ERR_NOT_READY;
    goto end;
  }
  master_df = mtlk_vap_manager_get_master_df(mtlk_vap_get_manager(master_core->vap_handle));
  if (master_df == NULL) {
    ELOG_D("Thermal: CID-%02x Error getting master_df", card_idx);
    res = MTLK_ERR_UNKNOWN;
    goto end;
  }
  res = _mtlk_df_user_pull_core_data(master_df, WAVE_HW_REQ_GET_TEMPERATURE_SENSOR,
                                     FALSE, (void**) &temperature_cfg, &data_size, &lhandle);
  if (res != MTLK_ERR_OK) {
    ELOG_D("Thermal: CID-%02x Failed to read temperature data for tzd", card_idx);
    goto end;
  }

  MTLK_ASSERT(sizeof(*temperature_cfg) == data_size);
  MTLK_CFG_GET_ITEM(temperature_cfg, temperature, temp);

  /* convert to millicelsius */
  *temperature = temp * MILLIDEGREE_PER_DEGREE;
  ILOG3_DD("Thermal: CID-%02x temperature %d", card_idx, *temperature);

end:
  if (MTLK_INVALID_HANDLE != lhandle) {
    _mtlk_df_user_free_core_data(master_df, lhandle);
  }

  return _mtlk_df_mtlk_to_linux_error_code(res);
}

int __MTLK_IFUNC
wave_cooling_get_max_state (struct thermal_cooling_device *cd,
            unsigned long *state)
{
  mtlk_hw_t *hw;
  struct wave_thermal *thermal;

  if (!cd || !state) {
    ELOG_PP("Thermal: Invalid input params, cd %p state %p", cd, state);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  hw = (mtlk_hw_t*) cd->devdata;
  if (!hw) {
    ELOG_S("Thermal: Invalid devdata from %s", cd->type);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  thermal = wave_hw_get_thermal_mgmt_data(hw);
  if (!thermal) {
    ELOG_D("Thermal: CID-%02x Invalid thermal mgmt data",
            mtlk_hw_mmb_get_card_idx(hw));
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_VALUE);
  }

  *state = thermal->max_cooling_state;
  ILOG3_DD("Thermal: CID-%02x Max state %lu", mtlk_hw_mmb_get_card_idx(hw), *state);
  return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_OK);
}

int __MTLK_IFUNC
wave_cooling_get_cur_state (struct thermal_cooling_device *cd,
            unsigned long *state)
{
  mtlk_hw_t *hw;
  struct wave_thermal *thermal;

  if (!cd || !state) {
    ELOG_PP("Thermal: Invalid input params, cd %p state %p", cd, state);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  hw = (mtlk_hw_t*) cd->devdata;
  if (!hw) {
    ELOG_S("Thermal: Invalid devdata from %s", cd->type);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  thermal = wave_hw_get_thermal_mgmt_data(hw);
  if (!thermal) {
    ELOG_D("Thermal: CID-%02x Invalid thermal mgmt data",
            mtlk_hw_mmb_get_card_idx(hw));
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_VALUE);
  }
  *state = thermal->cooling_state;

  ILOG3_DD("Thermal: CID-%02x Current state %lu", mtlk_hw_mmb_get_card_idx(hw), *state);
  return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_OK);
}

static mtlk_error_t
_wave_cooling_radio_set_duty_cycle (mtlk_hw_t *hw, uint32 offtime)
{
  mtlk_core_t *master_core;
  mtlk_error_t res;
  mtlk_coc_erp_cfg_t erp_cfg;
  mtlk_erp_t *erp_obj;
  uint8 card_idx = mtlk_hw_mmb_get_card_idx(hw);

  master_core = wave_hw_get_first_radio_master_vap_core(hw);
  erp_obj = wave_radio_erp_mgmt_get(wave_vap_radio_get(master_core->vap_handle));
#define DUTY_CYCLE_ON_MAX 100
  if (offtime != MAX_UINT32) {
    erp_cfg.erp_enabled    =  TRUE;
    erp_cfg.radio_on_time  =  (DUTY_CYCLE_ON_MAX - offtime);
    erp_cfg.radio_off_time =  offtime;
  } else {
    erp_cfg.erp_enabled    =  FALSE;
    erp_cfg.radio_on_time  =  DUTY_CYCLE_ON_MAX;
    erp_cfg.radio_off_time =  0;
  }

  /* ERP config: initial_wait_time = 1 sec for immediate UMI dispatch.
   * If the erp criterion value are reached (ex. max_num_sta, tx_*_max_tp values),
   * ERP will be turned off. This will turnoff our duty cycle config too.
   * Hence keep other irrelevent params to MAX value
   */
  erp_cfg.initial_wait_time =  1;
  erp_cfg.max_num_sta       =  WAVE_MAX_STA_ID;
  erp_cfg.rx_tp_max         =  MAX_UINT32;
  erp_cfg.tx_20_max_tp      =  MAX_UINT32;
  erp_cfg.tx_40_max_tp      =  MAX_UINT32;
  erp_cfg.tx_80_max_tp      =  MAX_UINT32;
  erp_cfg.tx_160_max_tp     =  MAX_UINT32;

  ILOG2_DDD("Thermal: CID-%02x Set DutyCycle request offtime %u, ontime %u",
     mtlk_hw_mmb_get_card_idx(hw), erp_cfg.radio_off_time, erp_cfg.radio_on_time);
  res = mtlk_coc_set_erp_mode(erp_obj, &erp_cfg);
  if (res != MTLK_ERR_OK) {
    ELOG_DDD("Thermal: CID-%02x Unable to set DutyCycle request offtime %u, ontime %u",
             card_idx, erp_cfg.radio_off_time, erp_cfg.radio_on_time);
  }
  return res;
}

static mtlk_error_t
_wave_cooling_radio_set_antenna_mask (mtlk_hw_t *hw, uint32 ant_cnt)
{
  mtlk_core_t *master_core;
  mtlk_coc_power_cfg_t power_params;
  uint8 card_idx = mtlk_hw_mmb_get_card_idx(hw);
  mtlk_error_t res;

  master_core = wave_hw_get_first_radio_master_vap_core(hw);
  memset(&power_params, 0, sizeof(power_params));
  power_params.is_auto_mode = FALSE;
  if (ant_cnt != MAX_UINT32) {
    power_params.antenna_params.num_rx_antennas = ant_cnt;
    power_params.antenna_params.num_tx_antennas = ant_cnt;
  } else {
    power_params.antenna_params.num_rx_antennas  =
    mtlk_core_get_max_rx_antennas(master_core);
    power_params.antenna_params.num_tx_antennas  =
    ant_cnt = mtlk_core_get_max_tx_antennas(master_core);
  }

  if (power_params.antenna_params.num_rx_antennas > mtlk_core_get_max_rx_antennas(master_core) ||
      power_params.antenna_params.num_tx_antennas > mtlk_core_get_max_tx_antennas(master_core)) {
    ELOG_DDD("Thermal: CID-%02x Invalid Antenna count value tx %u rx %u",
             card_idx, power_params.antenna_params.num_tx_antennas,
             power_params.antenna_params.num_rx_antennas);
  }

  ILOG2_DDD("Thermal: CID-%02x Set Antenna request, tx %u rx %u",
            card_idx, power_params.antenna_params.num_tx_antennas,
            power_params.antenna_params.num_rx_antennas);

  res = wave_core_set_coc_power_params(master_core, &power_params);
  if (res != MTLK_ERR_OK) {
    ELOG_DDD("Thermal: CID-%02x Unable to set Antenna param tx %u rx %u", card_idx,
             power_params.antenna_params.num_tx_antennas,
             power_params.antenna_params.num_rx_antennas);
    return res;
  }

  power_params.bw_params.coc_omn_IE = ant_cnt;
  res = wave_core_set_coc_power_params(master_core, &power_params);
  if (res != MTLK_ERR_OK) {
    ELOG_DD("Thermal: CID-%02x Unable to update OMN IE, ant_cnt: %u", card_idx, ant_cnt);
    return res;
  }
  return MTLK_ERR_OK;
}

static mtlk_error_t
_wave_cooling_cur_state_cooling_method(mtlk_hw_t *hw, struct wave_thermal *thermal,
            cooling_method_t *cmethod, uint32 *updated_cooling_state_cnt)
{
  uint32 i, param;
  mtlk_error_t res;
  for (i = COOLING_TYPE_FIRST; i < COOLING_TYPE_MAX; i++) {
    ILOG2_DDDDD("Thermal: CID-%02x Type %u param %u cooling_state_cnt (old/new): %u/%u",
                mtlk_hw_mmb_get_card_idx(hw), i,  cmethod[i].param,
                thermal->cooling_state_cnt[i], updated_cooling_state_cnt[i]);
    if (thermal->cooling_state_cnt[i] == updated_cooling_state_cnt[i])
      continue;

    param = cmethod[i].param;
    /* The updated count is 0. i.e. Any previous cooling state of the cooling method
     * should be turned off. Set param to MAX_UINT32 to identify such case.
     */
    if (thermal->cooling_state_cnt[i] && !updated_cooling_state_cnt[i])
      param = MAX_UINT32;

    switch (i) {
      case COOLING_TYPE_TX_DUTY_CYCLE:
        res = _wave_cooling_radio_set_duty_cycle(hw, param);
        break;
      case COOLING_TYPE_ANTENNA:
        res = _wave_cooling_radio_set_antenna_mask(hw, param);
        break;
      default:
        break;
    }
    if (res == MTLK_ERR_OK)
      /* Store the cooling state count for the cooling method */
      thermal->cooling_state_cnt[i] = updated_cooling_state_cnt[i];
  }
  return res;
}

int __MTLK_IFUNC
wave_cooling_set_cur_state(struct thermal_cooling_device *cd,
            unsigned long state)
{
  mtlk_hw_t *hw;
  struct wave_thermal *thermal;
  uint8 card_idx;
  mtlk_error_t res;
  unsigned long cur_state, req_state = state;
  uint32 type;
  BOOL trend_raising;
  cooling_method_t *cooling_state_params, cur_cooling_state_params[COOLING_TYPE_MAX];
  uint32 updated_cooling_state_cnt[COOLING_TYPE_MAX];

  if (!cd) {
    ELOG_P("Thermal: Invalid input params, cd %p", cd);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  hw = (mtlk_hw_t*) cd->devdata;
  if (!hw) {
    ELOG_S("Thermal: Invalid devdata from %s", cd->type);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  thermal = wave_hw_get_thermal_mgmt_data(hw);
  if (!thermal) {
    ELOG_D("Thermal: CID-%02x Invalid thermal mgmt data",
            mtlk_hw_mmb_get_card_idx(hw));
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_VALUE);
  }
  if (req_state > thermal->max_cooling_state) {
    ELOG_DDD("Thermal: CID-%02x Invalid state request, requested %lu max %lu",
            mtlk_hw_mmb_get_card_idx(hw), req_state, thermal->max_cooling_state);
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_PARAMS);
  }
  cur_state = thermal->cooling_state;
  if (req_state == cur_state)
    return _mtlk_df_mtlk_to_linux_error_code(MTLK_ERR_ALREADY_EXISTS);

  card_idx = mtlk_hw_mmb_get_card_idx(hw);
  cooling_state_params = thermal->cooling_state_params;
  memset(cur_cooling_state_params, 0xFF, sizeof(cur_cooling_state_params));
  wave_memcpy(updated_cooling_state_cnt, sizeof(updated_cooling_state_cnt),
       thermal->cooling_state_cnt, sizeof(thermal->cooling_state_cnt));
  trend_raising = (cur_state < req_state);
  /* When requested is not same as cur_state
   * If trend_raising is TRUE i.e.  Requested cooling state is Higher than current
   *  1. Go through cooling state params for each state from current
   *     to Requested state. This will be in ascending order thus providing the
   *     Max cooling state param for each type for the requested cooling state.
   *  2. Increment cooling state count for the cooling method/type. Helps in
   *     turning off the cooling method and skip when no change in cooling state
   *     of a type.
   * If trend_raising is FALSE i.e.  Requested cooling state is Lower than current
   *  1. Go through cooling state params for each state from current
   *     to Requested state. This will be in descending order thus providing the
   *     Max cooling state param for each type for the requested cooling state.
   *  2. Decrement cooling state count for the cooling method/type.
   */
  while (cur_state != req_state) {
    if (trend_raising) {
      type = cooling_state_params[cur_state++].type;
      updated_cooling_state_cnt[type]++;
    } else {
      type = cooling_state_params[--cur_state].type;
      updated_cooling_state_cnt[type]--;
    }
    if (cur_state > 0) {
      type = cooling_state_params[cur_state-1].type;
      cur_cooling_state_params[type] = cooling_state_params[cur_state-1];
    }
    ILOG2_DD("Thermal: CID-%02x state -> %lu", card_idx, cur_state);
  }
  res = _wave_cooling_cur_state_cooling_method(hw, thermal,
            &cur_cooling_state_params[0], updated_cooling_state_cnt);
  if (res == MTLK_ERR_OK)
    thermal->cooling_state = state;

  return _mtlk_df_mtlk_to_linux_error_code(res);
}

static struct thermal_zone_of_device_ops tzd_ops = {
  .get_temp = wave_thermal_zone_get_temp,
};

static const struct thermal_cooling_device_ops wave_cooling_ops = {
  .get_max_state = wave_cooling_get_max_state,
  .get_cur_state = wave_cooling_get_cur_state,
  .set_cur_state = wave_cooling_set_cur_state,
};

static void
_wave_thermal_cooling_device_unregister (mtlk_hw_t *hw)
{
  struct wave_thermal *thermal = wave_hw_get_thermal_mgmt_data(hw);
  if (!thermal)
    return;

  ILOG1_D("Thermal: CID-%02x Unregister cooling device",
          mtlk_hw_mmb_get_card_idx(hw));
  thermal_cooling_device_unregister(thermal->cd);
}

static int
_wave_thermal_cooling_device_register (mtlk_hw_t *hw)
{
  struct wave_thermal *thermal = wave_hw_get_thermal_mgmt_data(hw);
  char dev_name[THERMAL_NAME_LENGTH];
  struct pci_dev *pdev = wave_hw_mmb_get_pci_dev(hw);

  ILOG1_D("Thermal: CID-%02x Register cooling device", mtlk_hw_mmb_get_card_idx(hw));
  mtlk_snprintf(dev_name, sizeof(dev_name), "cdev-%s", thermal->tzd->type);
  thermal->cd = thermal_of_cooling_device_register(pdev->dev.of_node,
      dev_name, hw, &wave_cooling_ops);
  if (IS_ERR(thermal->cd)) {
    pr_err("Failed to register cooling device (error %ld)",
      PTR_ERR(thermal->cd));
    return MTLK_ERR_UNKNOWN;
  }
  return MTLK_ERR_OK;
}

static mtlk_error_t
_wave_thermal_set_cooling_props(struct wave_thermal *thermal, uint32 max_cooling_state, cooling_method_t *cooling_params)
{
  cooling_method_t default_cooling_params[DEFAULT_NUM_COOLING_STATE] =
    {
/* TODO: reenable when dutycycle can be used */
#if 0
     {COOLING_TYPE_TX_DUTY_CYCLE, 70},
     {COOLING_TYPE_TX_DUTY_CYCLE, 50},
     {COOLING_TYPE_TX_DUTY_CYCLE, 30},
#endif
     {COOLING_TYPE_ANTENNA, 3},
     {COOLING_TYPE_ANTENNA, 2},
     {COOLING_TYPE_ANTENNA, 1}};

  thermal->cooling_state_params = mtlk_osal_mem_alloc(sizeof(cooling_method_t) * max_cooling_state, WAVE_MEM_TAG_THERMAL);
  if (!thermal->cooling_state_params) {
    ELOG_S("Thermal: Unable to allocate cooling state param for tzd %s", thermal->tzd->type);
    return MTLK_ERR_NO_MEM;
  }
  memset(thermal->cooling_state_params, 0, sizeof(cooling_method_t) * max_cooling_state);
  thermal->max_cooling_state = max_cooling_state;

  if (cooling_params) {
    wave_memcpy(thermal->cooling_state_params, sizeof(cooling_method_t) * max_cooling_state,
        cooling_params, sizeof(cooling_method_t) * max_cooling_state);
  } else {
    wave_memcpy(thermal->cooling_state_params, sizeof(cooling_method_t) * max_cooling_state,
        default_cooling_params, sizeof(default_cooling_params));
  }
  mtlk_dump(2, thermal->cooling_state_params, (sizeof(cooling_method_t) * thermal->max_cooling_state), "cooling-states");
  return MTLK_ERR_OK;
}

static mtlk_error_t
_wave_thermal_parse_cooling_props(struct device_node *np, struct wave_thermal *thermal, uint8 card_idx)
{
  uint32 max_cooling_state = 0xFF;
  int error;
  mtlk_error_t res = MTLK_ERR_UNKNOWN;

  if (((error = of_property_read_u32(np, "max-cooling-state", &max_cooling_state)) != 0) ||
      (max_cooling_state == 0 || max_cooling_state > MAX_NUM_COOLING_STATE)) {
    WLOG_DDD("Thermal: CID-%02x Didn't find/Invalid max-cooling-state param, error %d"
            " max_cooling_state %u", card_idx, error, max_cooling_state);
    /* set default cooling states and params */
    res = _wave_thermal_set_cooling_props(thermal, DEFAULT_NUM_COOLING_STATE, NULL);
    return res;
  }

  ILOG1_DD("Thermal: CID-%02x Found max-cooling-state param %u", card_idx, max_cooling_state);
  thermal->max_cooling_state = max_cooling_state;
  {
    uint32 num_u32_elements = thermal->max_cooling_state * (sizeof(cooling_method_t)/sizeof(uint32));
    cooling_method_t  *cooling_params;
    cooling_params = mtlk_osal_mem_alloc(sizeof(*cooling_params) * thermal->max_cooling_state, WAVE_MEM_TAG_THERMAL);
    if (!cooling_params) {
      ELOG_D("Thermal: CID-%02x Failed to allocate cooling params", card_idx);
      return MTLK_ERR_NO_MEM;
    }
    if ((error = of_property_read_u32_array(np, "cooling-states", (uint32*) cooling_params, num_u32_elements)) != 0) {
      /* set default cooling states and params */
      WLOG_DD("Thermal: CID-%02x Didn't find cooling state params, error %d", card_idx, error);
      res = _wave_thermal_set_cooling_props(thermal, DEFAULT_NUM_COOLING_STATE, NULL);
      mtlk_osal_mem_free(cooling_params);
      return res;
    } else {
      ILOG1_D("Thermal: CID-%02x Found cooling state params", card_idx);
      res = _wave_thermal_set_cooling_props(thermal, max_cooling_state, cooling_params);
    }
    mtlk_osal_mem_free(cooling_params);
  }
  return res;
}

static mtlk_error_t
_wave_thermal_thermal_zone_register (mtlk_hw_t *hw)
{
  struct device_node *np;
  struct wave_thermal *thermal = NULL;
  struct pci_dev *pdev = wave_hw_mmb_get_pci_dev(hw);
  mtlk_error_t res;

  uint8 card_idx = mtlk_hw_mmb_get_card_idx(hw);
  wave_radio_descr_t *radio_descr = wave_card_radio_descr_get(hw);

  /* Temperature sensor are per card. Should be OK using radio0 master core */
  wave_radio_t *radio = wave_radio_descr_wave_radio_get(radio_descr, 0);
  uint8 wave_band = wave_radio_band_get(radio);

  ILOG1_DD("Thermal: CID-%02x Register thermal zone device, band %d", card_idx, wave_band);

  thermal = mtlk_osal_mem_alloc(sizeof(*thermal), WAVE_MEM_TAG_THERMAL);
  if (!thermal) {
    ELOG_D("Thermal: CID-%02x Failed to allocate thermal data", card_idx);
    return MTLK_ERR_NO_MEM;
  }
  memset(thermal, 0, sizeof(*thermal));

  /* PCI  device has no node in the DT, search for compatible devices */
  for_each_compatible_node(np, NULL, "mxl,wave") {
    u32 band;

    if (of_property_read_u32(np, "wave-band", &band) == 0) {
      if (band == wave_band) {
        ILOG1_D("Thermal: CID-%02x found DT node for PCI dev", card_idx);
        res = _wave_thermal_parse_cooling_props(np, thermal, card_idx);
        if (res != MTLK_ERR_OK)
           goto error;
        pdev->dev.of_node = of_node_get(np);
        goto register_sensor;
      }
    }
  }

  /* TODO: No PCI device node, no compatible node, try to register a thermal
   * zone and don't use DT */

  ILOG0_D("Thermal: CID-%02x No DT node for PCI dev", card_idx);
  mtlk_osal_mem_free(thermal);
  /* DT node not found. Lets not fail, Skip tzd registeration */
  return MTLK_ERR_NO_ENTRY;

register_sensor:
  thermal->tzd = devm_thermal_zone_of_sensor_register(&pdev->dev,
                   0, hw, &tzd_ops);
  if (IS_ERR(thermal->tzd)) {
    pr_err(" Thermal: CID-%02x Failed to register thermal zone device"
           "( err %ld)", card_idx, PTR_ERR(thermal->tzd));
    res = MTLK_ERR_UNKNOWN;
    goto error;
  }
  ILOG1_DD("Thermal: CID-%02x Register thermal zone device success!!!, band %d", card_idx, wave_band);
  /* per card thermal data */
  wave_hw_set_thermal_mgmt_data(hw, thermal);

  return MTLK_ERR_OK;

error:
  if (thermal) {
    if (thermal->cooling_state_params)
      mtlk_osal_mem_free(thermal->cooling_state_params);
    mtlk_osal_mem_free(thermal);
  }
  wave_hw_set_thermal_mgmt_data(hw, NULL);

  return res;
}

static void
_wave_thermal_thermal_zone_unregister (mtlk_hw_t *hw)
{
  struct wave_thermal *thermal = wave_hw_get_thermal_mgmt_data(hw);
  struct pci_dev *pdev = wave_hw_mmb_get_pci_dev(hw);

  ILOG1_D("Thermal: CID-%02x Unregister thermal zone device", mtlk_hw_mmb_get_card_idx(hw));

  if (!thermal)
    return;

  if (thermal->tzd) {
    devm_thermal_zone_of_sensor_unregister(&pdev->dev, thermal->tzd);
    thermal->tzd = NULL;
  }

  if (thermal->cooling_state_params)
    mtlk_osal_mem_free(thermal->cooling_state_params);
  if (thermal)
    mtlk_osal_mem_free(thermal);
  wave_hw_set_thermal_mgmt_data(hw, NULL);
}
#endif /*CONFIG_THERMAL */

mtlk_error_t __MTLK_IFUNC
wave_thermal_init (mtlk_hw_t *hw)
{
  mtlk_error_t res = MTLK_ERR_OK;
#ifdef CONFIG_THERMAL
  res = _wave_thermal_thermal_zone_register(hw);
  if (res != MTLK_ERR_OK) {
   if (res == MTLK_ERR_NO_ENTRY)
     /* Don't fail the init, when TZD DT entry not found */
     res = MTLK_ERR_OK;
   goto finish;
  }
  res = _wave_thermal_cooling_device_register(hw);

finish:
#endif
  return res;
}

void __MTLK_IFUNC
wave_thermal_exit (mtlk_hw_t *hw)
{
#ifdef CONFIG_THERMAL
  _wave_thermal_cooling_device_unregister(hw);
  _wave_thermal_thermal_zone_unregister(hw);
#endif
}
