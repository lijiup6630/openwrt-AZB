
/***********************************************************************************
File:				B1HobPacDelRegs.h
Module:				b1HobPacDel
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:11:49
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_HOB_PAC_DEL_REGS_H_
#define _B1_HOB_PAC_DEL_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_HOB_PAC_DEL_BASE_ADDRESS                             MEMORY_MAP_UNIT_10503_BASE_ADDRESS
#define	REG_B1_HOB_PAC_DEL_HOB_DEL_COUNTER0_EVENT         (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x0)
#define	REG_B1_HOB_PAC_DEL_HOB_DEL_COUNTER1_EVENT         (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x4)
#define	REG_B1_HOB_PAC_DEL_NOP_WAIT_EVENT_VECTOR          (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x8)
#define	REG_B1_HOB_PAC_DEL_TX_DATA_STRUCTURE_ADDR         (B1_HOB_PAC_DEL_BASE_ADDRESS + 0xC)
#define	REG_B1_HOB_PAC_DEL_DEL2GENRISC_START_TX_INT       (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x10)
#define	REG_B1_HOB_PAC_DEL_PRBS_DATA                      (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x18)
#define	REG_B1_HOB_PAC_DEL_PHY_MODE                       (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x1C)
#define	REG_B1_HOB_PAC_DEL_BF_TX_MAX_THRESHOLD_TIMER      (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x20)
#define	REG_B1_HOB_PAC_DEL_ZLD_VAL                        (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x24)
#define	REG_B1_HOB_PAC_DEL_DEL_TXC_RESP_TIMEOUT_VALUE     (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x28)
#define	REG_B1_HOB_PAC_DEL_RX_LAST_MPDU_IN_PTR            (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x2C)
#define	REG_B1_HOB_PAC_DEL_CTR_DATA                       (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x34)
#define	REG_B1_HOB_PAC_DEL_LOGGER_HOB_INFO                (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x38)
#define	REG_B1_HOB_PAC_DEL_HT_DELIMITER_DATA_IN           (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x3C)
#define	REG_B1_HOB_PAC_DEL_VHT_DELIMITER_DATA_IN          (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x40)
#define	REG_B1_HOB_PAC_DEL_VHT_EOF_DELIMITER_DATA_IN      (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x44)
#define	REG_B1_HOB_PAC_DEL_DELIMITER_DATA_OUT             (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x48)
#define	REG_B1_HOB_PAC_DEL_DELIA_EVENT_THRESHOLD_TIMER    (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x4C)
#define	REG_B1_HOB_PAC_DEL_TIM_DEL_EVENT_TIMER_EXPIRED    (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x50)
#define	REG_B1_HOB_PAC_DEL_TCR_TXOP_DUR_FROM_MAC          (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x54)
#define	REG_B1_HOB_PAC_DEL_DELIA_TX_MPDU_DUR_FIELD        (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x5C)
#define	REG_B1_HOB_PAC_DEL_PAC_PHY_TX_LENGTH_ZERO         (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x60)
#define	REG_B1_HOB_PAC_DEL_DELIMITER_VALUE_PRE_TX_DATA    (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x64)
#define	REG_B1_HOB_PAC_DEL_NUM_OF_USER_TCRS               (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x68)
#define	REG_B1_HOB_PAC_DEL_NUM_OF_USER_TCR_BYTES          (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x6C)
#define	REG_B1_HOB_PAC_DEL_EXPECTED_RCRS                  (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x70)
#define	REG_B1_HOB_PAC_DEL_NUM_OF_USER_RCR_BYTES          (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x74)
#define	REG_B1_HOB_PAC_DEL_TX_CIR_BUF_BASE_ADDR           (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x78)
#define	REG_B1_HOB_PAC_DEL_REG2HOB_GP0                    (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x7C)
#define	REG_B1_HOB_PAC_DEL_REG2HOB_GP1                    (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x80)
#define	REG_B1_HOB_PAC_DEL_TCR_BASE_ADDR1                 (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x84)
#define	REG_B1_HOB_PAC_DEL_TCR_BASE_ADDR2                 (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x88)
#define	REG_B1_HOB_PAC_DEL_RCR_BASE_ADDR                  (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x8C)
#define	REG_B1_HOB_PAC_DEL_SENDER_MPDU_DURATION           (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x90)
#define	REG_B1_HOB_PAC_DEL_ALL_ONES_PADDING               (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x94)
#define	REG_B1_HOB_PAC_DEL_TCC_CRC                        (B1_HOB_PAC_DEL_BASE_ADDRESS + 0x98)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_HOB_PAC_DEL_HOB_DEL_COUNTER0_EVENT 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hobDelCounter0Event : 12; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB1HobPacDelHobDelCounter0Event_u;

/*REG_B1_HOB_PAC_DEL_HOB_DEL_COUNTER1_EVENT 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hobDelCounter1Event : 12; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB1HobPacDelHobDelCounter1Event_u;

/*REG_B1_HOB_PAC_DEL_NOP_WAIT_EVENT_VECTOR 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 nopWaitEventVector : 22; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 10;
	} bitFields;
} RegB1HobPacDelNopWaitEventVector_u;

/*REG_B1_HOB_PAC_DEL_TX_DATA_STRUCTURE_ADDR 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txDataStructureAddr : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB1HobPacDelTxDataStructureAddr_u;

/*REG_B1_HOB_PAC_DEL_DEL2GENRISC_START_TX_INT 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 del2GenriscStartTxInt : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegB1HobPacDelDel2GenriscStartTxInt_u;

/*REG_B1_HOB_PAC_DEL_PRBS_DATA 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsData : 8; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB1HobPacDelPrbsData_u;

/*REG_B1_HOB_PAC_DEL_PHY_MODE 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhy11AgMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhy11BMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhy11NMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhy11AcMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeSu : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeExSu : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeMuTf : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeMu : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyEhtSu : 1; //no description, reset value: 0x0, access type: RW
		uint32 pacPhyEhtMuTf : 1; //no description, reset value: 0x0, access type: RW
		uint32 pacPhyEhtMu : 1; //no description, reset value: 0x0, access type: RW
		uint32 pacPhyVhtHeEht : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB1HobPacDelPhyMode_u;

/*REG_B1_HOB_PAC_DEL_BF_TX_MAX_THRESHOLD_TIMER 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bfTxMaxThresholdTimer : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegB1HobPacDelBfTxMaxThresholdTimer_u;

/*REG_B1_HOB_PAC_DEL_ZLD_VAL 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 zldVal : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB1HobPacDelZldVal_u;

/*REG_B1_HOB_PAC_DEL_DEL_TXC_RESP_TIMEOUT_VALUE 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delTxcRespTimeoutValue : 13; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 19;
	} bitFields;
} RegB1HobPacDelDelTxcRespTimeoutValue_u;

/*REG_B1_HOB_PAC_DEL_RX_LAST_MPDU_IN_PTR 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxLastMpduInPtr : 25; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
	} bitFields;
} RegB1HobPacDelRxLastMpduInPtr_u;

/*REG_B1_HOB_PAC_DEL_CTR_DATA 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ctrData : 8; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB1HobPacDelCtrData_u;

/*REG_B1_HOB_PAC_DEL_LOGGER_HOB_INFO 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 loggerHobInfo : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1HobPacDelLoggerHobInfo_u;

/*REG_B1_HOB_PAC_DEL_HT_DELIMITER_DATA_IN 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataIn : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1HobPacDelHtDelimiterDataIn_u;

/*REG_B1_HOB_PAC_DEL_VHT_DELIMITER_DATA_IN 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataIn : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1HobPacDelVhtDelimiterDataIn_u;

/*REG_B1_HOB_PAC_DEL_VHT_EOF_DELIMITER_DATA_IN 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataIn : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1HobPacDelVhtEofDelimiterDataIn_u;

/*REG_B1_HOB_PAC_DEL_DELIMITER_DATA_OUT 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataOut : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB1HobPacDelDelimiterDataOut_u;

/*REG_B1_HOB_PAC_DEL_DELIA_EVENT_THRESHOLD_TIMER 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 deliaEventThresholdTimer : 24; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB1HobPacDelDeliaEventThresholdTimer_u;

/*REG_B1_HOB_PAC_DEL_TIM_DEL_EVENT_TIMER_EXPIRED 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 timDelEventTimerExpired : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1HobPacDelTimDelEventTimerExpired_u;

/*REG_B1_HOB_PAC_DEL_TCR_TXOP_DUR_FROM_MAC 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tcrTxopDurFromMac : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1HobPacDelTcrTxopDurFromMac_u;

/*REG_B1_HOB_PAC_DEL_DELIA_TX_MPDU_DUR_FIELD 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txMpduDurField : 16; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1HobPacDelDeliaTxMpduDurField_u;

/*REG_B1_HOB_PAC_DEL_PAC_PHY_TX_LENGTH_ZERO 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhyTxLengthZero : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1HobPacDelPacPhyTxLengthZero_u;

/*REG_B1_HOB_PAC_DEL_DELIMITER_VALUE_PRE_TX_DATA 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterValuePreTxData : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB1HobPacDelDelimiterValuePreTxData_u;

/*REG_B1_HOB_PAC_DEL_NUM_OF_USER_TCRS 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numOfUserTcrs : 8; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB1HobPacDelNumOfUserTcrs_u;

/*REG_B1_HOB_PAC_DEL_NUM_OF_USER_TCR_BYTES 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numOfUserTcrBytes : 12; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB1HobPacDelNumOfUserTcrBytes_u;

/*REG_B1_HOB_PAC_DEL_EXPECTED_RCRS 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 expectedRcrs : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1HobPacDelExpectedRcrs_u;

/*REG_B1_HOB_PAC_DEL_NUM_OF_USER_RCR_BYTES 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numOfUserRcrBytes : 12; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB1HobPacDelNumOfUserRcrBytes_u;

/*REG_B1_HOB_PAC_DEL_TX_CIR_BUF_BASE_ADDR 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txCirBufBaseAddr : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB1HobPacDelTxCirBufBaseAddr_u;

/*REG_B1_HOB_PAC_DEL_REG2HOB_GP0 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reg2HobGp0 : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB1HobPacDelReg2HobGp0_u;

/*REG_B1_HOB_PAC_DEL_REG2HOB_GP1 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reg2HobGp1 : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB1HobPacDelReg2HobGp1_u;

/*REG_B1_HOB_PAC_DEL_TCR_BASE_ADDR1 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tcrBaseAddr2 : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB1HobPacDelTcrBaseAddr1_u;

/*REG_B1_HOB_PAC_DEL_TCR_BASE_ADDR2 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tcrBaseAddr2 : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB1HobPacDelTcrBaseAddr2_u;

/*REG_B1_HOB_PAC_DEL_RCR_BASE_ADDR 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rcrBaseAddr : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB1HobPacDelRcrBaseAddr_u;

/*REG_B1_HOB_PAC_DEL_SENDER_MPDU_DURATION 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 senderMpduDuration : 16; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1HobPacDelSenderMpduDuration_u;

/*REG_B1_HOB_PAC_DEL_ALL_ONES_PADDING 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 allOnesPadding : 32; //no description, reset value: 0xffffffff, access type: RO
	} bitFields;
} RegB1HobPacDelAllOnesPadding_u;

/*REG_B1_HOB_PAC_DEL_TCC_CRC 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tccCrc : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB1HobPacDelTccCrc_u;



#endif // _B1_HOB_PAC_DEL_REGS_H_
