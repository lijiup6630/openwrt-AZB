/******************************************************************************

                               Copyright (c) 2021
                              MaxLinear Technologies

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
#include "SecureBoot_definitions.h"
#ifdef MTLK_WAVE_700
#define LOG_LOCAL_GID   GID_CCR_PCIE
#define LOG_LOCAL_FID   9

typedef enum {
  LMAC_G7_CPU_NUM0,
  LMAC_G7_CPU_NUM1,
  LMAC_G7_CPU_NUM2,
  LMAC_G7_CPU_NUM_TOTAL
} e_lmac_cpu_num;

/*--------- Table of FW dump files ---------------*/
/* All IO base addresses are offsets from BAR0
 * Required order in the table:
 *    Common files for both radios
 *    (B0) Radio 0 specific
 *    (B1) Radio 1 specific
*/

enum g7_proc_fw_dump_idx { /* index in array */
  /* Common files for both radios */
  FW_IDX_CMN_FIRST = 0,
  FW_IDX_IRAM      = FW_IDX_CMN_FIRST,
  FW_IDX_SHRAM,
  FW_IDX_IF_COUNTERS,
  FW_IDX_IF_UC_INT,
  FW_IDX_IF_UC_CLUS,
  FW_IDX_IF_SCP,
  FW_IDX_DESC_RAM_A,
  FW_IDX_DESC_RAM_B,
  FW_IDX_DLM,
  FW_IDX_DLM_M2,
  FW_IDX_DMA_LL,
  FW_IDX_DMA_LL_M2,
  FW_IDX_RX_PP_RAM,
  FW_IDX_RX_PP_M2_RAM,
  FW_IDX_TRA_IND,
  FW_IDX_CMN_LAST,

  /* (B0) Radio 0 specific */
  FW_IDX_B0_FIRST  = FW_IDX_CMN_LAST,
  FW_IDX_B0_TX_RAM = FW_IDX_B0_FIRST,
  FW_IDX_B0_TX_REG,
  FW_IDX_B0_TX_SCP,
  FW_IDX_B0_TX_SEL,
  FW_IDX_B0_TX_STD,
  FW_IDX_B0_RX_RAM,
  FW_IDX_B0_RX_REG,
  FW_IDX_B0_RX_SCP,
  FW_IDX_B0_AUTO_RESP,
  FW_IDX_B0_TEST_BUS,
  FW_IDX_B0_PHY_RX_TD_REG096,
  FW_IDX_B0_LAST,

  /* (B1) Radio 1 specific */
  FW_IDX_B1_FIRST  = FW_IDX_B0_LAST,
  FW_IDX_B1_TX_RAM = FW_IDX_B1_FIRST,
  FW_IDX_B1_TX_REG,
  FW_IDX_B1_TX_SCP,
  FW_IDX_B1_TX_SEL,
  FW_IDX_B1_TX_STD,
  FW_IDX_B1_RX_RAM,
  FW_IDX_B1_RX_REG,
  FW_IDX_B1_RX_SCP,
  FW_IDX_B1_AUTO_RESP,
  FW_IDX_B1_TEST_BUS,
  FW_IDX_B1_PHY_RX_TD_REG096,
  FW_IDX_B1_LAST,
  /* Total number */
  FW_IDX_TOTAL = FW_IDX_B1_LAST
};

/*--- MACs and GenRiscs: offsets from bar0 and sizes ---*/
#define WAVE_PCIE_IFCPU_IRAM_START    (MAC_HOSTIF_UC_INTERNAL_OFFSET_FROM_BAR0)
#define WAVE_PCIE_IFCPU_IRAM_SIZE     (MAC_HOSTIF_UC_INTERNAL_SIZE)

#define MAC_GENRISC_REG_DUMP_SIZE           (0x100)
#define BX_MAC_GENRISC_REG_DUMP_SIZE        MAC_GENRISC_REG_DUMP_SIZE
/* Special defines for "test_bus_b0" */
#define TEST_BUS_SINGLE_BAND_SIZE           (B0_PHY_TEST_BUS_OR_DUMMY_PHY_SIZE)          /* Single band - full size */
#define TEST_BUS_DUAL_BAND_SIZE             ((B0_PHY_TEST_BUS_OR_DUMMY_PHY_SIZE) / 2)    /* Dual band   - half size */

static wave_fw_dump_info_t  g7_proc_fw_dump_files[FW_IDX_TOTAL] = {
  /* Common files for both radios */
  [ FW_IDX_IRAM         ] = { "iram",                PROC_FW_IO,  CPU_IRAM_OFFSET_FROM_BAR0,                CPU_IRAM_SIZE                },
  [ FW_IDX_SHRAM        ] = { "shram",               PROC_FW_IO,  SHARED_RAM_OFFSET_FROM_BAR0,              SHARED_RAM_SIZE              },
  [ FW_IDX_IF_COUNTERS  ] = { "host_if_counters",    PROC_FW_IO,  HOST_IF_COUNTERS_OFFSET_FROM_BAR0,        HOST_IF_COUNTERS_SIZE        },
  [ FW_IDX_IF_UC_INT    ] = { "host_if_uc_internal", PROC_FW_IO,  MAC_HOSTIF_UC_INTERNAL_OFFSET_FROM_BAR0,  MAC_HOSTIF_UC_INTERNAL_SIZE  },
  [ FW_IDX_IF_UC_CLUS   ] = { "host_if_uc_cluster",  PROC_FW_IO,  MAC_HOSTIF_UC_CLUSTER_OFFSET_FROM_BAR0,   MAC_HOSTIF_UC_CLUSTER_SIZE   },
  [ FW_IDX_DESC_RAM_A   ] = { "descriptor_ram_a",    PROC_FW_IO,  DESCRIPTOR_RAM_A_OFFSET_FROM_BAR0,        DESCRIPTOR_RAM_A_SIZE        },
  [ FW_IDX_DESC_RAM_B   ] = { "descriptor_ram_b",    PROC_FW_IO,  DESCRIPTOR_RAM_B_OFFSET_FROM_BAR0,        DESCRIPTOR_RAM_B_SIZE        },
  [ FW_IDX_DLM          ] = { "dlm",                 PROC_FW_IO,  DLM_OFFSET_FROM_BAR0,                     DLM_SIZE                     },
  [ FW_IDX_DLM_M2       ] = { "dlm_m2",              PROC_FW_IO,  DLM_M2_OFFSET_FROM_BAR0,                  DLM_M2_SIZE                  },
  [ FW_IDX_DMA_LL       ] = { "dma_linked_list",     PROC_FW_IO,  WLAN_DMA_LL_MEM_OFFSET_FROM_BAR0,         WLAN_DMA_LL_MEM_SIZE         },
  [ FW_IDX_DMA_LL_M2    ] = { "dma_linked_list_m2",  PROC_FW_IO,  WLAN_DMA_LL_MEM_M2_OFFSET_FROM_BAR0,      WLAN_DMA_LL_MEM_M2_SIZE      },
  [ FW_IDX_RX_PP_RAM    ] = { "rxpp_ram",            PROC_FW_IO,  RX_PP_OFFSET_FROM_BAR0,                   RX_PP_SIZE                   },
  [ FW_IDX_RX_PP_M2_RAM ] = { "rxpp_ram_m2",         PROC_FW_IO,  RX_PP_M2_OFFSET_FROM_BAR0,                RX_PP_M2_SIZE                },
  [ FW_IDX_TRA_IND      ] = { "traffic_ind",         PROC_FW_IO,  TRAFFIC_INDICATOR_OFFSET_FROM_BAR0,       TRAFFIC_INDICATOR_SIZE       },
  /* (B0) Radio 0 specific */
  [ FW_IDX_B0_TX_SEL    ] = { "tx_selector_b0",      PROC_FW_IO,  B0_TX_SELECTOR_OFFSET_FROM_BAR0,          B0_TX_SELECTOR_SIZE          },
  [ FW_IDX_B0_TX_RAM    ] = { "tx_sender_ram_b0",    PROC_FW_IO,  B0_MAC_GENRISC_TX_IRAM_OFFSET_FROM_BAR0,  B0_MAC_GENRISC_TX_IRAM_SIZE  },
  [ FW_IDX_B0_TX_REG    ] = { "tx_sender_reg_b0",    PROC_FW_IO,  B0_MAC_GENRISC_TX_REG_OFFSET_FROM_BAR0,   BX_MAC_GENRISC_REG_DUMP_SIZE }, /* B0_MAC_GENRISC_TX_REG_SIZE */
  [ FW_IDX_B0_TX_SCP    ] = { "tx_sender_scpad_b0",  PROC_FW_IO,  B0_MAC_GENRISC_TX_SPRAM_OFFSET_FROM_BAR0, B0_MAC_GENRISC_TX_SPRAM_SIZE },
  [ FW_IDX_B0_TX_STD    ] = { "tx_sender_std_b0",    PROC_FW_IO,  B0_MAC_GENRISC_TX_STD_OFFSET_FROM_BAR0,   B0_MAC_GENRISC_TX_STD_SIZE   },
  [ FW_IDX_B0_RX_RAM    ] = { "rx_handler_ram_b0",   PROC_FW_IO,  B0_MAC_GENRISC_RX_IRAM_OFFSET_FROM_BAR0,  B0_MAC_GENRISC_RX_IRAM_SIZE  },
  [ FW_IDX_B0_RX_REG    ] = { "rx_handler_reg_b0",   PROC_FW_IO,  B0_MAC_GENRISC_RX_REG_OFFSET_FROM_BAR0,   BX_MAC_GENRISC_REG_DUMP_SIZE }, /* B0_MAC_GENRISC_RX_REG_SIZE */
  [ FW_IDX_B0_RX_SCP    ] = { "rx_handler_scpad_b0", PROC_FW_IO,  B0_MAC_GENRISC_RX_SPRAM_OFFSET_FROM_BAR0, B0_MAC_GENRISC_RX_SPRAM_SIZE },
  [ FW_IDX_B0_AUTO_RESP ] = { "auto_resp_ram_b0",    PROC_FW_IO,  B0_AUTO_RESP_MEMS_OFFSET_FROM_BAR0,       B0_AUTO_RESP_MEMS_SIZE       },
  [ FW_IDX_B0_TEST_BUS  ] = { "test_bus_b0",         PROC_FW_IO,  B0_PHY_TEST_BUS_OR_DUMMY_PHY_OFFSET_FROM_BAR0, B0_PHY_TEST_BUS_OR_DUMMY_PHY_SIZE },
  [ FW_IDX_B0_PHY_RX_TD_REG096 ] =
                               { "phy_rx_td_reg096_b0", PROC_FW_IO,  B0_PHY_RX_TD_PHY_RXTD_REG096,             (sizeof(uint32) * 1)         },
  /* (B1) Radio 1 specific */
  [ FW_IDX_B1_TX_SEL    ] = { "tx_selector_b1",      PROC_FW_IO,  B1_TX_SELECTOR_OFFSET_FROM_BAR0,          B1_TX_SELECTOR_SIZE          },
  [ FW_IDX_B1_TX_RAM    ] = { "tx_sender_ram_b1",    PROC_FW_IO,  B1_MAC_GENRISC_TX_IRAM_OFFSET_FROM_BAR0,  B1_MAC_GENRISC_TX_IRAM_SIZE  },
  [ FW_IDX_B1_TX_REG    ] = { "tx_sender_reg_b1",    PROC_FW_IO,  B1_MAC_GENRISC_TX_REG_OFFSET_FROM_BAR0,   BX_MAC_GENRISC_REG_DUMP_SIZE }, /* B1_MAC_GENRISC_TX_REG_SIZE */
  [ FW_IDX_B1_TX_SCP    ] = { "tx_sender_scpad_b1",  PROC_FW_IO,  B1_MAC_GENRISC_TX_SPRAM_OFFSET_FROM_BAR0, B1_MAC_GENRISC_TX_SPRAM_SIZE },
  [ FW_IDX_B1_TX_STD    ] = { "tx_sender_std_b1",    PROC_FW_IO,  B1_MAC_GENRISC_TX_STD_OFFSET_FROM_BAR0,   B1_MAC_GENRISC_TX_STD_SIZE   },
  [ FW_IDX_B1_RX_RAM    ] = { "rx_handler_ram_b1",   PROC_FW_IO,  B1_MAC_GENRISC_RX_IRAM_OFFSET_FROM_BAR0,  B1_MAC_GENRISC_RX_IRAM_SIZE  },
  [ FW_IDX_B1_RX_REG    ] = { "rx_handler_reg_b1",   PROC_FW_IO,  B1_MAC_GENRISC_RX_REG_OFFSET_FROM_BAR0,   BX_MAC_GENRISC_REG_DUMP_SIZE }, /* B1_MAC_GENRISC_RX_REG_SIZE */
  [ FW_IDX_B1_RX_SCP    ] = { "rx_handler_scpad_b1", PROC_FW_IO,  B1_MAC_GENRISC_RX_SPRAM_OFFSET_FROM_BAR0, B1_MAC_GENRISC_RX_SPRAM_SIZE },
  [ FW_IDX_B1_AUTO_RESP ] = { "auto_resp_ram_b1",    PROC_FW_IO,  B1_AUTO_RESP_MEMS_OFFSET_FROM_BAR0,       B1_AUTO_RESP_MEMS_SIZE       },
  [ FW_IDX_B1_TEST_BUS  ] = { "test_bus_b1",         PROC_FW_IO,  B1_PHY_TEST_BUS_OR_DUMMY_PHY_OFFSET_FROM_BAR0, B1_PHY_TEST_BUS_OR_DUMMY_PHY_SIZE      },
  [ FW_IDX_B1_PHY_RX_TD_REG096 ] =
                               { "phy_rx_td_reg096_b1", PROC_FW_IO,  B1_PHY_RX_TD_PHY_RXTD_REG096,             (sizeof(uint32) * 1)         },

};

/* Secure Boot: FW binary images loading address and sizes */

/* Table with sizes of FW binary images.
   Only exactly defined sizes are filled in.
   Unfilled items suppose actual size of FW.
 */
static const uint32 _wave_fw_size[WAVE_FW_NUM_CNT] =
{
  [WAVE_FW_NUM_UM]            = WAVE_PCIE_URAM_IRAM_SIZE,                       /* Unified RAM */
  [WAVE_FW_NUM_SECB_FC]       = SECURE_BOOT_FW_CERTIFICATE_SIZE_WAVE700,        /* FW certificate */
  [WAVE_FW_NUM_SECB_DC]       = SECURE_BOOT_DUT_CERTIFICATE_SIZE_WAVE700,       /* DUT certificate */
  [WAVE_FW_NUM_SECB_FW_HDR]   = SECURE_BOOT_FW_HEADER_SIZE_WAVE700,             /* Signed FW header */
  [WAVE_FW_NUM_SECB_PSD_HDR]  = SECURE_BOOT_PSD_HEADER_SIZE_WAVE700,            /* Signed PSD header */
  [WAVE_FW_NUM_SECB_CAL_HDR]  = SECURE_BOOT_CAL_FILE_HEADER_SIZE_WAVE700,       /* Signed Cal file header */
  [WAVE_FW_NUM_TX]            = SECURE_BOOT_TX_SENDER_GENRISC_FIRST_IMAGE_SIZE, /* Tx Sender CPUs */
  [WAVE_FW_NUM_RX]            = SECURE_BOOT_RX_HANDLER_GENRISC_SIZE,            /* Rx Handler CPUs */
  [WAVE_FW_NUM_IF]            = SECURE_BOOT_HOST_IF_IRAM_SIZE_WAVE700,                /* Host Interface CPUs */
};

/*--------------------------------------------------------------*/
static int
_mtlk_pcie_ccr_get_sec_boot_fw_info (void *ccr_mem, wave_fw_num_e fw_num, mtlk_fw_info_t *fw_info)
{
  mtlk_pcie_ccr_t *pcie_mem = (mtlk_pcie_ccr_t *)ccr_mem;
  MTLK_ASSERT(ARRAY_SIZE(fw_info->mem) >= 3);

  /* Default memory chunks values for any FW bin */
  fw_info->mem[0].start   = 0;
  fw_info->mem[0].length  = 0;
  fw_info->mem[0].swap    = FALSE;
  fw_info->mem[1].start   = 0;
  fw_info->mem[1].length  = 0;
  fw_info->mem[1].swap    = FALSE;
  fw_info->mem[2].start   = 0;
  fw_info->mem[2].length  = 0;
  fw_info->mem[2].swap    = FALSE;

  /* FW specific */
  switch (fw_num)
  {
    /* Fixed loading address */
    case WAVE_FW_NUM_UM: /* URAM */
      fw_info->mem[0].start   = ((unsigned char*)pcie_mem->pas) + WAVE_PCIE_URAM_IRAM_START;
      break;
    case WAVE_FW_NUM_SECB_FC: /* FW certificate */
      fw_info->mem[0].start   = ((unsigned char*)pcie_mem->pas) + SECURE_BOOT_FW_CERTIFICATE_ADDRESS_WAVE700;
      break;

    /* All below have variable loading address */
    case WAVE_FW_NUM_SECB_DC:       /* DUT certificate */
    case WAVE_FW_NUM_SECB_FW_HDR:   /* FW header */
    case WAVE_FW_NUM_SECB_PSD_HDR:  /* PSD header */
    case WAVE_FW_NUM_SECB_CAL_HDR:  /* Cal header */
    case WAVE_FW_NUM_TX:            /* Tx Sender CPUs */
    case WAVE_FW_NUM_RX:            /* Rx Handler CPUs */
    case WAVE_FW_NUM_IF:            /* Host Interface CPUs */
    case WAVE_FW_NUM_SECB_PM_CMN:    /* ProgModel Common */
    case WAVE_FW_NUM_SECB_PM_ANT_RX: /* ProgModel Rx Ant */
    case WAVE_FW_NUM_SECB_PM_ANT_TX: /* ProgModel Tx Ant */
    case WAVE_FW_NUM_SECB_PSD_FILE:  /* PSD file */
    case WAVE_FW_NUM_SECB_CAL_FILE:  /* Cal file */
      break;
    /* Not supported */
    default:
      return MTLK_ERR_NOT_SUPPORTED;
  }

  fw_info->mem[0].length = _wave_fw_size[fw_num];

  return MTLK_ERR_OK;
}

static int
_mtlk_pcie_ccr_get_size_fw_dump_info (void *ccr_mem, wave_fw_dump_info_t *fw_info)
{
  mtlk_pcie_ccr_t *pcie_mem = (mtlk_pcie_ccr_t *)ccr_mem;
  int size = ARRAY_SIZE(g7_proc_fw_dump_files);
  uint32 reg_val = 0;

  MTLK_ASSERT(ccr_mem);

  /* Size of the B0_TEST_BUS file depends on Single/Dual band mode */
  if (wave_hw_radio_band_cfg_is_single(pcie_mem->hw)) {
    fw_info[FW_IDX_B0_TEST_BUS].io_size = TEST_BUS_SINGLE_BAND_SIZE;
    size = FW_IDX_B0_LAST;
  } else {
    fw_info[FW_IDX_B0_TEST_BUS].io_size = TEST_BUS_DUAL_BAND_SIZE;
    size = FW_IDX_B1_LAST;
  }

  /* WAV600-2: FW Dump should not include Black zone when Firewall is enabled*/
  MTLK_FIREWALL_ON_UPDATE_SHARED_RAM_SIZE(g7_proc_fw_dump_files[FW_IDX_SHRAM].io_size,reg_val);

  /* Set size to 0 for files which are unsupported by dummy phy */
  /* FIXME: what about PDXP (Emulation) with real PHY ? */
  if (wave_hw_mmb_card_is_phy_dummy(pcie_mem->hw)) {
    fw_info[FW_IDX_B0_TEST_BUS].io_size  = 0;
    fw_info[FW_IDX_B1_TEST_BUS].io_size  = 0;
    fw_info[FW_IDX_B0_PHY_RX_TD_REG096].io_size = 0;
    fw_info[FW_IDX_B1_PHY_RX_TD_REG096].io_size = 0;
  }

  /* Different size of DESC_RAM */
  if (wave_hw_mmb_card_is_asic(pcie_mem->hw)) {
    fw_info[FW_IDX_DESC_RAM_A].io_size = DESCRIPTOR_RAM_A_SIZE;
    fw_info[FW_IDX_DESC_RAM_B].io_size = DESCRIPTOR_RAM_B_SIZE;
  } else { /* non ASIC */
    fw_info[FW_IDX_DESC_RAM_A].io_size = REDUCED_DESCRIPTOR_RAM_SIZE;
    fw_info[FW_IDX_DESC_RAM_B].io_size = REDUCED_DESCRIPTOR_RAM_SIZE;
  }

  return size;
}

static int
_mtlk_pcie_ccr_get_fw_dump_info (void *ccr_mem, wave_fw_dump_info_t **fw_info)
{
  size_t alloc_size = 0;

  MTLK_ASSERT(NULL != fw_info);
  MTLK_ASSERT(NULL == *fw_info);

  alloc_size = sizeof(g7_proc_fw_dump_files);
  *fw_info = mtlk_osal_mem_alloc(alloc_size, LQLA_MEM_TAG_FW_RECOVERY);
  if (*fw_info == NULL) {
    ELOG_V("Failed to alloc memory for fw_info");
    return MTLK_ERR_NO_MEM;
  }

  wave_memcpy(*fw_info, alloc_size, &g7_proc_fw_dump_files[0], sizeof(g7_proc_fw_dump_files));

  return _mtlk_pcie_ccr_get_size_fw_dump_info(ccr_mem, *fw_info);
}
#undef LOG_LOCAL_GID
#undef LOG_LOCAL_FID
#endif
