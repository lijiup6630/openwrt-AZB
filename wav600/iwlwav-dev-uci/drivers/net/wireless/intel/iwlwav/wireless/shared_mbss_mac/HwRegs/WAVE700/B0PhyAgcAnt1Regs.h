
/***********************************************************************************
File:				B0PhyAgcAnt1Regs.h
Module:				b0PhyAgcAnt1
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:11:23
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B0_PHY_AGC_ANT1_REGS_H_
#define _B0_PHY_AGC_ANT1_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B0_PHY_AGC_ANT1_BASE_ADDRESS                             MEMORY_MAP_UNIT_221_BASE_ADDRESS
#define	REG_B0_PHY_AGC_ANT1_BB_RSSI_PARAMS_REG                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x0)
#define	REG_B0_PHY_AGC_ANT1_BB_RSSI_OFFSET2_REG                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x4)
#define	REG_B0_PHY_AGC_ANT1_BB_RSSI_SYSTEM_GAIN_REG                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x8)
#define	REG_B0_PHY_AGC_ANT1_BB_RSSI_SYSTEM_GAIN_SELECT_REG          (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xC)
#define	REG_B0_PHY_AGC_ANT1_BB_RSSI_SAT_THR                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x10)
#define	REG_B0_PHY_AGC_ANT1_INB_RSSI_PARAMS_REG                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x14)
#define	REG_B0_PHY_AGC_ANT1_INB_RSSI_OFFSET2_REG                    (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x18)
#define	REG_B0_PHY_AGC_ANT1_INBAND_RSSI_SYSTEM_GAIN_REG             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1C)
#define	REG_B0_PHY_AGC_ANT1_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x20)
#define	REG_B0_PHY_AGC_ANT1_INBAND_RSSI_SAT_THR                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x24)
#define	REG_B0_PHY_AGC_ANT1_FB_RSSI_PARAMS_REG                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x28)
#define	REG_B0_PHY_AGC_ANT1_FB_RSSI_OFFSET2_REG                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2C)
#define	REG_B0_PHY_AGC_ANT1_FB_RSSI_SYSTEM_GAIN_REG                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x30)
#define	REG_B0_PHY_AGC_ANT1_FB_RSSI_SYSTEM_GAIN_SELECT_REG          (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x34)
#define	REG_B0_PHY_AGC_ANT1_FB_RSSI_SAT_THR                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x38)
#define	REG_B0_PHY_AGC_ANT1_HB_RSSI_PARAMS_REG                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3C)
#define	REG_B0_PHY_AGC_ANT1_HB_RSSI_OFFSET2_REG                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x40)
#define	REG_B0_PHY_AGC_ANT1_HB_RSSI_SYSTEM_GAIN_REG                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x44)
#define	REG_B0_PHY_AGC_ANT1_HB_RSSI_SYSTEM_GAIN_SELECT_REG          (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x48)
#define	REG_B0_PHY_AGC_ANT1_HB_RSSI_SAT_THR                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x4C)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_PARAMS_REG                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x50)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET1_RX_RANGE0               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x54)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET1_RX_RANGE1               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x58)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET1_TX                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x5C)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET2_RX_REG                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x60)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET2_TX_REG                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x64)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_SYSTEM_GAIN_REG                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x68)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_SYSTEM_GAIN_SELECT_REG          (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x6C)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_SAT_THR_RANGE0                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x70)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_SAT_THR_RANGE1                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x74)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A_RANGE0_REG               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x78)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A_RANGE1_REG               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x7C)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A2_RANGE0_REG              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x80)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A2_RANGE1_REG              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x84)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_B_RANGE0_REG               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x88)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_B_RANGE1_REG               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x8C)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_C_RANGE0_REG               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x90)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_C_RANGE1_REG               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x94)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_NLOG_RANGE0_REG            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x98)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_NLOG_RANGE1_REG            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x9C)
#define	REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_A_REG                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xA0)
#define	REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_A2_REG                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xA4)
#define	REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_B_REG                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xA8)
#define	REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_C_REG                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xAC)
#define	REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_NLOG_REG                   (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xB0)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_TX_RX_REG                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xB4)
#define	REG_B0_PHY_AGC_ANT1_BB_RSSI_REG                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xB8)
#define	REG_B0_PHY_AGC_ANT1_BB_POWER_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xBC)
#define	REG_B0_PHY_AGC_ANT1_BB_SRSSI_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xC0)
#define	REG_B0_PHY_AGC_ANT1_BB_SPOWER_REG                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xC4)
#define	REG_B0_PHY_AGC_ANT1_BB_PWR_DIFF_REG                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xC8)
#define	REG_B0_PHY_AGC_ANT1_IB_RSSI_REG                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xCC)
#define	REG_B0_PHY_AGC_ANT1_IB_POWER_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xD0)
#define	REG_B0_PHY_AGC_ANT1_IB_SRSSI_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xD4)
#define	REG_B0_PHY_AGC_ANT1_IB_SPOWER_REG                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xD8)
#define	REG_B0_PHY_AGC_ANT1_IB_PWR_DIFF_REG                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xDC)
#define	REG_B0_PHY_AGC_ANT1_FB_RSSI_REG                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xE0)
#define	REG_B0_PHY_AGC_ANT1_FB_POWER_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xE4)
#define	REG_B0_PHY_AGC_ANT1_FB_SRSSI_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xE8)
#define	REG_B0_PHY_AGC_ANT1_FB_SPOWER_REG                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xEC)
#define	REG_B0_PHY_AGC_ANT1_FB_PWR_DIFF_REG                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xF0)
#define	REG_B0_PHY_AGC_ANT1_HB_RSSI_REG                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xF4)
#define	REG_B0_PHY_AGC_ANT1_HB_POWER_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xF8)
#define	REG_B0_PHY_AGC_ANT1_HB_SRSSI_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0xFC)
#define	REG_B0_PHY_AGC_ANT1_HB_SPOWER_REG                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x100)
#define	REG_B0_PHY_AGC_ANT1_HB_PWR_DIFF_REG                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x104)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_REG                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x108)
#define	REG_B0_PHY_AGC_ANT1_RF_POWER_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x10C)
#define	REG_B0_PHY_AGC_ANT1_RF_SRSSI_REG                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x110)
#define	REG_B0_PHY_AGC_ANT1_RF_SPOWER_REG                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x114)
#define	REG_B0_PHY_AGC_ANT1_SATURATION_RESULT                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x118)
#define	REG_B0_PHY_AGC_ANT1_RSSI_BLOCKS_GCLK_EN                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x11C)
#define	REG_B0_PHY_AGC_ANT1_RF_RSSI_DEC_OUT_STS                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x120)
#define	REG_B0_PHY_AGC_ANT1_PM_RF_POWER                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x140)
#define	REG_B0_PHY_AGC_ANT1_PM_FB_POWER                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x144)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_POWER                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x148)
#define	REG_B0_PHY_AGC_ANT1_PM_HB_POWER                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x14C)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_POWER                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x150)
#define	REG_B0_PHY_AGC_ANT1_PM_ACI_POWER                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x154)
#define	REG_B0_PHY_AGC_ANT1_PM_RF_OFFSET                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x158)
#define	REG_B0_PHY_AGC_ANT1_PM_FB_OFFSET                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x15C)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_OFFSET                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x160)
#define	REG_B0_PHY_AGC_ANT1_PM_HB_OFFSET                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x164)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_OFFSET                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x168)
#define	REG_B0_PHY_AGC_ANT1_PM_ACI_OFFSET                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x16C)
#define	REG_B0_PHY_AGC_ANT1_PM_SATURATION_REG                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x170)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_DELAY                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x174)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_SOURCES                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x178)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_MAX_POWER_LEVEL             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x17C)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_MIN_POWER_LEVEL             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x180)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_SIGNAL_MAX_LEVEL            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x184)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_ENV_MIN_LEVEL               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x188)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_SIGNAL_ENV_DIFF_VALUES      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x18C)
#define	REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_GSP_TABLE_CONTROL           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x190)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_0                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x194)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_1                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x198)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_2                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x19C)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_3                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1A0)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_4                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1A4)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_5                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1A8)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_6                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1AC)
#define	REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_7                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1B0)
#define	REG_B0_PHY_AGC_ANT1_PM_SEL_S2D_RX_LUT                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1B4)
#define	REG_B0_PHY_AGC_ANT1_PM_PGC1_GAIN_OFFSET                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1B8)
#define	REG_B0_PHY_AGC_ANT1_PM_PGC1_GAIN_LIMITS                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1BC)
#define	REG_B0_PHY_AGC_ANT1_PM_PGC1_GAIN_SHIFT                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1C0)
#define	REG_B0_PHY_AGC_ANT1_PM_RX_FILTER_CONTROL                    (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1C4)
#define	REG_B0_PHY_AGC_ANT1_PM_RF_SYSTEM_GAIN_OFFSET                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1C8)
#define	REG_B0_PHY_AGC_ANT1_PM_FB_SYSTEM_GAIN_OFFSET                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1CC)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_SYSTEM_GAIN_OFFSET                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1D0)
#define	REG_B0_PHY_AGC_ANT1_PM_POST_BB_SYSTEM_GAIN_OFFSET           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1D4)
#define	REG_B0_PHY_AGC_ANT1_PM_HB_SYSTEM_GAIN_OFFSET                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1D8)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_SYSTEM_GAIN_OFFSET                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1DC)
#define	REG_B0_PHY_AGC_ANT1_PM_ACI_SYSTEM_GAIN_OFFSET               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1E0)
#define	REG_B0_PHY_AGC_ANT1_PM_CCA_SYSTEM_GAIN_OFFSET               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1E4)
#define	REG_B0_PHY_AGC_ANT1_PM_DET_SYSTEM_GAIN_OFFSET               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1E8)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_BOF_OFFSET                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1EC)
#define	REG_B0_PHY_AGC_ANT1_PM_HB_BOF_OFFSET                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1F0)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_RSSI_BOF_OFFSET                   (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1F4)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_ACI_BOF_OFFSET                    (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1F8)
#define	REG_B0_PHY_AGC_ANT1_PM_DET_BOF_OFFSET                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x1FC)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_BOF_TARGET                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x200)
#define	REG_B0_PHY_AGC_ANT1_PM_HB_BOF_TARGET                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x204)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_BOF_TARGET                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x208)
#define	REG_B0_PHY_AGC_ANT1_PM_DET_BOF_TARGET                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x20C)
#define	REG_B0_PHY_AGC_ANT1_PM_DIFI1_DB_GAIN                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x210)
#define	REG_B0_PHY_AGC_ANT1_PM_PRESET_LNA_PGC1                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x214)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_BB_DIGITAL_GAIN                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x218)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_BB_DIGITAL_GAIN                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x21C)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_BB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x220)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_BB_DIGITAL_GAIN     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x224)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_HB_DIGITAL_GAIN                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x228)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_HB_DIGITAL_GAIN                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x22C)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_HB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x230)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_HB_DIGITAL_GAIN     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x234)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_IB_DIGITAL_GAIN                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x238)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_IB_DIGITAL_GAIN                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x23C)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_IB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x240)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_IB_DIGITAL_GAIN     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x244)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_DET_DIGITAL_GAIN                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x248)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_DET_DIGITAL_GAIN               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x24C)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_DET_DIGITAL_GAIN       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x250)
#define	REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_DET_DIGITAL_GAIN    (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x254)
#define	REG_B0_PHY_AGC_ANT1_ACC_RF_POWER                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x258)
#define	REG_B0_PHY_AGC_ANT1_ACC_FB_POWER                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x25C)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_POWER                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x260)
#define	REG_B0_PHY_AGC_ANT1_ACC_HB_POWER                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x264)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_POWER                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x268)
#define	REG_B0_PHY_AGC_ANT1_ACC_ACI_POWER                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x26C)
#define	REG_B0_PHY_AGC_ANT1_ACC_SIGNAL_POWER                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x270)
#define	REG_B0_PHY_AGC_ANT1_ACC_ENV_POWER                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x274)
#define	REG_B0_PHY_AGC_ANT1_ACC_STATUS                              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x278)
#define	REG_B0_PHY_AGC_ANT1_ACC_RF_SYSTEM_GAIN                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x27C)
#define	REG_B0_PHY_AGC_ANT1_ACC_FB_SYSTEM_GAIN                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x280)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_SYSTEM_GAIN                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x284)
#define	REG_B0_PHY_AGC_ANT1_ACC_POST_BB_SYSTEM_GAIN                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x288)
#define	REG_B0_PHY_AGC_ANT1_ACC_HB_SYSTEM_GAIN                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x28C)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_SYSTEM_GAIN                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x290)
#define	REG_B0_PHY_AGC_ANT1_ACC_ACI_SYSTEM_GAIN                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x294)
#define	REG_B0_PHY_AGC_ANT1_ACC_CCA_SYSTEM_GAIN                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x298)
#define	REG_B0_PHY_AGC_ANT1_ACC_DET_SYSTEM_GAIN                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x29C)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_DIGITAL_GAIN                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2A0)
#define	REG_B0_PHY_AGC_ANT1_ACC_HB_DIGITAL_GAIN                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2A4)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_DIGITAL_GAIN                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2A8)
#define	REG_B0_PHY_AGC_ANT1_ACC_DET_DIGITAL_GAIN                    (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2AC)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_BOF                              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2B0)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_TOTAL_DIGITAL_GAIN               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2B4)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_DIGITAL_BOF                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2B8)
#define	REG_B0_PHY_AGC_ANT1_ACC_HB_BOF                              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2BC)
#define	REG_B0_PHY_AGC_ANT1_ACC_HB_TOTAL_DIGITAL_GAIN               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2C0)
#define	REG_B0_PHY_AGC_ANT1_ACC_HB_DIGITAL_BOF                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2C4)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_BOF                              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2C8)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_TOTAL_DIGITAL_GAIN               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2CC)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_DIGITAL_BOF                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2D0)
#define	REG_B0_PHY_AGC_ANT1_ACC_DET_BOF                             (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2D4)
#define	REG_B0_PHY_AGC_ANT1_ACC_DET_TOTAL_DIGITAL_GAIN              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2D8)
#define	REG_B0_PHY_AGC_ANT1_ACC_DET_DIGITAL_BOF                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2DC)
#define	REG_B0_PHY_AGC_ANT1_ACC_DC_OFFSET_I                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2E0)
#define	REG_B0_PHY_AGC_ANT1_ACC_DC_OFFSET_Q                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2E4)
#define	REG_B0_PHY_AGC_ANT1_PM_AGC_RAMS_RM                          (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2E8)
#define	REG_B0_PHY_AGC_ANT1_ACC_GAIN_VALUES                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2EC)
#define	REG_B0_PHY_AGC_ANT1_PM_SHORT_HEADER                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2F0)
#define	REG_B0_PHY_AGC_ANT1_PM_FCSI_ADDRESS                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2F4)
#define	REG_B0_PHY_AGC_ANT1_ACC_FCSI_VALUES                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2F8)
#define	REG_B0_PHY_AGC_ANT1_ACC_GAIN_ACC_CONTROL                    (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x2FC)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_CODE_ACC_THR                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x300)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_CODE_ACC_THR                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x304)
#define	REG_B0_PHY_AGC_ANT1_PM_LONGTERM_RELEASE_THR                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x308)
#define	REG_B0_PHY_AGC_ANT1_PM_LONGTERM_THR                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x30C)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_POWER_FAST_LOW_THR                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x310)
#define	REG_B0_PHY_AGC_ANT1_PM_DELTA_CODE_ACC_THR                   (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x314)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_POWER_UP_THR                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x318)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_POWER_SLOW_LOW_THR                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x31C)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_POWER_UP_THR                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x320)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_POWER_SLOW_LOW_THR                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x324)
#define	REG_B0_PHY_AGC_ANT1_PM_SET_CODE_ACC_THR_CTRL                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x328)
#define	REG_B0_PHY_AGC_ANT1_PM_ALGO_CTRL                            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x32C)
#define	REG_B0_PHY_AGC_ANT1_ACC_EVENT_STATUS                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x330)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_TH_SET_INC_GAP_DB                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x334)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_TH_SET_DEC_GAP_DB                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x338)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_TH_UP_EXTRA_GAP_DB                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x33C)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_POWER_UP_DEF_THR                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x340)
#define	REG_B0_PHY_AGC_ANT1_PM_BB_POWER_SLOW_LOW_MIN_THR            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x344)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_TH_SET_INC_GAP_DB                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x348)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_TH_SET_DEC_GAP_DB                 (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x34C)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_TH_UP_EXTRA_GAP_DB                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x350)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_POWER_UP_DEF_THR                  (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x354)
#define	REG_B0_PHY_AGC_ANT1_PM_IB_POWER_SLOW_LOW_MIN_THR            (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x358)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_POWER_UP_THR                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x35C)
#define	REG_B0_PHY_AGC_ANT1_ACC_BB_POWER_SLOW_LOW_THR               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x360)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_POWER_UP_THR                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x364)
#define	REG_B0_PHY_AGC_ANT1_ACC_IB_POWER_SLOW_LOW_THR               (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x368)
#define	REG_B0_PHY_AGC_ANT1_CALC_AGC_GAIN_WORD                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x36C)
#define	REG_B0_PHY_AGC_ANT1_CALC_AGC_STM_CLEAR_CONTROL              (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x370)
#define	REG_B0_PHY_AGC_ANT1_CALC_ACC_AUTO_CLOSE_MODE                (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x374)
#define	REG_B0_PHY_AGC_ANT1_CALC_POWER_THR_ACC_GO                   (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x378)
#define	REG_B0_PHY_AGC_ANT1_CALC_AGC_GAIN_CANCEL                    (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x37C)
#define	REG_B0_PHY_AGC_ANT1_DISABLE_PERIPHERALS                     (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x380)
#define	REG_B0_PHY_AGC_ANT1_AGC_STM_RDBACK                          (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x384)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_BB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x388)
#define	REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_BB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x38C)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_HB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x390)
#define	REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_HB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x394)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_IB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x398)
#define	REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_IB_DIGITAL_GAIN        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x39C)
#define	REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_DET_DIGITAL_GAIN       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3A0)
#define	REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_DET_DIGITAL_GAIN       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3A4)
#define	REG_B0_PHY_AGC_ANT1_PM_BS_ABS_TH_B0_B4                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3A8)
#define	REG_B0_PHY_AGC_ANT1_PM_BS_ABS_TH_B5_B7                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3AC)
#define	REG_B0_PHY_AGC_ANT1_PM_BS_OFF_TH_B0_B4                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3B0)
#define	REG_B0_PHY_AGC_ANT1_PM_BS_OFF_TH_B5_B7                      (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3B4)
#define	REG_B0_PHY_AGC_ANT1_ACC_BLOCKER_MAP                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3B8)
#define	REG_B0_PHY_AGC_ANT1_ACC_MAX_BLOCKER_POWER                   (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3BC)
#define	REG_B0_PHY_AGC_ANT1_BLOCKER_CONTROL                         (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3C0)
#define	REG_B0_PHY_AGC_ANT1_PM_BLOCKER_TH                           (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3C4)
#define	REG_B0_PHY_AGC_ANT1_ACC_OFFSET_BS0_B4                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3C8)
#define	REG_B0_PHY_AGC_ANT1_ACC_OFFSET_BS4_B7                       (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3CC)
#define	REG_B0_PHY_AGC_ANT1_PM_ALGO_CTRL_SEL                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3D0)
#define	REG_B0_PHY_AGC_ANT1_ACC_BLOCKER_ADDR                        (B0_PHY_AGC_ANT1_BASE_ADDRESS + 0x3D4)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B0_PHY_AGC_ANT1_BB_RSSI_PARAMS_REG 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bbRssiBlkSize : 3; //bb rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 bbRssiIirPole : 4; //bb rssi iir pole, reset value: 0x0, access type: RW
		uint32 bbRssiIirPoleMin : 3; //bb rssi iir shift, reset value: 0x0, access type: RW
		uint32 bbRssiOffset1 : 16; //bb rssi offset1, reset value: 0x0, access type: RW
		uint32 bbRssiCancelDc : 1; //cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB0PhyAgcAnt1BbRssiParamsReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_RSSI_OFFSET2_REG 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssiOffset2 : 9; //bb rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1BbRssiOffset2Reg_u;

/*REG_B0_PHY_AGC_ANT1_BB_RSSI_SYSTEM_GAIN_REG 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssiSystemGain : 9; //bb rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1BbRssiSystemGainReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_RSSI_SYSTEM_GAIN_SELECT_REG 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bbRssiSystemGainHwSelect : 1; //bb rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1BbRssiSystemGainSelectReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_RSSI_SAT_THR 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssiSatThr : 9; //bb rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1BbRssiSatThr_u;

/*REG_B0_PHY_AGC_ANT1_INB_RSSI_PARAMS_REG 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 inbandRssiBlkSize : 3; //inband rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 inbandRssiIirPole : 4; //inband rssi iir pole, reset value: 0x0, access type: RW
		uint32 inbandRssiIirPoleMin : 3; //inband rssi iir shift, reset value: 0x0, access type: RW
		uint32 inbandRssiOffset1 : 16; //inband rssi offset1, reset value: 0x0, access type: RW
		uint32 inbandRssiCancelDc : 1; //inband cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB0PhyAgcAnt1InbRssiParamsReg_u;

/*REG_B0_PHY_AGC_ANT1_INB_RSSI_OFFSET2_REG 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		int32  inbandRssiOffset2 : 9; //inband rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1InbRssiOffset2Reg_u;

/*REG_B0_PHY_AGC_ANT1_INBAND_RSSI_SYSTEM_GAIN_REG 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		int32  inbandRssiSystemGain : 9; //inband rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1InbandRssiSystemGainReg_u;

/*REG_B0_PHY_AGC_ANT1_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 inbandRssiSystemGainHwSelect : 1; //inband rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1InbandRssiSystemGainSelectReg_u;

/*REG_B0_PHY_AGC_ANT1_INBAND_RSSI_SAT_THR 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		int32  inbandRssiSatThr : 9; //inband rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1InbandRssiSatThr_u;

/*REG_B0_PHY_AGC_ANT1_FB_RSSI_PARAMS_REG 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fbRssiBlkSize : 3; //full band rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 fbRssiIirPole : 4; //full band rssi iir pole, reset value: 0x0, access type: RW
		uint32 fbRssiIirPoleMin : 3; //fll band rssi iir shift, reset value: 0x0, access type: RW
		uint32 fbRssiOffset1 : 16; //full band rssi offset1, reset value: 0x0, access type: RW
		uint32 fbRssiCancelDc : 1; //full bandcancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB0PhyAgcAnt1FbRssiParamsReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_RSSI_OFFSET2_REG 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssiOffset2 : 9; //full band rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1FbRssiOffset2Reg_u;

/*REG_B0_PHY_AGC_ANT1_FB_RSSI_SYSTEM_GAIN_REG 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssiSystemGain : 9; //full band rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1FbRssiSystemGainReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_RSSI_SYSTEM_GAIN_SELECT_REG 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fbRssiSystemGainHwSelect : 1; //full band rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1FbRssiSystemGainSelectReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_RSSI_SAT_THR 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssiSatThr : 9; //fb rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1FbRssiSatThr_u;

/*REG_B0_PHY_AGC_ANT1_HB_RSSI_PARAMS_REG 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hbRssiBlkSize : 3; //bb rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 hbRssiIirPole : 4; //bb rssi iir pole, reset value: 0x0, access type: RW
		uint32 hbRssiIirPoleMin : 3; //bb rssi iir shift, reset value: 0x0, access type: RW
		uint32 hbRssiOffset1 : 16; //bb rssi offset1, reset value: 0x0, access type: RW
		uint32 hbRssiCancelDc : 1; //cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB0PhyAgcAnt1HbRssiParamsReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_RSSI_OFFSET2_REG 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssiOffset2 : 9; //bb rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1HbRssiOffset2Reg_u;

/*REG_B0_PHY_AGC_ANT1_HB_RSSI_SYSTEM_GAIN_REG 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssiSystemGain : 9; //bb rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1HbRssiSystemGainReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_RSSI_SYSTEM_GAIN_SELECT_REG 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hbRssiSystemGainHwSelect : 1; //bb rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1HbRssiSystemGainSelectReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_RSSI_SAT_THR 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssiSatThr : 9; //bb rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1HbRssiSatThr_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_PARAMS_REG 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiBlkSizeRxMode : 3; //rf rssi decimatiion, 2^(block size), in RX mode, reset value: 0x0, access type: RW
		uint32 rfRssiBlkSizeTxMode : 3; //rf rssi decimatiion, 2^(block size), in TX mode, reset value: 0x0, access type: RW
		uint32 rfRssiBlkSizeUserMode : 3; //rf rssi decimatiion, 2^(block size), in user mode (override TX/RX), reset value: 0x0, access type: RW
		uint32 rfRssiIirPole : 4; //rf rssi iir pole, reset value: 0x0, access type: RW
		uint32 rfRssiIirPoleMin : 3; //rf rssi iir shift, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiParamsReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET1_RX_RANGE0 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset1RxRange0 : 14; //rf rssi offset1, used for dc cancellation in rx range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiOffset1RxRange0_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET1_RX_RANGE1 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset1RxRange1 : 14; //rf rssi offset1, used for dc cancellation in rx range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiOffset1RxRange1_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET1_TX 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset1Tx : 14; //rf rssi offset1, used for dc cancellation in tx, reset value: 0x0, access type: RWS
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiOffset1Tx_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET2_RX_REG 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset2Rx : 8; //rf rssi offset2, used for digital top power dBm conversion, RX mode, reset value: 0x0, access type: RWS
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiOffset2RxReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_OFFSET2_TX_REG 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset2Tx : 8; //rf rssi offset2, used for digital top power dBm conversion, TX mode, reset value: 0x0, access type: RWS
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiOffset2TxReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_SYSTEM_GAIN_REG 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiSystemGain : 9; //rf rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiSystemGainReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_SYSTEM_GAIN_SELECT_REG 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiSystemGainHwSelect : 1; //rf  rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiSystemGainSelectReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_SAT_THR_RANGE0 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiSatThrRange0 : 9; //rf rssi saturation threshold for range 0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiSatThrRange0_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_SAT_THR_RANGE1 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiSatThrRange1 : 9; //rf rssi saturation threshold for range 1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiSatThrRange1_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A_RANGE0_REG 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefARange0 : 16; //rf rssi coef A range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefARange0Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A_RANGE1_REG 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefARange1 : 16; //rf rssi coef A range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefARange1Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A2_RANGE0_REG 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefA2Range0 : 16; //rf rssi coef A2 range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefA2Range0Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_A2_RANGE1_REG 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefA2Range1 : 16; //rf rssi coef A2 range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefA2Range1Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_B_RANGE0_REG 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefBRange0 : 16; //rf rssi coef B range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefBRange0Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_B_RANGE1_REG 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefBRange1 : 16; //rf rssi coef B range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefBRange1Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_C_RANGE0_REG 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefCRange0 : 16; //rf rssi coef C range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefCRange0Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_C_RANGE1_REG 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefCRange1 : 16; //rf rssi coef C range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefCRange1Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_NLOG_RANGE0_REG 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefNlogRange0 : 16; //rf rssi coef Nlog range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefNlogRange0Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_COEF_NLOG_RANGE1_REG 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefNlogRange1 : 16; //rf rssi coef Nlog range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiCoefNlogRange1Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_A_REG 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefA : 16; //rf_tssi_coef_A, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfTssiCoefAReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_A2_REG 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefA2 : 16; //rf_tssi_coef_A2, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfTssiCoefA2Reg_u;

/*REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_B_REG 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefB : 16; //rf_tssi_coef_B, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfTssiCoefBReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_C_REG 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefC : 16; //rf_tssi_coef_C, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfTssiCoefCReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_TSSI_COEF_NLOG_REG 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefNlog : 16; //rf_tssi_coef_Nlog, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1RfTssiCoefNlogReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_TX_RX_REG 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiTxMode : 1; //rf rssi user programable mode : 1 tx mode, 0 rx mode, reset value: 0x0, access type: RW
		uint32 rfRssiRxRange : 1; //rf rssi user programable range, reset value: 0x0, access type: RW
		uint32 rfRssiModeOverride : 1; //rf rssi  mode override  - 1 use from pm, 0 use hw mode, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rfRssiRangeOverride : 1; //rf rssi  range override  - 1 use from pm, 0 use hw mode, reset value: 0x0, access type: RW
		uint32 rfTssiCoefOverride : 1; //rf tssi coef override  - 1 tssi coef from pm, 0 tssi coef from TPC  hw , reset value: 0x0, access type: RW
		uint32 rfRssiBlkSizeOverride : 1; //rf rssi blk size override: 1 decimation from pm, 0 - decimation according to TX/RX mode, reset value: 0x0, access type: RW
		uint32 rfTssiCoefMode : 2; //rf_tssi_coef_mode, reset value: 0x0, access type: RW
		uint32 reserved1 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiTxRxReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_RSSI_REG 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssi : 9; //BB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1BbRssiReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_POWER_REG 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbPower : 9; //BB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1BbPowerReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_SRSSI_REG 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbSrssi : 9; //BB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1BbSrssiReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_SPOWER_REG 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbSpower : 9; //BB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1BbSpowerReg_u;

/*REG_B0_PHY_AGC_ANT1_BB_PWR_DIFF_REG 0xC8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bbB1 : 9; //BB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 bbB2 : 9; //BB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB0PhyAgcAnt1BbPwrDiffReg_u;

/*REG_B0_PHY_AGC_ANT1_IB_RSSI_REG 0xCC */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibRssi : 9; //IB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1IbRssiReg_u;

/*REG_B0_PHY_AGC_ANT1_IB_POWER_REG 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibPower : 9; //IB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1IbPowerReg_u;

/*REG_B0_PHY_AGC_ANT1_IB_SRSSI_REG 0xD4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibSrssi : 9; //IB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1IbSrssiReg_u;

/*REG_B0_PHY_AGC_ANT1_IB_SPOWER_REG 0xD8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibSpower : 9; //IB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1IbSpowerReg_u;

/*REG_B0_PHY_AGC_ANT1_IB_PWR_DIFF_REG 0xDC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ibB1 : 9; //IB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 ibB2 : 9; //IB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB0PhyAgcAnt1IbPwrDiffReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_RSSI_REG 0xE0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssi : 9; //FB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1FbRssiReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_POWER_REG 0xE4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbPower : 9; //FB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1FbPowerReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_SRSSI_REG 0xE8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbSrssi : 9; //FB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1FbSrssiReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_SPOWER_REG 0xEC */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbSpower : 9; //FB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1FbSpowerReg_u;

/*REG_B0_PHY_AGC_ANT1_FB_PWR_DIFF_REG 0xF0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fbB1 : 9; //FB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 fbB2 : 9; //FB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB0PhyAgcAnt1FbPwrDiffReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_RSSI_REG 0xF4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssi : 9; //HB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1HbRssiReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_POWER_REG 0xF8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbPower : 9; //HB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1HbPowerReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_SRSSI_REG 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbSrssi : 9; //HB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1HbSrssiReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_SPOWER_REG 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbSpower : 9; //HB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1HbSpowerReg_u;

/*REG_B0_PHY_AGC_ANT1_HB_PWR_DIFF_REG 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hbB1 : 9; //HB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 hbB2 : 9; //HB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB0PhyAgcAnt1HbPwrDiffReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_REG 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssi : 9; //RF RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_POWER_REG 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfPower : 9; //RF power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfPowerReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_SRSSI_REG 0x110 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfSrssi : 9; //RF RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfSrssiReg_u;

/*REG_B0_PHY_AGC_ANT1_RF_SPOWER_REG 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfSpower : 9; //RF Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1RfSpowerReg_u;

/*REG_B0_PHY_AGC_ANT1_SATURATION_RESULT 0x118 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiSatFlag : 1; //rf rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 fbRssiSatFlag : 1; //fb rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 bbRssiSatFlag : 1; //bb rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 hbRssiSatFlag : 1; //hb rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 ibRssiSatFlag : 1; //ib rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 aciRssiSatFlag : 1; //aci rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 reserved0 : 26;
	} bitFields;
} RegB0PhyAgcAnt1SaturationResult_u;

/*REG_B0_PHY_AGC_ANT1_RSSI_BLOCKS_GCLK_EN 0x11C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiGclkEn : 1; //enable rf rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 fbRssiGclkEn : 1; //enable fb rssi peripheral gator, reset value: 0x0, access type: RW
		uint32 bbRssiGclkEn : 1; //enable bb rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 hbRssiGclkEn : 1; //enable hb rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 ibRssiGclkEn : 1; //enable ib rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 reserved0 : 27;
	} bitFields;
} RegB0PhyAgcAnt1RssiBlocksGclkEn_u;

/*REG_B0_PHY_AGC_ANT1_RF_RSSI_DEC_OUT_STS 0x120 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiDecOutSts : 14; //rf rssi decimator output for dc measurement, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1RfRssiDecOutSts_u;

/*REG_B0_PHY_AGC_ANT1_PM_RF_POWER 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmRfPower : 9; //programmble rf power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmRfPower_u;

/*REG_B0_PHY_AGC_ANT1_PM_FB_POWER 0x144 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmFbPower : 9; //programmble fb power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmFbPower_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_POWER 0x148 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPower : 9; //programmble bb power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbPower_u;

/*REG_B0_PHY_AGC_ANT1_PM_HB_POWER 0x14C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbPower : 9; //programmble hb power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmHbPower_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_POWER 0x150 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPower : 9; //programmble ib power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbPower_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACI_POWER 0x154 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAciPower : 9; //programmble aci power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmAciPower_u;

/*REG_B0_PHY_AGC_ANT1_PM_RF_OFFSET 0x158 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmRfOffset : 9; //offset for rf power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmRfOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_FB_OFFSET 0x15C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmFbOffset : 9; //offset for fb power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmFbOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_OFFSET 0x160 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbOffset : 9; //offset for bb power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_HB_OFFSET 0x164 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbOffset : 9; //offset for hb power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmHbOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_OFFSET 0x168 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbOffset : 9; //offset for ib power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACI_OFFSET 0x16C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAciOffset : 9; //offset for aci power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmAciOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_SATURATION_REG 0x170 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRfRssiSatFlag : 1; //rf rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmFbRssiSatFlag : 1; //fb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmBbRssiSatFlag : 1; //bb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmHbRssiSatFlag : 1; //hb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmIbRssiSatFlag : 1; //ib rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAciRssiSatFlag : 1; //aci rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegB0PhyAgcAnt1PmSaturationReg_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_DELAY 0x174 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainDelay : 16; //delay between table go to start acceleration, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainDelay_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_SOURCES 0x178 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainRfSource : 1; //rf power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainFbSource : 1; //fb power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainBbSource : 1; //bb power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainHbSource : 1; //hb power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainIbSource : 1; //ib power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainAciSource : 1; //aci power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmAccGainRfSatSource : 1; //rf rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainFbSatSource : 1; //fb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainBbSatSource : 1; //bb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainHbSatSource : 1; //hb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainIbSatSource : 1; //ib rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainAciSatSource : 1; //aci rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmAccGainSignalSource : 2; //acc_gain_signal_source: 0-from BB, 1-from IB, 2-from Aci, 3- from HB, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmAccGainEnvSource : 2; //acc_gain_env_source: 0- from rf, 1-from fb, 2 - from bb, reset value: 0x0, access type: RW
		uint32 pmAccGainPgc1Source : 2; //acc_gain_pgc1_source: 0- from fb, 1-from bb,2-rf, reset value: 0x0, access type: RW
		uint32 pmAccGainIbGainSource : 1; //acc_gain_ib_gain calculation source: 0-from ib rssi, 1- from aci, reset value: 0x0, access type: RW
		uint32 pmAccGainBlockerTypeSource : 1; //blocker type source, reset value: 0x0, access type: RW
		uint32 reserved3 : 6;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainSources_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_MAX_POWER_LEVEL 0x17C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainMaxPowerLevel : 9; //acc gain HW limit max power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainMaxPowerLevel_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_MIN_POWER_LEVEL 0x180 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainMinPowerLevel : 9; //acc gain HW limit min power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainMinPowerLevel_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_SIGNAL_MAX_LEVEL 0x184 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainSignalMaxLevel : 9; //acc gain HW limit for BB is RF  in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainSignalMaxLevel_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_ENV_MIN_LEVEL 0x188 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainEnvMinLevel : 9; //acc gain HW limit for RF is BB in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainEnvMinLevel_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_SIGNAL_ENV_DIFF_VALUES 0x18C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainSignalEnvMaxDiff : 9; //maximal difference beween signal and environment for table access in 1/2 dB, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 pmAccGainSignalEnvMinDiff : 9; //minimal difference beween signal and environment for table access, reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainSignalEnvDiffValues_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACC_GAIN_GSP_TABLE_CONTROL 0x190 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 16;
		uint32 pmAccGainGspTableShift : 3; //shift for delta calculated for table resolution, reset value: 0x0, access type: RW
		uint32 reserved1 : 5;
		uint32 pmAccGainGspTableMode : 1; //mode for table:0-per bw, 1-full band, reset value: 0x0, access type: RW
		uint32 reserved2 : 7;
	} bitFields;
} RegB0PhyAgcAnt1PmAccGainGspTableControl_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_0 0x194 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut0 : 9; //lna gain in db for lna_index 0 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut0_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_1 0x198 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut1 : 9; //lna gain in db for lna_index 1 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut1_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_2 0x19C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut2 : 9; //lna gain in db for lna_index 2 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut2_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_3 0x1A0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut3 : 9; //lna gain in db for lna_index 3 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut3_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_4 0x1A4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut4 : 9; //lna gain in db for lna_index 4 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut4_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_5 0x1A8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut5 : 9; //lna gain in db for lna_index 5 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut5_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_6 0x1AC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut6 : 9; //lna gain in db for lna_index 6 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut6_u;

/*REG_B0_PHY_AGC_ANT1_PM_LNA_GAIN_LUT_7 0x1B0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut7 : 9; //lna gain in db for lna_index 7 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLnaGainLut7_u;

/*REG_B0_PHY_AGC_ANT1_PM_SEL_S2D_RX_LUT 0x1B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSelS2DRxLut0 : 1; //control bit to select rf rssi range and s2d pair for lna index 0, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut1 : 1; //control bit to select rf rssi range and s2d pair for lna index 1, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut2 : 1; //control bit to select rf rssi range and s2d pair for lna index 2, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut3 : 1; //control bit to select rf rssi range and s2d pair for lna index 3, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut4 : 1; //control bit to select rf rssi range and s2d pair for lna index 4, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut5 : 1; //control bit to select rf rssi range and s2d pair for lna index 5, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut6 : 1; //control bit to select rf rssi range and s2d pair for lna index 6, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut7 : 1; //control bit to select rf rssi range and s2d pair for lna index 7, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyAgcAnt1PmSelS2DRxLut_u;

/*REG_B0_PHY_AGC_ANT1_PM_PGC1_GAIN_OFFSET 0x1B8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmPgc1GainOffset : 9; //pgc1 target power offset in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmPgc1GainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_PGC1_GAIN_LIMITS 0x1BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPgc1GainPlusOffsetMaxLimit : 9; //pgc1 gain plus offset max limit in 1/2 dB, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 pmPgc1GainPlusOffsetMinLimit : 9; //pgc1 gain plus offset min limit in 1/2 dB, reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
	} bitFields;
} RegB0PhyAgcAnt1PmPgc1GainLimits_u;

/*REG_B0_PHY_AGC_ANT1_PM_PGC1_GAIN_SHIFT 0x1C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPgc1GainShift : 3; //pgc1 index shift to convert from gain to index, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyAgcAnt1PmPgc1GainShift_u;

/*REG_B0_PHY_AGC_ANT1_PM_RX_FILTER_CONTROL 0x1C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRxFilterBwPowerMode : 2; //rx_filter_power_mode: , 0-per bw w/wo interfirence mode , 1-reduced power for 20MHz/40MHz only , 2-COC 20MHz only , 3-DPD wide band only, reset value: 0x0, access type: RW
		uint32 pmRxFilterBwInterferenceMode : 1; //rx_filter_bw interference_mode: 0-no interference, 1-w/ interference. Different filter bw for int, reset value: 0x0, access type: RW
		uint32 pmRxFilterMode : 1; //pgc1 rx filter mode: 0-WAV600, 1-WAV600-2, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyAgcAnt1PmRxFilterControl_u;

/*REG_B0_PHY_AGC_ANT1_PM_RF_SYSTEM_GAIN_OFFSET 0x1C8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmRfSystemGainOffset : 9; //offset for rf gain acceleration (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmRfSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_FB_SYSTEM_GAIN_OFFSET 0x1CC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmFbSystemGainOffset : 9; //offset for fb gain acceleration (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmFbSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_SYSTEM_GAIN_OFFSET 0x1D0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbSystemGainOffset : 9; //offset for bb gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_POST_BB_SYSTEM_GAIN_OFFSET 0x1D4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmPostBbSystemGainOffset : 9; //offset for pre bb gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmPostBbSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_HB_SYSTEM_GAIN_OFFSET 0x1D8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbSystemGainOffset : 9; //offset for hb gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmHbSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_SYSTEM_GAIN_OFFSET 0x1DC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbSystemGainOffset : 9; //offset for ib gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_ACI_SYSTEM_GAIN_OFFSET 0x1E0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAciSystemGainOffset : 9; //offset for aci gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmAciSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_CCA_SYSTEM_GAIN_OFFSET 0x1E4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmCcaSystemGainOffset : 9; //offset for cca gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmCcaSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_DET_SYSTEM_GAIN_OFFSET 0x1E8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDetSystemGainOffset : 9; //offset for det gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmDetSystemGainOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_BOF_OFFSET 0x1EC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbBofOffset : 9; //convert bb rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbBofOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_HB_BOF_OFFSET 0x1F0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbBofOffset : 9; //convert hb rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmHbBofOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_RSSI_BOF_OFFSET 0x1F4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbRssiBofOffset : 9; //convert ib rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbRssiBofOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_ACI_BOF_OFFSET 0x1F8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbAciBofOffset : 9; //convert ib aci power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbAciBofOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_DET_BOF_OFFSET 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDetBofOffset : 9; //convert det power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmDetBofOffset_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_BOF_TARGET 0x200 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbBofTarget : 9; //target backoff from full scale at bb rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbBofTarget_u;

/*REG_B0_PHY_AGC_ANT1_PM_HB_BOF_TARGET 0x204 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbBofTarget : 9; //target backoff from full scale at hb rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmHbBofTarget_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_BOF_TARGET 0x208 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbBofTarget : 9; //target backoff from full scale at ib rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbBofTarget_u;

/*REG_B0_PHY_AGC_ANT1_PM_DET_BOF_TARGET 0x20C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDetBofTarget : 9; //target backoff from full scale at det rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmDetBofTarget_u;

/*REG_B0_PHY_AGC_ANT1_PM_DIFI1_DB_GAIN 0x210 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDifi1DbGain : 9; //difi1 gain in 1/2 dB must be equal to the linear gain of pm_difi1_gain , reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmDifi1DbGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_PRESET_LNA_PGC1 0x214 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLnaIndexMaxGain : 3; //max gain lna index, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 pmLnaIndexStep1Gain : 3; //step1 env & signal are saturated, gain lna index, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 pmLnaIndexStep1EnvSatGain : 3; //step1 env only is saturated, gain lna index, reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 pmLnaIndexStep1SignalSatGain : 3; //step1 signal only is saturated, gain lna index, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 pmPgc1IndexMaxGain : 4; //max gain pgc1 index, reset value: 0x0, access type: RW
		uint32 pmPgc1IndexStep1Gain : 4; //step1 env & signal are satuarted gain pgc1 index, reset value: 0x0, access type: RW
		uint32 pmPgc1IndexStep1EnvSatGain : 4; //step1 env only is saturated gain pgc1 index, reset value: 0x0, access type: RW
		uint32 pmPgc1IndexStep1SignalSatGain : 4; //step1 signal only is saturated gain pgc1 index, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyAgcAnt1PmPresetLnaPgc1_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_BB_DIGITAL_GAIN 0x218 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxBbDigitalGain : 9; //max gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxBbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_BB_DIGITAL_GAIN 0x21C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1BbDigitalGain : 9; //step1 env & signal are saturated gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1BbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_BB_DIGITAL_GAIN 0x220 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatBbDigitalGain : 9; //step1 env only is saturated gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1EnvSatBbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_BB_DIGITAL_GAIN 0x224 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatBbDigitalGain : 9; //step1 signal only is saturated gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1SignalSatBbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_HB_DIGITAL_GAIN 0x228 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxHbDigitalGain : 9; //max gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxHbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_HB_DIGITAL_GAIN 0x22C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1HbDigitalGain : 9; //step1 env & signal are saturated gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1HbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_HB_DIGITAL_GAIN 0x230 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatHbDigitalGain : 9; //step1 env only is saturated gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1EnvSatHbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_HB_DIGITAL_GAIN 0x234 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatHbDigitalGain : 9; //step1 signal only is saturated gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1SignalSatHbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_IB_DIGITAL_GAIN 0x238 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxIbDigitalGain : 9; //max gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxIbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_IB_DIGITAL_GAIN 0x23C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1IbDigitalGain : 9; //step1 env & signal are saturated, gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1IbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_IB_DIGITAL_GAIN 0x240 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatIbDigitalGain : 9; //step1 env only is saturated, gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1EnvSatIbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_IB_DIGITAL_GAIN 0x244 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatIbDigitalGain : 9; //step1 signal only is saturated, gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1SignalSatIbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_DET_DIGITAL_GAIN 0x248 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxDetDigitalGain : 9; //max gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxDetDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_DET_DIGITAL_GAIN 0x24C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1DetDigitalGain : 9; //step1 env & signal are saturated, gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1DetDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_ENV_SAT_DET_DIGITAL_GAIN 0x250 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatDetDigitalGain : 9; //step1 env only is saturated, gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1EnvSatDetDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_STEP1_SIGNAL_SAT_DET_DIGITAL_GAIN 0x254 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatDetDigitalGain : 9; //step1 signal only is saturated, gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmStep1SignalSatDetDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_RF_POWER 0x258 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accRfPower : 9; //rf power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccRfPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_FB_POWER 0x25C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accFbPower : 9; //fb power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccFbPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_POWER 0x260 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbPower : 9; //bb power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_HB_POWER 0x264 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbPower : 9; //hb power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccHbPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_POWER 0x268 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbPower : 9; //ib power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_ACI_POWER 0x26C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accAciPower : 9; //aci power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccAciPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_SIGNAL_POWER 0x270 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accSignalPower : 9; //signal power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccSignalPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_ENV_POWER 0x274 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accEnvPower : 9; //env power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccEnvPower_u;

/*REG_B0_PHY_AGC_ANT1_ACC_STATUS 0x278 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accRfSat : 1; //rf rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accFbSat : 1; //fb rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accBbSat : 1; //bb rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accHbSat : 1; //hb rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accIbSat : 1; //ib rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accAciSat : 1; //aci rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accSignalLimitMax : 1; //signal power is bigger than pm_max_power_level, reset value: 0x0, access type: RO
		uint32 accSignalLimitMin : 1; //signal power is less than pm_min_power_level, reset value: 0x0, access type: RO
		uint32 accSignalSat : 1; //signal rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accEnvLimitMax : 1; //env power is bigger than pm_max_power_level, reset value: 0x0, access type: RO
		uint32 accEnvSat : 1; //env rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accEnvLimitMin : 1; //env power is less than pm_min_power_level, reset value: 0x0, access type: RO
		uint32 accSignalIsEnvValid : 1; //signal power is bigger than pm_signal_max_level, use env power instead, reset value: 0x0, access type: RO
		uint32 accEnvIsSignalValid : 1; //env power is less than pm_env_min_level, use signal power instead, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1AccStatus_u;

/*REG_B0_PHY_AGC_ANT1_ACC_RF_SYSTEM_GAIN 0x27C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accRfSystemGain : 9; //rf system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccRfSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_FB_SYSTEM_GAIN 0x280 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accFbSystemGain : 9; //fb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccFbSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_SYSTEM_GAIN 0x284 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbSystemGain : 9; //bb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_POST_BB_SYSTEM_GAIN 0x288 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accPostBbSystemGain : 9; //pre bb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccPostBbSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_HB_SYSTEM_GAIN 0x28C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbSystemGain : 9; //hb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccHbSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_SYSTEM_GAIN 0x290 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbSystemGain : 9; //ib system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_ACI_SYSTEM_GAIN 0x294 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accAciSystemGain : 9; //aci system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccAciSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_CCA_SYSTEM_GAIN 0x298 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accCcaSystemGain : 9; //cca system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccCcaSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_DET_SYSTEM_GAIN 0x29C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetSystemGain : 9; //det system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccDetSystemGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_DIGITAL_GAIN 0x2A0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbDigitalGain : 9; //bb digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_HB_DIGITAL_GAIN 0x2A4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbDigitalGain : 9; //hb digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccHbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_DIGITAL_GAIN 0x2A8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbDigitalGain : 9; //ib digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_DET_DIGITAL_GAIN 0x2AC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetDigitalGain : 9; //det digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccDetDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_BOF 0x2B0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbBof : 9; //bb backoff accelerator calculation result in 1/2 dB pre bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_TOTAL_DIGITAL_GAIN 0x2B4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbTotalDigitalGain : 9; //bb_total_digital_gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbTotalDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_DIGITAL_BOF 0x2B8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbDigitalBof : 9; //bb_digital_bof accelerator calculation result in 1/2 dB post bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbDigitalBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_HB_BOF 0x2BC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbBof : 9; //hb backoff accelerator calculation result in 1/2 dB pre bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccHbBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_HB_TOTAL_DIGITAL_GAIN 0x2C0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbTotalDigitalGain : 9; //hb_total_digital_gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccHbTotalDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_HB_DIGITAL_BOF 0x2C4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbDigitalBof : 9; //hb_digital_bof accelerator calculation result in 1/2 dB post bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccHbDigitalBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_BOF 0x2C8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbBof : 9; //ib backoff accelerator calculation result in 1/2 dB pre ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_TOTAL_DIGITAL_GAIN 0x2CC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbTotalDigitalGain : 9; //sum of ib digital gain compunents: agc acceleration, pm and hw (bw compensation), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbTotalDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_DIGITAL_BOF 0x2D0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbDigitalBof : 9; //ib_digital_bof accelerator calculation result in 1/2 dB post ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbDigitalBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_DET_BOF 0x2D4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetBof : 9; //det backoff accelerator calculation result in 1/2 dB pre ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccDetBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_DET_TOTAL_DIGITAL_GAIN 0x2D8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetTotalDigitalGain : 9; //sum of det digital gain compunents: agc acceleration, pm and hw (bw compensation), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccDetTotalDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_ACC_DET_DIGITAL_BOF 0x2DC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetDigitalBof : 9; //det_digital_bof accelerator calculation result in 1/2 dB post ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccDetDigitalBof_u;

/*REG_B0_PHY_AGC_ANT1_ACC_DC_OFFSET_I 0x2E0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDcOffsetI : 14; //chosen dc Q offset according to bw,pgc1_index,lna_index, reset value: 0x0, access type: ROS
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1AccDcOffsetI_u;

/*REG_B0_PHY_AGC_ANT1_ACC_DC_OFFSET_Q 0x2E4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDcOffsetQ : 14; //chosen dc I offset according to bw,pgc1_index,lna_index, reset value: 0x0, access type: ROS
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1AccDcOffsetQ_u;

/*REG_B0_PHY_AGC_ANT1_PM_AGC_RAMS_RM 0x2E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAgcTableRm : 3; //agc_gsp_table_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyAgcAnt1PmAgcRamsRm_u;

/*REG_B0_PHY_AGC_ANT1_ACC_GAIN_VALUES 0x2EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accLnaIndex : 3; //calculated lna_index, reset value: 0x0, access type: RO
		uint32 accSelS2DRx : 1; //calculated sel_s2d_rx, reset value: 0x0, access type: RO
		uint32 accPgc1Index : 4; //calculated pgc1_index, reset value: 0x0, access type: RO
		uint32 accRxFilter : 6; //calculated rx_filter tuning word, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyAgcAnt1AccGainValues_u;

/*REG_B0_PHY_AGC_ANT1_PM_SHORT_HEADER 0x2F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmShort1Header : 2; //short1_header upper 2 bits of fcsi short 1 word, reset value: 0x0, access type: RW
		uint32 pmShort3HeaderMode1 : 2; //index which is written to rfic by short 3 for step1 env & signal saturated, reset value: 0x1, access type: RW
		uint32 pmShort3HeaderMode2 : 2; //index which is written to rfic by short 3 for step1 env only saturated, reset value: 0x2, access type: RW
		uint32 pmShort3HeaderMode3 : 2; //index which is written to rfic by short 3 for step1 signal only saturated, reset value: 0x3, access type: RW
		uint32 pmShort3SupportEn : 1; //rfic support short3 type access, reset value: 0x0, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmShortHeader_u;

/*REG_B0_PHY_AGC_ANT1_PM_FCSI_ADDRESS 0x2F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmShort1Address : 7; //short1_address, reset value: 0x1, access type: RW
		uint32 reserved0 : 1;
		uint32 pmShort3Address : 7; //short3_address, reset value: 0x3, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegB0PhyAgcAnt1PmFcsiAddress_u;

/*REG_B0_PHY_AGC_ANT1_ACC_FCSI_VALUES 0x2F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accFcsiData : 16; //data which is sent to rfic via fcsi, reset value: 0x0, access type: RO
		uint32 accFcsiAddr : 7; //address which is sent to rfic via fcsi, reset value: 0x0, access type: RO
		uint32 reserved0 : 9;
	} bitFields;
} RegB0PhyAgcAnt1AccFcsiValues_u;

/*REG_B0_PHY_AGC_ANT1_ACC_GAIN_ACC_CONTROL 0x2FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accDelayTimer : 16; //read acc_delay_timer counting, 0 means no timer, reset value: 0x0, access type: RO
		uint32 accStmCounter : 5; //read acc_stm_counter counting, 0 means no ongoing acceleration, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 accFcsiBusy : 1; //fcsi_busy, 0 means no fcsi access, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
	} bitFields;
} RegB0PhyAgcAnt1AccGainAccControl_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_CODE_ACC_THR 0x300 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmIbTimerThr : 16; //pm_ib_timer_thr, reset value: 0x0, access type: RW
		uint32 pmIbReleaseThr : 16; //pm_ib_release_thr, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyAgcAnt1PmIbCodeAccThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_CODE_ACC_THR 0x304 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBbTimerThr : 16; //pm_bb_timer_thr, reset value: 0x0, access type: RW
		uint32 pmBbReleaseThr : 16; //pm_bb_release_thr, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyAgcAnt1PmBbCodeAccThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_LONGTERM_RELEASE_THR 0x308 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLongtermReleaseThr : 16; //pm_longterm_release_thr, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1PmLongtermReleaseThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_LONGTERM_THR 0x30C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLongtermThr : 9; //pm_longterm_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmLongtermThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_POWER_FAST_LOW_THR 0x310 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerFastLowThr : 9; //pm_bb_power_fast_low_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbPowerFastLowThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_DELTA_CODE_ACC_THR 0x314 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBbDeltaThr : 9; //pm_bb_delta_thr, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 pmIbDeltaThr : 9; //pm_ib_delta_thr, reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
	} bitFields;
} RegB0PhyAgcAnt1PmDeltaCodeAccThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_POWER_UP_THR 0x318 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerUpThr : 9; //pm_bb_power_up_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbPowerUpThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_POWER_SLOW_LOW_THR 0x31C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerSlowLowThr : 9; //pm_bb_power_slow_low_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbPowerSlowLowThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_POWER_UP_THR 0x320 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerUpThr : 9; //pm_ib_power_up_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbPowerUpThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_POWER_SLOW_LOW_THR 0x324 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerSlowLowThr : 9; //pm_ib_power_slow_low_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbPowerSlowLowThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_SET_CODE_ACC_THR_CTRL 0x328 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSetBbThrCtrl : 1; //set_bb_thr_ctrl: 1 -from pm, 0- from hw accelerator, reset value: 0x0, access type: RW
		uint32 pmSetIbThrCtrl : 1; //set_ib_thr_ctrl: 1 -from pm, 0- from hw accelerator, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB0PhyAgcAnt1PmSetCodeAccThrCtrl_u;

/*REG_B0_PHY_AGC_ANT1_PM_ALGO_CTRL 0x32C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAlgoCtrl : 16; //code acclerator algo ctrl, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyAgcAnt1PmAlgoCtrl_u;

/*REG_B0_PHY_AGC_ANT1_ACC_EVENT_STATUS 0x330 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accCodeAccEventType : 9; //code acc event, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 accCodeAccEventIndication : 1; //code acc event bit wise or, reset value: 0x0, access type: RO
		uint32 reserved1 : 19;
	} bitFields;
} RegB0PhyAgcAnt1AccEventStatus_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_TH_SET_INC_GAP_DB 0x334 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbThSetIncGapDb : 9; //margin to add above measured bb power to calculate energy increase threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbThSetIncGapDb_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_TH_SET_DEC_GAP_DB 0x338 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbThSetDecGapDb : 9; //margin to substract below measured bb power to calculate energy deccrease threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbThSetDecGapDb_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_TH_UP_EXTRA_GAP_DB 0x33C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbThUpExtraGapDb : 9; //margin used inorder to limit enery increase threhold for high bb power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbThUpExtraGapDb_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_POWER_UP_DEF_THR 0x340 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerUpDefThr : 9; //default energy increases bb power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbPowerUpDefThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_BB_POWER_SLOW_LOW_MIN_THR 0x344 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerSlowLowMinThr : 9; //default energy decrease bb power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmBbPowerSlowLowMinThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_TH_SET_INC_GAP_DB 0x348 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbThSetIncGapDb : 9; //margin to add above measured ib power to calculate energy increase threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbThSetIncGapDb_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_TH_SET_DEC_GAP_DB 0x34C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbThSetDecGapDb : 9; //margin to substract below measured ib power to calculate energy deccrease threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbThSetDecGapDb_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_TH_UP_EXTRA_GAP_DB 0x350 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbThUpExtraGapDb : 9; //margin used inorder to limit enery increase threhold for high ib power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbThUpExtraGapDb_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_POWER_UP_DEF_THR 0x354 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerUpDefThr : 9; //default energy increases ib power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbPowerUpDefThr_u;

/*REG_B0_PHY_AGC_ANT1_PM_IB_POWER_SLOW_LOW_MIN_THR 0x358 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerSlowLowMinThr : 9; //default energy decrease ib power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmIbPowerSlowLowMinThr_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_POWER_UP_THR 0x35C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbPowerUpThr : 9; //bb energy increase threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbPowerUpThr_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BB_POWER_SLOW_LOW_THR 0x360 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbPowerSlowLowThr : 9; //bb energy deccrease threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccBbPowerSlowLowThr_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_POWER_UP_THR 0x364 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbPowerUpThr : 9; //ib energy increase threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbPowerUpThr_u;

/*REG_B0_PHY_AGC_ANT1_ACC_IB_POWER_SLOW_LOW_THR 0x368 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbPowerSlowLowThr : 9; //ib energy deccrease threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1AccIbPowerSlowLowThr_u;

/*REG_B0_PHY_AGC_ANT1_CALC_AGC_GAIN_WORD 0x36C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcTableGo : 1; //trigger agc gain accleration, reset value: 0x0, access type: WO
		uint32 reserved0 : 3;
		uint32 calcSetMaxGain : 1; //calc_set_max_gain, reset value: 0x0, access type: RW
		uint32 calcSetStep1Gain : 1; //calc_set_step1_gain, reset value: 0x0, access type: RW
		uint32 calcNewLna : 1; //calc_new_lna, reset value: 0x0, access type: RW
		uint32 calcNewPgc1 : 1; //calc_new_pgc1, reset value: 0x0, access type: RW
		uint32 calcNewBbDigitalGain : 1; //calc_new_bb_digital_gain after difi2, reset value: 0x0, access type: RW
		uint32 calcNewHbDigitalGain : 1; //calc_new_hb_digital_gain after pre filter, reset value: 0x0, access type: RW
		uint32 calcNewIbDigitalGain : 1; //calc_new_ib_digital_gain after channel filter, reset value: 0x0, access type: RW
		uint32 calcNewDetDigitalGain : 1; //calc_new_det_digital_gain after band select for detector, reset value: 0x0, access type: RW
		uint32 calcNewDcValues : 1; //calc_new_dc_values offset after difi2, reset value: 0x0, access type: RW
		uint32 calcNewBlockerType : 1; //calc new blocker type, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 calcNoRfAccess : 1; //calc new gain without rf access, reset value: 0x0, access type: RW
		uint32 reserved2 : 16;
	} bitFields;
} RegB0PhyAgcAnt1CalcAgcGainWord_u;

/*REG_B0_PHY_AGC_ANT1_CALC_AGC_STM_CLEAR_CONTROL 0x370 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcClearAgcTimers : 1; //clear agc timers in code acceleator stm, reset value: 0x0, access type: WO
		uint32 calcClearAgcEventType : 1; //clea agc event in code accelerator stm, reset value: 0x0, access type: WO
		uint32 calcClearAgcMaskOp : 1; //disable code accelerator, reset value: 0x0, access type: WO
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyAgcAnt1CalcAgcStmClearControl_u;

/*REG_B0_PHY_AGC_ANT1_CALC_ACC_AUTO_CLOSE_MODE 0x374 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcAccAutoCloseMode : 1; //enables code acceleration, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1CalcAccAutoCloseMode_u;

/*REG_B0_PHY_AGC_ANT1_CALC_POWER_THR_ACC_GO 0x378 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcBbPowerThrAccGo : 1; //calc_bb_power_thr_acc_go, reset value: 0x0, access type: WO
		uint32 calcIbPowerThrAccGo : 1; //calc_ib_power_thr_acc_go, reset value: 0x0, access type: WO
		uint32 reserved0 : 30;
	} bitFields;
} RegB0PhyAgcAnt1CalcPowerThrAccGo_u;

/*REG_B0_PHY_AGC_ANT1_CALC_AGC_GAIN_CANCEL 0x37C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcAgcGainCancel : 1; //cancels gain acceleration timer and cancels table go, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1CalcAgcGainCancel_u;

/*REG_B0_PHY_AGC_ANT1_DISABLE_PERIPHERALS 0x380 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 disablePeripherals : 1; //disable_peripherals, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyAgcAnt1DisablePeripherals_u;

/*REG_B0_PHY_AGC_ANT1_AGC_STM_RDBACK 0x384 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 agcStmRdback : 6; //agc_stm_rdback, reset value: 0x0, access type: RO
		uint32 reserved0 : 26;
	} bitFields;
} RegB0PhyAgcAnt1AgcStmRdback_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_BB_DIGITAL_GAIN 0x388 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccBbDigitalGain : 9; //max limit for bb digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxLimitAccBbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_BB_DIGITAL_GAIN 0x38C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccBbDigitalGain : 9; //min limit for bb digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMinLimitAccBbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_HB_DIGITAL_GAIN 0x390 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccHbDigitalGain : 9; //max limit for hb digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxLimitAccHbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_HB_DIGITAL_GAIN 0x394 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccHbDigitalGain : 9; //min limit for hb digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMinLimitAccHbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_IB_DIGITAL_GAIN 0x398 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccIbDigitalGain : 9; //max limit for ib digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxLimitAccIbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_IB_DIGITAL_GAIN 0x39C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccIbDigitalGain : 9; //min limit for ib digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMinLimitAccIbDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MAX_LIMIT_ACC_DET_DIGITAL_GAIN 0x3A0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccDetDigitalGain : 9; //max limit for det digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMaxLimitAccDetDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_MIN_LIMIT_ACC_DET_DIGITAL_GAIN 0x3A4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccDetDigitalGain : 9; //min limit for det digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB0PhyAgcAnt1PmMinLimitAccDetDigitalGain_u;

/*REG_B0_PHY_AGC_ANT1_PM_BS_ABS_TH_B0_B4 0x3A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsAbsThB0 : 8; //absolut threshold for for blocker in 1 db resolution for band 0, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB1 : 8; //absolut threshold for for blocker in 1 db resolution for band 1, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB2 : 8; //absolut threshold for for blocker in 1 db resolution for band 2, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB3 : 8; //absolut threshold for for blocker in 1 db resolution for band 3, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyAgcAnt1PmBsAbsThB0B4_u;

/*REG_B0_PHY_AGC_ANT1_PM_BS_ABS_TH_B5_B7 0x3AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsAbsThB4 : 8; //absolut threshold for for blocker in 1 db resolution for band 4, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB5 : 8; //absolut threshold for for blocker in 1 db resolution for band 5, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB6 : 8; //absolut threshold for for blocker in 1 db resolution for band 6, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB7 : 8; //absolut threshold for for blocker in 1 db resolution for band 7, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyAgcAnt1PmBsAbsThB5B7_u;

/*REG_B0_PHY_AGC_ANT1_PM_BS_OFF_TH_B0_B4 0x3B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsOffThB0 : 8; //relative threshold for for blocker in 1 db resolution for band 0, reset value: 0x0, access type: RW
		uint32 pmBsOffThB1 : 8; //relative threshold for for blocker in 1 db resolution for band 1, reset value: 0x0, access type: RW
		uint32 pmBsOffThB2 : 8; //relative threshold for for blocker in 1 db resolution for band 2, reset value: 0x0, access type: RW
		uint32 pmBsOffThB3 : 8; //relative threshold for for blocker in 1 db resolution for band 3, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyAgcAnt1PmBsOffThB0B4_u;

/*REG_B0_PHY_AGC_ANT1_PM_BS_OFF_TH_B5_B7 0x3B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsOffThB4 : 8; //relative threshold for for blocker in 1 db resolution for band 4, reset value: 0x0, access type: RW
		uint32 pmBsOffThB5 : 8; //relative threshold for for blocker in 1 db resolution for band 5, reset value: 0x0, access type: RW
		uint32 pmBsOffThB6 : 8; //relative threshold for for blocker in 1 db resolution for band 6, reset value: 0x0, access type: RW
		uint32 pmBsOffThB7 : 8; //relative threshold for for blocker in 1 db resolution for band 7, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyAgcAnt1PmBsOffThB5B7_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BLOCKER_MAP 0x3B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accAbsBlockerMap : 16; //map of absolute threshold check, reset value: 0x0, access type: RO
		uint32 accThBlockerMap : 16; //map of relative threshold check, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyAgcAnt1AccBlockerMap_u;

/*REG_B0_PHY_AGC_ANT1_ACC_MAX_BLOCKER_POWER 0x3BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accMaxBlockerLsbPower : 9; //max blocker power in lsb side in 1/2 db resolution, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 accMaxBlockerUsbPower : 9; //max blocker power in usb side in 1/2 db resolution, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
	} bitFields;
} RegB0PhyAgcAnt1AccMaxBlockerPower_u;

/*REG_B0_PHY_AGC_ANT1_BLOCKER_CONTROL 0x3C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBlockerType : 2; //pm blocker type, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 accBlockerType : 2; //selected blocker type, reset value: 0x0, access type: RO
		uint32 reserved1 : 26;
	} bitFields;
} RegB0PhyAgcAnt1BlockerControl_u;

/*REG_B0_PHY_AGC_ANT1_PM_BLOCKER_TH 0x3C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsAdjAltTh : 8; //threshold for adj alt between LSB and USB in 1 db, reset value: 0x0, access type: RW
		uint32 pmEnvAltTh : 8; //threshold for alt on env, reset value: 0x0, access type: RW
		uint32 pmEnvSigAltTh : 8; //threshold for alt on env compare to sig, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB0PhyAgcAnt1PmBlockerTh_u;

/*REG_B0_PHY_AGC_ANT1_ACC_OFFSET_BS0_B4 0x3C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accOffsetBs0 : 7; //offset to band select in 1 db resolution for band0, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 accOffsetBs1 : 7; //offset to band select in 1 db resolution for band1, reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
		uint32 accOffsetBs2 : 7; //offset to band select in 1 db resolution for band2, reset value: 0x0, access type: RO
		uint32 reserved2 : 1;
		uint32 accOffsetBs3 : 7; //offset to band select in 1 db resolution for band3, reset value: 0x0, access type: RO
		uint32 reserved3 : 1;
	} bitFields;
} RegB0PhyAgcAnt1AccOffsetBs0B4_u;

/*REG_B0_PHY_AGC_ANT1_ACC_OFFSET_BS4_B7 0x3CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accOffsetBs4 : 7; //offset to band select in 1 db resolution for band4, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 accOffsetBs5 : 7; //offset to band select in 1 db resolution for band5, reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
		uint32 accOffsetBs6 : 7; //offset to band select in 1 db resolution for band6, reset value: 0x0, access type: RO
		uint32 reserved2 : 1;
		uint32 accOffsetBs7 : 7; //offset to band select in 1 db resolution for band7, reset value: 0x0, access type: RO
		uint32 reserved3 : 1;
	} bitFields;
} RegB0PhyAgcAnt1AccOffsetBs4B7_u;

/*REG_B0_PHY_AGC_ANT1_PM_ALGO_CTRL_SEL 0x3D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAlgoCtrlSelIn0 : 3; //select source in0: 0-rf, 1-fb, 2-bb, 3-hb, 4-ib, 5-aci, reset value: 0x2, access type: RW
		uint32 reserved0 : 1;
		uint32 pmAlgoCtrlSelIn1 : 3; //select source in1: 0-rf, 1-fb, 2-bb, 3-hb, 4-ib, 5-aci, reset value: 0x3, access type: RW
		uint32 reserved1 : 25;
	} bitFields;
} RegB0PhyAgcAnt1PmAlgoCtrlSel_u;

/*REG_B0_PHY_AGC_ANT1_ACC_BLOCKER_ADDR 0x3D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accLsbBlockerAddr : 7; //lsb blocker address, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 accUsbBlockerAddr : 7; //usb blocker address, reset value: 0x0, access type: RO
		uint32 reserved1 : 17;
	} bitFields;
} RegB0PhyAgcAnt1AccBlockerAddr_u;



#endif // _B0_PHY_AGC_ANT1_REGS_H_
