
/***********************************************************************************
File:				B2PacTimRegs.h
Module:				b2PacTim
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:12:24
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B2_PAC_TIM_REGS_H_
#define _B2_PAC_TIM_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B2_PAC_TIM_BASE_ADDRESS                             MEMORY_MAP_UNIT_20013_BASE_ADDRESS
#define	REG_B2_PAC_TIM_ONE_MICRO_PRESCALER                          (B2_PAC_TIM_BASE_ADDRESS + 0x0)
#define	REG_B2_PAC_TIM_EIGHTH_MICRO_PRESCALER                       (B2_PAC_TIM_BASE_ADDRESS + 0x4)
#define	REG_B2_PAC_TIM_TSF_HW_EVENT0                                (B2_PAC_TIM_BASE_ADDRESS + 0x8)
#define	REG_B2_PAC_TIM_TSF_HW_EVENT1                                (B2_PAC_TIM_BASE_ADDRESS + 0xC)
#define	REG_B2_PAC_TIM_TSF_REQ_SWITCH                               (B2_PAC_TIM_BASE_ADDRESS + 0x10)
#define	REG_B2_PAC_TIM_TSF_SW_EVENT2                                (B2_PAC_TIM_BASE_ADDRESS + 0x14)
#define	REG_B2_PAC_TIM_TSF_SW_EVENT3                                (B2_PAC_TIM_BASE_ADDRESS + 0x18)
#define	REG_B2_PAC_TIM_TICK_TIMER                                   (B2_PAC_TIM_BASE_ADDRESS + 0x2C)
#define	REG_B2_PAC_TIM_SLOT_TIMER                                   (B2_PAC_TIM_BASE_ADDRESS + 0x30)
#define	REG_B2_PAC_TIM_TIMER_CONTROL                                (B2_PAC_TIM_BASE_ADDRESS + 0x34)
#define	REG_B2_PAC_TIM_TIMER_CONTROL_RD                             (B2_PAC_TIM_BASE_ADDRESS + 0x38)
#define	REG_B2_PAC_TIM_TICK                                         (B2_PAC_TIM_BASE_ADDRESS + 0x44)
#define	REG_B2_PAC_TIM_SLOT                                         (B2_PAC_TIM_BASE_ADDRESS + 0x48)
#define	REG_B2_PAC_TIM_IFS_TIMER                                    (B2_PAC_TIM_BASE_ADDRESS + 0x50)
#define	REG_B2_PAC_TIM_RESP_TIMER                                   (B2_PAC_TIM_BASE_ADDRESS + 0x54)
#define	REG_B2_PAC_TIM_TSF_TIMER_LOW_WPORT                          (B2_PAC_TIM_BASE_ADDRESS + 0x58)
#define	REG_B2_PAC_TIM_TSF_TIMER_HIGH_WPORT                         (B2_PAC_TIM_BASE_ADDRESS + 0x5C)
#define	REG_B2_PAC_TIM_TSF_TIMER_LOW_RPORT                          (B2_PAC_TIM_BASE_ADDRESS + 0x60)
#define	REG_B2_PAC_TIM_TSF_TIMER_HIGH_RPORT                         (B2_PAC_TIM_BASE_ADDRESS + 0x64)
#define	REG_B2_PAC_TIM_TSF_HW_EVENT2                                (B2_PAC_TIM_BASE_ADDRESS + 0x68)
#define	REG_B2_PAC_TIM_TTL                                          (B2_PAC_TIM_BASE_ADDRESS + 0x6C)
#define	REG_B2_PAC_TIM_QBSS_LOAD_INTEGRATOR_WR                      (B2_PAC_TIM_BASE_ADDRESS + 0x88)
#define	REG_B2_PAC_TIM_QBSS_LOAD_INTEGRATOR_RD                      (B2_PAC_TIM_BASE_ADDRESS + 0x8C)
#define	REG_B2_PAC_TIM_REDUCED_FREQ_CHANGE_LATCHED_TSF_TIMER_LOW    (B2_PAC_TIM_BASE_ADDRESS + 0x90)
#define	REG_B2_PAC_TIM_RX_DUR_TIMER                                 (B2_PAC_TIM_BASE_ADDRESS + 0x98)
#define	REG_B2_PAC_TIM_DELIA_TIMER                                  (B2_PAC_TIM_BASE_ADDRESS + 0x9C)
#define	REG_B2_PAC_TIM_DELIA_MAX_LIMIT_TIMER                        (B2_PAC_TIM_BASE_ADDRESS + 0xA0)
#define	REG_B2_PAC_TIM_TXH_PAUSER_REP_TIMER                         (B2_PAC_TIM_BASE_ADDRESS + 0xA4)
#define	REG_B2_PAC_TIM_TX_NAV_TIMER_CFG_SET_VALUE                   (B2_PAC_TIM_BASE_ADDRESS + 0xB0)
#define	REG_B2_PAC_TIM_TX_NAV_TIMER                                 (B2_PAC_TIM_BASE_ADDRESS + 0xB4)
#define	REG_B2_PAC_TIM_TX_NAV_TIMER_IFS_COMPENSATION                (B2_PAC_TIM_BASE_ADDRESS + 0xB8)
#define	REG_B2_PAC_TIM_TIMER_CONTROL2                               (B2_PAC_TIM_BASE_ADDRESS + 0xBC)
#define	REG_B2_PAC_TIM_QBSS2_LOAD_INTEGRATOR_WR                     (B2_PAC_TIM_BASE_ADDRESS + 0xC0)
#define	REG_B2_PAC_TIM_QBSS2_LOAD_INTEGRATOR_RD                     (B2_PAC_TIM_BASE_ADDRESS + 0xC4)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B2_PAC_TIM_ONE_MICRO_PRESCALER 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 oneMicroPrescaler : 10; //TIM one micro prescaler, reset value: 0x27f, access type: RW
		uint32 reserved0 : 6;
		uint32 oneMicroPrescalerFreqReduced : 10; //TIM one micro prescaler reduced clk, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegB2PacTimOneMicroPrescaler_u;

/*REG_B2_PAC_TIM_EIGHTH_MICRO_PRESCALER 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 eighthMicroPrescaler : 10; //TIM eighth micro prescaler, reset value: 0x4f, access type: RW
		uint32 reserved0 : 6;
		uint32 eighthMicroPrescalerFreqReduced : 10; //TIM eighth micro prescaler reduced clk, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegB2PacTimEighthMicroPrescaler_u;

/*REG_B2_PAC_TIM_TSF_HW_EVENT0 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfHwEvent0Time : 24; //TIM  time, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 tsfHwEvent0HwEnableRd : 1; //TIM  hw enable RD, reset value: 0x0, access type: RO
		uint32 tsfHwEvent0SwEnableRd : 1; //TIM  sw enable RD, reset value: 0x0, access type: RO
		uint32 tsfHwEvent0HwEnableWr : 1; //TIM  hw enable WR, reset value: 0x0, access type: WO
		uint32 tsfHwEvent0SwEnableWr : 1; //TIM  sw enable WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfHwEvent0_u;

/*REG_B2_PAC_TIM_TSF_HW_EVENT1 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfHwEvent1Time : 24; //TIM  time, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 tsfHwEvent1HwEnableRd : 1; //TIM  hw enable RD, reset value: 0x0, access type: RO
		uint32 tsfHwEvent1SwEnableRd : 1; //TIM  sw enable RD, reset value: 0x0, access type: RO
		uint32 tsfHwEvent1HwEnableWr : 1; //TIM  hw enable WR, reset value: 0x0, access type: WO
		uint32 tsfHwEvent1SwEnableWr : 1; //TIM  sw enable WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfHwEvent1_u;

/*REG_B2_PAC_TIM_TSF_REQ_SWITCH 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfReqSwitchTime : 24; //TIM  time, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 tsfReqSwitchHwEnableRd : 1; //TIM  hw enable RD, reset value: 0x0, access type: RO
		uint32 tsfReqSwitchSwEnableRd : 1; //TIM  sw enable RD, reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
		uint32 tsfReqSwitchTo1 : 1; //TIM  to 1, reset value: 0x0, access type: RW
		uint32 tsfReqSwitchHwEnableWr : 1; //TIM  hw enable WR, reset value: 0x0, access type: WO
		uint32 tsfReqSwitchSwEnableWr : 1; //TIM  sw enable WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfReqSwitch_u;

/*REG_B2_PAC_TIM_TSF_SW_EVENT2 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfSwEvent2Time : 24; //TIM  time event 2, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 tsfSwEvent2EnableRd : 1; //TIM  enable event 2 RD, reset value: 0x0, access type: RO
		uint32 tsfSwEvent2EnableWr : 1; //TIM  enable event 2 WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfSwEvent2_u;

/*REG_B2_PAC_TIM_TSF_SW_EVENT3 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfSwEvent3Time : 24; //TIM  time event 3, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 tsfSwEvent3EnableRd : 1; //TIM  enable event 3 RD, reset value: 0x0, access type: RO
		uint32 tsfSwEvent3EnableWr : 1; //TIM  enable event 3 WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfSwEvent3_u;

/*REG_B2_PAC_TIM_TICK_TIMER 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tickTimerPeriod : 16; //TIM  period, reset value: 0xffff, access type: RW
		uint32 reserved0 : 15;
		uint32 tickTimerEnable : 1; //TIM  enable, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PacTimTickTimer_u;

/*REG_B2_PAC_TIM_SLOT_TIMER 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 16;
		uint32 slotTimerPeriod : 8; //Slot period, reset value: 0x8, access type: RW
		uint32 reserved1 : 8;
	} bitFields;
} RegB2PacTimSlotTimer_u;

/*REG_B2_PAC_TIM_TIMER_CONTROL 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 tsfEnable : 1; //TIM  tsf enable, reset value: 0x0, access type: RW
		uint32 tsfNudgeWr : 1; //TIM  tsf nudge WR, reset value: 0x0, access type: WO
		uint32 reserved1 : 1;
		uint32 tsfNudgeRd : 1; //TIM  tsf nudge RD, reset value: 0x0, access type: RO
		uint32 integrateTxTimeToQbss : 1; //Integrate Tx time to QBSS load integrator, reset value: 0x0, access type: RW
		uint32 integrateNavTimeToQbss : 1; //Integrate NAV time to QBSS load integrator, reset value: 0x0, access type: RW
		uint32 integrateCcaTimeToQbss : 1; //Integrate CCA time to QBSS load integrator, reset value: 0x0, access type: RW
		uint32 tsfAdj : 9; //TIM  tsf adj, reset value: 0x0, access type: RW
		uint32 reserved2 : 7;
		uint32 tsfSwEvent0Wr : 1; //TIM  tsf sw event0 WR, reset value: 0x0, access type: WO
		uint32 tsfSwEvent1Wr : 1; //TIM  tsf sw event1 WR, reset value: 0x0, access type: WO
		uint32 tsfSwEvent2Wr : 1; //TIM  tsf sw event2 WR, reset value: 0x0, access type: WO
		uint32 tsfSwEvent3Wr : 1; //TIM  tsf sw event3 WR, reset value: 0x0, access type: WO
		uint32 tsfSwEvent4Wr : 1; //TIM  tsf sw event4 WR, reset value: 0x0, access type: WO
		uint32 tsfSwEvent5Wr : 1; //TIM  tsf sw event5 WR, reset value: 0x0, access type: WO
		uint32 reserved3 : 2;
	} bitFields;
} RegB2PacTimTimerControl_u;

/*REG_B2_PAC_TIM_TIMER_CONTROL_RD 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 24;
		uint32 tsfSwEvent0Rd : 1; //TIM  tsf sw event0 RD, reset value: 0x0, access type: RO
		uint32 tsfSwEvent1Rd : 1; //TIM  tsf sw event1 RD, reset value: 0x0, access type: RO
		uint32 tsfSwEvent2Rd : 1; //TIM  tsf sw event2 RD, reset value: 0x0, access type: RO
		uint32 tsfSwEvent3Rd : 1; //TIM  tsf sw event3 RD, reset value: 0x0, access type: RO
		uint32 tsfSwEvent4Rd : 1; //TIM  tsf sw event4 RD, reset value: 0x0, access type: RO
		uint32 tsfSwEvent5Rd : 1; //TIM  tsf sw event5 RD, reset value: 0x0, access type: RO
		uint32 reserved1 : 2;
	} bitFields;
} RegB2PacTimTimerControlRd_u;

/*REG_B2_PAC_TIM_TICK 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 timerTick : 16; //TIM  timer, reset value: 0xffff, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PacTimTick_u;

/*REG_B2_PAC_TIM_SLOT 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 16;
		uint32 slotTimer : 8; //Slot timer, reset value: 0x8, access type: RO
		uint32 reserved1 : 8;
	} bitFields;
} RegB2PacTimSlot_u;

/*REG_B2_PAC_TIM_IFS_TIMER 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ifsTimer : 19; //TIM  ifs timer, reset value: 0x0, access type: RO
		uint32 reserved0 : 13;
	} bitFields;
} RegB2PacTimIfsTimer_u;

/*REG_B2_PAC_TIM_RESP_TIMER 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 respTimer : 13; //TIM  resp timer, reset value: 0x0, access type: RO
		uint32 reserved0 : 19;
	} bitFields;
} RegB2PacTimRespTimer_u;

/*REG_B2_PAC_TIM_TSF_TIMER_LOW_WPORT 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfTimerLowWport : 32; //TIM  tsf timer low WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfTimerLowWport_u;

/*REG_B2_PAC_TIM_TSF_TIMER_HIGH_WPORT 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfTimerHighWport : 32; //TIM  tsf timer high WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfTimerHighWport_u;

/*REG_B2_PAC_TIM_TSF_TIMER_LOW_RPORT 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfTimerLowRport : 32; //TIM  tsf timer low RD, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PacTimTsfTimerLowRport_u;

/*REG_B2_PAC_TIM_TSF_TIMER_HIGH_RPORT 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfTimerHighRport : 32; //TIM  tsf timer high RD, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PacTimTsfTimerHighRport_u;

/*REG_B2_PAC_TIM_TSF_HW_EVENT2 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tsfHwEvent2 : 24; //TSF HW event 2, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 tsfHwEvent2HwEnableRd : 1; //TSF HW event 2 enable RD, reset value: 0x0, access type: RO
		uint32 tsfHwEvent2SwEnableRd : 1; //TSF SW event 2 enable RD, reset value: 0x0, access type: RO
		uint32 tsfHwEvent2HwEnableWr : 1; //TSF HW event 2 enable WR, reset value: 0x0, access type: WO
		uint32 tsfHwEvent2SwEnableWr : 1; //TSF SW event 2 enable WR, reset value: 0x0, access type: WO
	} bitFields;
} RegB2PacTimTsfHwEvent2_u;

/*REG_B2_PAC_TIM_TTL 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ttl : 7; //TTL value - Quantized to 256K uS, reset value: 0x0, access type: RO
		uint32 reserved0 : 25;
	} bitFields;
} RegB2PacTimTtl_u;

/*REG_B2_PAC_TIM_QBSS_LOAD_INTEGRATOR_WR 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 qbssLoadIntegratorWr : 28; //QBSS load integrator WR, reset value: 0x0, access type: WO
		uint32 reserved0 : 4;
	} bitFields;
} RegB2PacTimQbssLoadIntegratorWr_u;

/*REG_B2_PAC_TIM_QBSS_LOAD_INTEGRATOR_RD 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 qbssLoadIntegratorRd : 28; //QBSS load integrator RD, reset value: 0x0, access type: RO
		uint32 reserved0 : 4;
	} bitFields;
} RegB2PacTimQbssLoadIntegratorRd_u;

/*REG_B2_PAC_TIM_REDUCED_FREQ_CHANGE_LATCHED_TSF_TIMER_LOW 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reducedFreqChangeLatchedTsfTimerLow : 32; //reduced_freq_change_latched_tsf_timer_low, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PacTimReducedFreqChangeLatchedTsfTimerLow_u;

/*REG_B2_PAC_TIM_RX_DUR_TIMER 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxDurTimer : 8; //rx duration timer, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB2PacTimRxDurTimer_u;

/*REG_B2_PAC_TIM_DELIA_TIMER 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 deliaTimer : 24; //delia timer, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB2PacTimDeliaTimer_u;

/*REG_B2_PAC_TIM_DELIA_MAX_LIMIT_TIMER 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 deliaMaxLimitTimer : 24; //delia max limit timer, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB2PacTimDeliaMaxLimitTimer_u;

/*REG_B2_PAC_TIM_TXH_PAUSER_REP_TIMER 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserRepTimer : 16; //TxH Pauser repetition timer, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PacTimTxhPauserRepTimer_u;

/*REG_B2_PAC_TIM_TX_NAV_TIMER_CFG_SET_VALUE 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txNavTimerCfgSetValue : 18; //Setting Tx NAV timer value, reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PacTimTxNavTimerCfgSetValue_u;

/*REG_B2_PAC_TIM_TX_NAV_TIMER 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txNavTimer : 18; //Tx NAV timer, reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PacTimTxNavTimer_u;

/*REG_B2_PAC_TIM_TX_NAV_TIMER_IFS_COMPENSATION 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txNavIfsCompensation : 16; //Tx NAV timer IFS compensation [resolution in cycles], reset value: 0x0, access type: RW
		uint32 reducedFreqTxNavIfsCompensation : 16; //Tx NAV timer IFS compensation in mode of reduced frequency [resolution in cycles], reset value: 0x0, access type: RW
	} bitFields;
} RegB2PacTimTxNavTimerIfsCompensation_u;

/*REG_B2_PAC_TIM_TIMER_CONTROL2 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 integrateTxTimeToQbss2 : 1; //Integrate Tx time to QBSS load integrator, reset value: 0x0, access type: RW
		uint32 integrateNavTimeToQbss2 : 1; //Integrate NAV time to QBSS load integrator, reset value: 0x0, access type: RW
		uint32 integrateCcaTimeToQbss2 : 1; //Integrate CCA time to QBSS load integrator, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB2PacTimTimerControl2_u;

/*REG_B2_PAC_TIM_QBSS2_LOAD_INTEGRATOR_WR 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 qbss2LoadIntegratorWr : 28; //QBSS load integrator WR, reset value: 0x0, access type: WO
		uint32 reserved0 : 4;
	} bitFields;
} RegB2PacTimQbss2LoadIntegratorWr_u;

/*REG_B2_PAC_TIM_QBSS2_LOAD_INTEGRATOR_RD 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 qbss2LoadIntegratorRd : 28; //QBSS load integrator RD, reset value: 0x0, access type: RO
		uint32 reserved0 : 4;
	} bitFields;
} RegB2PacTimQbss2LoadIntegratorRd_u;



#endif // _B2_PAC_TIM_REGS_H_
