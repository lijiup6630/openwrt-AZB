/******************************************************************************

         Copyright (c) 2020, MaxLinear, Inc.
         Copyright 2016 - 2020 Intel Corporation
         Copyright 2015 - 2016 Lantiq Beteiligungs-GmbH & Co. KG
         Copyright 2009 - 2014 Lantiq Deutschland GmbH
         Copyright 2007 - 2008 Infineon Technologies AG

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

/*
 * $Id$
 *
 *
 *
 * Core configuration implementation
 *
 */
#include "mtlkinc.h"
#include "core.h"
#include "core_stats.h"
#include "core_config.h"
#include "mtlk_vap_manager.h"
#include "eeprom.h"
#include "hw_mmb.h"
#include "mtlkaux.h"
#include "mtlk_df_user_priv.h"
#include "mtlkdfdefs.h"
#include "mhi_umi.h"
#include "mhi_umi_propr.h"
#include "scan_support.h"
#include "mtlk_df_priv.h"
#include "mtlk_df.h"
#include "cfg80211.h"
#include "mac80211.h"
#include "mcast.h"
#include "wave_hal_stats.h"
#include "bitrate.h"
#include <linux/jiffies.h>

#define LOG_LOCAL_GID   GID_CORE
#define LOG_LOCAL_FID   5

/* convert TID to AC   */
static const uint8 convert_tid_to_AC[HAL_NUM_OF_TIDS] = {
    WIFI_RADIO_QUEUE_TYPE_BE,
    WIFI_RADIO_QUEUE_TYPE_BK,
    WIFI_RADIO_QUEUE_TYPE_BK,
    WIFI_RADIO_QUEUE_TYPE_BE,
    WIFI_RADIO_QUEUE_TYPE_VI,
    WIFI_RADIO_QUEUE_TYPE_VI,
    WIFI_RADIO_QUEUE_TYPE_VO,
    WIFI_RADIO_QUEUE_TYPE_VO,
    WIFI_RADIO_QUEUE_TYPE_BE,
    WIFI_RADIO_QUEUE_TYPE_BK,
    WIFI_RADIO_QUEUE_TYPE_BK,
    WIFI_RADIO_QUEUE_TYPE_BE,
    WIFI_RADIO_QUEUE_TYPE_VI,
    WIFI_RADIO_QUEUE_TYPE_VI,
    WIFI_RADIO_QUEUE_TYPE_VO,
    WIFI_RADIO_QUEUE_TYPE_VO,
};

static inline unsigned int mtlk_nsecs_to_msecs(u64 nsecs)
{
  return jiffies_to_msecs(nsecs_to_jiffies(nsecs));
}

int __MTLK_IFUNC
mtlk_core_get_associated_dev_tid_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerTidStats tid_stats;
  int tid_idx;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      memset(&tid_stats, 0, sizeof(peerTidStats));
      /* Plume needs the following per TID stats, however FW maintains per STA
         Thus we are filling the same statistic for all 16 TIDs                */
      for (tid_idx = 0; tid_idx < HAL_NUM_OF_TIDS; tid_idx++) {
        /* Number of msdus in given interval for per STA */
        tid_stats[tid_idx].num_msdus    = sta->sta_stats64_cntrs.numMsdus;
        /* Moving average value based on last couple of transmitted msdus for per station */
        tid_stats[tid_idx].ewma_time_ms = mtlk_nsecs_to_msecs((uint64)sta->sta_stats_cntrs.ewmaTimeNsec);
        /* Delta of cumulative msdus times over interval for per station  */
        tid_stats[tid_idx].sum_time_ms  = mtlk_nsecs_to_msecs(sta->sta_stats64_cntrs.sumTimeNsec);
        tid_stats[tid_idx].tid = tid_idx;
        tid_stats[tid_idx].ac  = convert_tid_to_AC[tid_idx];
      }
      mtlk_sta_decref(sta);
  }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &tid_stats, sizeof(peerTidStats));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
mtlk_core_get_channel_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_channel_stats *chan_stats = NULL;
  int res = MTLK_ERR_OK;
  uint32 num_of_channels = 0, channels_list_size, chan_idx, *channels_list;
  size_t total_size = 0;
  mtlk_hw_t *hw = NULL;

  channels_list = mtlk_clpb_enum_get_next(clpb, &channels_list_size);
  num_of_channels = channels_list_size/(sizeof(*channels_list));
  MTLK_CLPB_TRY_EX(channels_list, channels_list_size, sizeof(*channels_list)*num_of_channels)

    hw = mtlk_vap_get_hw(core->vap_handle);

    total_size = sizeof(mtlk_channel_stats) * num_of_channels;
    chan_stats = mtlk_osal_mem_alloc(total_size, MTLK_MEM_TAG_EXTENSION);
    if (NULL == chan_stats) {
      ELOG_V("Can't allocate memory");
      MTLK_CLPB_EXIT(MTLK_ERR_NO_MEM);
    }
    memset(chan_stats, 0, total_size);

    for (chan_idx = 0; chan_idx < num_of_channels; chan_idx++) {
      mtlk_hw_copy_stats_per_channel(hw, &chan_stats[chan_idx], channels_list[chan_idx]);
    }
  MTLK_CLPB_FINALLY(res)
    res = mtlk_clpb_push_res_data_no_copy(clpb, res, chan_stats, total_size);
    if (MTLK_ERR_OK != res && chan_stats != NULL) {
      mtlk_osal_mem_free(chan_stats);
    }
    return res;
  MTLK_CLPB_END;
}

static const uint16 hal_cbw[] = {HAL_BW_20MHZ, HAL_BW_40MHZ, HAL_BW_80MHZ, HAL_BW_160MHZ};
void __MTLK_IFUNC
mtlk_core_get_associated_dev_rate_info_rx_stats (sta_entry * sta, peerRateInfoRxStats * peer_rx_rate_info)
{
  uint8 cbw, i, mode;
  cbw  = mtlk_bitrate_params_get_psdu_cbw(sta->info.stats.rx_psdu_data_rate_info);
  mode = mtlk_bitrate_params_get_psdu_mode(sta->info.stats.rx_psdu_data_rate_info);

  memset(peer_rx_rate_info, 0, sizeof(*peer_rx_rate_info));

  /* Handling mcs seperately incase of HT(11n) mode because WIFI HAL expects mcs value <0-7> for HT(11n)
    * but as per statndard HT mcs value is <0-32> */
  if (PHY_MODE_N == mode){
    mtlk_bitrate_params_get_11n_mcs_and_nss_for_plume(sta->info.stats.rx_psdu_data_rate_info, &peer_rx_rate_info->mcs, &peer_rx_rate_info->nss);
  } else {
    mtlk_bitrate_params_get_psdu_mcs_and_nss(sta->info.stats.rx_psdu_data_rate_info, &peer_rx_rate_info->mcs, &peer_rx_rate_info->nss);
  }

  peer_rx_rate_info->bw = hal_cbw[cbw];
  peer_rx_rate_info->bytes = sta->sta_stats64_cntrs.rxOutStaNumOfBytes;
  peer_rx_rate_info->flags |= BIT_ULL(HAS_BYTES);
  peer_rx_rate_info->msdus = sta->sta_stats64_cntrs.rdCount;
  peer_rx_rate_info->flags |= BIT_ULL(HAS_MSDUS);
  peer_rx_rate_info->mpdus = sta->sta_stats64_cntrs.mpduInAmpdu;
  peer_rx_rate_info->flags |= BIT_ULL(HAS_MPDUS);
  peer_rx_rate_info->ppdus = sta->sta_stats64_cntrs.ampdu;
  peer_rx_rate_info->flags |= BIT_ULL(HAS_PPDUS);
  peer_rx_rate_info->retries = sta->sta_stats64_cntrs.rxRetryCount;
  peer_rx_rate_info->rssi_combined = sta->info.stats.max_rssi;
  peer_rx_rate_info->flags |= BIT_ULL(HAS_RSSI_COMB);
  for (i = 0; i < MAX_NUM_RX_ANTENNAS; i++) {
    peer_rx_rate_info->rssi_array[i][0] = sta->info.stats.data_rssi[i];
  }
  peer_rx_rate_info->flags |= BIT_ULL(HAS_RSSI_ARRAY);
}

int __MTLK_IFUNC
mtlk_core_get_associated_dev_rate_info_rx_stats_clb (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerRateInfoRxStats peer_rx_rate_info;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_core_get_associated_dev_rate_info_rx_stats(sta, &peer_rx_rate_info);
      mtlk_sta_decref(sta);
    }
  MTLK_CLPB_FINALLY(res)
  return mtlk_clpb_push_res_data(clpb, res, &peer_rx_rate_info, sizeof(peerRateInfoRxStats));
  MTLK_CLPB_END;
}

void __MTLK_IFUNC
mtlk_core_calc_associated_dev_rate_info_rx_stats (peerRateInfoRxStats * dest, peerRateInfoRxStats * new, peerRateInfoRxStats * old)
{
  dest->bytes += new->bytes - old->bytes;
  dest->msdus += new->msdus - old->msdus;
  dest->mpdus += new->mpdus - old->mpdus;
  dest->ppdus += new->ppdus - old->ppdus;
  dest->retries += new->retries - old->retries;
  dest->rssi_combined = new->rssi_combined;
  wave_memcpy(dest->rssi_array, sizeof(dest->rssi_array), new->rssi_array, sizeof(new->rssi_array));
}

void __MTLK_IFUNC
mtlk_core_get_associated_dev_rate_info_tx_stats (sta_entry * sta, peerRateInfoTxStats * peer_tx_rate_info)
{
  uint8 cbw, mode;
  mode = mtlk_bitrate_params_get_mode(sta->info.stats.tx_data_rate_params);

  memset(peer_tx_rate_info, 0, sizeof(*peer_tx_rate_info));

  if ((mode == PHY_MODE_AG) || (mode == PHY_MODE_B)) {
    peer_tx_rate_info->nss = HAL_LEGACY_NSS;
  } else {
    peer_tx_rate_info->nss = mtlk_bitrate_params_get_nss(sta->info.stats.tx_data_rate_params);
  }

  peer_tx_rate_info->mcs = mtlk_bitrate_params_get_mcs(sta->info.stats.tx_data_rate_params);
  cbw = mtlk_bitrate_params_get_cbw(sta->info.stats.tx_data_rate_params);
  peer_tx_rate_info->bw = hal_cbw[cbw];
  peer_tx_rate_info->bytes = sta->sta_stats64_cntrs.mpduByteTransmitted;
  peer_tx_rate_info->flags |= BIT_ULL(HAS_BYTES);
  peer_tx_rate_info->msdus = sta->sta_stats64_cntrs.successCount + sta->sta_stats64_cntrs.exhaustedCount;
  peer_tx_rate_info->flags |= BIT_ULL(HAS_MSDUS);
  peer_tx_rate_info->mpdus = sta->sta_stats64_cntrs.mpduTransmitted;
  peer_tx_rate_info->flags |= BIT_ULL(HAS_MPDUS);
  peer_tx_rate_info->ppdus = sta->sta_stats64_cntrs.transmittedAmpdu;
  peer_tx_rate_info->flags |= BIT_ULL(HAS_PPDUS);
  peer_tx_rate_info->retries = sta->sta_stats64_cntrs.txRetryCount;
  peer_tx_rate_info->attempts = sta->sta_stats64_cntrs.mpduFirstRetransmission;
}

int __MTLK_IFUNC
mtlk_core_get_associated_dev_rate_info_tx_stats_clb (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerRateInfoTxStats peer_tx_rate_info;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_core_get_associated_dev_rate_info_tx_stats(sta, &peer_tx_rate_info);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
  return mtlk_clpb_push_res_data(clpb, res, &peer_tx_rate_info, sizeof(peerRateInfoTxStats));
  MTLK_CLPB_END;
}

void __MTLK_IFUNC
mtlk_core_calc_associated_dev_rate_info_tx_stats (peerRateInfoTxStats * dest, peerRateInfoTxStats * new, peerRateInfoTxStats * old)
{
  dest->bytes += new->bytes - old->bytes;
  dest->msdus += new->msdus - old->msdus;
  dest->mpdus += new->mpdus - old->mpdus;
  dest->retries += new->retries - old->retries;
  dest->attempts += new->attempts - old->attempts;
}

int __MTLK_IFUNC
mtlk_core_get_associated_dev_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerFlowStats peer_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      memset(&peer_stats , 0, sizeof(peerFlowStats));
      mtlk_sta_get_associated_dev_stats(sta, &peer_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_stats, sizeof(peerFlowStats));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
mtlk_core_stats_poll_period_get (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_hw_t *hw = NULL;
  uint32 poll_period = 0;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  hw = mtlk_vap_get_hw(core->vap_handle);
  MTLK_ASSERT(hw);

  /* read config from internal db */
  poll_period = wave_hw_mmb_get_stats_poll_period(hw);

  /* push result and config to clipboard*/
  res = mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &poll_period,
    sizeof(poll_period));

  return res;
}

int __MTLK_IFUNC
mtlk_core_stats_poll_period_set (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_df_t *df = mtlk_vap_get_df(core->vap_handle);
  mtlk_df_user_t *df_user = mtlk_df_get_user(df);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  uint32 *poll_period = NULL, poll_period_size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* get configuration */
  poll_period = mtlk_clpb_enum_get_next(clpb, &poll_period_size);
  MTLK_CLPB_TRY(poll_period, poll_period_size)
    wave_hw_mmb_set_stats_poll_period(df, *poll_period);
    mtlk_df_user_stats_timer_set(df_user, *poll_period);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

int __MTLK_IFUNC
mtlk_core_get_peer_list (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  if (0 == (mtlk_core_get_net_state(nic) & (NET_STATE_HALTED | NET_STATE_CONNECTED))) {
    return MTLK_ERR_OK;
  }

  return mtlk_stadb_get_peer_list(&nic->slow_ctx->stadb, clpb);
}

int __MTLK_IFUNC
wave_core_probe_req_list_get(mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  int res;
  probe_req_info info;
  res = wave_radio_copy_probe_req_list(radio, &info);
  if (MTLK_ERR_OK != res) {
    return res;
  }
  res = mtlk_clpb_push(clpb, &info, sizeof(probe_req_info));
  if (MTLK_ERR_OK != res) {
    goto free;
  }

  return res;

free:
  if (info.data)
    mtlk_osal_mem_free(info.data);

  return res;
}

int __MTLK_IFUNC
mtlk_core_get_peer_flow_status (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  mtlk_wssa_drv_peer_stats_t peer_flow_status;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_peer_stats(sta, &peer_flow_status);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_flow_status, sizeof(mtlk_wssa_drv_peer_stats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
mtlk_core_get_peer_capabilities (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  mtlk_wssa_drv_peer_capabilities_t peer_capabilities;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_peer_capabilities(sta, &peer_capabilities);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_capabilities, sizeof(mtlk_wssa_drv_peer_capabilities_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
mtlk_core_get_peer_rate_info (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  mtlk_wssa_drv_peer_rates_info_t peer_rate_info;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      _mtlk_sta_get_peer_rates_info(sta, &peer_rate_info);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_rate_info, sizeof(mtlk_wssa_drv_peer_rates_info_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
mtlk_core_get_recovery_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_recovery_stats_t recovery_stats;
  mtlk_hw_t *hw = NULL;

  hw = mtlk_vap_get_hw(core->vap_handle);
  MTLK_ASSERT(hw);

  wave_hw_get_recovery_stats(hw, &recovery_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &recovery_stats, sizeof(mtlk_wssa_drv_recovery_stats_t));
}

int __MTLK_IFUNC
mtlk_core_get_hw_flow_status (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t  *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_wssa_drv_hw_stats_t hw_flow_status;

  wave_radio_get_hw_stats(radio, &hw_flow_status);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &hw_flow_status, sizeof(mtlk_wssa_drv_hw_stats_t));
}

int __MTLK_IFUNC
mtlk_core_get_tr181_wlan_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_tr181_wlan_stats_t tr181_stats;

  mtlk_core_get_tr181_wlan_stats(core, &tr181_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &tr181_stats, sizeof(mtlk_wssa_drv_tr181_wlan_stats_t));
}

int __MTLK_IFUNC
mtlk_core_get_tr181_hw_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t  *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_wssa_drv_tr181_hw_stats_t tr181_stats;

  wave_radio_get_tr181_hw_stats(radio, &tr181_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &tr181_stats, sizeof(mtlk_wssa_drv_tr181_hw_stats_t));
}

int __MTLK_IFUNC
mtlk_core_get_tr181_peer_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  st_info_data_t *info_data;
  unsigned info_data_size;
  sta_entry *sta = NULL;
  mtlk_wssa_drv_tr181_peer_stats_t tr181_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  info_data = mtlk_clpb_enum_get_next(clpb, &info_data_size);
  MTLK_CLPB_TRY(info_data, info_data_size)

  if (info_data->sta)
    sta = wv_ieee80211_get_sta(info_data->sta);
  else
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, info_data->mac);

  if (NULL == sta) {
    ILOG1_DY("CID-%04x: station %Y not found",
               mtlk_vap_get_oid(core->vap_handle), info_data->mac);
    MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
  } else {
      mtlk_sta_get_tr181_peer_stats(sta, &tr181_stats);
      mtlk_sta_decref(sta);
  }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &tr181_stats, sizeof(mtlk_wssa_drv_tr181_peer_stats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_dev_diag_result2 (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  wifiAssociatedDevDiagnostic2_t dev_diag_res2_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      wave_sta_get_dev_diagnostic_res2(core, sta, &dev_diag_res2_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &dev_diag_res2_stats, sizeof(wifiAssociatedDevDiagnostic2_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_dev_diag_result3 (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  wifiAssociatedDevDiagnostic3_t *dev_diag_res3_stats = NULL;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)
    dev_diag_res3_stats = mtlk_osal_mem_alloc(sizeof(wifiAssociatedDevDiagnostic3_t), MTLK_MEM_TAG_EXTENSION);
    if (NULL == dev_diag_res3_stats) {
      ELOG_V("Can't allocate memory for dev_diag_res3_stats struct");
      MTLK_CLPB_EXIT(MTLK_ERR_NO_MEM);
    }
    memset(dev_diag_res3_stats, 0, sizeof(wifiAssociatedDevDiagnostic3_t));

    /* find station in stadb */
    sta = mtlk_vap_find_sta(core->vap_handle, addr->au8Addr);
    if (NULL == sta) {
      ILOG1_DY("CID-%04x: station %Y not found", mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      wave_sta_get_dev_diagnostic_res3(core, sta, dev_diag_res3_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    res = mtlk_clpb_push_res_data_no_copy(clpb, res, dev_diag_res3_stats, sizeof(wifiAssociatedDevDiagnostic3_t));
    if (MTLK_ERR_OK != res && dev_diag_res3_stats != NULL) {
      mtlk_osal_mem_free(dev_diag_res3_stats);
    }
    return res;
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_associated_stations_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr_list, *addr;
  uint32 i, addr_list_size, num_addr = 0, alloc_size = 0;
  sta_entry *sta = NULL;
  wifiAssociatedStationStats_t *assoc_stations_stats = NULL, *assoc_sta_stats;
  mtlk_wssa_drv_peer_rates_info_t peer_rates_info;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr_list = mtlk_clpb_enum_get_next(clpb, &addr_list_size);
  if (addr_list_size <= sizeof(IEEE_ADDR))
    num_addr = 1;
  else
    num_addr = addr_list_size / sizeof(IEEE_ADDR);

  MTLK_CLPB_TRY_EX(addr_list, addr_list_size, (sizeof(IEEE_ADDR) * num_addr))
    alloc_size = sizeof(wifiAssociatedStationStats_t) * num_addr;
    assoc_stations_stats = mtlk_osal_mem_alloc(alloc_size, MTLK_MEM_TAG_EXTENSION);
    if (NULL == assoc_stations_stats) {
      ELOG_V("Can't allocate memory for assoc_stations_stats struct");
      MTLK_CLPB_EXIT(MTLK_ERR_NO_MEM);
    }
    memset(assoc_stations_stats, 0, alloc_size);

    for (i = 0; i < num_addr; ++i) {
      /* find station in stadb */
      addr = &addr_list[i];
      assoc_sta_stats = &assoc_stations_stats[i];

      sta = mtlk_vap_find_sta(core->vap_handle, addr->au8Addr);
      if (NULL == sta) {
        ILOG2_DY("CID-%04x: station %Y not found", mtlk_vap_get_oid(core->vap_handle), addr);
      } else {
        int j;

        _mtlk_sta_get_peer_rates_info(sta, &peer_rates_info);

        assoc_sta_stats->BytesSent = sta->sta_stats64_cntrs.mpduByteTransmitted;
        assoc_sta_stats->BytesReceived = sta->sta_stats64_cntrs.rxOutStaNumOfBytes;

        /* TX */
        assoc_sta_stats->TxDataRateInfo.InfoFlag = peer_rates_info.tx_data_rate_info.InfoFlag;
        assoc_sta_stats->TxDataRateInfo.DataRate = peer_rates_info.TxDataRate;
        assoc_sta_stats->TxDataRateInfo.CbwIdx = peer_rates_info.tx_data_rate_info.CbwIdx;
        assoc_sta_stats->TxDataRateInfo.Nss = peer_rates_info.tx_data_rate_info.Nss;
        if (peer_rates_info.rx_data_rate_info.PhyMode < PHY_MODE_AX) {
          assoc_sta_stats->TxDataRateInfo.Sgi = peer_rates_info.tx_data_rate_info.Scp ? TRUE : FALSE; /* FW enum Scp_e */
        }
        else { /* FW enum CyclicPrefixMode_e */
          switch (peer_rates_info.tx_data_rate_info.Scp) {
            case 0: /* CP_MODE_SHORT_CP_SHORT_LTF */
            case 2: /* CP_MODE_SHORT_CP_MED_LTF */
            case 4: /* CP_MODE_SHORT_CP_LONG_LTF */
              assoc_sta_stats->TxDataRateInfo.Sgi  = 1;
              break;
            default:
              assoc_sta_stats->TxDataRateInfo.Sgi  = 0;
          }
        }

        /* RX */
        assoc_sta_stats->RxDataRateInfo.InfoFlag = peer_rates_info.rx_data_rate_info.InfoFlag;
        assoc_sta_stats->RxDataRateInfo.DataRate = peer_rates_info.RxDataRate;
        assoc_sta_stats->RxDataRateInfo.CbwIdx = peer_rates_info.rx_data_rate_info.CbwIdx;
        assoc_sta_stats->RxDataRateInfo.Nss = peer_rates_info.rx_data_rate_info.Nss;
        if (peer_rates_info.rx_data_rate_info.PhyMode < PHY_MODE_AX) /* SCP [bit 0], HE CP [bits 1..2] */
          assoc_sta_stats->RxDataRateInfo.Sgi = (peer_rates_info.rx_data_rate_info.Scp & BIT(0));
        else
          assoc_sta_stats->RxDataRateInfo.Sgi = !(peer_rates_info.rx_data_rate_info.Scp & (BIT(1) | BIT(2)));

        MTLK_STATIC_ASSERT(NUMBER_OF_RX_ANTENNAS ==
                           (sizeof(assoc_sta_stats->RSSI) / sizeof(assoc_sta_stats->RSSI[0])));
        for (j = 0; j < NUMBER_OF_RX_ANTENNAS; ++j) {
          assoc_sta_stats->RSSI[j] = mtlk_sta_get_short_term_rssi(sta, j);
        }

        /* Let upper layer know the station was found, and statistics were filled.
         * This is needed since we don't wish to fail the call if one or more mac addr
         * are no longer connected to driver. (not found) */
        assoc_sta_stats->IsFilled = 1;

        mtlk_sta_decref(sta);
      }
    }

  MTLK_CLPB_FINALLY(res)
    res = mtlk_clpb_push_res_data_no_copy(clpb, res, assoc_stations_stats, alloc_size);
    if (MTLK_ERR_OK != res && assoc_stations_stats != NULL) {
      mtlk_osal_mem_free(assoc_stations_stats);
    }
    return res;
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
mtlk_core_get_priority_gpio_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_hw_t *hw = NULL;
  mtlk_priority_gpio_stats_t pta_stats;

  hw = mtlk_vap_get_hw(core->vap_handle);
  mtlk_hw_get_priority_gpio_stats(hw, &pta_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &pta_stats, sizeof(mtlk_priority_gpio_stats_t));
}

static void _wave_core_cca_stats_to_cca_stats_user (wave_cca_stats_t *cca, wave_cca_stats_user_t *user)
{
  /* round up and convert to milliseconds */
  cca->time_on_channel += 500ul;
  cca->ccaIntf         += 500ul;
  cca->ccaTx           += 500ul;
  cca->ccaRx           += 500ul;

  do_div(cca->time_on_channel,  1000ul);
  do_div(cca->ccaIntf,          1000ul);
  do_div(cca->ccaTx,            1000ul);
  do_div(cca->ccaRx,            1000ul);

  /* Intf = Rx - BusySelf */
  cca->ccaIntf = cca->ccaRx - cca->ccaIntf;
  /* Idle = Total - (Rx+Tx) */
  cca->ccaIdle = cca->time_on_channel - (cca->ccaTx + cca->ccaRx);

  user->ccaTotal = (uint32)cca->time_on_channel;
  user->ccaIdle  = (uint32)cca->ccaIdle;
  user->ccaIntf  = (uint32)cca->ccaIntf;
  user->ccaTx    = (uint32)cca->ccaTx;
  user->ccaRx    = (uint32)cca->ccaRx;

  user->has_ccaTotal = 1;
  user->has_ccaIdle  = 1;
  user->has_ccaIntf  = 1;
  user->has_ccaTx    = 1;
  user->has_ccaRx    = 1;

  ILOG1_DDDDD("OnChan Total %u Idle %u Intf %u Tx %u Rx %u", user->ccaTotal, user->ccaIdle, user->ccaIntf, user->ccaTx, user->ccaRx);

  /* check for overflow: u64 vs u32 comparison */
  if (cca->time_on_channel > user->ccaTotal) {
    ILOG1_V("ccaTotal overflow");
    user->has_ccaTotal = 0;
  }
  if (cca->ccaIdle > user->ccaIdle) {
    ILOG1_V("ccaIdle overflow");
    user->has_ccaIdle  = 0;
  }
  if (cca->ccaIntf > user->ccaIntf) {
    ILOG1_V("ccaIntf overflow");
    user->has_ccaIntf  = 0;
  }
  if (cca->ccaTx > user->ccaTx) {
    ILOG1_V("ccaTx overflow");
    user->has_ccaTx    = 0;
  }
  if (cca->ccaRx > user->ccaRx) {
    ILOG1_V("ccaRx overflow");
    user->has_ccaRx    = 0;
  }
}

void __MTLK_IFUNC
wave_core_cca_stats_save (mtlk_core_t *core, int channel, wave_cca_stats_t *cca_stats, wave_cca_stats_user_t *cca_stats_user, BOOL on_chan)
{
  mtlk_hw_t *hw = mtlk_vap_get_hw(core->vap_handle);
  wave_hw_cca_stats_get(hw, channel, cca_stats);

  if (on_chan) {
    wave_radio_t  *radio = wave_vap_radio_get(core->vap_handle);
    wave_radio_cca_stat_update(radio, cca_stats, channel);
  }

  _wave_core_cca_stats_to_cca_stats_user(cca_stats, cca_stats_user);
}

int __MTLK_IFUNC
 wave_core_cca_stats_get (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *master_core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_hw_t *hw = NULL;
  wave_cca_stats_t cca_stats = { 0 };
  wave_cca_stats_user_t cca_stats_user = { 0 };
  int channel;

  MTLK_ASSERT(NULL != master_core);

  hw = mtlk_vap_get_hw(master_core->vap_handle);
  channel = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(master_core->vap_handle), PARAM_DB_RADIO_CHANNEL_CUR);

  ILOG1_D("channel %d", channel);
  wave_core_cca_stats_save(master_core, channel, &cca_stats, &cca_stats_user, TRUE);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &cca_stats_user, sizeof(cca_stats_user));
}

int __MTLK_IFUNC
wave_core_radio_usage_stats_get (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *master_core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_hw_t *hw = NULL;
  wave_radio_usage_stats_t radio_stats = { 0 };
  int channel, radio_id;

  MTLK_ASSERT(NULL != master_core);

  hw = mtlk_vap_get_hw(master_core->vap_handle);
  channel = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(master_core->vap_handle), PARAM_DB_RADIO_CHANNEL_CUR);
  radio_id = wave_vap_radio_id_get(master_core->vap_handle);

  ILOG1_D("channel %d", channel);
  wave_hw_radio_usage_stats_get(hw, radio_id, channel, &radio_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &radio_stats, sizeof(radio_stats));
}

static void
_wave_core_reset_sta_reset(mtlk_hw_t *hw, sta_entry *sta)
{
  sta->sta_stats64_cntrs_snapshot = sta->sta_stats64_cntrs;
  sta->sta_stats_cntrs_snapshot = sta->sta_stats_cntrs;
  return;
}

static void
_wave_core_reset_radio_statistics(mtlk_hw_t *hw, wave_radio_t *radio)
{
  wave_hw_reset_recovery_stats(hw);
  mtlk_radio_wss_reset_stat(radio);
  wave_hw_reset_txm_stats(hw);
}

static void
_wave_core_reset_all_vap_sta_reset(mtlk_hw_t *hw, mtlk_df_user_t *df_user)
{
    mtlk_vap_manager_t *vap_mgr;
    mtlk_vap_handle_t vap_handle;
    mtlk_df_t *master_df = mtlk_df_user_get_master_df(df_user);
    mtlk_df_user_t *df_master_user;
    unsigned vaps_count, vap_id;
    mtlk_stadb_iterator_t iter;
    const sta_entry      *sta_loop = NULL;

    MTLK_CHECK_DF_NORES(master_df);
    df_master_user = mtlk_df_get_user(master_df);
    vap_mgr = mtlk_df_get_vap_manager(master_df);
    vaps_count = mtlk_vap_manager_get_max_vaps_count(vap_mgr);

    for (vap_id = 0; vap_id < vaps_count; vap_id++)
    {
        if (mtlk_vap_manager_get_vap_handle(vap_mgr, vap_id, &vap_handle) == MTLK_ERR_OK) {
          mtlk_core_t *core = mtlk_vap_get_core(vap_handle);
          memset(&core->pstats, 0, sizeof(core->pstats));
          sta_loop = mtlk_stadb_iterate_first(&core->slow_ctx->stadb, &iter);
          if (sta_loop) {
            do {
              _wave_core_reset_sta_reset(hw,(sta_entry *)sta_loop);
              sta_loop = mtlk_stadb_iterate_next(&iter);
            } while(sta_loop);
            mtlk_stadb_iterate_done(&iter);
          }
        }
    }

    return;
}

int __MTLK_IFUNC
wave_core_reset_statistics(mtlk_handle_t hcore, const void *data, uint32 data_size)
{

  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_hw_t *hw = NULL;
  wave_radio_t *radio = NULL;
  int res = MTLK_ERR_OK;
  struct intel_vendor_reset_statistics *reset_stats = NULL;
  uint32 reset_stats_size;
  mtlk_df_t *df = NULL;
  MTLK_ASSERT(core != NULL);
  hw = mtlk_vap_get_hw(core->vap_handle);
  radio = wave_vap_radio_get(core->vap_handle);
  df = mtlk_vap_get_df(core->vap_handle);
  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  reset_stats = mtlk_clpb_enum_get_next(clpb, &reset_stats_size);
  MTLK_CLPB_TRY(reset_stats, reset_stats_size)
    wave_hw_stats_lock(hw, TRUE);
    wave_hw_capture_stats_snapshot_for_reset(hw);
    wave_core_reset_vap_stats(core);
    if(reset_stats->category == RESET_FULL)
    {
      _wave_core_reset_all_vap_sta_reset(hw, mtlk_df_get_user(df));
      _wave_core_reset_radio_statistics(hw, radio);
    }
    wave_hw_stats_lock(hw, FALSE);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

mtlk_error_t __MTLK_IFUNC
wave_core_get_peer_mixed_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_error_t res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  wave_peer_mixed_stats_t peer_mixed_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      memset(&peer_mixed_stats , 0, sizeof(peer_mixed_stats));
      wave_sta_get_mixed_stats(sta, &peer_mixed_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_mixed_stats, sizeof(peer_mixed_stats));
  MTLK_CLPB_END;
}

static mtlk_error_t
_wave_core_get_radio_la_mu_ofdma_count_stats(mtlk_hw_t *hw, mtlk_df_user_t *df_user, mtlk_clpb_t *clpb)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_vap_manager_t *vap_mgr;
  mtlk_vap_handle_t vap_handle;
  wave_wssa_link_adapt_mu_ofdma_stats_t muofdma_stats;
  mtlk_df_t *master_df;
  unsigned vaps_count, vap_id;
  mtlk_stadb_iterator_t iter;
  const sta_entry      *sta = NULL;

  master_df = mtlk_df_user_get_master_df(df_user);
  MTLK_RET_CHECK_DF(master_df);
  vap_mgr = mtlk_df_get_vap_manager(master_df);
  vaps_count = mtlk_vap_manager_get_max_vaps_count(vap_mgr);

  for (vap_id = 0; vap_id < vaps_count; vap_id++) {
     if (mtlk_vap_manager_get_vap_handle(vap_mgr, vap_id, &vap_handle) == MTLK_ERR_OK) {
       mtlk_core_t *core = mtlk_vap_get_core(vap_handle);
       sta = mtlk_stadb_iterate_first(&core->slow_ctx->stadb, &iter);
       if (sta) {
         do {
           muofdma_stats.sta_sid = mtlk_sta_get_sid(sta);
           muofdma_stats.addr = *(mtlk_sta_get_addr(sta));
           muofdma_stats.staRemovedNbiqBelowThresholdCounter =
                       sta->info.stats.ofdma_count_stats.staRemovedNbiqBelowThresholdCounter;
           muofdma_stats.staRemovedFavoringSuCounter =
                       sta->info.stats.ofdma_count_stats.staRemovedFavoringSuCounter;
           muofdma_stats.staNotAddedNbiqBelowThresholdCounter =
                       sta->info.stats.ofdma_count_stats.staNotAddedNbiqBelowThresholdCounter;


           res = mtlk_clpb_push(clpb, &muofdma_stats, sizeof(wave_wssa_link_adapt_mu_ofdma_stats_t));
           if (MTLK_ERR_OK != res) {
             goto err_push_sta;
           }

           sta = mtlk_stadb_iterate_next(&iter);
           } while (sta);

           mtlk_stadb_iterate_done(&iter);
       }
     }
  }

  return res;

err_push_sta:
  mtlk_stadb_iterate_done(&iter);
  mtlk_clpb_purge(clpb);
  return res;
}

mtlk_error_t __MTLK_IFUNC
wave_core_get_link_adapt_muofdma_statistics(mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  uint32 chip_id, radio_sta_cnt;
  wave_radio_t  *radio;
  mtlk_hw_t *hw = NULL;
  mtlk_df_t *df = NULL;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  df = mtlk_vap_get_df(core->vap_handle);
  hw = mtlk_vap_get_hw(core->vap_handle);
  radio = wave_vap_radio_get(core->vap_handle);
  radio_sta_cnt = wave_radio_sta_cnt_get(radio);
  chip_id = hw_mmb_get_chip_id(hw);

  if (_chipid_is_gen6_a0(chip_id)) {
    ILOG0_D("CID-%04x: Unsupported chip", chip_id);
    return MTLK_ERR_OK;
  }

  res = mtlk_clpb_push(clpb, &radio_sta_cnt, sizeof(uint32));
  if (MTLK_ERR_OK != res) {
    return res;
  }

  res = _wave_core_get_radio_la_mu_ofdma_count_stats(hw, mtlk_df_get_user(df), clpb);

  return res;
}

mtlk_error_t __MTLK_IFUNC
wave_core_get_la_su_mu_ru_ofdma_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  sta_entry       *sta = NULL;
  uint32          addr_size, ru_id;
  wave_wssa_ofdma_su_mu_ru_stats_t   peer_su_mu_ru_stats;
  wave_wssa_ofdma_su_mu_stats_t      su_mu_stats;
  wave_wssa_ofdma_total_stats_t      total_stats;
  wave_mhi_la_ofdma_su_mu_ru_stats_t *sta_stats = NULL;
  wave_vendor_su_mu_ru_stats_t       *vendor_stats = NULL;
  mtlk_error_t res  = MTLK_ERR_OK;
  mtlk_core_t *nic  = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  void *payload       = NULL;
  uint32 payload_size = 0;
  wave_vap_su_mu_ru_stats_t *mhi_vap_ofdma_stats = &nic->ofdma_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  vendor_stats = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(vendor_stats, addr_size)
    if ((vendor_stats->category != OFDMA_CATEGORY_TOTAL_STATS)) {
      /* find station in stadb */
      sta = mtlk_stadb_find_sta(&nic->slow_ctx->stadb, vendor_stats->sta_addr.au8Addr);
      if ((NULL == sta)) {
        ELOG_DY("CID-%04x: station %Y not found", mtlk_vap_get_oid(nic->vap_handle), vendor_stats->sta_addr.au8Addr);
        MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
      }
    }

    if (vendor_stats->category == OFDMA_CATEGORY_TOTAL_STATS) {
      total_stats.all_sta_failed_su_ampdus = mhi_vap_ofdma_stats->vap_failed_su_ampdus;
      total_stats.all_sta_success_su_ampdus = mhi_vap_ofdma_stats->vap_success_su_ampdus;
      for (ru_id = 0; ru_id < NUM_OF_RU_SIZES; ru_id++) {
        total_stats.all_sta_success_ru_ampdus[ru_id] = mhi_vap_ofdma_stats->vap_success_ru_ampdus[ru_id];
        total_stats.all_sta_failed_ru_ampdus[ru_id] = mhi_vap_ofdma_stats->vap_failed_ru_ampdus[ru_id];
      }
      payload = &total_stats;
      payload_size = sizeof(wave_wssa_ofdma_total_stats_t);
    } else {
      sta_stats = wave_sta_get_ofdma_su_mu_ru_stats(sta);

      if (vendor_stats->category == OFDMA_CATEGORY_MU_RU) {
        peer_su_mu_ru_stats.addr = *(mtlk_sta_get_addr(sta));
        peer_su_mu_ru_stats.sta_sid = mtlk_sta_get_sid(sta);

        for (ru_id = 0; ru_id < NUM_OF_RU_SIZES; ru_id++) {
           sta_stats->sta_mu_ru[ru_id].pkt_err_ru_percent  = WAVE_GET_PERCENTAGE(sta_stats->sta_mu_ru[ru_id].failed_ru_ampdus,
                                                                                 sta_stats->sta_mu_ru[ru_id].total_tx_ru_ampdus);
           sta_stats->sta_mu_ru[ru_id].ru_percent          = WAVE_GET_PERCENTAGE(sta_stats->sta_mu_ru[ru_id].total_tx_ru_ampdus,
                                                                                 sta_stats->total_tx_mu_ampdus);
        }

        MTLK_STATIC_ASSERT(sizeof(peer_su_mu_ru_stats.mu_ru_stats) == sizeof(sta_stats->sta_mu_ru));
        wave_memcpy(peer_su_mu_ru_stats.mu_ru_stats, sizeof(peer_su_mu_ru_stats.mu_ru_stats),
                    sta_stats->sta_mu_ru, sizeof(sta_stats->sta_mu_ru));

        payload = &peer_su_mu_ru_stats;
        payload_size = sizeof(wave_wssa_ofdma_su_mu_ru_stats_t);

      } else if (vendor_stats->category == OFDMA_CATEGORY_SU_MU) {
        su_mu_stats.addr = *(mtlk_sta_get_addr(sta));
        su_mu_stats.sta_sid = mtlk_sta_get_sid(sta);
        sta_stats = wave_sta_get_ofdma_su_mu_ru_stats(sta);

        sta_stats->pkt_err_su_percent      = WAVE_GET_PERCENTAGE(sta_stats->failed_su_ampdus, sta_stats->total_su_ampdus);
        sta_stats->pkt_err_mu_percent      = WAVE_GET_PERCENTAGE(sta_stats->failed_mu_ampdus, sta_stats->total_mu_ampdus);
        sta_stats->total_su_ampdus_percent = WAVE_GET_PERCENTAGE(sta_stats->total_su_ampdus, sta_stats->total_tx_ampdus);
        sta_stats->total_mu_ampdus_percent = WAVE_GET_PERCENTAGE(sta_stats->total_mu_ampdus, sta_stats->total_tx_ampdus);
        sta_stats->total_pkt_err_percent   = WAVE_GET_PERCENTAGE(sta_stats->total_fail_ampdus, sta_stats->total_tx_ampdus);

        su_mu_stats.su_pkt_err_percent = sta_stats->pkt_err_su_percent;
        su_mu_stats.mu_pkt_err_percent = sta_stats->pkt_err_mu_percent;
        su_mu_stats.total_su_pkts_percent = sta_stats->total_su_ampdus_percent;
        su_mu_stats.total_mu_pkts_percent = sta_stats->total_mu_ampdus_percent;
        su_mu_stats.success_su_pkts = sta_stats->success_su_ampdus;
        su_mu_stats.failed_su_pkts  = sta_stats->failed_su_ampdus;
        su_mu_stats.success_mu_pkts = sta_stats->success_mu_ampdus;
        su_mu_stats.failed_mu_pkts  = sta_stats->failed_mu_ampdus;
        su_mu_stats.total_tx_pkts   = sta_stats->total_tx_ampdus;
        su_mu_stats.total_fail_pkts = sta_stats->total_fail_ampdus;
        su_mu_stats.total_pkt_err_percent = sta_stats->total_pkt_err_percent;
        payload = &su_mu_stats;
        payload_size = sizeof(wave_wssa_ofdma_su_mu_stats_t);
      }
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, payload, payload_size);
  MTLK_CLPB_END;
}

uint __MTLK_IFUNC
wave_get_csi_bw_hw_map(uint8 bw_mode) {

  switch(bw_mode) {
    case CSI_BW_20:
      return 20;
    case CSI_BW_40:
      return 40;
    case CSI_BW_80:
      return 80;
    case CSI_BW_160:
      return 160;
	default:
      return 0;
  }
}

void __MTLK_IFUNC
wave_sta_get_csi_stats(mtlk_core_t *core, sta_entry* sta, wifi_csi_driver_data_t *csi_stats)
{
  uint8 index;
  MTLK_ASSERT(sta != NULL);
  MTLK_ASSERT(csi_stats != NULL);

  mtlk_osal_lock_acquire(&sta->lock);
  csi_stats->frame_info.bw_mode = sta->csi_stats.frame_info.bw_mode;
  csi_stats->frame_info.mcs = sta->csi_stats.frame_info.mcs;
  csi_stats->frame_info.Nr = sta->csi_stats.frame_info.Nr;
  csi_stats->frame_info.Nc = sta->csi_stats.frame_info.Nc;
  /* Ignore dummy values from src array */
  for (index = 0; index < MAX_NR_SIZE; index += 2) {
    csi_stats->frame_info.nr_rssi[index/2] = MAC_TO_HOST16(sta->csi_stats.frame_info.nr_rssi[index]);
  }
  csi_stats->frame_info.channel = (uint32) MAC_TO_HOST16(sta->csi_stats.frame_info.channel);
  csi_stats->frame_info.valid_mask = MAC_TO_HOST16(sta->csi_stats.frame_info.valid_mask);
  csi_stats->frame_info.phy_bw = (unsigned short) wave_get_csi_bw_hw_map(MAC_TO_HOST16(sta->csi_stats.frame_info.phy_bw));
  csi_stats->frame_info.cap_bw = (unsigned short) wave_get_csi_bw_hw_map(MAC_TO_HOST16(sta->csi_stats.frame_info.cap_bw));
  csi_stats->frame_info.num_sc = (uint32) MAC_TO_HOST16(sta->csi_stats.frame_info.num_sc);
  csi_stats->frame_info.decimation = sta->csi_stats.frame_info.decimation;
  wave_memcpy(&csi_stats->csi_raw_data, sizeof(sta->csi_stats.csi_raw_data), &sta->csi_stats.csi_raw_data, sizeof(sta->csi_stats.csi_raw_data));
  mtlk_osal_lock_release(&sta->lock);
}

mtlk_error_t __MTLK_IFUNC
wave_core_get_csi_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_error_t res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  wifi_csi_driver_data_t *csi_stats = NULL;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)
    csi_stats = mtlk_osal_mem_alloc(sizeof(wifi_csi_driver_data_t), MTLK_MEM_TAG_EXTENSION);
    if (NULL == csi_stats) {
      ELOG_V("Can't allocate memory for wifi_csi_data_t struct");
      MTLK_CLPB_EXIT(MTLK_ERR_NO_MEM);
    }
    memset(csi_stats, 0, sizeof(wifi_csi_driver_data_t));

    /* find station in stadb */
    sta = mtlk_vap_find_sta(core->vap_handle, addr->au8Addr);
    if (NULL == sta) {
      ELOG_DY("CID-%04x: station %Y not found", mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      /* Check if CSI is enabled */
      if(!(sta->csi_enable || sta->csi_auto_enable)) {
        ELOG_DY("CID-%04x: CSI not enabled for Sta %Y", mtlk_vap_get_oid(core->vap_handle), addr);
        MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
      } else {
        wave_sta_get_csi_stats(core, sta, csi_stats);
        sta->csi_sta_cntrs.csiReqInfoCount++;
      }
    }
  MTLK_CLPB_FINALLY(res)
    if (sta) mtlk_sta_decref(sta);
    res = mtlk_clpb_push_res_data_no_copy(clpb, res, csi_stats, sizeof(wifi_csi_driver_data_t));
    if (MTLK_ERR_OK != res && csi_stats != NULL) {
      mtlk_osal_mem_free(csi_stats);
    }
    return res;
  MTLK_CLPB_END;
}

mtlk_error_t __MTLK_IFUNC
wave_core_get_csi_counters (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_error_t res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  wave_csi_sta_stats64_cntr_t *csi_counters = NULL;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)
    csi_counters = mtlk_osal_mem_alloc(sizeof(wave_csi_sta_stats64_cntr_t), MTLK_MEM_TAG_EXTENSION);
    if (NULL == csi_counters) {
      ELOG_V("Can't allocate memory for wave_csi_sta_stats64_cntr_t struct");
      MTLK_CLPB_EXIT(MTLK_ERR_NO_MEM);
    }
    memset(csi_counters, 0, sizeof(wave_csi_sta_stats64_cntr_t));

    /* find station in stadb */
    sta = mtlk_vap_find_sta(core->vap_handle, addr->au8Addr);
    if (NULL == sta) {
      ELOG_DY("CID-%04x: station %Y not found", mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
	  /* Check if CSI is enabled */
      if(!(sta->csi_enable || sta->csi_auto_enable)) {
        ELOG_DY("CID-%04x: CSI not enabled for Sta %Y", mtlk_vap_get_oid(core->vap_handle), addr);
        MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
      } else {
        csi_counters->csiSendQosNullCount = sta->csi_sta_cntrs.csiSendQosNullCount;
        csi_counters->csiRecvFrameCount = sta->csi_sta_cntrs.csiRecvFrameCount;
        csi_counters->csiSendNlCsiData = sta->csi_sta_cntrs.csiSendNlCsiData;
        csi_counters->csiReqInfoCount = sta->csi_sta_cntrs.csiReqInfoCount;
      }
    }
  MTLK_CLPB_FINALLY(res)
    if (sta) mtlk_sta_decref(sta);
    res = mtlk_clpb_push_res_data_no_copy(clpb, res, csi_counters, sizeof(wave_csi_sta_stats64_cntr_t));
    if (MTLK_ERR_OK != res && csi_counters != NULL) {
      mtlk_osal_mem_free(csi_counters);
    }
    return res;
  MTLK_CLPB_END;
}

mtlk_error_t __MTLK_IFUNC
wave_core_send_csi_stats (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_error_t res = MTLK_ERR_OK;
  uint16 *sid = NULL;
  uint32 addr_size;
  sta_entry *sta = NULL;
  wifi_csi_driver_nl_event_data_t *csi_stats = NULL;
  mtlk_vap_handle_t vap_handle = core->vap_handle;
  mtlk_df_t *df                = mtlk_vap_get_df(vap_handle);
  mtlk_df_user_t *df_user      = mtlk_df_get_user(df);
  struct wireless_dev *wdev    = mtlk_df_user_get_wdev(df_user);

  MTLK_ASSERT(NULL != core);
  MTLK_ASSERT(NULL != df);
  MTLK_ASSERT(NULL != df_user);
  MTLK_ASSERT(NULL != wdev);
  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  sid = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(sid, addr_size)
    csi_stats = mtlk_osal_mem_alloc(sizeof(wifi_csi_driver_nl_event_data_t), MTLK_MEM_TAG_EXTENSION);
    if (NULL == csi_stats) {
      ELOG_V("Can't allocate memory for wifi_csi_data_t struct");
      MTLK_CLPB_EXIT(MTLK_ERR_NO_MEM);
    }
    memset(csi_stats, 0, sizeof(wifi_csi_driver_data_t));

    /* find station in stadb */
    sta = mtlk_stadb_find_sid (mtlk_core_get_stadb(core), *sid);
    if (NULL == sta) {
      ELOG_DD("CID-%04x: station with sid %d not found, Cant send CSI Stats through NL Event", mtlk_vap_get_oid(core->vap_handle), *sid);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
        csi_stats->sta_addr = *(mtlk_sta_get_addr(sta));
        wave_sta_get_csi_stats(core, sta, &csi_stats->csi_data);
        res = wave_nl_send_msg(LTQ_NL80211_VENDOR_EVENT_CSI_STATS, wdev, csi_stats, sizeof(wifi_csi_driver_nl_event_data_t));
        sta->csi_sta_cntrs.csiSendNlCsiData++;
    }
  MTLK_CLPB_FINALLY(res)
    if (sta) mtlk_sta_decref(sta);
    if (csi_stats) mtlk_osal_mem_free(csi_stats);
    return res;
  MTLK_CLPB_END;
}

#ifdef CONFIG_WAVE_DEBUG
int __MTLK_IFUNC
wave_core_get_peer_host_if_qos_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerHostIfQos_t peer_host_if_qos;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_host_if_qos_stats(sta, &peer_host_if_qos);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_host_if_qos, sizeof(peerHostIfQos_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_peer_host_if_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerHostIf_t peer_host_if;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_host_if_stats(sta, &peer_host_if);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_host_if, sizeof(peerHostIf_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_peer_rx_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerRxStats_t peer_rx_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_peer_rx_stats(sta, &peer_rx_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_rx_stats, sizeof(peerRxStats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_peer_ul_bsrc_tid_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerUlBsrcTidStats_t peer_ul_bsrc_tid;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_peer_ul_bsrc_tid_stats(sta, &peer_ul_bsrc_tid);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_ul_bsrc_tid, sizeof(peerUlBsrcTidStats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_peer_baa_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerBaaStats_t peer_baa_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_peer_baa_stats(sta, &peer_baa_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_baa_stats, sizeof(peerBaaStats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_link_adaption_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  linkAdaptionStats_t link_adaption_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_link_adaption_stats(sta, &link_adaption_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &link_adaption_stats, sizeof(linkAdaptionStats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_plan_manager_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  planManagerStats_t plan_manager_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_plan_manager_stats(sta, &plan_manager_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &plan_manager_stats, sizeof(planManagerStats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_peer_twt_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  twtStats_t twt_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_twt_stats(sta, &twt_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &twt_stats, sizeof(twtStats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_per_client_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  perClientStats_t per_client_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_per_client_stats(sta, &per_client_stats);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &per_client_stats, sizeof(perClientStats_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_peer_phy_rx_status (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerPhyRxStatus_t phy_rx_status;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_phy_rx_status(sta, &phy_rx_status);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &phy_rx_status, sizeof(peerPhyRxStatus_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_peer_info_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  IEEE_ADDR *addr;
  uint32 addr_size;
  sta_entry *sta = NULL;
  peerInfo_t peer_info;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  addr = mtlk_clpb_enum_get_next(clpb, &addr_size);
  MTLK_CLPB_TRY(addr, addr_size)

    /* find station in stadb */
    sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, addr->au8Addr);
    if (NULL == sta) {
      WLOG_DY("CID-%04x: station %Y not found",
        mtlk_vap_get_oid(core->vap_handle), addr);
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);
    } else {
      mtlk_sta_get_peer_info(sta, &peer_info);
      mtlk_sta_decref(sta);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, &peer_info, sizeof(peerInfo_t));
  MTLK_CLPB_END;
}

int __MTLK_IFUNC
wave_core_get_wlan_host_if_qos_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_wlan_host_if_qos_t wlan_host_if_qos;

  wave_core_get_wlan_host_if_qos_stats(core, &wlan_host_if_qos);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &wlan_host_if_qos, sizeof(mtlk_wssa_drv_wlan_host_if_qos_t));
}

int __MTLK_IFUNC
wave_core_get_wlan_host_if_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_wlan_host_if_t wlan_host_if;

  wave_core_get_wlan_host_if_stats(core, &wlan_host_if);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &wlan_host_if, sizeof(mtlk_wssa_drv_wlan_host_if_t));
}

int __MTLK_IFUNC
wave_core_get_wlan_rx_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_wlan_rx_stats_t wlan_rx_stats;

  wave_core_get_wlan_rx_stats(core, &wlan_rx_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &wlan_rx_stats, sizeof(mtlk_wssa_drv_wlan_rx_stats_t));
}

int __MTLK_IFUNC
wave_core_get_wlan_baa_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_wlan_baa_stats_t wlan_baa_stats;

  wave_core_get_wlan_baa_stats(core, &wlan_baa_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &wlan_baa_stats, sizeof(mtlk_wssa_drv_wlan_baa_stats_t));
}

int __MTLK_IFUNC
wave_core_get_radio_rx_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_radio_rx_stats_t radio_rx_stats;

  wave_core_get_radio_rx_stats(core, &radio_rx_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &radio_rx_stats, sizeof(mtlk_wssa_drv_radio_rx_stats_t));
}

int __MTLK_IFUNC
wave_core_get_radio_baa_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_radio_baa_stats_t radio_baa_stats;

  wave_core_get_radio_baa_stats(core, &radio_baa_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &radio_baa_stats, sizeof(mtlk_wssa_drv_radio_baa_stats_t));
}

int __MTLK_IFUNC
wave_core_get_tsman_init_tid_gl_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_tsman_init_tid_gl_t ts_init_tid_gl;

  wave_core_get_tsman_init_tid_gl_stats(core, &ts_init_tid_gl);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &ts_init_tid_gl, sizeof(mtlk_wssa_drv_tsman_init_tid_gl_t));
}

int __MTLK_IFUNC
wave_core_get_tsman_init_sta_gl_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_tsman_init_sta_gl_t ts_init_sta_gl;

  wave_core_get_tsman_init_sta_gl_stats(core, &ts_init_sta_gl);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &ts_init_sta_gl, sizeof(mtlk_wssa_drv_tsman_init_sta_gl_t));
}

int __MTLK_IFUNC
wave_core_get_tsman_rcpt_tid_gl_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_tsman_rcpt_tid_gl_t ts_rcpt_tid_gl;

  wave_core_get_tsman_rcpt_tid_gl_stats(core, &ts_rcpt_tid_gl);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &ts_rcpt_tid_gl, sizeof(mtlk_wssa_drv_tsman_rcpt_tid_gl_t));
}

int __MTLK_IFUNC
wave_core_get_tsman_rcpt_sta_gl_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_tsman_rcpt_sta_gl_t ts_rcpt_sta_gl;

  wave_core_get_tsman_rcpt_sta_gl_stats(core, &ts_rcpt_sta_gl);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &ts_rcpt_sta_gl, sizeof(mtlk_wssa_drv_tsman_rcpt_sta_gl_t));
}

int __MTLK_IFUNC
wave_core_get_radio_link_adapt_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_radio_link_adapt_stats_t link_adapt_stats;

  wave_core_get_radio_link_adapt_stats(core, &link_adapt_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &link_adapt_stats, sizeof(mtlk_wssa_drv_radio_link_adapt_stats_t));
}

int __MTLK_IFUNC
wave_core_get_multicast_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_multicast_stats_t mc_stats;

  wave_core_get_multicast_stats(core, &mc_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &mc_stats, sizeof(mtlk_wssa_drv_multicast_stats_t));
}

int __MTLK_IFUNC
wave_core_get_training_man_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_training_man_stats_t tr_man_stats;

  wave_core_get_training_man_stats(core, &tr_man_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &tr_man_stats, sizeof(mtlk_wssa_drv_training_man_stats_t));
}

int __MTLK_IFUNC
wave_core_get_grp_man_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_group_man_stats_t gr_man_stats;

  wave_core_get_grp_man_stats(core, &gr_man_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &gr_man_stats, sizeof(mtlk_wssa_drv_group_man_stats_t));
}

int __MTLK_IFUNC
wave_core_get_general_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_general_stats_t gen_stats;

  wave_core_get_general_stats(core, &gen_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &gen_stats, sizeof(mtlk_wssa_drv_general_stats_t));
}

int __MTLK_IFUNC
wave_core_get_cur_channel_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_cur_channel_stats_t channel_stats;

  wave_core_get_cur_channel_stats(core, &channel_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &channel_stats, sizeof(mtlk_wssa_drv_cur_channel_stats_t));
}

int __MTLK_IFUNC
wave_core_get_radio_phy_rx_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_radio_phy_rx_stats_t phy_rx_stats;

  wave_core_get_radio_phy_rx_stats(core, &phy_rx_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &phy_rx_stats, sizeof(mtlk_wssa_drv_radio_phy_rx_stats_t));
}

int __MTLK_IFUNC
wave_core_get_dynamic_bw_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  //wave_radio_t  *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_wssa_drv_dynamic_bw_stats_t dy_bw_stats;

  wave_core_get_dynamic_bw_stats(core, &dy_bw_stats);

  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &dy_bw_stats, sizeof(mtlk_wssa_drv_dynamic_bw_stats_t));
}

int __MTLK_IFUNC
wave_core_get_link_adapt_mu_statistics (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  uint8 *mu;
  uint32 mu_size;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_wssa_drv_radio_link_adapt_mu_stats_t link_adapt_stats;
  int res= MTLK_ERR_OK;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  mu = mtlk_clpb_enum_get_next(clpb, &mu_size);
  MTLK_CLPB_TRY(mu, mu_size)
  wave_core_get_radio_link_adapt_mu_stats (core, &link_adapt_stats, mu);
  MTLK_CLPB_FINALLY(res)
  return mtlk_clpb_push_res_data(clpb, res, &link_adapt_stats, sizeof(mtlk_wssa_drv_radio_link_adapt_mu_stats_t));
  MTLK_CLPB_END;
}

#endif /* CONFIG_WAVE_DEBUG */

enum _wave_fixed_ltf_and_gi_e
{
  SHORT_GI_SHORT_LTF,   /* 0 - HT/VHT: 0.4us GI; HE: 0.8us GI, 1x LTF */
  MEDIUM_GI_SHORT_LTF,  /* 1 - HT/VHT: 0.8us GI; HE: 1.6us GI, 1x LTF */
  SHORT_GI_MED_LTF,     /* 2 - HT/VHT: invalid;  HE: 0.8us GI, 2x LTF */
  MEDIUM_GI_MEDIUM_LTF, /* 3 - HT/VHT: invalid;  HE: 1.6us GI, 2x LTF */
  SHORT_GI_LONG_LTF,    /* 4 - HT/VHT: invalid;  HE: 0.8us GI, 4x LTF */
  LONG_GI_LONG_LTF,     /* 5 - HT/VHT: invalid;  HE: 3.2us GI, 4x LTF */
};

static uint32 _wave_update_ht_and_vht_gi_if_fixed (UMI_FIXED_LTF_AND_GI_REQ *ltf_and_gi, uint32 curr_gi)
{
  if (ltf_and_gi->isAuto)
    return curr_gi;

  if (ltf_and_gi->ltfAndGi == SHORT_GI_SHORT_LTF)
    return 1; /* Short 0.4us GI supported */
  if (ltf_and_gi->ltfAndGi == MEDIUM_GI_SHORT_LTF)
    return 0; /* Short 0.4us GI not supported */

  return curr_gi;
}

void __MTLK_IFUNC
mtlk_core_find_max_sta_rate (struct nic *nic, sta_entry *sta, struct ieee80211_sta *mac80211_sta)
{
  uint32 max_nss = 0;
  uint32 max_rate = 0;
  uint32 rate_1ss = 0; /* per one stream */
  uint32 ht_bw = IEEE80211_STA_RX_BW_20;
  uint32 ht_scp = 0;
  uint8  max_supp_mcs = 0;
  uint8  sgi_enable = 0;
  uint8  max_supp_bw = IEEE80211_STA_RX_BW_20;
  struct mtlk_chan_def *cd;
  mtlk_core_t *mcore;
  uint32 width;
  size_t i;
  UMI_FIXED_LTF_AND_GI_REQ gi_and_ltf;

  MTLK_ASSERT(NULL != sta);
  MTLK_ASSERT(NULL != mac80211_sta);
  MTLK_ASSERT(NULL != nic);

  mcore = mtlk_core_get_master(nic);
  MTLK_ASSERT(NULL != mcore);

  memset(&gi_and_ltf, 0, sizeof(gi_and_ltf));
  mtlk_core_cfg_get_fixed_ltf_and_gi(mcore, &gi_and_ltf);
  cd = __wave_core_chandef_get(mcore);
  width = cd->width;
  ILOG1_D("current radio BW:%d", width);

  /* Get max non-HT rate */
  if (!MTLK_BFIELD_GET(sta->info.flags, STA_FLAGS_11n)) {
    unsigned  supp_rate = 0;
    for (i = 0; i < sta->info.supported_rates_len; i++) {
      supp_rate = MAX(supp_rate, sta->info.rates[i]);
    }
    max_nss = 1;
    max_rate = MTLK_SUPP_RATE_TO_BITRATE(supp_rate);
    rate_1ss = max_rate;
    ILOG1_DD("STA non-HT supported rate:%u max_phy_rate:%u", supp_rate, max_rate);
  }

  /* Get max HT rate */
  if (MTLK_BFIELD_GET(sta->info.flags, STA_FLAGS_11n)) {
    int i,y;
    uint32 ht_nss = 0;
    uint32 ht_mcs = 0;
    uint16 ht_cap;
    uint32 ht_max_phy_rate = 0;
    uint32 ht_1ss_phy_rate = 0;

    /* TBD: BITRATE_MCS32 for BPSK */

    for (i = 3; i >= 0; i--) { /* we support max 4 nss */
      uint8 rx_mask = mac80211_sta->ht_cap.mcs.rx_mask[i];
      if (rx_mask) {
        ht_nss = i + 1;
        for (y = 7; y >= 0; y--) {
          if (MTLK_BIT_GET(rx_mask, y) != 0) {
            ht_mcs = y + i*8;
            break;
          }
        }
        break;
      }
    }

    ht_cap = mac80211_sta->ht_cap.cap;
    if ((ht_cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40) &&
          !(ht_cap & IEEE80211_HT_CAP_40MHZ_INTOLERANT)) {
      ht_bw = IEEE80211_STA_RX_BW_40;
      if (ht_cap & IEEE80211_HT_CAP_SGI_40)
        ht_scp = 1;
    } else {
      ht_bw = 0;
      if (ht_cap & IEEE80211_HT_CAP_SGI_20)
        ht_scp = 1;
    }

    ht_scp = _wave_update_ht_and_vht_gi_if_fixed(&gi_and_ltf, ht_scp);

    ht_bw = min(width, ht_bw);
    ht_1ss_phy_rate = mtlk_bitrate_hw_params_to_rate(PHY_MODE_N, ht_bw, ht_scp,
        (ht_mcs == BITRATE_MCS32) ? BITRATE_MCS32 : (ht_mcs & 7), 1);
    ht_max_phy_rate = mtlk_bitrate_hw_params_to_rate(PHY_MODE_N, ht_bw, ht_scp, ht_mcs, ht_nss);
    if (max_rate < ht_max_phy_rate) {
      max_nss  = ht_nss;
      max_rate = ht_max_phy_rate;
      rate_1ss = ht_1ss_phy_rate;
    }
    ILOG1_DDDDDD("STA HT IE max_mcs:%u nss:%u bw:%u scp:%u phy_rate (1ss/max):(%u/%u)",
                 ht_mcs, ht_nss, ht_bw, ht_scp, ht_1ss_phy_rate, ht_max_phy_rate);
    max_supp_mcs = ht_mcs;
    max_supp_bw = ht_bw;
    sgi_enable = ht_scp;
  }

  /* Get max VHT rate */
  if (MTLK_BFIELD_GET(sta->info.flags, STA_FLAGS_11ac)) {
    uint32 vht_nss = 0;
    uint32 vht_mcs = 0;
    uint16 vht_tx_mcs_map = 0;
    uint32 vht_max_phy_rate = 0;
    uint32 vht_1ss_phy_rate = 0;

    vht_tx_mcs_map = WLAN_TO_HOST16(mac80211_sta->vht_cap.vht_mcs.rx_mcs_map);
    for (vht_nss = 8; vht_nss > 0; vht_nss--) {
      vht_mcs = ((vht_tx_mcs_map >> (2 * (vht_nss - 1))) & 3);
      if (vht_mcs != IEEE80211_VHT_MCS_NOT_SUPPORTED)
        break;
    }

    if (vht_mcs != IEEE80211_VHT_MCS_NOT_SUPPORTED) {
      uint32 vht_cap;
      uint32 vht_bw;
      uint32 vht_scp = 0;
      uint32 mcs_1ss, mcs_max;

      vht_mcs = 7 + vht_mcs;
      vht_cap = mac80211_sta->vht_cap.cap;

      if (MTLK_HW_BAND_2_4_GHZ == core_cfg_get_freq_band_cur(nic)) {
        vht_bw = ht_bw;
        vht_scp = ht_scp;
      } else {
        switch (vht_cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_MASK) {
        case IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ:
          vht_bw = IEEE80211_STA_RX_BW_160;
          if (vht_cap & IEEE80211_VHT_CAP_SHORT_GI_160)
            vht_scp = 1;
          break;
        default:
          vht_bw = IEEE80211_STA_RX_BW_80;
          if (vht_cap & IEEE80211_VHT_CAP_SHORT_GI_80)
            vht_scp = 1;
        }
      }

      vht_scp = _wave_update_ht_and_vht_gi_if_fixed(&gi_and_ltf, vht_scp);

      vht_bw = min(width, vht_bw);
      /* Look for max MCS supported for both 1 and max SS */
      for (mcs_1ss = vht_mcs; mcs_1ss >= 7; mcs_1ss--) {
        if (mtlk_bitrate_hw_params_supported_rate(&vht_1ss_phy_rate, PHY_MODE_AC, vht_bw, vht_scp, mcs_1ss, 1))
          break;
      }
      for (mcs_max = vht_mcs; mcs_max >= 7; mcs_max--) {
        if (mtlk_bitrate_hw_params_supported_rate(&vht_max_phy_rate, PHY_MODE_AC, vht_bw, vht_scp, mcs_max, vht_nss))
          break;
      }
      if (rate_1ss < vht_1ss_phy_rate) {
        rate_1ss = vht_1ss_phy_rate;
      }
      if (max_rate < vht_max_phy_rate) {
        max_nss  = vht_nss;
        max_rate = vht_max_phy_rate;
      }
      max_supp_mcs = vht_mcs;
      max_supp_bw = vht_bw;
      sgi_enable = vht_scp;
      ILOG1_DDDDDD("STA VHT IE max_mcs:%u nss:%u bw:%u scp:%u phy_rate (1ss/max):(%u/%u)",
                   vht_mcs, vht_nss, vht_bw, vht_scp, vht_1ss_phy_rate, vht_max_phy_rate);
    } else {
      ELOG_V("VHT MCS is not found");
    }
  }

  /* Get max HE rate */
  if (MTLK_BFIELD_GET(sta->info.flags, STA_FLAGS_11ax)) {
    uint32 he_nss = 0;
    uint32 he_mcs = 0;
    uint16 he_tx_mcs_map = 0;
    uint8  *he_phy_cap_info;
    uint32 he_max_phy_rate = 0;
    uint32 he_1ss_phy_rate = 0;
    uint32 he_bw= IEEE80211_STA_RX_BW_20;
    uint32 he_scp = 0;

    he_phy_cap_info = mac80211_sta->he_cap.he_cap_elem.phy_cap_info;

    if (!gi_and_ltf.isAuto)
      he_scp = gi_and_ltf.ltfAndGi;

    /* Process BW */
    if (MTLK_HW_BAND_2_4_GHZ == core_cfg_get_freq_band_cur(nic)) {
      if (he_phy_cap_info[0] &  IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_40MHZ_IN_2G)
       he_bw = IEEE80211_STA_RX_BW_40;
      else
       he_bw = IEEE80211_STA_RX_BW_20;
      } else {
      if (he_phy_cap_info[0] &  HE_5G_6G_PHY_CAP0_CHAN_WIDTH_SET_40MHZ_80MHZ)
        he_bw = IEEE80211_STA_RX_BW_80;
      else
        he_bw = IEEE80211_STA_RX_BW_20;
    }

    /* Process <= 80 MHz BW */
    he_tx_mcs_map = WLAN_TO_HOST16(mac80211_sta->he_cap.he_mcs_nss_supp.rx_mcs_80);
    for (he_nss = 8; he_nss > 0; he_nss--) {
      he_mcs = ((he_tx_mcs_map >> (2 * (he_nss - 1))) & 3);
       if (he_mcs != IEEE80211_HE_MCS_NOT_SUPPORTED)
         break;
     }

    if (he_mcs != IEEE80211_HE_MCS_NOT_SUPPORTED) {

      he_mcs = 7 + he_mcs * 2;
      he_bw = min(width, he_bw);
      he_1ss_phy_rate = mtlk_bitrate_hw_params_to_rate(PHY_MODE_AX, he_bw, he_scp, he_mcs, 1);
      he_max_phy_rate = mtlk_bitrate_hw_params_to_rate(PHY_MODE_AX, he_bw, he_scp, he_mcs, he_nss);
      if (max_rate < he_max_phy_rate) {
        max_nss  = he_nss;
        max_rate = he_max_phy_rate;
        rate_1ss = he_1ss_phy_rate;
      }
      ILOG1_DDDDDD("STA HE <= 80MHz IE max_mcs:%u nss:%u bw:%d scp:%u phy_rate (1ss/max):(%u/%u)",
                   he_mcs, he_nss, he_bw, he_scp, he_1ss_phy_rate, he_max_phy_rate);
    } else {
      ELOG_V("HE MCS is not found");
    }

    if (width == IEEE80211_STA_RX_BW_160) {
      /* Process 160 MHz BW */
      if ((MTLK_HW_BAND_5_2_GHZ == core_cfg_get_freq_band_cur(nic) || MTLK_HW_BAND_6_GHZ == core_cfg_get_freq_band_cur(nic)) &&
        (he_phy_cap_info[0] &  HE_5G_6G_PHY_CAP0_CHAN_WIDTH_SET_160MHZ)) {

        he_bw  = width;
        he_mcs = 0;
        he_nss = 0;

        he_tx_mcs_map = WLAN_TO_HOST16(mac80211_sta->he_cap.he_mcs_nss_supp.rx_mcs_160);
        for (he_nss = 8; he_nss > 0; he_nss--) {
          he_mcs = ((he_tx_mcs_map >> (2 * (he_nss - 1))) & 3);
          if (he_mcs != IEEE80211_HE_MCS_NOT_SUPPORTED)
            break;
        }

        if (he_mcs != IEEE80211_HE_MCS_NOT_SUPPORTED) {
          he_mcs = 7 + he_mcs * 2;
          he_1ss_phy_rate = mtlk_bitrate_hw_params_to_rate(PHY_MODE_AX, he_bw, he_scp, he_mcs, 1);
          he_max_phy_rate = mtlk_bitrate_hw_params_to_rate(PHY_MODE_AX, he_bw, he_scp, he_mcs, he_nss);
          if (max_rate < he_max_phy_rate) {
            max_nss  = he_nss;
            max_rate = he_max_phy_rate;
            rate_1ss = he_1ss_phy_rate;
          }
          ILOG1_DDDDDD("STA HE 160 MHz IE max_mcs:%u nss:%u bw:%u scp:%u phy_rate (1ss/max):(%u/%u)",
                       he_mcs, he_nss, he_bw, he_scp, he_1ss_phy_rate, he_max_phy_rate);
        } else {
          ELOG_V("HE MCS is not found");
        }
      }
    }
    max_supp_mcs = he_mcs;
    max_supp_bw = he_bw;
    sgi_enable = he_scp;
  }

  mtlk_sta_set_bitrate_1ss(sta, rate_1ss);
  mtlk_sta_set_bitrate_max(sta, max_rate);
  mtlk_sta_set_max_antennas(sta, max_nss);
  mtlk_sta_set_max_mcs(sta, max_supp_mcs);
  mtlk_sta_set_max_bw(sta, max_supp_bw);
  mtlk_sta_set_short_gi(sta, sgi_enable);
  ILOG1_DDD("STA max_antennas:%u phy_rate (1ss/max):(%u/%u)", max_nss, rate_1ss, max_rate);
}
