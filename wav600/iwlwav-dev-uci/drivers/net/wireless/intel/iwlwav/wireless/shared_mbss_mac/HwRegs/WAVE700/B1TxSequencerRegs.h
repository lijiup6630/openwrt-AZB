
/***********************************************************************************
File:				B1TxSequencerRegs.h
Module:				b1TxSequencer
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:12:11
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_TX_SEQUENCER_REGS_H_
#define _B1_TX_SEQUENCER_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_TX_SEQUENCER_BASE_ADDRESS                             MEMORY_MAP_UNIT_10068_BASE_ADDRESS
#define	REG_B1_TX_SEQUENCER_SUCCESSFUL_SEQUENCE_EN                      (B1_TX_SEQUENCER_BASE_ADDRESS + 0x0)
#define	REG_B1_TX_SEQUENCER_OTHER_RX_SEQUENCE_EN                        (B1_TX_SEQUENCER_BASE_ADDRESS + 0x4)
#define	REG_B1_TX_SEQUENCER_RESP_TIMEOUT_SEQUENCE_EN                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x8)
#define	REG_B1_TX_SEQUENCER_SEQUENCE_EXPECTED                           (B1_TX_SEQUENCER_BASE_ADDRESS + 0xC)
#define	REG_B1_TX_SEQUENCER_TX_END_ERR_SEQUENCE_EN                      (B1_TX_SEQUENCER_BASE_ADDRESS + 0x10)
#define	REG_B1_TX_SEQUENCER_MINIMAL_SEQ_TIME_THRESHOLD                  (B1_TX_SEQUENCER_BASE_ADDRESS + 0x14)
#define	REG_B1_TX_SEQUENCER_MINIMAL_SU_TXOP_TIME_THRESHOLD              (B1_TX_SEQUENCER_BASE_ADDRESS + 0x18)
#define	REG_B1_TX_SEQUENCER_MINIMAL_VHT_MU_TXOP_TIME_THRESHOLD          (B1_TX_SEQUENCER_BASE_ADDRESS + 0x1C)
#define	REG_B1_TX_SEQUENCER_MINIMAL_HE_MU_TXOP_TIME_THRESHOLD           (B1_TX_SEQUENCER_BASE_ADDRESS + 0x20)
#define	REG_B1_TX_SEQUENCER_MINIMAL_BF_SEQ_TIME_THRESHOLD               (B1_TX_SEQUENCER_BASE_ADDRESS + 0x24)
#define	REG_B1_TX_SEQUENCER_MINIMAL_CF_END_TIME_THRESHOLD               (B1_TX_SEQUENCER_BASE_ADDRESS + 0x28)
#define	REG_B1_TX_SEQUENCER_MINIMAL_ETSI_FILLER_TIME_THRESHOLD          (B1_TX_SEQUENCER_BASE_ADDRESS + 0x2C)
#define	REG_B1_TX_SEQUENCER_TX_NAV_TIMER_SAMPLE_SIFS_COMP               (B1_TX_SEQUENCER_BASE_ADDRESS + 0x30)
#define	REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIME_DELAY_TX                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x34)
#define	REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIME_DELAY_RX                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x38)
#define	REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIME_DELAY_TIMEOUT               (B1_TX_SEQUENCER_BASE_ADDRESS + 0x3C)
#define	REG_B1_TX_SEQUENCER_MAC_PHY_TX_TXOP_SIGNAL_EN                   (B1_TX_SEQUENCER_BASE_ADDRESS + 0x40)
#define	REG_B1_TX_SEQUENCER_MAC_PHY_TX_TXOP_SIGNAL                      (B1_TX_SEQUENCER_BASE_ADDRESS + 0x44)
#define	REG_B1_TX_SEQUENCER_BW_LIMITS                                   (B1_TX_SEQUENCER_BASE_ADDRESS + 0x48)
#define	REG_B1_TX_SEQUENCER_SET_BW_LIMIT                                (B1_TX_SEQUENCER_BASE_ADDRESS + 0x4C)
#define	REG_B1_TX_SEQUENCER_SET_FILLER_RA_BF_RPT_BW_LOWER_EN            (B1_TX_SEQUENCER_BASE_ADDRESS + 0x50)
#define	REG_B1_TX_SEQUENCER_TX_SEQUENCER_IRQ_STATUS                     (B1_TX_SEQUENCER_BASE_ADDRESS + 0x54)
#define	REG_B1_TX_SEQUENCER_TX_SEQUENCER_IRQ_EN                         (B1_TX_SEQUENCER_BASE_ADDRESS + 0x58)
#define	REG_B1_TX_SEQUENCER_TX_SEQUENCER_IRQ_CLR                        (B1_TX_SEQUENCER_BASE_ADDRESS + 0x5C)
#define	REG_B1_TX_SEQUENCER_TX_SEQUENCER_ERR_IRQ_STATUS                 (B1_TX_SEQUENCER_BASE_ADDRESS + 0x60)
#define	REG_B1_TX_SEQUENCER_TX_SEQUENCER_ERR_IRQ_EN                     (B1_TX_SEQUENCER_BASE_ADDRESS + 0x64)
#define	REG_B1_TX_SEQUENCER_TX_SEQUENCER_ERR_IRQ_CLR                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x68)
#define	REG_B1_TX_SEQUENCER_CPU_RA_FILLER_IRQ                           (B1_TX_SEQUENCER_BASE_ADDRESS + 0x6C)
#define	REG_B1_TX_SEQUENCER_CPU_RA_FILLER_IRQ_EN                        (B1_TX_SEQUENCER_BASE_ADDRESS + 0x70)
#define	REG_B1_TX_SEQUENCER_CPU_RA_FILLER_IRQ_CLR                       (B1_TX_SEQUENCER_BASE_ADDRESS + 0x74)
#define	REG_B1_TX_SEQUENCER_BF_RPT_VALID                                (B1_TX_SEQUENCER_BASE_ADDRESS + 0x78)
#define	REG_B1_TX_SEQUENCER_BF_RPT_VALID_CLR                            (B1_TX_SEQUENCER_BASE_ADDRESS + 0x7C)
#define	REG_B1_TX_SEQUENCER_AGG_REACT_PSDU_DUR_LIMIT_ADD                (B1_TX_SEQUENCER_BASE_ADDRESS + 0x80)
#define	REG_B1_TX_SEQUENCER_AGG_REACT_STATUS                            (B1_TX_SEQUENCER_BASE_ADDRESS + 0x84)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_BASE_ADDR                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x88)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_DEPTH_MINUS_ONE              (B1_TX_SEQUENCER_BASE_ADDRESS + 0x8C)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_CLEAR_STRB                   (B1_TX_SEQUENCER_BASE_ADDRESS + 0x90)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_RD_ENTRIES_NUM               (B1_TX_SEQUENCER_BASE_ADDRESS + 0x94)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_NUM_ENTRIES_COUNT            (B1_TX_SEQUENCER_BASE_ADDRESS + 0x98)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_DEBUG                        (B1_TX_SEQUENCER_BASE_ADDRESS + 0x9C)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_CCA_CONTROL                       (B1_TX_SEQUENCER_BASE_ADDRESS + 0xA0)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_LOGGER                            (B1_TX_SEQUENCER_BASE_ADDRESS + 0xA4)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_LOGGER_ACTIVE                     (B1_TX_SEQUENCER_BASE_ADDRESS + 0xA8)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_DEBUG_SM                          (B1_TX_SEQUENCER_BASE_ADDRESS + 0xAC)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_DEBUG                             (B1_TX_SEQUENCER_BASE_ADDRESS + 0xB0)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_PLANNED_EXECUTED_DEBUG            (B1_TX_SEQUENCER_BASE_ADDRESS + 0xB4)
#define	REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIMER                            (B1_TX_SEQUENCER_BASE_ADDRESS + 0xB8)
#define	REG_B1_TX_SEQUENCER_SENDER_USP_INDEX                            (B1_TX_SEQUENCER_BASE_ADDRESS + 0xBC)
#define	REG_B1_TX_SEQUENCER_SENDER_CURRENT_TRANSMITTED_PLAN_FLOW        (B1_TX_SEQUENCER_BASE_ADDRESS + 0xC0)
#define	REG_B1_TX_SEQUENCER_MAX_NUM_MULT_USERS_TRAINING                 (B1_TX_SEQUENCER_BASE_ADDRESS + 0xC4)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_REPORT_SENDER_BITS                (B1_TX_SEQUENCER_BASE_ADDRESS + 0xC8)
#define	REG_B1_TX_SEQUENCER_ABORT_WAIT_PHY_MULT_USERS_TRAINING          (B1_TX_SEQUENCER_BASE_ADDRESS + 0xCC)
#define	REG_B1_TX_SEQUENCER_PHY_SAMPLE_INFO_DEBUG_EN                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0xD0)
#define	REG_B1_TX_SEQUENCER_PHY_PAC_TX_PHY_MU_EFFECTIVE_RATE            (B1_TX_SEQUENCER_BASE_ADDRESS + 0xD4)
#define	REG_B1_TX_SEQUENCER_PHY_PAC_TX_BF_31TO0                         (B1_TX_SEQUENCER_BASE_ADDRESS + 0xD8)
#define	REG_B1_TX_SEQUENCER_PHY_PAC_TX_BF_35TO32                        (B1_TX_SEQUENCER_BASE_ADDRESS + 0xDC)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_END_IRQ                           (B1_TX_SEQUENCER_BASE_ADDRESS + 0xE0)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_END_IRQ_CLR                       (B1_TX_SEQUENCER_BASE_ADDRESS + 0xE4)
#define	REG_B1_TX_SEQUENCER_TX_AUTO_RESP_DISABLE_SETTING                (B1_TX_SEQUENCER_BASE_ADDRESS + 0xE8)
#define	REG_B1_TX_SEQUENCER_TX_AUTO_RESP_DISABLE                        (B1_TX_SEQUENCER_BASE_ADDRESS + 0xEC)
#define	REG_B1_TX_SEQUENCER_BAA_NEEDED_SET_31TO0                        (B1_TX_SEQUENCER_BASE_ADDRESS + 0xF0)
#define	REG_B1_TX_SEQUENCER_BAA_NEEDED_SET_35TO32                       (B1_TX_SEQUENCER_BASE_ADDRESS + 0xF4)
#define	REG_B1_TX_SEQUENCER_BAA_NEEDED_31TO0                            (B1_TX_SEQUENCER_BASE_ADDRESS + 0xF8)
#define	REG_B1_TX_SEQUENCER_BAA_NEEDED_35TO32                           (B1_TX_SEQUENCER_BASE_ADDRESS + 0xFC)
#define	REG_B1_TX_SEQUENCER_MAX_NUM_BF_SEQ_ITERATIONS                   (B1_TX_SEQUENCER_BASE_ADDRESS + 0x100)
#define	REG_B1_TX_SEQUENCER_TX_SEQ_DEL_RECIPE_POINTER                   (B1_TX_SEQUENCER_BASE_ADDRESS + 0x104)
#define	REG_B1_TX_SEQUENCER_BF_RPT_HE_MU_ONESHOT_PHASE                  (B1_TX_SEQUENCER_BASE_ADDRESS + 0x10C)
#define	REG_B1_TX_SEQUENCER_TRIGGER_CF_END_BAA_BUSY_EN                  (B1_TX_SEQUENCER_BASE_ADDRESS + 0x110)
#define	REG_B1_TX_SEQUENCER_RXC_SEQ_RX_RESULT_DBG1                      (B1_TX_SEQUENCER_BASE_ADDRESS + 0x114)
#define	REG_B1_TX_SEQUENCER_RXC_SEQ_RX_RESULT_DBG2                      (B1_TX_SEQUENCER_BASE_ADDRESS + 0x118)
#define	REG_B1_TX_SEQUENCER_RXC_SEQ_RX_RESULT_DBG3                      (B1_TX_SEQUENCER_BASE_ADDRESS + 0x11C)
#define	REG_B1_TX_SEQUENCER_ETSI_MODE                                   (B1_TX_SEQUENCER_BASE_ADDRESS + 0x120)
#define	REG_B1_TX_SEQUENCER_SENDER_CFG_ETSI_BO_COUNT                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x124)
#define	REG_B1_TX_SEQUENCER_ETSI_BO_COUNTER                             (B1_TX_SEQUENCER_BASE_ADDRESS + 0x128)
#define	REG_B1_TX_SEQUENCER_ETSI_IFSN_ECW                               (B1_TX_SEQUENCER_BASE_ADDRESS + 0x12C)
#define	REG_B1_TX_SEQUENCER_ETSI_BO_RANDOM_GEN_START                    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x130)
#define	REG_B1_TX_SEQUENCER_ETSI_BO_RANDOM_GEN_RESULT                   (B1_TX_SEQUENCER_BASE_ADDRESS + 0x134)
#define	REG_B1_TX_SEQUENCER_LCG_RAND_FUNC_SEED                          (B1_TX_SEQUENCER_BASE_ADDRESS + 0x138)
#define	REG_B1_TX_SEQUENCER_LCG_RAND_FUNC_SHIFT_NUM                     (B1_TX_SEQUENCER_BASE_ADDRESS + 0x13C)
#define	REG_B1_TX_SEQUENCER_ADDITION_ETSI_FILLER_TXOP_TIME_THRESHOLD    (B1_TX_SEQUENCER_BASE_ADDRESS + 0x140)
#define	REG_B1_TX_SEQUENCER_SEQUENCER_TRANSACTION_NUMBER                (B1_TX_SEQUENCER_BASE_ADDRESS + 0x144)
#define	REG_B1_TX_SEQUENCER_SPARE_REGISTERS                             (B1_TX_SEQUENCER_BASE_ADDRESS + 0x1FC)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_TX_SEQUENCER_SUCCESSFUL_SEQUENCE_EN 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 successActivateBaaEn : 1; //Enable BAA activation, reset value: 0x0, access type: RW
		uint32 successVerifyCcaPrimaryEn : 1; //Enable cancel Tx due to CCA primary 20MHz busy, reset value: 0x0, access type: RW
		uint32 successVerifyCcaSecondaryEn : 1; //Enable verify CCA secondary, reset value: 0x0, access type: RW
		uint32 successUpdateDynamicBwEn : 1; //Enable update BW based on PHY status service bits, reset value: 0x0, access type: RW
		uint32 successBfIterationEn : 1; //Enable BF iteration, reset value: 0x0, access type: RW
		uint32 successClrBfReqTxSelBitmapEn : 1; //Enable clear of BF request in Tx Selector BitMAP, reset value: 0x0, access type: RW
		uint32 successAggReactivationEn : 1; //Enable AGG reactivation, reset value: 0x0, access type: RW
		uint32 successAggReactivationForce : 1; //Force AGG reactivation, reset value: 0x0, access type: RW
		uint32 successAggReactivationRdDb : 1; //Read DB in case of AGG reactivation, reset value: 0x0, access type: RW
		uint32 successAggVerifySifsLimitEn : 1; //Enable verify SIFS limit AGG operation, reset value: 0x0, access type: RW
		uint32 successTriggerTxReqEn : 1; //Enable triggering Tx request, reset value: 0x0, access type: RW
		uint32 successFillRateAdaptiveRptEn : 1; //Enable filling rate adaptive report, reset value: 0x0, access type: RW
		uint32 successTriggerCfEndForce : 1; //Force CF-end triggering, reset value: 0x0, access type: RW
		uint32 successTriggerCfEndEn : 1; //Enable CF-end triggering, reset value: 0x0, access type: RW
		uint32 successTxSelBitmapUnlockEn : 1; //Enable unlock queue in Tx selector BitMAP, reset value: 0x0, access type: RW
		uint32 successTxhMapUnfreezeEn : 1; //Enable TXH MAP unfreeze, reset value: 0x0, access type: RW
		uint32 successGenCpuIntEn : 1; //Generate interrupt to CPU, reset value: 0x0, access type: RW
		uint32 successClrTxNavTimerEn : 1; //Enable clear Tx NAV timer, reset value: 0x0, access type: RW
		uint32 successVerifyMinSeqTimeEn : 1; //Enable verify minimum sequence time threshold, reset value: 0x0, access type: RW
		uint32 successWaitPhyMultUsersTrainingEn : 1; //Enable waiting PHY completes its operation on MU BF DB, reset value: 0x0, access type: RW
		uint32 successManageBfPollEn : 1; //Enable handling BF poll1 bit and STD “Next BF report”, reset value: 0x0, access type: RW
		uint32 successEtsiFillerSettingEn : 1; //Enable setting CTS2Self filler, with cause of ETSI, reset value: 0x0, access type: RW
		uint32 successEtsiBoCountingEn : 1; //Enable counting BO before continue to the next Tx frame, reset value: 0x0, access type: RW
		uint32 successVerifyCcaPrimaryPostAggEn : 1; //Enable verify CCA primary 20MHz after Pre-AGG operation, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB1TxSequencerSuccessfulSequenceEn_u;

/*REG_B1_TX_SEQUENCER_OTHER_RX_SEQUENCE_EN 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 otherActivateBaaEn : 1; //Enable BAA activation, reset value: 0x0, access type: RW
		uint32 otherVerifyCcaPrimaryEn : 1; //Enable cancel Tx due to CCA primary 20MHz busy, reset value: 0x0, access type: RW
		uint32 otherVerifyCcaSecondaryEn : 1; //Enable verify CCA secondary, reset value: 0x0, access type: RW
		uint32 otherUpdateDynamicBwEn : 1; //Enable update BW based on PHY status service bits, reset value: 0x0, access type: RW
		uint32 otherBfIterationEn : 1; //Enable BF iteration, reset value: 0x0, access type: RW
		uint32 otherClrBfReqTxSelBitmapEn : 1; //Enable clear of BF request in Tx Selector BitMAP, reset value: 0x0, access type: RW
		uint32 otherAggReactivationEn : 1; //Enable AGG reactivation, reset value: 0x0, access type: RW
		uint32 otherAggReactivationForce : 1; //Force AGG reactivation, reset value: 0x0, access type: RW
		uint32 otherAggReactivationRdDb : 1; //Read DB in case of AGG reactivation, reset value: 0x0, access type: RW
		uint32 otherAggVerifySifsLimitEn : 1; //Enable verify SIFS limit AGG operation, reset value: 0x0, access type: RW
		uint32 otherTriggerTxReqEn : 1; //Enable triggering Tx request, reset value: 0x0, access type: RW
		uint32 otherFillRateAdaptiveRptEn : 1; //Enable filling rate adaptive report, reset value: 0x0, access type: RW
		uint32 otherTriggerCfEndForce : 1; //Force CF-end triggering., reset value: 0x0, access type: RW
		uint32 otherTriggerCfEndEn : 1; //Enable CF-end triggering, reset value: 0x0, access type: RW
		uint32 otherTxSelBitmapUnlockEn : 1; //Enable unlock queue in Tx selector BitMAP, reset value: 0x0, access type: RW
		uint32 otherTxhMapUnfreezeEn : 1; //Enable TXH MAP unfreeze, reset value: 0x0, access type: RW
		uint32 otherGenCpuIntEn : 1; //Generate interrupt to CPU, reset value: 0x0, access type: RW
		uint32 otherClrTxNavTimerEn : 1; //Enable clear Tx NAV timer, reset value: 0x0, access type: RW
		uint32 otherVerifyMinSeqTimeEn : 1; //Enable verify minimum sequence time threshold, reset value: 0x0, access type: RW
		uint32 otherWaitPhyMultUsersTrainingEn : 1; //Enable waiting PHY completes its operation on MU BF DB, reset value: 0x0, access type: RW
		uint32 otherManageBfPollEn : 1; //Enable handling BF poll1 bit and STD “Next BF report”, reset value: 0x0, access type: RW
		uint32 otherEtsiFillerSettingEn : 1; //Enable setting CTS2Self filler, with cause of ETSI, reset value: 0x0, access type: RW
		uint32 otherEtsiBoCountingEn : 1; //Enable counting BO before continue to the next Tx frame, reset value: 0x0, access type: RW
		uint32 otherVerifyCcaPrimaryPostAggEn : 1; //Enable verify CCA primary 20MHz after Pre-AGG operation, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB1TxSequencerOtherRxSequenceEn_u;

/*REG_B1_TX_SEQUENCER_RESP_TIMEOUT_SEQUENCE_EN 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 timeoutActivateBaaEn : 1; //Enable BAA activation, reset value: 0x0, access type: RW
		uint32 timeoutVerifyCcaPrimaryEn : 1; //Enable cancel Tx due to CCA primary 20MHz busy, reset value: 0x0, access type: RW
		uint32 timeoutVerifyCcaSecondaryEn : 1; //Enable verify CCA secondary, reset value: 0x0, access type: RW
		uint32 timeoutUpdateDynamicBwEn : 1; //Enable update BW based on PHY status service bits, reset value: 0x0, access type: RW
		uint32 timeoutBfIterationEn : 1; //Enable BF iteration, reset value: 0x0, access type: RW
		uint32 timeoutClrBfReqTxSelBitmapEn : 1; //Enable clear of BF request in Tx Selector BitMAP, reset value: 0x0, access type: RW
		uint32 timeoutAggReactivationEn : 1; //Enable AGG reactivation, reset value: 0x0, access type: RW
		uint32 timeoutAggReactivationForce : 1; //Force AGG reactivation, reset value: 0x0, access type: RW
		uint32 timeoutAggReactivationRdDb : 1; //Read DB in case of AGG reactivation, reset value: 0x0, access type: RW
		uint32 timeoutAggVerifySifsLimitEn : 1; //Enable verify SIFS limit AGG operation, reset value: 0x0, access type: RW
		uint32 timeoutTriggerTxReqEn : 1; //Enable triggering Tx request, reset value: 0x0, access type: RW
		uint32 timeoutFillRateAdaptiveRptEn : 1; //Enable filling rate adaptive report, reset value: 0x0, access type: RW
		uint32 timeoutTriggerCfEndForce : 1; //Force CF-end triggering., reset value: 0x0, access type: RW
		uint32 timeoutTriggerCfEndEn : 1; //Enable CF-end triggering, reset value: 0x0, access type: RW
		uint32 timeoutTxSelBitmapUnlockEn : 1; //Enable unlock queue in Tx selector BitMAP, reset value: 0x0, access type: RW
		uint32 timeoutTxhMapUnfreezeEn : 1; //Enable TXH MAP unfreeze, reset value: 0x0, access type: RW
		uint32 timeoutGenCpuIntEn : 1; //Generate interrupt to CPU, reset value: 0x0, access type: RW
		uint32 timeoutClrTxNavTimerEn : 1; //Enable clear Tx NAV timer, reset value: 0x0, access type: RW
		uint32 timeoutVerifyMinSeqTimeEn : 1; //Enable verify minimum sequence time threshold, reset value: 0x0, access type: RW
		uint32 timeoutWaitPhyMultUsersTrainingEn : 1; //Enable waiting PHY completes its operation on MU BF DB, reset value: 0x0, access type: RW
		uint32 timeoutManageBfPollEn : 1; //Enable handling BF poll1 bit and STD “Next BF report”, reset value: 0x0, access type: RW
		uint32 timeoutEtsiFillerSettingEn : 1; //Enable setting CTS2Self filler, with cause of ETSI, reset value: 0x0, access type: RW
		uint32 timeoutEtsiBoCountingEn : 1; //Enable counting BO before continue to the next Tx frame, reset value: 0x0, access type: RW
		uint32 timeoutVerifyCcaPrimaryPostAggEn : 1; //Enable verify CCA primary 20MHz after Pre-AGG operation, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB1TxSequencerRespTimeoutSequenceEn_u;

/*REG_B1_TX_SEQUENCER_SEQUENCE_EXPECTED 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 postTxSeqActivateStart : 1; //Sequencer activation after Post Tx, reset value: 0x0, access type: RW
		uint32 postRxSeqActivateStart : 1; //Sequencer activation after Post Rx, reset value: 0x0, access type: RW
		uint32 expectedRxAck : 1; //Expected Rx ACK, reset value: 0x0, access type: RW
		uint32 expectedRxBa : 1; //Expected Rx BA, reset value: 0x0, access type: RW
		uint32 expectedRxCts : 1; //Expected Rx CTS, reset value: 0x0, access type: RW
		uint32 expectedRxBfRpt : 1; //Expected Rx BF report, reset value: 0x0, access type: RW
		uint32 expectedRxAny : 1; //Expected Rx Any frame, reset value: 0x0, access type: RW
		uint32 expectedAutoRespAfterRx : 1; //Expected suto-resp after Rx, reset value: 0x0, access type: RW
		uint32 expectedRxNdpFb : 1; //Expected Rx NDP feedback, reset value: 0x0, access type: RW
		uint32 expectedRxBaBroadcast : 1; //Expected Rx non unicast BACK, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegB1TxSequencerSequenceExpected_u;

/*REG_B1_TX_SEQUENCER_TX_END_ERR_SEQUENCE_EN 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 cca20PBusyTriggerCfEndEn : 1; //Enable CF-end triggering, , In case of CCA 20MHz primary is busy., reset value: 0x0, access type: RW
		uint32 cca20PBusyTxSelBitmapUnlockEn : 1; //Enable unlock queue in Tx selector BitMAP, , In case of CCA 20MHz primary is busy, reset value: 0x0, access type: RW
		uint32 cca20PBusyTxhMapUnfreezeEn : 1; //Enable TXH MAP unfreeze, , In case of CCA 20MHz primary is busy, reset value: 0x0, access type: RW
		uint32 cca20PBusyGenCpuIntEn : 1; //Generate interrupt to CPU, , In case of CCA 20MHz primary is busy, reset value: 0x0, access type: RW
		uint32 cca20PBusyClrTxNavTimerEn : 1; //Enable clear Tx NAV timer, , In case of CCA 20MHz primary is busy., reset value: 0x0, access type: RW
		uint32 reserved0 : 5;
		uint32 aggErrTriggerCfEndEn : 1; //Enable CF-end triggering, , In case of AGG builder error, reset value: 0x0, access type: RW
		uint32 aggErrTxSelBitmapUnlockEn : 1; //Enable unlock queue in Tx selector BitMAP, , In case of AGG builder error, reset value: 0x0, access type: RW
		uint32 aggErrTxhMapUnfreezeEn : 1; //Enable TXH MAP unfreeze, , In case of AGG builder error, reset value: 0x0, access type: RW
		uint32 aggErrGenCpuIntEn : 1; //Generate interrupt to CPU, , In case of AGG builder error, reset value: 0x0, access type: RW
		uint32 aggErrClrTxNavTimerEn : 1; //Enable clear Tx NAV timer, , In case of AGG builder error, reset value: 0x0, access type: RW
		uint32 noFillerTriggerCfEndEn : 1; //Enable CF-end triggering, , In case of no filler supported, but there is a need to add a filler, reset value: 0x0, access type: RW
		uint32 noFillerTxSelBitmapUnlockEn : 1; //Enable unlock queue in Tx selector BitMAP, , In case of no filler supported, but there is a need to add a filler, reset value: 0x0, access type: RW
		uint32 noFillerTxhMapUnfreezeEn : 1; //Enable TXH MAP unfreeze, , In case of no filler supported, but there is a need to add a filler, reset value: 0x0, access type: RW
		uint32 noFillerGenCpuIntEn : 1; //Generate interrupt to CPU, , In case of no filler supported, but there is a need to add a filler, reset value: 0x0, access type: RW
		uint32 noFillerClrTxNavTimerEn : 1; //Enable clear Tx NAV timer, , In case of no filler supported, but there is a need to add a filler, reset value: 0x0, access type: RW
		uint32 reserved1 : 12;
	} bitFields;
} RegB1TxSequencerTxEndErrSequenceEn_u;

/*REG_B1_TX_SEQUENCER_MINIMAL_SEQ_TIME_THRESHOLD 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimalSeqTimeThreshold : 18; //Minimal time threshold for continue sequence flow, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerMinimalSeqTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_MINIMAL_SU_TXOP_TIME_THRESHOLD 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimalSuTxopTimeThreshold : 18; //Minimal time threshold for continue TXOP multiple main transmission sequence flow in SU, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerMinimalSuTxopTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_MINIMAL_VHT_MU_TXOP_TIME_THRESHOLD 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimalVhtMuTxopTimeThreshold : 18; //Minimal time threshold for continue TXOP multiple main transmission sequence flow in VHT MU, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerMinimalVhtMuTxopTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_MINIMAL_HE_MU_TXOP_TIME_THRESHOLD 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimalHeMuTxopTimeThreshold : 18; //Minimal time threshold for continue TXOP multiple main transmission sequence flow in HE MU, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerMinimalHeMuTxopTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_MINIMAL_BF_SEQ_TIME_THRESHOLD 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimalBfSeqTimeThreshold : 18; //Minimal time threshold for iteration of BF sequence, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerMinimalBfSeqTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_MINIMAL_CF_END_TIME_THRESHOLD 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimalCfEndTimeThreshold : 18; //Minimal time threshold for CF-end transmission, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerMinimalCfEndTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_MINIMAL_ETSI_FILLER_TIME_THRESHOLD 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimalEtsiFillerTimeThreshold : 18; //Minimal time threshold for ETSI Filler transmission, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerMinimalEtsiFillerTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_TX_NAV_TIMER_SAMPLE_SIFS_COMP 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txNavTimerSamplePostTxOfdmSifsComp : 4; //Time in micro seconds from "PHY-MAC Tx ready signal fall" till next Delia start, when the last Tx was in PHY mode of OFDM, reset value: 0x0, access type: RW
		uint32 txNavTimerSamplePostTx11BSifsComp : 4; //Time in micro seconds from "PHY-MAC Tx ready signal fall" till next Delia start, when the last Tx was in PHY mode of 11B, reset value: 0x0, access type: RW
		uint32 txNavTimerSamplePostRxOfdmSifsComp : 4; //Time in micro seconds from "CCA 20p becomes free (after Rx session)" till next Delia start, when the last Rx was in PHY mode of OFDM, reset value: 0x0, access type: RW
		uint32 txNavTimerSamplePostRx11BSifsComp : 4; //Time in micro seconds from "CCA 20p becomes free (after Rx session)" till next Delia start, when the last Rx was in PHY mode of 11B, reset value: 0x0, access type: RW
		uint32 txNavTimerSamplePostTimeoutSifsComp : 4; //Time in micro seconds from "Response timeout expired" till next Delia start., reset value: 0x0, access type: RW
		uint32 txNavTimerSamplePostEtsiFillerSifsComp : 4; //Time in micro seconds from "epsilon time at the last slot after ETSI filler" till next Delia start., reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB1TxSequencerTxNavTimerSampleSifsComp_u;

/*REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIME_DELAY_TX 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ccaSampleTimeDelayTxOfdm : 14; //Time delay in cycles from the PHY-MAC "Tx ready" signal fall (when the PHY mode of last Tx frame is OFDM) till when to sample CCA signals, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 ccaSampleTimeDelayTx11B : 14; //Time delay in cycles from the PHY-MAC "Tx ready" signal fall (when the PHY mode of last Tx frame is 11B) till when to sample CCA signals, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegB1TxSequencerCcaSampleTimeDelayTx_u;

/*REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIME_DELAY_RX 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ccaSampleTimeDelayRxOfdm : 14; //Time delay in cycles from "CCA 20p becomes free (after Rx session)"  (when the PHY mode of last Rx frame is OFDM) till when to sample CCA signals, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 ccaSampleTimeDelayRx11B : 14; //Time delay in cycles from "CCA 20p becomes free (after Rx session)"  (when the PHY mode of last Rx frame is 11B) till when to sample CCA signals, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegB1TxSequencerCcaSampleTimeDelayRx_u;

/*REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIME_DELAY_TIMEOUT 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ccaSampleTimeDelayTimeout : 14; //Time delay in cycles from timeout expired event till when to sample CCA signals, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegB1TxSequencerCcaSampleTimeDelayTimeout_u;

/*REG_B1_TX_SEQUENCER_MAC_PHY_TX_TXOP_SIGNAL_EN 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 macPhyTxTxopSignalEn : 1; //Enable settings the MAC-PHY Tx TXOP signal, reset value: 0x1, access type: RW
		uint32 macPhyTxTxopSignalDebugOverrideEn : 1; //Enable override the MAC-PHY Tx TXOP signal, reset value: 0x0, access type: RW
		uint32 macPhyTxTxopSignalDebugOverrideVal : 1; //The override value of the MAC-PHY Tx TXOP signal, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB1TxSequencerMacPhyTxTxopSignalEn_u;

/*REG_B1_TX_SEQUENCER_MAC_PHY_TX_TXOP_SIGNAL 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 macPhyTxTxopSignal : 1; //MAC-PHY Tx TXOP signal, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerMacPhyTxTxopSignal_u;

/*REG_B1_TX_SEQUENCER_BW_LIMITS 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxBfRptMimoBw : 3; //BW limit based on BF report MIMO control, used only in case of SU, reset value: 0x0, access type: RO
		uint32 rxPhyStatusDynamicBwLimit : 3; //BW limit based on dynamic/static BW, reset value: 0x0, access type: RO
		uint32 lastGoodAggBwLimit : 3; //Current BW limit based on AGG builder activation, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegB1TxSequencerBwLimits_u;

/*REG_B1_TX_SEQUENCER_SET_BW_LIMIT 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 setBwLimit : 3; //Set BW limit in the middle of TXOP, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB1TxSequencerSetBwLimit_u;

/*REG_B1_TX_SEQUENCER_SET_FILLER_RA_BF_RPT_BW_LOWER_EN 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 setFillerRaBfRptBwLowerEn : 1; //Enable settings Filler of rate adaptive on Rx BF report with BW lower than planned, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerSetFillerRaBfRptBwLowerEn_u;

/*REG_B1_TX_SEQUENCER_TX_SEQUENCER_IRQ_STATUS 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 successRxBfRptIrq : 1; //Successful Rx BF report IRQ, reset value: 0x0, access type: RO
		uint32 successRxCtsIrq : 1; //Successful Rx CTS IRQ, reset value: 0x0, access type: RO
		uint32 successRxAckIrq : 1; //Successful Rx ACK IRQ, reset value: 0x0, access type: RO
		uint32 successRxBaIrq : 1; //Successful Rx BA IRQ, reset value: 0x0, access type: RO
		uint32 successRxAnyIrq : 1; //Successful Rx Any IRQ, reset value: 0x0, access type: RO
		uint32 successTxAutoRespIrq : 1; //Successful tx auto response IRQ, reset value: 0x0, access type: RO
		uint32 otherRxIrq : 1; //Other Rx IRQ, reset value: 0x0, access type: RO
		uint32 respTimeoutRxIrq : 1; //Response timeout Rx IRQ, reset value: 0x0, access type: RO
		uint32 postTxIrq : 1; //Post Tx IRQ, reset value: 0x0, access type: RO
		uint32 cca20PBusyIrq : 1; //Stop due CCA 20MHz primary busy IRQ, reset value: 0x0, access type: RO
		uint32 aggErrIrq : 1; //Stop due AGG builder error IRQ, reset value: 0x0, access type: RO
		uint32 noFillerSupportIrq : 1; //Stop due to no filler support IRQ, reset value: 0x0, access type: RO
		uint32 successRxBaBroadcastIrq : 1; //Successful Rx BA broadcast IRQ, reset value: 0x0, access type: RO
		uint32 successRxNdpFbIrq : 1; //Successful Rx NDP feedback IRQ, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB1TxSequencerTxSequencerIrqStatus_u;

/*REG_B1_TX_SEQUENCER_TX_SEQUENCER_IRQ_EN 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 successRxBfRptIrqEn : 1; //Successful Rx BF report IRQ enable, reset value: 0x0, access type: RW
		uint32 successRxCtsIrqEn : 1; //Successful Rx CTS IRQ enable, reset value: 0x0, access type: RW
		uint32 successRxAckIrqEn : 1; //Successful Rx ACK IRQ enable, reset value: 0x0, access type: RW
		uint32 successRxBaIrqEn : 1; //Successful Rx BA IRQ enable, reset value: 0x0, access type: RW
		uint32 successRxAnyIrqEn : 1; //Successful Rx Any IRQ enable, reset value: 0x0, access type: RW
		uint32 successTxAutoRespIrqEn : 1; //Successful tx auto response IRQ enable, reset value: 0x0, access type: RW
		uint32 otherRxIrqEn : 1; //Other Rx IRQ enable, reset value: 0x0, access type: RW
		uint32 respTimeoutRxIrqEn : 1; //Response timeout Rx IRQ enable, reset value: 0x0, access type: RW
		uint32 postTxIrqEn : 1; //Post Tx IRQ enable, reset value: 0x0, access type: RW
		uint32 cca20PBusyIrqEn : 1; //Stop due CCA 20MHz primary busy IRQ enable, reset value: 0x0, access type: RW
		uint32 aggErrIrqEn : 1; //Stop due AGG builder error IRQ enable, reset value: 0x0, access type: RW
		uint32 noFillerSupportIrqEn : 1; //Stop due to no filler support IRQ enable, reset value: 0x0, access type: RW
		uint32 successRxBaBroadcastIrqEn : 1; //Successful Rx BA broadcast IRQ enable, reset value: 0x0, access type: RW
		uint32 successRxNdpFbIrqEn : 1; //Successful Rx NDP feedback IRQ enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegB1TxSequencerTxSequencerIrqEn_u;

/*REG_B1_TX_SEQUENCER_TX_SEQUENCER_IRQ_CLR 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 successRxBfRptIrqClr : 1; //Successful Rx BF report IRQ clear, reset value: 0x0, access type: WO
		uint32 successRxCtsIrqClr : 1; //Successful Rx CTS IRQ clear, reset value: 0x0, access type: WO
		uint32 successRxAckIrqClr : 1; //Successful Rx ACK IRQ clear, reset value: 0x0, access type: WO
		uint32 successRxBaIrqClr : 1; //Successful Rx BA IRQ clear, reset value: 0x0, access type: WO
		uint32 successRxAnyIrqClr : 1; //Successful Rx Any IRQ clear, reset value: 0x0, access type: WO
		uint32 successTxAutoRespIrqClr : 1; //Successful tx auto response IRQ clear, reset value: 0x0, access type: WO
		uint32 otherRxIrqClr : 1; //Other Rx IRQ clear, reset value: 0x0, access type: WO
		uint32 respTimeoutRxIrqClr : 1; //Response timeout Rx IRQ clear, reset value: 0x0, access type: WO
		uint32 postTxIrqClr : 1; //Post Tx IRQ clear, reset value: 0x0, access type: WO
		uint32 cca20PBusyIrqClr : 1; //Stop due CCA 20MHz primary busy IRQ clear, reset value: 0x0, access type: WO
		uint32 aggErrIrqClr : 1; //Stop due AGG builder error IRQ clear, reset value: 0x0, access type: WO
		uint32 noFillerSupportIrqClr : 1; //Stop due to no filler support IRQ clear, reset value: 0x0, access type: WO
		uint32 successRxBaBroadcastIrqClr : 1; //Successful Rx BA broadcast IRQ clear, reset value: 0x0, access type: WO
		uint32 successRxNdpFbIrqClr : 1; //Successful Rx NDP feedback IRQ clear, reset value: 0x0, access type: WO
		uint32 reserved0 : 18;
	} bitFields;
} RegB1TxSequencerTxSequencerIrqClr_u;

/*REG_B1_TX_SEQUENCER_TX_SEQUENCER_ERR_IRQ_STATUS 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 compOwnerErrIrq : 1; //Compare owner bit failed IRQ, reset value: 0x0, access type: RO
		uint32 sequencerFifoFullDropIrq : 1; //Sequencer drop entry due to FIFO full IRQ, reset value: 0x0, access type: RO
		uint32 sequencerFifoDecrementLessThanZeroIrq : 1; //Sequencer FIFO amount has been decremented less than zero IRQ, reset value: 0x0, access type: RO
		uint32 baaNeedsStartWhileBusyIrq : 1; //Sequencer needed to activate BAA, but BAA is still busy IRQ, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxSequencerTxSequencerErrIrqStatus_u;

/*REG_B1_TX_SEQUENCER_TX_SEQUENCER_ERR_IRQ_EN 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 compOwnerErrIrqEn : 1; //Compare owner bit failed IRQ enable, reset value: 0x0, access type: RW
		uint32 sequencerFifoFullDropIrqEn : 1; //Sequencer drop entry due to FIFO full IRQ enable, reset value: 0x0, access type: RW
		uint32 sequencerFifoDecrementLessThanZeroIrqEn : 1; //Sequencer FIFO amount has been decremented less than zero IRQ enable, reset value: 0x0, access type: RW
		uint32 baaNeedsStartWhileBusyIrqEn : 1; //Sequencer needed to activate BAA, but BAA is still busy IRQ enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxSequencerTxSequencerErrIrqEn_u;

/*REG_B1_TX_SEQUENCER_TX_SEQUENCER_ERR_IRQ_CLR 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 compOwnerErrIrqClr : 1; //Compare owner bit failed IRQ clear, by write '1', reset value: 0x0, access type: WO
		uint32 reserved0 : 1;
		uint32 sequencerFifoDecrementLessThanZeroIrqClr : 1; //Sequencer FIFO amount has been decremented less than zero IRQ clear, by write '1', reset value: 0x0, access type: WO
		uint32 baaNeedsStartWhileBusyIrqClr : 1; //Sequencer needed to activate BAA, but BAA is still busy IRQ clear, by write '1', reset value: 0x0, access type: WO
		uint32 reserved1 : 28;
	} bitFields;
} RegB1TxSequencerTxSequencerErrIrqClr_u;

/*REG_B1_TX_SEQUENCER_CPU_RA_FILLER_IRQ 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 cpuRaFillerIrq : 1; //CPU Rate adaptive filler IRQ, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerCpuRaFillerIrq_u;

/*REG_B1_TX_SEQUENCER_CPU_RA_FILLER_IRQ_EN 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 cpuRaFillerIrqEn : 1; //CPU Rate adaptive filler IRQ enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerCpuRaFillerIrqEn_u;

/*REG_B1_TX_SEQUENCER_CPU_RA_FILLER_IRQ_CLR 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 cpuRaFillerIrqClr : 1; //CPU Rate adaptive filler IRQ clear, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerCpuRaFillerIrqClr_u;

/*REG_B1_TX_SEQUENCER_BF_RPT_VALID 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bfRptSenderValid : 1; //BF report Sender valid bit, reset value: 0x0, access type: RO
		uint32 bfRptCpuValid : 1; //BF report CPU valid bit, reset value: 0x0, access type: RO
		uint32 bfRptSequencerValid : 1; //BF report Sequencer valid bit, reset value: 0x0, access type: RO
		uint32 bfRptHeMuOneshotSenderValid : 1; //BF report HE MU one-shot Sender valid bit, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxSequencerBfRptValid_u;

/*REG_B1_TX_SEQUENCER_BF_RPT_VALID_CLR 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bfRptSenderValidClr : 1; //BF report Sender valid bit clear, reset value: 0x0, access type: WO
		uint32 bfRptCpuValidClr : 1; //BF report CPU valid bit clear, reset value: 0x0, access type: WO
		uint32 reserved0 : 1;
		uint32 bfRptHeMuOneshotSenderValidClr : 1; //BF report HE MU one-shot Sender valid bit clear, reset value: 0x0, access type: WO
		uint32 reserved1 : 28;
	} bitFields;
} RegB1TxSequencerBfRptValidClr_u;

/*REG_B1_TX_SEQUENCER_AGG_REACT_PSDU_DUR_LIMIT_ADD 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aggReactPsduDurLimitAdd : 10; //Add time in [us] for the remaining PSDU duration limit in case of AGG builder reactivation, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegB1TxSequencerAggReactPsduDurLimitAdd_u;

/*REG_B1_TX_SEQUENCER_AGG_REACT_STATUS 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aggReactErrNoBuildPsdu : 1; //AGG reactivate error on PD type data - can't construct even one MPDU, reset value: 0x0, access type: RO
		uint32 reserved0 : 15;
		uint32 aggReactRequiredRaFiller : 1; //AGG reactivate required to set rate adaptive filler due to BF report, reset value: 0x0, access type: RO
		uint32 aggReactFirstPdNull : 1; //AGG reactivate stop due to first PD is NULL, reset value: 0x0, access type: RO
		uint32 aggReactLessMinTimer : 1; //AGG reactivate operation time is less than minimum , reset value: 0x0, access type: RO
		uint32 aggReactDone : 1; //AGG reactivation has been completed, reset value: 0x0, access type: RO
		uint32 aggReactUspPrimaryDrop : 1; //AGG reactivate stop due to Primary USP indicated as Drop, reset value: 0x0, access type: RO
		uint32 aggReactMuPrimaryNotDataPd : 1; //AGG reactivate stop due to MU Primary USP first PD is not data type, reset value: 0x0, access type: RO
		uint32 aggSeqReactOtfModeChange : 1; //AGG reactivate stop due to OTF mode change, reset value: 0x0, access type: RO
		uint32 reserved1 : 9;
	} bitFields;
} RegB1TxSequencerAggReactStatus_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_BASE_ADDR 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerFifoBaseAddr : 22; //Sequencer FIFO base address (byte address), reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegB1TxSequencerSequencerFifoBaseAddr_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_DEPTH_MINUS_ONE 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerFifoDepthMinusOne : 10; //Sequencer FIFO depth minus one (boundary of entries, each entry is 12 bytes), reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegB1TxSequencerSequencerFifoDepthMinusOne_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_CLEAR_STRB 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 sequencerFifoClearFullDropCtrStrb : 1; //Clear Sequencer fifo full drop counter, by write '1', reset value: 0x0, access type: WO
		uint32 sequencerFifoClearStrb : 1; //Clear Sequencer FIFO by write '1', reset value: 0x0, access type: WO
		uint32 reserved1 : 29;
	} bitFields;
} RegB1TxSequencerSequencerFifoClearStrb_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_RD_ENTRIES_NUM 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerFifoRdEntriesNum : 11; //Sequencer FIFO number of entries to decrement, reset value: 0x0, access type: RW
		uint32 reserved0 : 21;
	} bitFields;
} RegB1TxSequencerSequencerFifoRdEntriesNum_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_NUM_ENTRIES_COUNT 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerFifoNumEntriesCount : 11; //Sequencer FIFO number of entries count, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegB1TxSequencerSequencerFifoNumEntriesCount_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_FIFO_DEBUG 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerFifoWrPtr : 10; //Sequencer FIFO write pointer entry index, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 sequencerFifoNotEmpty : 1; //Sequencer FIFO not empty indication, reset value: 0x0, access type: RO
		uint32 sequencerFifoFull : 1; //Sequencer FIFO full indication, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 sequencerFifoFullDropCtr : 8; //Sequencer FIFO full drop counter, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxSequencerSequencerFifoDebug_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_CCA_CONTROL 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 forceDisable11BSampleCca : 1; //Force disable sample CCA signals in case the PHY mode is 11B by Sequencer, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerSequencerCcaControl_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_LOGGER 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerLoggerEn : 1; //Sequencer logger enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 sequencerLoggerPriority : 2; //Sequencer logger priority, reset value: 0x0, access type: RW
		uint32 reserved1 : 22;
	} bitFields;
} RegB1TxSequencerSequencerLogger_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_LOGGER_ACTIVE 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerLoggerActive : 1; //Sequencer logger active, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerSequencerLoggerActive_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_DEBUG_SM 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 seqMainSm : 7; //Sequencer main state machine, reset value: 0x0, access type: RO
		uint32 seqExpectedSm : 4; //Sequencer expected state machine, reset value: 0x0, access type: RO
		uint32 bfWaitSm : 2; //BF wait state machine, reset value: 0x0, access type: RO
		uint32 txselUnlockIfSm : 3; //Tx Selector unlock interface state machine, reset value: 0x0, access type: RO
		uint32 rdPrevStdSm : 3; //Read STD prev section state machine, reset value: 0x0, access type: RO
		uint32 etsiBoCountingSm : 3; //ETSI BO counting state machine, reset value: 0x0, access type: RO
		uint32 reserved0 : 10;
	} bitFields;
} RegB1TxSequencerSequencerDebugSm_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_DEBUG 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 seqSenderConfig : 3; //Sequencer Sender config result: 0 - Success, 1 - timeout, 2 - Other Rx, 3 - Post Tx, 4 - Success response Tx, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 timeoutEventSticky : 4; //Timeout event sticky, 1 bit per USP, reset value: 0x0, access type: RO
		uint32 otherRxEventSticky : 4; //Other Rx event sticky, 1 bit per USP, reset value: 0x0, access type: RO
		uint32 bwChangeSticky : 1; //BW was changed during the sequence, sticky indication, reset value: 0x0, access type: RO
		uint32 aggSeqBfRptNssModifiedSticky : 1; //Nss was changed during the sequence due to BF report, sticky indication, reset value: 0x0, access type: RO
		uint32 aggSeqBfRptMcsModifiedSticky : 1; //MCS was changed during the sequence due to BF report, sticky indication, reset value: 0x0, access type: RO
		uint32 reserved1 : 11;
	} bitFields;
} RegB1TxSequencerSequencerDebug_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_PLANNED_EXECUTED_DEBUG 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 stdPlannedFlow : 16; //STD planned flow bits, read at the start of Tx sequencer operation, reset value: 0x0, access type: RO
		uint32 stdExecutedFlow : 16; //STD executed flow bits, read at the start of Tx sequencer operation, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxSequencerSequencerPlannedExecutedDebug_u;

/*REG_B1_TX_SEQUENCER_CCA_SAMPLE_TIMER 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ccaSampleTimer : 14; //CCA sample timer, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB1TxSequencerCcaSampleTimer_u;

/*REG_B1_TX_SEQUENCER_SENDER_USP_INDEX 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 senderUspIndex : 2; //Sender configuration of USP index for the use of BAA and Sequencer , reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB1TxSequencerSenderUspIndex_u;

/*REG_B1_TX_SEQUENCER_SENDER_CURRENT_TRANSMITTED_PLAN_FLOW 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 senderCurrentTransmittedPlanFlow : 16; //Sender configuration of which Tx plan bit has been currently transmitted, only 1bit should be set , reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxSequencerSenderCurrentTransmittedPlanFlow_u;

/*REG_B1_TX_SEQUENCER_MAX_NUM_MULT_USERS_TRAINING 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxNumMultUsersTraining : 4; //Maximum number of users during MU multiple users training (minus one), reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxSequencerMaxNumMultUsersTraining_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_REPORT_SENDER_BITS 0xC8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerReportSenderBits : 32; //Sender bits for Sequencer report, reset value: 0x0, access type: RW
	} bitFields;
} RegB1TxSequencerSequencerReportSenderBits_u;

/*REG_B1_TX_SEQUENCER_ABORT_WAIT_PHY_MULT_USERS_TRAINING 0xCC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 abortWaitPhyMultUsersTraining : 1; //Abort waiting PHY completse its operation on MU BF DB at the end of MU multiple users training sequence, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerAbortWaitPhyMultUsersTraining_u;

/*REG_B1_TX_SEQUENCER_PHY_SAMPLE_INFO_DEBUG_EN 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phySampleInfoDebugEn : 1; //Enable sample PHY Tx type and effective rate for debug, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerPhySampleInfoDebugEn_u;

/*REG_B1_TX_SEQUENCER_PHY_PAC_TX_PHY_MU_EFFECTIVE_RATE 0xD4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyPacTxPhyMuEffectiveRate : 16; //PHY Tx MU effective rate, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxSequencerPhyPacTxPhyMuEffectiveRate_u;

/*REG_B1_TX_SEQUENCER_PHY_PAC_TX_BF_31TO0 0xD8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyPacTxBf31To0 : 32; //PHY Tx BF of users [31:0], reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxSequencerPhyPacTxBf31To0_u;

/*REG_B1_TX_SEQUENCER_PHY_PAC_TX_BF_35TO32 0xDC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyPacTxBf35To32 : 4; //PHY Tx BF of users [35:32], reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxSequencerPhyPacTxBf35To32_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_END_IRQ 0xE0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerEndIrq : 1; //Sequencer end IRQ, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerSequencerEndIrq_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_END_IRQ_CLR 0xE4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerEndIrqClr : 1; //Sequencer end IRQ clear, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerSequencerEndIrqClr_u;

/*REG_B1_TX_SEQUENCER_TX_AUTO_RESP_DISABLE_SETTING 0xE8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txAutoRespDisableSetting : 1; //Write 1 to disable transmit of auto-resp during the Tx sequence, , Write 0 to enable transmit of auto-resp during the Tx sequence., reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerTxAutoRespDisableSetting_u;

/*REG_B1_TX_SEQUENCER_TX_AUTO_RESP_DISABLE 0xEC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txAutoRespDisable : 1; //Transmit of auto-resp disable indication, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerTxAutoRespDisable_u;

/*REG_B1_TX_SEQUENCER_BAA_NEEDED_SET_31TO0 0xF0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 baaNeededSet31To0 : 32; //Set the BAA needed bits for users [31:0], 1 bit per USP, reset value: 0x0, access type: WO
	} bitFields;
} RegB1TxSequencerBaaNeededSet31To0_u;

/*REG_B1_TX_SEQUENCER_BAA_NEEDED_SET_35TO32 0xF4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 baaNeededSet35To32 : 4; //Set the BAA needed bits for users [35:32], 1 bit per USP, reset value: 0x0, access type: WO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxSequencerBaaNeededSet35To32_u;

/*REG_B1_TX_SEQUENCER_BAA_NEEDED_31TO0 0xF8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 baaNeeded31To0 : 32; //BAA needed bits for users [31:0], 1 bit per USP, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxSequencerBaaNeeded31To0_u;

/*REG_B1_TX_SEQUENCER_BAA_NEEDED_35TO32 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 baaNeeded35To32 : 4; //BAA needed bits for users [35:32], 1 bit per USP, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxSequencerBaaNeeded35To32_u;

/*REG_B1_TX_SEQUENCER_MAX_NUM_BF_SEQ_ITERATIONS 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxNumBfSeqIterations : 2; //Maximum number of BF sequence iterations minus one, reset value: 0x3, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB1TxSequencerMaxNumBfSeqIterations_u;

/*REG_B1_TX_SEQUENCER_TX_SEQ_DEL_RECIPE_POINTER 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txSeqDelRecipePointer : 25; //Tx Sequencer to Delia recipe pointer (byte address), reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
	} bitFields;
} RegB1TxSequencerTxSeqDelRecipePointer_u;

/*REG_B1_TX_SEQUENCER_BF_RPT_HE_MU_ONESHOT_PHASE 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bfRptHeMuOneshotPhasePointer : 25; //Phase pointer latch on BF report in HE MU one-shot, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 bfRptHeMuOneshotPhaseIdx : 4; //Phase index latch on BF report in HE MU one-shot, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxSequencerBfRptHeMuOneshotPhase_u;

/*REG_B1_TX_SEQUENCER_TRIGGER_CF_END_BAA_BUSY_EN 0x110 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 triggerCfEndBaaBusyEn : 16; //Enable trigger CF-end when BAA is still busy, 1 bit per "DL Data type" enum in STD, reset value: 0x50, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxSequencerTriggerCfEndBaaBusyEn_u;

/*REG_B1_TX_SEQUENCER_RXC_SEQ_RX_RESULT_DBG1 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxcSeqRxAck31To0 : 32; //RxC to sequencer Rx ACK result for users 0 till 31, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxSequencerRxcSeqRxResultDbg1_u;

/*REG_B1_TX_SEQUENCER_RXC_SEQ_RX_RESULT_DBG2 0x118 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxcSeqRxBack31To0 : 32; //RxC to sequencer Rx BACK result for users 0 till 31, reset value: 0x0, access type: RO
	} bitFields;
} RegB1TxSequencerRxcSeqRxResultDbg2_u;

/*REG_B1_TX_SEQUENCER_RXC_SEQ_RX_RESULT_DBG3 0x11C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxcSeqRxAck35To32 : 4; //RxC to sequencer Rx ACK result for users 32 till 35, reset value: 0x0, access type: RO
		uint32 rxcSeqRxBack35To32 : 4; //RxC to sequencer Rx BACK result for users 32 till 35, reset value: 0x0, access type: RO
		uint32 rxcSeqRxCts : 1; //RxC to sequencer Rx CTS result for user 0, reset value: 0x0, access type: RO
		uint32 rxcSeqRxAtLeastOneGoodMpdu : 1; //RxC to sequencer Rx result of at least one good MPDU, reset value: 0x0, access type: RO
		uint32 rxcSeqRxBaBroadcast : 1; //RxC success BACK non unicast MPDU, reset value: 0x0, access type: RO
		uint32 rxcSeqRxNdpFb : 1; //RxC success NDP feedback, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB1TxSequencerRxcSeqRxResultDbg3_u;

/*REG_B1_TX_SEQUENCER_ETSI_MODE 0x120 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 etsiMode : 1; //Enable ETSI mode, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxSequencerEtsiMode_u;

/*REG_B1_TX_SEQUENCER_SENDER_CFG_ETSI_BO_COUNT 0x124 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 senderCfgEtsiBoCount : 16; //Sender to Sequencer, number of slots to count after ETSI filler, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxSequencerSenderCfgEtsiBoCount_u;

/*REG_B1_TX_SEQUENCER_ETSI_BO_COUNTER 0x128 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 etsiBoCounter : 16; //ETSI BO counter, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxSequencerEtsiBoCounter_u;

/*REG_B1_TX_SEQUENCER_ETSI_IFSN_ECW 0x12C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 etsiIfsnAcBe : 4; //ETSI IFSN of AC_BE, reset value: 0x3, access type: RW
		uint32 etsiIfsnAcBk : 4; //ETSI IFSN of AC_BK, reset value: 0x7, access type: RW
		uint32 etsiIfsnAcVi : 4; //ETSI IFSN of AC_VI, reset value: 0x1, access type: RW
		uint32 etsiIfsnAcVo : 4; //ETSI IFSN of AC_VO, reset value: 0x1, access type: RW
		uint32 etsiEcwAcBe : 4; //ETSI ECW of AC_BE, reset value: 0x4, access type: RW
		uint32 etsiEcwAcBk : 4; //ETSI ECW of AC_BK, reset value: 0x4, access type: RW
		uint32 etsiEcwAcVi : 4; //ETSI ECW of AC_VI, reset value: 0x3, access type: RW
		uint32 etsiEcwAcVo : 4; //ETSI ECW of AC_VO, reset value: 0x2, access type: RW
	} bitFields;
} RegB1TxSequencerEtsiIfsnEcw_u;

/*REG_B1_TX_SEQUENCER_ETSI_BO_RANDOM_GEN_START 0x130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 etsiBoRandomGenAcId : 2; //Write AC_ID, in order to calculate number of BO to count due to ETSI filler, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB1TxSequencerEtsiBoRandomGenStart_u;

/*REG_B1_TX_SEQUENCER_ETSI_BO_RANDOM_GEN_RESULT 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 etsiBoRandomGenResult : 16; //ETSI BO random generator result of number slots to count, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxSequencerEtsiBoRandomGenResult_u;

/*REG_B1_TX_SEQUENCER_LCG_RAND_FUNC_SEED 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lcgRandFuncSeed : 32; //LCG random function seed, reset value: 0x12345678, access type: RW
	} bitFields;
} RegB1TxSequencerLcgRandFuncSeed_u;

/*REG_B1_TX_SEQUENCER_LCG_RAND_FUNC_SHIFT_NUM 0x13C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lcgRandFuncShiftNum : 5; //LCG random function shift number, reset value: 0x10, access type: RW
		uint32 reserved0 : 27;
	} bitFields;
} RegB1TxSequencerLcgRandFuncShiftNum_u;

/*REG_B1_TX_SEQUENCER_ADDITION_ETSI_FILLER_TXOP_TIME_THRESHOLD 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 additionEtsiFillerTxopTimeThreshold : 18; //addition to minimal TXOP time threshold in case of setting filler is enabled, resolution [us]., reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegB1TxSequencerAdditionEtsiFillerTxopTimeThreshold_u;

/*REG_B1_TX_SEQUENCER_SEQUENCER_TRANSACTION_NUMBER 0x144 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sequencerTransactionNumber : 8; //Sequencer transaction number, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB1TxSequencerSequencerTransactionNumber_u;

/*REG_B1_TX_SEQUENCER_SPARE_REGISTERS 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareRegisters : 16; //spare registers, reset value: 0x8888, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxSequencerSpareRegisters_u;



#endif // _B1_TX_SEQUENCER_REGS_H_
