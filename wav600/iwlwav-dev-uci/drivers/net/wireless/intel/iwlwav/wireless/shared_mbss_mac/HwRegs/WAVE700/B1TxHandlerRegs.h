
/***********************************************************************************
File:				B1TxHandlerRegs.h
Module:				b1TxHandler
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:12:09
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_TX_HANDLER_REGS_H_
#define _B1_TX_HANDLER_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_TX_HANDLER_BASE_ADDRESS                             MEMORY_MAP_UNIT_10023_BASE_ADDRESS
#define	REG_B1_TX_HANDLER_LAST_VAP_WINNER_AC_ID0TO3           (B1_TX_HANDLER_BASE_ADDRESS + 0x18)
#define	REG_B1_TX_HANDLER_LAST_VAP_WINNER_AC_ID4TO7           (B1_TX_HANDLER_BASE_ADDRESS + 0x1C)
#define	REG_B1_TX_HANDLER_AC_ID_PRIORITY                      (B1_TX_HANDLER_BASE_ADDRESS + 0x20)
#define	REG_B1_TX_HANDLER_WLAN_RETRY_CTR_LIMIT                (B1_TX_HANDLER_BASE_ADDRESS + 0x24)
#define	REG_B1_TX_HANDLER_AC_EXT_CW_REMAPPING                 (B1_TX_HANDLER_BASE_ADDRESS + 0x28)
#define	REG_B1_TX_HANDLER_LCG_RAND_FUNC_SEED                  (B1_TX_HANDLER_BASE_ADDRESS + 0x2C)
#define	REG_B1_TX_HANDLER_LCG_RAND_FUNC_SHIFT_NUM             (B1_TX_HANDLER_BASE_ADDRESS + 0x30)
#define	REG_B1_TX_HANDLER_TXH_MAP_CONTROL                     (B1_TX_HANDLER_BASE_ADDRESS + 0x34)
#define	REG_B1_TX_HANDLER_TX_REQ_VAP_AC_BE                    (B1_TX_HANDLER_BASE_ADDRESS + 0x40)
#define	REG_B1_TX_HANDLER_TX_REQ_VAP_AC_BK                    (B1_TX_HANDLER_BASE_ADDRESS + 0x44)
#define	REG_B1_TX_HANDLER_TX_REQ_VAP_AC_VI                    (B1_TX_HANDLER_BASE_ADDRESS + 0x48)
#define	REG_B1_TX_HANDLER_TX_REQ_VAP_AC_VO                    (B1_TX_HANDLER_BASE_ADDRESS + 0x4C)
#define	REG_B1_TX_HANDLER_TX_REQ_VAP_AC_GPLP                  (B1_TX_HANDLER_BASE_ADDRESS + 0x50)
#define	REG_B1_TX_HANDLER_TX_REQ_VAP_AC_GPHP                  (B1_TX_HANDLER_BASE_ADDRESS + 0x54)
#define	REG_B1_TX_HANDLER_TX_REQ_VAP_AC_BEACON                (B1_TX_HANDLER_BASE_ADDRESS + 0x58)
#define	REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_BE                 (B1_TX_HANDLER_BASE_ADDRESS + 0x5C)
#define	REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_BK                 (B1_TX_HANDLER_BASE_ADDRESS + 0x60)
#define	REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_VI                 (B1_TX_HANDLER_BASE_ADDRESS + 0x64)
#define	REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_VO                 (B1_TX_HANDLER_BASE_ADDRESS + 0x68)
#define	REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_GPLP               (B1_TX_HANDLER_BASE_ADDRESS + 0x6C)
#define	REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_GPHP               (B1_TX_HANDLER_BASE_ADDRESS + 0x70)
#define	REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_BEACON             (B1_TX_HANDLER_BASE_ADDRESS + 0x74)
#define	REG_B1_TX_HANDLER_WINNER_RESULT                       (B1_TX_HANDLER_BASE_ADDRESS + 0x7C)
#define	REG_B1_TX_HANDLER_UNFREEZE_REPORT_SET                 (B1_TX_HANDLER_BASE_ADDRESS + 0x80)
#define	REG_B1_TX_HANDLER_UNFREEZE_REPORT                     (B1_TX_HANDLER_BASE_ADDRESS + 0x84)
#define	REG_B1_TX_HANDLER_TXH_MAP_DBG                         (B1_TX_HANDLER_BASE_ADDRESS + 0x88)
#define	REG_B1_TX_HANDLER_RECIPE_PTR_AC_ID0TO3                (B1_TX_HANDLER_BASE_ADDRESS + 0x8C)
#define	REG_B1_TX_HANDLER_RECIPE_PTR_AC_GPLP                  (B1_TX_HANDLER_BASE_ADDRESS + 0x90)
#define	REG_B1_TX_HANDLER_RECIPE_PTR_AC_GPHP                  (B1_TX_HANDLER_BASE_ADDRESS + 0x94)
#define	REG_B1_TX_HANDLER_RECIPE_PTR_AC_BEACON                (B1_TX_HANDLER_BASE_ADDRESS + 0x98)
#define	REG_B1_TX_HANDLER_TXH_NTD_TX_REQ_PARAMS               (B1_TX_HANDLER_BASE_ADDRESS + 0x9C)
#define	REG_B1_TX_HANDLER_TXH_EPSILON_MICRO_PRESCALER_NUM     (B1_TX_HANDLER_BASE_ADDRESS + 0xA0)
#define	REG_B1_TX_HANDLER_TXH_EPSILON_MICRO_NUM               (B1_TX_HANDLER_BASE_ADDRESS + 0xA4)
#define	REG_B1_TX_HANDLER_TXH_LOGGER                          (B1_TX_HANDLER_BASE_ADDRESS + 0xA8)
#define	REG_B1_TX_HANDLER_TXH_LOGGER_ACTIVE                   (B1_TX_HANDLER_BASE_ADDRESS + 0xAC)
#define	REG_B1_TX_HANDLER_DEBUG_MU_EDCA_TIMER_RESOLUTION      (B1_TX_HANDLER_BASE_ADDRESS + 0xB0)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_REP_CYCLE_COUNT          (B1_TX_HANDLER_BASE_ADDRESS + 0x104)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_REP_DURATION             (B1_TX_HANDLER_BASE_ADDRESS + 0x108)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_STATUS                   (B1_TX_HANDLER_BASE_ADDRESS + 0x10C)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_BE                (B1_TX_HANDLER_BASE_ADDRESS + 0x110)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_BK                (B1_TX_HANDLER_BASE_ADDRESS + 0x114)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_VI                (B1_TX_HANDLER_BASE_ADDRESS + 0x118)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_VO                (B1_TX_HANDLER_BASE_ADDRESS + 0x11C)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_GPLP              (B1_TX_HANDLER_BASE_ADDRESS + 0x120)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_GPHP              (B1_TX_HANDLER_BASE_ADDRESS + 0x124)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_BEACON            (B1_TX_HANDLER_BASE_ADDRESS + 0x128)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_DBG                      (B1_TX_HANDLER_BASE_ADDRESS + 0x12C)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_IRQ                      (B1_TX_HANDLER_BASE_ADDRESS + 0x130)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_CLEAR_IRQ                (B1_TX_HANDLER_BASE_ADDRESS + 0x134)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_GENERATE_IRQ_COMMANDS    (B1_TX_HANDLER_BASE_ADDRESS + 0x138)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_COMMAND_VAP_VECTOR       (B1_TX_HANDLER_BASE_ADDRESS + 0x13C)
#define	REG_B1_TX_HANDLER_TXH_PAUSER_COMMAND                  (B1_TX_HANDLER_BASE_ADDRESS + 0x140)
#define	REG_B1_TX_HANDLER_SPARE_REGISTERS                     (B1_TX_HANDLER_BASE_ADDRESS + 0x1FC)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_TX_HANDLER_LAST_VAP_WINNER_AC_ID0TO3 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastVapWinnerAcBe : 5; //Last VAP winner for AC_BE, reset value: 0x0, access type: RO
		uint32 lastVapWinnerAcBk : 5; //Last VAP winner for AC_BK, reset value: 0x0, access type: RO
		uint32 lastVapWinnerAcVi : 5; //Last VAP winner for AC_VI, reset value: 0x0, access type: RO
		uint32 lastVapWinnerAcVo : 5; //Last VAP winner for AC_VO, reset value: 0x0, access type: RO
		uint32 reserved0 : 12;
	} bitFields;
} RegB1TxHandlerLastVapWinnerAcId0To3_u;

/*REG_B1_TX_HANDLER_LAST_VAP_WINNER_AC_ID4TO7 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastVapWinnerAcGplp : 5; //Last VAP winner for AC_GPLP, reset value: 0x0, access type: RO
		uint32 lastVapWinnerAcGphp : 5; //Last VAP winner for AC_GPHP, reset value: 0x0, access type: RO
		uint32 lastVapWinnerAcBeacon : 5; //Last VAP winner for AC_BEACON, reset value: 0x0, access type: RO
		uint32 reserved0 : 17;
	} bitFields;
} RegB1TxHandlerLastVapWinnerAcId4To7_u;

/*REG_B1_TX_HANDLER_AC_ID_PRIORITY 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acIdPriority0 : 3; //AC_ID priority0, reset value: 0x5, access type: RW
		uint32 reserved0 : 1;
		uint32 acIdPriority1 : 3; //AC_ID priority1, reset value: 0x1, access type: RW
		uint32 reserved1 : 1;
		uint32 acIdPriority2 : 3; //AC_ID priority2, reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 acIdPriority3 : 3; //AC_ID priority3, reset value: 0x2, access type: RW
		uint32 reserved3 : 1;
		uint32 acIdPriority4 : 3; //AC_ID priority4, reset value: 0x3, access type: RW
		uint32 reserved4 : 1;
		uint32 acIdPriority5 : 3; //AC_ID priority5, reset value: 0x6, access type: RW
		uint32 reserved5 : 1;
		uint32 acIdPriority6 : 3; //AC_ID priority6, reset value: 0x7, access type: RW
		uint32 reserved6 : 5;
	} bitFields;
} RegB1TxHandlerAcIdPriority_u;

/*REG_B1_TX_HANDLER_WLAN_RETRY_CTR_LIMIT 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 wlanShortRetryCtrLimit : 8; //WLAN Short Retry limit, reset value: 0x7, access type: RW
		uint32 wlanLongRetryCtrLimit : 8; //WLAN Long Retry limit, reset value: 0x4, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxHandlerWlanRetryCtrLimit_u;

/*REG_B1_TX_HANDLER_AC_EXT_CW_REMAPPING 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acGplpCwRemappingAp : 3; //AC_GPLP CW remapping in AP mode, reset value: 0x5, access type: RW
		uint32 reserved0 : 1;
		uint32 acGphpCwRemappingAp : 3; //AC_GPHP CW remapping in AP mode, reset value: 0x6, access type: RW
		uint32 reserved1 : 1;
		uint32 acBeaconCwRemappingAp : 3; //AC_BEACON CW remapping in AP mode, reset value: 0x7, access type: RW
		uint32 reserved2 : 5;
		uint32 acGplpCwRemappingSta : 3; //AC_GPLP CW remapping in STA mode, reset value: 0x5, access type: RW
		uint32 reserved3 : 1;
		uint32 acGphpCwRemappingSta : 3; //AC_GPHP CW remapping in STA mode, reset value: 0x6, access type: RW
		uint32 reserved4 : 1;
		uint32 acBeaconCwRemappingSta : 3; //AC_BEACON CW remapping in STA mode, reset value: 0x7, access type: RW
		uint32 reserved5 : 5;
	} bitFields;
} RegB1TxHandlerAcExtCwRemapping_u;

/*REG_B1_TX_HANDLER_LCG_RAND_FUNC_SEED 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lcgRandFuncSeed : 32; //LCG random function seed, reset value: 0x12345678, access type: RW
	} bitFields;
} RegB1TxHandlerLcgRandFuncSeed_u;

/*REG_B1_TX_HANDLER_LCG_RAND_FUNC_SHIFT_NUM 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lcgRandFuncShiftNum : 5; //LCG random function shift number, reset value: 0x10, access type: RW
		uint32 reserved0 : 27;
	} bitFields;
} RegB1TxHandlerLcgRandFuncShiftNum_u;

/*REG_B1_TX_HANDLER_TXH_MAP_CONTROL 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhMapEnable : 1; //Tx Handler MAP enable, reset value: 0x1, access type: RW
		uint32 freezeInAggBuilderErrorEn : 1; //freeze in AGG builder error enable, reset value: 0x0, access type: RW
		uint32 punishOnInternalCollisionEn : 1; //Punish on internal collision enable, reset value: 0x1, access type: RW
		uint32 increaseOnIntColSsrcSlrcN : 1; //Determined which retry counter to increment in case of internal collision: , 0 - SLRC, 1 - SSRC, reset value: 0x1, access type: RW
		uint32 txGroupAddressedSetEcwminEn : 1; //Tx group addressed set ECWmin enable, reset value: 0x1, access type: RW
		uint32 retryCtrLimitZeroedCtrEn : 1; //Retry ctr limit zeroed ctr enable, reset value: 0x1, access type: RW
		uint32 punishWinnerOnCollisionEn : 1; //Punish Winner on external collision enable, reset value: 0x1, access type: RW
		uint32 ignoreMuEdcaTimerExpired : 1; //Ignore MU EDCA timer expired event. it'll cause not to move back from MU EDCA to regular EDCA, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1TxHandlerTxhMapControl_u;

/*REG_B1_TX_HANDLER_TX_REQ_VAP_AC_BE 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txReqVapAcBe : 32; //Tx request VAP AC_BE vector internal, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerTxReqVapAcBe_u;

/*REG_B1_TX_HANDLER_TX_REQ_VAP_AC_BK 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txReqVapAcBk : 32; //Tx request VAP AC_BK vector internal, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerTxReqVapAcBk_u;

/*REG_B1_TX_HANDLER_TX_REQ_VAP_AC_VI 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txReqVapAcVi : 32; //Tx request VAP AC_VI vector internal, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerTxReqVapAcVi_u;

/*REG_B1_TX_HANDLER_TX_REQ_VAP_AC_VO 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txReqVapAcVo : 32; //Tx request VAP AC_VO vector internal, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerTxReqVapAcVo_u;

/*REG_B1_TX_HANDLER_TX_REQ_VAP_AC_GPLP 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txReqVapAcGplp : 32; //Tx request VAP AC_GPLP vector internal, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerTxReqVapAcGplp_u;

/*REG_B1_TX_HANDLER_TX_REQ_VAP_AC_GPHP 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txReqVapAcGphp : 32; //Tx request VAP AC_GPHP vector internal, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerTxReqVapAcGphp_u;

/*REG_B1_TX_HANDLER_TX_REQ_VAP_AC_BEACON 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txReqVapAcBeacon : 32; //Tx request VAP AC_BEACON vector internal, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerTxReqVapAcBeacon_u;

/*REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_BE 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastSlotVapAcBe : 32; //Last slot VAP AC_BE vector, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerLastSlotVapAcBe_u;

/*REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_BK 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastSlotVapAcBk : 32; //Last slot VAP AC_BK vector, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerLastSlotVapAcBk_u;

/*REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_VI 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastSlotVapAcVi : 32; //Last slot VAP AC_VI vector, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerLastSlotVapAcVi_u;

/*REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_VO 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastSlotVapAcVo : 32; //Last slot VAP AC_VO vector, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerLastSlotVapAcVo_u;

/*REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_GPLP 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastSlotVapAcGplp : 32; //Last slot VAP AC_GPLP vector, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerLastSlotVapAcGplp_u;

/*REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_GPHP 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastSlotVapAcGphp : 32; //Last slot VAP AC_GPHP vector, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerLastSlotVapAcGphp_u;

/*REG_B1_TX_HANDLER_LAST_SLOT_VAP_AC_BEACON 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastSlotVapAcBeacon : 32; //Last slot VAP AC_BEACON vector, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxHandlerLastSlotVapAcBeacon_u;

/*REG_B1_TX_HANDLER_WINNER_RESULT 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 winnerVapId : 5; //winner VAP ID, reset value: 0x0, access type: RO
		uint32 winnerAcId : 3; //winner AC ID, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB1TxHandlerWinnerResult_u;

/*REG_B1_TX_HANDLER_UNFREEZE_REPORT_SET 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 unfreezeCommand : 1; //Set Unfreeze command, reset value: 0x0, access type: WO
		uint32 ctsRxInfoUpdate : 1; //CTS Rx information update, reset value: 0x0, access type: WO
		uint32 txResultUpdate : 1; //Tx result update, reset value: 0x0, access type: WO
		uint32 reserved0 : 5;
		uint32 ctsRxInfo : 2; //CTS Rx information, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
		uint32 txResult : 2; //Tx result, reset value: 0x0, access type: RW
		uint32 txFrameLength : 1; //Tx frame length, reset value: 0x0, access type: RW
		uint32 txHeUlTbSuccessAcBitmap : 4; //Success AC IDs 0-3 bitmap - used for HE UL TB STA mode, reset value: 0x0, access type: RW
		uint32 txHeUlTbVapid : 5; //VAP ID - used for HE UL TB STA mode, reset value: 0x0, access type: RW
		uint32 reserved2 : 4;
	} bitFields;
} RegB1TxHandlerUnfreezeReportSet_u;

/*REG_B1_TX_HANDLER_UNFREEZE_REPORT 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 8;
		uint32 ctsRxInfoRd : 2; //CTS Rx information read, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 txResultRd : 2; //Tx result read, reset value: 0x0, access type: RO
		uint32 txFrameLengthRd : 1; //Tx frame length read, reset value: 0x0, access type: RO
		uint32 txHeUlTbSuccessAcBitmapRd : 4; //Success AC IDs 0-3 bitmap read - used for HE UL TB STA mode, reset value: 0x0, access type: RO
		uint32 txHeUlTbVapidRd : 5; //VAP ID read - used for HE UL TB STA mode, reset value: 0x0, access type: RO
		uint32 reserved2 : 4;
	} bitFields;
} RegB1TxHandlerUnfreezeReport_u;

/*REG_B1_TX_HANDLER_TXH_MAP_DBG 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhMapSm : 5; //TXH MAP state machine, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 pauseFdbkSm : 2; //pause fdbk state machine, reset value: 0x0, access type: RO
		uint32 reserved1 : 2;
		uint32 txhMapHandlerSm : 4; //TXH MAP handler state machine, reset value: 0x0, access type: RO
		uint32 txhMapInFreeze : 1; //TXH MAP  in freeze, reset value: 0x0, access type: RO
		uint32 lastSlotMaskedVapAc : 1; //last slot masked vap_ac, reset value: 0x0, access type: RO
		uint32 txReqVapAc : 1; //Tx req vap_ac, reset value: 0x0, access type: RO
		uint32 txSelTxhdVapAc : 1; //tx_sel txhd vap_ac, reset value: 0x0, access type: RO
		uint32 mapHandlerOperation : 4; //map handler operation, reset value: 0x0, access type: RO
		uint32 txhMapHeUlTbMode : 1; //TXH MAP in HE UL TB STA mode, reset value: 0x0, access type: RO
		uint32 reserved2 : 7;
	} bitFields;
} RegB1TxHandlerTxhMapDbg_u;

/*REG_B1_TX_HANDLER_RECIPE_PTR_AC_ID0TO3 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 recipePtrAcId0To3 : 25; //Recipe pointer AC_ID 0to3, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
	} bitFields;
} RegB1TxHandlerRecipePtrAcId0To3_u;

/*REG_B1_TX_HANDLER_RECIPE_PTR_AC_GPLP 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 recipePtrAcGplp : 25; //Recipe pointer AC_ID GPLP, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
	} bitFields;
} RegB1TxHandlerRecipePtrAcGplp_u;

/*REG_B1_TX_HANDLER_RECIPE_PTR_AC_GPHP 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 recipePtrAcGphp : 25; //Recipe pointer AC_ID GPHP, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
	} bitFields;
} RegB1TxHandlerRecipePtrAcGphp_u;

/*REG_B1_TX_HANDLER_RECIPE_PTR_AC_BEACON 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 recipePtrAcBeacon : 25; //Recipe pointer AC_ID Beacon, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
	} bitFields;
} RegB1TxHandlerRecipePtrAcBeacon_u;

/*REG_B1_TX_HANDLER_TXH_NTD_TX_REQ_PARAMS 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhNtdCcaSensitive : 1; //TXH to NTD CCA sensitive, reset value: 0x1, access type: RW
		uint32 txhNtdRxNavSensitive : 1; //TXH to NTD Rx NAV sensitive, reset value: 0x1, access type: RW
		uint32 txhNtdTxNavSensitive : 1; //TXH to NTD Tx NAV sensitive, reset value: 0x1, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB1TxHandlerTxhNtdTxReqParams_u;

/*REG_B1_TX_HANDLER_TXH_EPSILON_MICRO_PRESCALER_NUM 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhEpsilonMicroPrescalerNum : 10; //TxH HW epsilon micro prescaler num, reset value: 0x9f, access type: RW
		uint32 reserved0 : 6;
		uint32 txhEpsilonMicroPrescalerNumFreqReduced : 10; //TxH HW epsilon micro prescaler num freq reduced, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegB1TxHandlerTxhEpsilonMicroPrescalerNum_u;

/*REG_B1_TX_HANDLER_TXH_EPSILON_MICRO_NUM 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhEpsilonMicroNum : 8; //TxH HW epsilon micro num, reset value: 0x5, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1TxHandlerTxhEpsilonMicroNum_u;

/*REG_B1_TX_HANDLER_TXH_LOGGER 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhLoggerEn : 1; //Tx Handler logger enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 txhLoggerPriority : 2; //Tx Handler logger priority, reset value: 0x0, access type: RW
		uint32 reserved1 : 22;
	} bitFields;
} RegB1TxHandlerTxhLogger_u;

/*REG_B1_TX_HANDLER_TXH_LOGGER_ACTIVE 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhLoggerActive : 1; //Tx Handler logger active, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxHandlerTxhLoggerActive_u;

/*REG_B1_TX_HANDLER_DEBUG_MU_EDCA_TIMER_RESOLUTION 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 debugMuEdcaTimerResolution : 3; //for debug, change resolution of MU EDCA timer by (8*1024[us] shift right of this register value), reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB1TxHandlerDebugMuEdcaTimerResolution_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_REP_CYCLE_COUNT 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserRepCycleCount : 8; //TXH Pauser repetition cycle count, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1TxHandlerTxhPauserRepCycleCount_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_REP_DURATION 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserRepPauseDur : 16; //TXH Pauser repetition pause duration, reset value: 0x0, access type: RW
		uint32 txhPauserRepResumeDur : 16; //TXH Pauser repetition resume duration, reset value: 0x0, access type: RW
	} bitFields;
} RegB1TxHandlerTxhPauserRepDuration_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_STATUS 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcInUsed : 1; //TXH Pauser vap ac in used, reset value: 0x0, access type: RO
		uint32 txhPauserWaitForConfirm : 1; //TXH Pauser wait for confirm, reset value: 0x0, access type: RO
		uint32 txhPauserRepModeSeq : 1; //TXH pauser repetition mode seq, reset value: 0x0, access type: RO
		uint32 txhPauserRepLimitedInfiniteN : 1; //TXH Pauser repetition limited infinite_n, reset value: 0x0, access type: RO
		uint32 txhPauserRepPausePeriod : 1; //TXH Pauser repetition pause period, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 txhPauserRepCounter : 8; //TXH Pauser repetition counter, reset value: 0x0, access type: RO
		uint32 reserved1 : 16;
	} bitFields;
} RegB1TxHandlerTxhPauserStatus_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_BE 0x110 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcBe : 32; //TXH Pauser VAP AC_BE, reset value: 0xffff, access type: RO
	} bitFields;
} RegB1TxHandlerTxhPauserVapAcBe_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_BK 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcBk : 32; //TXH Pauser VAP AC_BK, reset value: 0xffff, access type: RO
	} bitFields;
} RegB1TxHandlerTxhPauserVapAcBk_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_VI 0x118 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcVi : 32; //TXH Pauser VAP AC_VI, reset value: 0xffff, access type: RO
	} bitFields;
} RegB1TxHandlerTxhPauserVapAcVi_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_VO 0x11C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcVo : 32; //TXH Pauser VAP AC_VO, reset value: 0xffff, access type: RO
	} bitFields;
} RegB1TxHandlerTxhPauserVapAcVo_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_GPLP 0x120 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcGplp : 32; //TXH Pauser VAP AC_GPLP, reset value: 0xffff, access type: RO
	} bitFields;
} RegB1TxHandlerTxhPauserVapAcGplp_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_GPHP 0x124 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcGphp : 32; //TXH Pauser VAP AC_GPHP, reset value: 0xffff, access type: RO
	} bitFields;
} RegB1TxHandlerTxhPauserVapAcGphp_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_VAP_AC_BEACON 0x128 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapAcBeacon : 32; //TXH Pauser VAP AC_BEACON, reset value: 0xffff, access type: RO
	} bitFields;
} RegB1TxHandlerTxhPauserVapAcBeacon_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_DBG 0x12C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserSm : 4; //TXH Pauser state machine, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxHandlerTxhPauserDbg_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_IRQ 0x130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserIrq : 1; //TXH Pauser IRQ, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxHandlerTxhPauserIrq_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_CLEAR_IRQ 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserClearIrq : 1; //TXH Pauser clear IRQ, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxHandlerTxhPauserClearIrq_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_GENERATE_IRQ_COMMANDS 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserGenerateIrqCommands : 16; //TXH Pauser generate IRQ per command , reset value: 0xffff, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxHandlerTxhPauserGenerateIrqCommands_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_COMMAND_VAP_VECTOR 0x13C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserVapVector : 32; //TXH Pauser VAP vector, reset value: 0x0, access type: RW
	} bitFields;
} RegB1TxHandlerTxhPauserCommandVapVector_u;

/*REG_B1_TX_HANDLER_TXH_PAUSER_COMMAND 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhPauserCommand : 4; //TXH Pauser command, reset value: 0x0, access type: RW
		uint32 txhPauserRepetitionType : 1; //TXH Pauser repetition type, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 txhPauserAcVector : 8; //TXH Pauser AC vector, reset value: 0x0, access type: RW
		uint32 reserved1 : 16;
	} bitFields;
} RegB1TxHandlerTxhPauserCommand_u;

/*REG_B1_TX_HANDLER_SPARE_REGISTERS 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareRegisters : 16; //Spare registers, reset value: 0x8888, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxHandlerSpareRegisters_u;



#endif // _B1_TX_HANDLER_REGS_H_
