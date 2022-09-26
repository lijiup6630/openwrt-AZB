
/***********************************************************************************
File:				HostIfAccRegs.h
Module:				hostIfAcc
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:12:39
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _HOST_IF_ACC_REGS_H_
#define _HOST_IF_ACC_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define HOST_IF_ACC_BASE_ADDRESS                             MEMORY_MAP_UNIT_39_BASE_ADDRESS
#define	REG_HOST_IF_ACC_SW_CLEAR_INSTRUCTION             (HOST_IF_ACC_BASE_ADDRESS + 0x0)
#define	REG_HOST_IF_ACC_TX_IN_SW_INSTRUCTION             (HOST_IF_ACC_BASE_ADDRESS + 0x4)
#define	REG_HOST_IF_ACC_TX_OUT_SW_INSTRUCTION            (HOST_IF_ACC_BASE_ADDRESS + 0x8)
#define	REG_HOST_IF_ACC_RX_IN_SW_INSTRUCTION             (HOST_IF_ACC_BASE_ADDRESS + 0xC)
#define	REG_HOST_IF_ACC_RX_OUT_SW_INSTRUCTION            (HOST_IF_ACC_BASE_ADDRESS + 0x10)
#define	REG_HOST_IF_ACC_TX_IN_CONV_CFG                   (HOST_IF_ACC_BASE_ADDRESS + 0x14)
#define	REG_HOST_IF_ACC_TX_OUT_CONV_CFG                  (HOST_IF_ACC_BASE_ADDRESS + 0x18)
#define	REG_HOST_IF_ACC_RX_IN_CONV_CFG                   (HOST_IF_ACC_BASE_ADDRESS + 0x1C)
#define	REG_HOST_IF_ACC_RX_OUT_CONV_CFG                  (HOST_IF_ACC_BASE_ADDRESS + 0x20)
#define	REG_HOST_IF_ACC_TX_IN_HD_BUF0_BASE_ADDR          (HOST_IF_ACC_BASE_ADDRESS + 0x24)
#define	REG_HOST_IF_ACC_TX_IN_HD_BUF1_BASE_ADDR          (HOST_IF_ACC_BASE_ADDRESS + 0x28)
#define	REG_HOST_IF_ACC_TX_OUT_HD_BUF0_BASE_ADDR         (HOST_IF_ACC_BASE_ADDRESS + 0x2C)
#define	REG_HOST_IF_ACC_TX_OUT_HD_BUF1_BASE_ADDR         (HOST_IF_ACC_BASE_ADDRESS + 0x30)
#define	REG_HOST_IF_ACC_RX_IN_HD_BUF0_BASE_ADDR          (HOST_IF_ACC_BASE_ADDRESS + 0x34)
#define	REG_HOST_IF_ACC_RX_IN_HD_BUF1_BASE_ADDR          (HOST_IF_ACC_BASE_ADDRESS + 0x38)
#define	REG_HOST_IF_ACC_RX_OUT_HD_BUF0_BASE_ADDR         (HOST_IF_ACC_BASE_ADDRESS + 0x3C)
#define	REG_HOST_IF_ACC_RX_OUT_HD_BUF1_BASE_ADDR         (HOST_IF_ACC_BASE_ADDRESS + 0x40)
#define	REG_HOST_IF_ACC_TX_IN_COUNTERS                   (HOST_IF_ACC_BASE_ADDRESS + 0x44)
#define	REG_HOST_IF_ACC_TX_OUT_COUNTERS                  (HOST_IF_ACC_BASE_ADDRESS + 0x48)
#define	REG_HOST_IF_ACC_RX_IN_COUNTERS                   (HOST_IF_ACC_BASE_ADDRESS + 0x4C)
#define	REG_HOST_IF_ACC_RX_OUT_COUNTERS                  (HOST_IF_ACC_BASE_ADDRESS + 0x50)
#define	REG_HOST_IF_ACC_TX_IN_HD_COUNT_BUF0              (HOST_IF_ACC_BASE_ADDRESS + 0x54)
#define	REG_HOST_IF_ACC_TX_IN_HD_COUNT_BUF1              (HOST_IF_ACC_BASE_ADDRESS + 0x58)
#define	REG_HOST_IF_ACC_TX_OUT_HD_COUNT_BUF0             (HOST_IF_ACC_BASE_ADDRESS + 0x5C)
#define	REG_HOST_IF_ACC_TX_OUT_HD_COUNT_BUF1             (HOST_IF_ACC_BASE_ADDRESS + 0x60)
#define	REG_HOST_IF_ACC_RX_IN_HD_COUNT_BUF0              (HOST_IF_ACC_BASE_ADDRESS + 0x64)
#define	REG_HOST_IF_ACC_RX_IN_HD_COUNT_BUF1              (HOST_IF_ACC_BASE_ADDRESS + 0x68)
#define	REG_HOST_IF_ACC_RX_OUT_HD_COUNT_BUF0             (HOST_IF_ACC_BASE_ADDRESS + 0x6C)
#define	REG_HOST_IF_ACC_RX_OUT_HD_COUNT_BUF1             (HOST_IF_ACC_BASE_ADDRESS + 0x70)
#define	REG_HOST_IF_ACC_TX_IN_LIST_IDX                   (HOST_IF_ACC_BASE_ADDRESS + 0x74)
#define	REG_HOST_IF_ACC_TX_OUT_LIST_IDX                  (HOST_IF_ACC_BASE_ADDRESS + 0x78)
#define	REG_HOST_IF_ACC_RX_IN_LIST_IDX                   (HOST_IF_ACC_BASE_ADDRESS + 0x7C)
#define	REG_HOST_IF_ACC_RX_OUT_LIST_IDX                  (HOST_IF_ACC_BASE_ADDRESS + 0x80)
#define	REG_HOST_IF_ACC_MULTICAST_PD_DISTRIB_CFG         (HOST_IF_ACC_BASE_ADDRESS + 0x84)
#define	REG_HOST_IF_ACC_PD_DISTRIB_UPDATE                (HOST_IF_ACC_BASE_ADDRESS + 0x88)
#define	REG_HOST_IF_ACC_FREE_PD_INIT                     (HOST_IF_ACC_BASE_ADDRESS + 0x8C)
#define	REG_HOST_IF_ACC_PD_THRESHOLD                     (HOST_IF_ACC_BASE_ADDRESS + 0x90)
#define	REG_HOST_IF_ACC_FREE_PD_COUNT                    (HOST_IF_ACC_BASE_ADDRESS + 0x94)
#define	REG_HOST_IF_ACC_TX_RING_CFG                      (HOST_IF_ACC_BASE_ADDRESS + 0x98)
#define	REG_HOST_IF_ACC_RX_RING_CFG                      (HOST_IF_ACC_BASE_ADDRESS + 0x9C)
#define	REG_HOST_IF_ACC_OWN_BIT_VALUE                    (HOST_IF_ACC_BASE_ADDRESS + 0xA4)
#define	REG_HOST_IF_ACC_TX_IN_COUNTERS_UPDATE            (HOST_IF_ACC_BASE_ADDRESS + 0xA8)
#define	REG_HOST_IF_ACC_TX_OUT_COUNTERS_UPDATE           (HOST_IF_ACC_BASE_ADDRESS + 0xAC)
#define	REG_HOST_IF_ACC_RX_IN_COUNTERS_UPDATE            (HOST_IF_ACC_BASE_ADDRESS + 0xB0)
#define	REG_HOST_IF_ACC_RX_OUT_COUNTERS_UPDATE           (HOST_IF_ACC_BASE_ADDRESS + 0xB4)
#define	REG_HOST_IF_ACC_TX_IN_HOST_IF_STATUS             (HOST_IF_ACC_BASE_ADDRESS + 0xB8)
#define	REG_HOST_IF_ACC_TX_OUT_HOST_IF_STATUS            (HOST_IF_ACC_BASE_ADDRESS + 0xBC)
#define	REG_HOST_IF_ACC_RX_IN_HOST_IF_STATUS             (HOST_IF_ACC_BASE_ADDRESS + 0xC0)
#define	REG_HOST_IF_ACC_RX_OUT_HOST_IF_STATUS            (HOST_IF_ACC_BASE_ADDRESS + 0xC4)
#define	REG_HOST_IF_ACC_SW_COUNTERS_CLR                  (HOST_IF_ACC_BASE_ADDRESS + 0xD0)
#define	REG_HOST_IF_ACC_THRESHOLD_CLR                    (HOST_IF_ACC_BASE_ADDRESS + 0xD4)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_STATUS          (HOST_IF_ACC_BASE_ADDRESS + 0xD8)
#define	REG_HOST_IF_ACC_HOST_IF_ACC_ERR_INT              (HOST_IF_ACC_BASE_ADDRESS + 0xDC)
#define	REG_HOST_IF_ACC_HOST_IF_ACC_ERR_INT_CLR          (HOST_IF_ACC_BASE_ADDRESS + 0xE0)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_A          (HOST_IF_ACC_BASE_ADDRESS + 0xE4)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_B          (HOST_IF_ACC_BASE_ADDRESS + 0xE8)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_C          (HOST_IF_ACC_BASE_ADDRESS + 0xEC)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_D          (HOST_IF_ACC_BASE_ADDRESS + 0xF0)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_E          (HOST_IF_ACC_BASE_ADDRESS + 0xF4)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_F          (HOST_IF_ACC_BASE_ADDRESS + 0xF8)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_G          (HOST_IF_ACC_BASE_ADDRESS + 0xFC)
#define	REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_H          (HOST_IF_ACC_BASE_ADDRESS + 0x100)
#define	REG_HOST_IF_ACC_DEBUG_REG                        (HOST_IF_ACC_BASE_ADDRESS + 0x104)
#define	REG_HOST_IF_ACC_GCLK_BYPASS_EN                   (HOST_IF_ACC_BASE_ADDRESS + 0x108)
#define	REG_HOST_IF_ACC_TTL_SCALE_SET                    (HOST_IF_ACC_BASE_ADDRESS + 0x10C)
#define	REG_HOST_IF_ACC_HOST_COUNTERS_CFG                (HOST_IF_ACC_BASE_ADDRESS + 0x130)
#define	REG_HOST_IF_ACC_TX_IN_MULTICAST_CFG              (HOST_IF_ACC_BASE_ADDRESS + 0x134)
#define	REG_HOST_IF_ACC_RX_OUT_MULTICAST_CFG             (HOST_IF_ACC_BASE_ADDRESS + 0x138)
#define	REG_HOST_IF_ACC_RD_THRESHOLD                     (HOST_IF_ACC_BASE_ADDRESS + 0x140)
#define	REG_HOST_IF_ACC_FREE_RD_COUNT                    (HOST_IF_ACC_BASE_ADDRESS + 0x148)
#define	REG_HOST_IF_ACC_TX_HD_BUSY_COUNT                 (HOST_IF_ACC_BASE_ADDRESS + 0x14C)
#define	REG_HOST_IF_ACC_RX_HD_BUSY_COUNT                 (HOST_IF_ACC_BASE_ADDRESS + 0x150)
#define	REG_HOST_IF_ACC_UMT_ORDER_CFG                    (HOST_IF_ACC_BASE_ADDRESS + 0x154)
#define	REG_HOST_IF_ACC_HOST_LOGGER_CFG                  (HOST_IF_ACC_BASE_ADDRESS + 0x158)
#define	REG_HOST_IF_ACC_HOST_LOGGER_BUSY                 (HOST_IF_ACC_BASE_ADDRESS + 0x15C)
#define	REG_HOST_IF_ACC_TX_OUT_MAX_HD                    (HOST_IF_ACC_BASE_ADDRESS + 0x160)
#define	REG_HOST_IF_ACC_RX_OUT_MAX_HD                    (HOST_IF_ACC_BASE_ADDRESS + 0x164)
#define	REG_HOST_IF_ACC_TX_OUT_CYCLIC_COUNTER_INIT       (HOST_IF_ACC_BASE_ADDRESS + 0x168)
#define	REG_HOST_IF_ACC_RX_OUT_CYCLIC_COUNTER_INIT       (HOST_IF_ACC_BASE_ADDRESS + 0x16C)
#define	REG_HOST_IF_ACC_TX_OUT_BUFFER_LIMIT_CFG          (HOST_IF_ACC_BASE_ADDRESS + 0x170)
#define	REG_HOST_IF_ACC_RX_OUT_BUFFER_LIMIT_CFG          (HOST_IF_ACC_BASE_ADDRESS + 0x174)
#define	REG_HOST_IF_ACC_PD_LENGTH_LOCATION_CFG           (HOST_IF_ACC_BASE_ADDRESS + 0x178)
#define	REG_HOST_IF_ACC_TX_PD_QOS_COUNTERS_UPDATE        (HOST_IF_ACC_BASE_ADDRESS + 0x17C)
#define	REG_HOST_IF_ACC_GENRISC_HOST_LIST_IDX_FOR_IRQ    (HOST_IF_ACC_BASE_ADDRESS + 0x180)
#define	REG_HOST_IF_ACC_AQM_CTRL                         (HOST_IF_ACC_BASE_ADDRESS + 0x184)
#define	REG_HOST_IF_ACC_AQM_RAND_SEED                    (HOST_IF_ACC_BASE_ADDRESS + 0x188)
#define	REG_HOST_IF_ACC_AQM_LOGGER_CTRL                  (HOST_IF_ACC_BASE_ADDRESS + 0x18C)
#define	REG_HOST_IF_ACC_AQM_DBG                          (HOST_IF_ACC_BASE_ADDRESS + 0x200)
#define	REG_HOST_IF_ACC_RD_THRESHOLD_HOST_GENRISC        (HOST_IF_ACC_BASE_ADDRESS + 0x204)
#define	REG_HOST_IF_ACC_RD_COUNT_NUM_UPDATE_CFG          (HOST_IF_ACC_BASE_ADDRESS + 0x208)
#define	REG_HOST_IF_ACC_RX_OUT_IN_LIST_RD_COUNT          (HOST_IF_ACC_BASE_ADDRESS + 0x20C)
#define	REG_HOST_IF_ACC_RD_COUNT_CLR                     (HOST_IF_ACC_BASE_ADDRESS + 0x210)
#define	REG_HOST_IF_ACC_HOST_IF_ACC_ERR_INT_EN           (HOST_IF_ACC_BASE_ADDRESS + 0x214)
#define	REG_HOST_IF_ACC_BYTE_COUNT_VIOLATION_ADDR        (HOST_IF_ACC_BASE_ADDRESS + 0x218)
#define	REG_HOST_IF_ACC_TX_IN_DIST_DEBUG                 (HOST_IF_ACC_BASE_ADDRESS + 0x21C)
#define	REG_HOST_IF_ACC_TX_PD_QOS_COUNTERS1_UPDATE       (HOST_IF_ACC_BASE_ADDRESS + 0x220)
#define	REG_HOST_IF_ACC_HOST_COUNTERS1_CFG               (HOST_IF_ACC_BASE_ADDRESS + 0x224)
#define	REG_HOST_IF_ACC_BYTE_COUNT1_VIOLATION_ADDR       (HOST_IF_ACC_BASE_ADDRESS + 0x228)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_HOST_IF_ACC_SW_CLEAR_INSTRUCTION 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInSwClear : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 txOutSwClear : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 rxInSwClear : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 rxOutSwClear : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 reserved0 : 28;
	} bitFields;
} RegHostIfAccSwClearInstruction_u;

/*REG_HOST_IF_ACC_TX_IN_SW_INSTRUCTION 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInSwHalt : 1; //Halts all SM at their current state, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegHostIfAccTxInSwInstruction_u;

/*REG_HOST_IF_ACC_TX_OUT_SW_INSTRUCTION 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutSwHalt : 1; //Halts all SM at their current state, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegHostIfAccTxOutSwInstruction_u;

/*REG_HOST_IF_ACC_RX_IN_SW_INSTRUCTION 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInSwHalt : 1; //Halts all SM at their current state, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegHostIfAccRxInSwInstruction_u;

/*REG_HOST_IF_ACC_RX_OUT_SW_INSTRUCTION 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutSwHalt : 1; //Halts all SM at their current state, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegHostIfAccRxOutSwInstruction_u;

/*REG_HOST_IF_ACC_TX_IN_CONV_CFG 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInHdLineNum : 3; //Number of line in TX HD, reset value: 0x3, access type: RW
		uint32 reserved0 : 1;
		uint32 txInPdLineNum : 3; //Number of line in TX PD, reset value: 0x5, access type: RW
		uint32 reserved1 : 1;
		uint32 txInTxqIdLine : 2; //The 64 bit line the txq_id field will be written too, reset value: 0x1, access type: RW
		uint32 txInTxqIdOffset : 6; //The offset of the field in the line, reset value: 0x20, access type: RW
		uint32 reserved2 : 9;
		uint32 txInSetNullPop : 1; //Inidcate whether the pop requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 txInSetNullPush : 1; //Inidcate whether the push requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 txInMaskConversionEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInSwap : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 3;
	} bitFields;
} RegHostIfAccTxInConvCfg_u;

/*REG_HOST_IF_ACC_TX_OUT_CONV_CFG 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutHdLineNum : 3; //Number of line in TX HD, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 txOutPdLineNum : 3; //Number of line in TX PD, reset value: 0x2, access type: RW
		uint32 reserved1 : 1;
		uint32 txOutTxqIdLine : 2; //line number of the TXQ_ID field in the PD. Used for Statistic counters., reset value: 0x1, access type: RW
		uint32 reserved2 : 6;
		uint32 txOutTxqIdOffset : 6; //Offset within line of the TXQ_ID field in the PD. Used for Statistic counters., reset value: 0x20, access type: RW
		uint32 reserved3 : 3;
		uint32 txOutSetNullPop : 1; //Inidcate whether the pop requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 txOutSetNullPush : 1; //Inidcate whether the push requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 txOutMaskConversionEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txOutSwap : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved4 : 3;
	} bitFields;
} RegHostIfAccTxOutConvCfg_u;

/*REG_HOST_IF_ACC_RX_IN_CONV_CFG 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInHdLineNum : 3; //Number of line in TX HD, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxInPdLineNum : 3; //Number of line in TX PD, reset value: 0x0, access type: RW
		uint32 reserved1 : 18;
		uint32 rxInSetNullPop : 1; //Inidcate whether the pop requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 rxInSetNullPush : 1; //Inidcate whether the push requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 rxInMaskConversionEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxInSwap : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 3;
	} bitFields;
} RegHostIfAccRxInConvCfg_u;

/*REG_HOST_IF_ACC_RX_OUT_CONV_CFG 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutHdLineNum : 3; //Number of line in TX HD, reset value: 0x3, access type: RW
		uint32 reserved0 : 1;
		uint32 rxOutPdLineNum : 3; //Number of line in TX PD, reset value: 0x3, access type: RW
		uint32 reserved1 : 1;
		uint32 rxOutTxqIdLine : 2; //line number of the TXQ_ID field in the RD. Used for Statistic counters., reset value: 0x0, access type: RW
		uint32 rxOutTxqIdOffset : 6; //Offset within line of the TXQ_ID field in the RD. Used for Statistic counters., reset value: 0x25, access type: RW
		uint32 reserved2 : 9;
		uint32 rxOutSetNullPop : 1; //Inidcate whether the pop requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 rxOutSetNullPush : 1; //Inidcate whether the push requests sets null in PD or not, reset value: 0x0, access type: RW
		uint32 rxOutMaskConversionEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutSwap : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 3;
	} bitFields;
} RegHostIfAccRxOutConvCfg_u;

/*REG_HOST_IF_ACC_TX_IN_HD_BUF0_BASE_ADDR 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInHdBuf0BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccTxInHdBuf0BaseAddr_u;

/*REG_HOST_IF_ACC_TX_IN_HD_BUF1_BASE_ADDR 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInHdBuf1BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccTxInHdBuf1BaseAddr_u;

/*REG_HOST_IF_ACC_TX_OUT_HD_BUF0_BASE_ADDR 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutHdBuf0BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccTxOutHdBuf0BaseAddr_u;

/*REG_HOST_IF_ACC_TX_OUT_HD_BUF1_BASE_ADDR 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutHdBuf1BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccTxOutHdBuf1BaseAddr_u;

/*REG_HOST_IF_ACC_RX_IN_HD_BUF0_BASE_ADDR 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInHdBuf0BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccRxInHdBuf0BaseAddr_u;

/*REG_HOST_IF_ACC_RX_IN_HD_BUF1_BASE_ADDR 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInHdBuf1BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccRxInHdBuf1BaseAddr_u;

/*REG_HOST_IF_ACC_RX_OUT_HD_BUF0_BASE_ADDR 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutHdBuf0BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccRxOutHdBuf0BaseAddr_u;

/*REG_HOST_IF_ACC_RX_OUT_HD_BUF1_BASE_ADDR 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutHdBuf1BaseAddr : 22; //Base address of buffer in SHRAM. Word aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegHostIfAccRxOutHdBuf1BaseAddr_u;

/*REG_HOST_IF_ACC_TX_IN_COUNTERS 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInBufferPointer : 1; //Pointer to the next valid buffer to be read, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 txInPendingJobsCounter : 2; //Pending job counter, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 txInAvailableBuffersCounter : 2; //Free buffers for DMA HD Write, reset value: 0x2, access type: RO
		uint32 reserved2 : 14;
	} bitFields;
} RegHostIfAccTxInCounters_u;

/*REG_HOST_IF_ACC_TX_OUT_COUNTERS 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutBufferPointer : 1; //Pointer to the next valid buffer to be read, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 txOutPendingJobsCounter : 2; //Pending job counter, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 txOutAvailableBuffersCounter : 2; //Free buffers for DMA HD Write, reset value: 0x2, access type: RO
		uint32 reserved2 : 14;
	} bitFields;
} RegHostIfAccTxOutCounters_u;

/*REG_HOST_IF_ACC_RX_IN_COUNTERS 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInBufferPointer : 1; //Pointer to the next valid buffer to be read, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 rxInPendingJobsCounter : 2; //Pending job counter, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 rxInAvailableBuffersCounter : 2; //Free buffers for DMA HD Write, reset value: 0x2, access type: RO
		uint32 reserved2 : 14;
	} bitFields;
} RegHostIfAccRxInCounters_u;

/*REG_HOST_IF_ACC_RX_OUT_COUNTERS 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutBufferPointer : 1; //Pointer to the next valid buffer to be read, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 rxOutPendingJobsCounter : 2; //Pending job counter, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 rxOutAvailableBuffersCounter : 2; //Free buffers for DMA HD Write, reset value: 0x2, access type: RO
		uint32 reserved2 : 14;
	} bitFields;
} RegHostIfAccRxOutCounters_u;

/*REG_HOST_IF_ACC_TX_IN_HD_COUNT_BUF0 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInHdCount0 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccTxInHdCountBuf0_u;

/*REG_HOST_IF_ACC_TX_IN_HD_COUNT_BUF1 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInHdCount1 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccTxInHdCountBuf1_u;

/*REG_HOST_IF_ACC_TX_OUT_HD_COUNT_BUF0 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutHdCount0 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccTxOutHdCountBuf0_u;

/*REG_HOST_IF_ACC_TX_OUT_HD_COUNT_BUF1 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutHdCount1 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccTxOutHdCountBuf1_u;

/*REG_HOST_IF_ACC_RX_IN_HD_COUNT_BUF0 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInHdCount0 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccRxInHdCountBuf0_u;

/*REG_HOST_IF_ACC_RX_IN_HD_COUNT_BUF1 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInHdCount1 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccRxInHdCountBuf1_u;

/*REG_HOST_IF_ACC_RX_OUT_HD_COUNT_BUF0 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutHdCount0 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccRxOutHdCountBuf0_u;

/*REG_HOST_IF_ACC_RX_OUT_HD_COUNT_BUF1 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutHdCount1 : 8; //Number of HDs pending in Buffer , reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccRxOutHdCountBuf1_u;

/*REG_HOST_IF_ACC_TX_IN_LIST_IDX 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInPopListIdx : 7; //Index number of pop list at the DLM (bits[5:0]) , Bit[6] selects target QManager., reset value: 0x18, access type: RW
		uint32 reserved0 : 1;
		uint32 umacUcPushListIdx : 7; //Index number of push list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x8, access type: RW
		uint32 reserved1 : 1;
		uint32 umacMcPushListIdx : 7; //Index number of push list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x9, access type: RW
		uint32 reserved2 : 9;
	} bitFields;
} RegHostIfAccTxInListIdx_u;

/*REG_HOST_IF_ACC_TX_OUT_LIST_IDX 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutPopListIdx : 7; //Index number of pop list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 txOutPushListIdx : 7; //Index number of push list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x18, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegHostIfAccTxOutListIdx_u;

/*REG_HOST_IF_ACC_RX_IN_LIST_IDX 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInPopListIdx : 7; //Index number of pop list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x11, access type: RW
		uint32 reserved0 : 1;
		uint32 rxInPushListIdx : 7; //Index number of push list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x18, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegHostIfAccRxInListIdx_u;

/*REG_HOST_IF_ACC_RX_OUT_LIST_IDX 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutPopListIdx : 7; //Index number of pop list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxOutPushListIdx : 7; //Index number of push list at the DLM(bits[5:0]) , Bit[6] selects target QManager., reset value: 0x11, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegHostIfAccRxOutListIdx_u;

/*REG_HOST_IF_ACC_MULTICAST_PD_DISTRIB_CFG 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 groupVapPrio : 2; //Defines VAP Group priority: , 0x0 – All Multicast PDs are distributed through UMAC , 0x1 - Multicast PDs are distributed according to Group index configuration , 0x2 - Multicast PDs are distributed according to VAP index configuration , 0x3 - Multicast PDs are distributed to UMAC only if both group and VAP       ,          index are set to it, reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
		uint32 mcBitLine : 2; //Multicast bit line at TX PD, reset value: 0x0, access type: RW
		uint32 mcBitOffset : 6; //Multicast bit offset in line at TX PD, reset value: 0x0, access type: RW
		uint32 groupIdxLine : 2; //Group index field line at TX PD, reset value: 0x0, access type: RW
		uint32 groupIdxOffset : 6; //Group index field offset in line at TX PD, reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccMulticastPdDistribCfg_u;

/*REG_HOST_IF_ACC_PD_DISTRIB_UPDATE 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pdDistAddr : 13; //Access address: , Unicast    : {TID[3],STA[7:0],TID[2:0]} , MC Group: {5'h0,Group_IDX[6:0]} , MC VAP  : {7'h0,VAP_IDX[4:0]}, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 pdDistAllTids : 1; //For Unicast (STA) only - Update TIDs 0-7 in one instruction. MGMT TID will need a separate access., reset value: 0x0, access type: RW
		uint32 reserved1 : 3;
		uint32 pdDistType : 2; //Update type: , 0: Unicast lines 0-71 , 1: Group lines 72-75 , 2: VAP line 76, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pdDistBitValue : 8; //Update value, reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccPdDistribUpdate_u;

/*REG_HOST_IF_ACC_FREE_PD_INIT 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freePdInit : 17; //Initial Free PD number, reset value: 0x800, access type: RW
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccFreePdInit_u;

/*REG_HOST_IF_ACC_PD_THRESHOLD 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pdThres : 17; //PD threshold limit, reset value: 0x10, access type: RW
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccPdThreshold_u;

/*REG_HOST_IF_ACC_FREE_PD_COUNT 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freePdCount : 17; //Free PD count, reset value: 0x800, access type: RO
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccFreePdCount_u;

/*REG_HOST_IF_ACC_TX_RING_CFG 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutRingSize : 16; //TX OUT Ring size, reset value: 0x20, access type: RW
		uint32 txInInOrder : 1; //TX IN is working in order with Host Ring, reset value: 0x0, access type: RW
		uint32 txOutInOrder : 1; //TX OUT is working in order with Host Ring, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 txSameBuffer : 1; //TX Host Ring uses same buffer, reset value: 0x0, access type: RW
		uint32 reserved1 : 3;
		uint32 txInOwnBitCheckEn : 1; //TX IN HD own bit check enable, reset value: 0x1, access type: RW
		uint32 txOutOwnBitCheckEn : 1; //TX OUT HD own bit check enable, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 txInRingWraparound : 1; //TX IN Host Ring supports wrap around, reset value: 0x0, access type: RW
		uint32 txOutRingWraparound : 1; //TX OUT Host Ring supports wrap around, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegHostIfAccTxRingCfg_u;

/*REG_HOST_IF_ACC_RX_RING_CFG 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutRingSize : 16; //RX OUT Ring size, reset value: 0x20, access type: RW
		uint32 rxInInOrder : 1; //RX IN is working in order with Host Ring, reset value: 0x1, access type: RW
		uint32 rxOutInOrder : 1; //RX OUT is working in order with Host Ring, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 rxSameBuffer : 1; //RX Host Ring uses same buffer, reset value: 0x1, access type: RW
		uint32 reserved1 : 3;
		uint32 rxInOwnBitCheckEn : 1; //RX IN HD own bit check enable, reset value: 0x0, access type: RW
		uint32 rxOutOwnBitCheckEn : 1; //RX OUT HD own bit check enable, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 rxInRingWraparound : 1; //RX IN Host Ring supports wrap around, reset value: 0x0, access type: RW
		uint32 rxOutRingWraparound : 1; //RX OUT Host Ring supports wrap around, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegHostIfAccRxRingCfg_u;

/*REG_HOST_IF_ACC_OWN_BIT_VALUE 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ownBitValue : 1; //OWN bit value polarity, reset value: 0x0, access type: RW
		uint32 reserved0 : 15;
		uint32 ownBitLine : 3; //Own bit line at TX HD, reset value: 0x0, access type: RW
		uint32 ownBitOffset : 5; //Own bit offset in line at TX HD, reset value: 0x0, access type: RW
		uint32 reserved1 : 8;
	} bitFields;
} RegHostIfAccOwnBitValue_u;

/*REG_HOST_IF_ACC_TX_IN_COUNTERS_UPDATE 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInPendingPush : 1; //Add 1 to pending_jobs counter, reset value: 0x0, access type: WO
		uint32 txInPendingPop : 1; //Remove 1 from pending_jobs counter, reset value: 0x0, access type: WO
		uint32 txInAvailablePush : 1; //Add 1 to available_buffers counter, reset value: 0x0, access type: WO
		uint32 txInAvailablePop : 1; //Remove 1 from available_buffers counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 28;
	} bitFields;
} RegHostIfAccTxInCountersUpdate_u;

/*REG_HOST_IF_ACC_TX_OUT_COUNTERS_UPDATE 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutPendingPush : 1; //Add 1 to pending_jobs counter, reset value: 0x0, access type: WO
		uint32 txOutPendingPop : 1; //Remove 1 from pending_jobs counter, reset value: 0x0, access type: WO
		uint32 txOutAvailablePush : 1; //Add 1 to available_buffers counter, reset value: 0x0, access type: WO
		uint32 txOutAvailablePop : 1; //Remove 1 from available_buffers counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 28;
	} bitFields;
} RegHostIfAccTxOutCountersUpdate_u;

/*REG_HOST_IF_ACC_RX_IN_COUNTERS_UPDATE 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInPendingPush : 1; //Add 1 to pending_jobs counter, reset value: 0x0, access type: WO
		uint32 rxInPendingPop : 1; //Remove 1 from pending_jobs counter, reset value: 0x0, access type: WO
		uint32 rxInAvailablePush : 1; //Add 1 to available_buffers counter, reset value: 0x0, access type: WO
		uint32 rxInAvailablePop : 1; //Remove 1 from available_buffers counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 28;
	} bitFields;
} RegHostIfAccRxInCountersUpdate_u;

/*REG_HOST_IF_ACC_RX_OUT_COUNTERS_UPDATE 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutPendingPush : 1; //Add 1 to pending_jobs counter, reset value: 0x0, access type: WO
		uint32 rxOutPendingPop : 1; //Remove 1 from pending_jobs counter, reset value: 0x0, access type: WO
		uint32 rxOutAvailablePush : 1; //Add 1 to available_buffers counter, reset value: 0x0, access type: WO
		uint32 rxOutAvailablePop : 1; //Remove 1 from available_buffers counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 28;
	} bitFields;
} RegHostIfAccRxOutCountersUpdate_u;

/*REG_HOST_IF_ACC_TX_IN_HOST_IF_STATUS 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInQmPopState : 1; //Queue Manger POP list State machine status, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 txInQmPushState : 1; //Queue Manger PUSH list State machine status, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
		uint32 txInDecSmState : 2; //Code decoding State machine status, reset value: 0x0, access type: RO
		uint32 reserved2 : 6;
		uint32 txInConverterState : 3; //Conversion State machine status, reset value: 0x0, access type: RO
		uint32 reserved3 : 5;
	} bitFields;
} RegHostIfAccTxInHostIfStatus_u;

/*REG_HOST_IF_ACC_TX_OUT_HOST_IF_STATUS 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutQmPopState : 1; //Queue Manger POP list State machine status, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 txOutQmPushState : 1; //Queue Manger PUSH list State machine status, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
		uint32 txOutDecSmState : 2; //Code decoding State machine status, reset value: 0x0, access type: RO
		uint32 reserved2 : 6;
		uint32 txOutConverterState : 3; //Conversion State machine status, reset value: 0x0, access type: RO
		uint32 reserved3 : 5;
	} bitFields;
} RegHostIfAccTxOutHostIfStatus_u;

/*REG_HOST_IF_ACC_RX_IN_HOST_IF_STATUS 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInQmPopState : 1; //Queue Manger POP list State machine status, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 rxInQmPushState : 1; //Queue Manger PUSH list State machine status, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
		uint32 rxInDecSmState : 2; //Code decoding State machine status, reset value: 0x0, access type: RO
		uint32 reserved2 : 6;
		uint32 rxInConverterState : 3; //Conversion State machine status, reset value: 0x0, access type: RO
		uint32 reserved3 : 5;
	} bitFields;
} RegHostIfAccRxInHostIfStatus_u;

/*REG_HOST_IF_ACC_RX_OUT_HOST_IF_STATUS 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutQmPopState : 1; //Queue Manger POP list State machine status, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 rxOutQmPushState : 1; //Queue Manger PUSH list State machine status, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
		uint32 rxOutDecSmState : 2; //Code decoding State machine status, reset value: 0x0, access type: RO
		uint32 reserved2 : 6;
		uint32 rxOutConverterState : 3; //Conversion State machine status, reset value: 0x0, access type: RO
		uint32 reserved3 : 5;
	} bitFields;
} RegHostIfAccRxOutHostIfStatus_u;

/*REG_HOST_IF_ACC_SW_COUNTERS_CLR 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutMgmtCountClr : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 txInMgmtCountClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 rxInMgmtCountClr : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 txOutMgmtCountClr : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 hostMacCountClr : 1; //Clears all counters and SM, reset value: 0x0, access type: WO
		uint32 macHostCountClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved0 : 26;
	} bitFields;
} RegHostIfAccSwCountersClr_u;

/*REG_HOST_IF_ACC_THRESHOLD_CLR 0xD4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pdThresReachedIntClr : 1; //PD threshold reached interrupt Clear, reset value: 0x0, access type: WO
		uint32 reserved0 : 7;
		uint32 rdThresReachedIntClr : 1; //RD threshold reached interrupt Clear, reset value: 0x0, access type: WO
		uint32 reserved1 : 23;
	} bitFields;
} RegHostIfAccThresholdClr_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_STATUS 0xD8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 rxOutPendingJobsInt : 1; //Rx out pending jobs int, reset value: 0x0, access type: RO
		uint32 rxInHdBufferFreeInt : 1; //Rx in hd buffer free int, reset value: 0x1, access type: RO
		uint32 reserved1 : 2;
		uint32 txOutPendingJobsInt : 1; //Tx out pending jobs int, reset value: 0x0, access type: RO
		uint32 txInHdBufferFreeInt : 1; //Tx in hd buffer free int, reset value: 0x0, access type: RO
		uint32 reserved2 : 1;
		uint32 rxInHdCountNotEmptyIrq : 1; //Rx in hd count not empty irq, reset value: 0x0, access type: RO
		uint32 txInHdCountNotEmptyIrq : 1; //Tx in hd count not empty irq, reset value: 0x0, access type: RO
		uint32 reserved3 : 4;
		uint32 rdFreeCountLessThresGenrisc : 1; //RD free counter less threshold of Host GenRisc, reset value: 0x0, access type: RO
		uint32 reserved4 : 17;
	} bitFields;
} RegHostIfAccHostGenriscIrqStatus_u;

/*REG_HOST_IF_ACC_HOST_IF_ACC_ERR_INT 0xDC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 busyPdCountOverflowInt : 1; //Number of busy PDs overflow interrupt, reset value: 0x0, access type: RO
		uint32 txInOwnBitErrInt : 1; //Own bit error interrupt, reset value: 0x0, access type: RO
		uint32 busyRdCountOverflowInt : 1; //Busy RD count overflow interrupt, reset value: 0x0, access type: RO
		uint32 byteCountNegativeWriteErr : 1; //Negative Byte/PD counter update error, reset value: 0x0, access type: RO
		uint32 byteCountWraparoundErr : 1; //Byte/PD counter wraparound error, reset value: 0x0, access type: RO
		uint32 freeRdCountOverflowInt : 1; //Free RD count overflow interrupt, reset value: 0x0, access type: RO
		uint32 rxOutInListRdCountOverflowInt : 1; //RD count of the temp list between Rx Out to Rx In overflow interrupt, reset value: 0x0, access type: RO
		uint32 byteCount1NegativeWriteErr : 1; //Similarly to "byte_count_negative_write_err" interrupt, but related to STA256..511, VAP32.63, reset value: 0x0, access type: RO
		uint32 byteCount1WraparoundErr : 1; //Similarly to "byte_count_wraparound_err" interrupt, but related to STA256..511, VAP32.63 , , , reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegHostIfAccHostIfAccErrInt_u;

/*REG_HOST_IF_ACC_HOST_IF_ACC_ERR_INT_CLR 0xE0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 busyPdCountOverflowIntClr : 1; //Number of busy PDs overflow interrupt Clear, reset value: 0x0, access type: WO
		uint32 txInOwnBitErrIntClr : 1; //Own bit error interrupt Clear, reset value: 0x0, access type: WO
		uint32 busyRdCountOverflowIntClr : 1; //Busy RD count overflow interrupt Clear, reset value: 0x0, access type: WO
		uint32 byteCountNegativeWriteErrClr : 1; //Negative Byte/PD counter update error Clear, reset value: 0x0, access type: RW
		uint32 byteCountWraparoundErrClr : 1; //Byte/PD counter wraparound error Clear, reset value: 0x0, access type: RW
		uint32 freeRdCountOverflowIntClr : 1; //Free RD count overflow interrupt Clear, reset value: 0x0, access type: WO
		uint32 rxOutInListRdCountOverflowIntClr : 1; //RD count of the temp list between Rx Out to Rx In RD count overflow interrupt Clear, reset value: 0x0, access type: WO
		uint32 byteCount1NegativeWriteErrClr : 1; //no description, reset value: 0x0, access type: RW
		uint32 byteCount1WraparoundErrClr : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegHostIfAccHostIfAccErrIntClr_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_A 0xE4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskA : 15; //Mask of Host GenRISC interrupts into group A, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskAOperation : 1; //Mask of Host GenRISC interrupts into group A operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskA_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_B 0xE8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskB : 15; //Mask of Host GenRISC interrupts into group B, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskBOperation : 1; //Mask of Host GenRISC interrupts into group B operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskB_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_C 0xEC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskC : 15; //Mask of Host GenRISC interrupts into group C, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskCOperation : 1; //Mask of Host GenRISC interrupts into group C operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskC_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_D 0xF0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskD : 15; //Mask of Host GenRISC interrupts into group D, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskDOperation : 1; //Mask of Host GenRISC interrupts into group D operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskD_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_E 0xF4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskE : 15; //Mask of Host GenRISC interrupts into group E, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskEOperation : 1; //Mask of Host GenRISC interrupts into group E operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskE_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_F 0xF8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskF : 15; //Mask of Host GenRISC interrupts into group F, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskFOperation : 1; //Mask of Host GenRISC interrupts into group F operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskF_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_G 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskG : 15; //Mask of Host GenRISC interrupts into group G, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskGOperation : 1; //Mask of Host GenRISC interrupts into group G operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskG_u;

/*REG_HOST_IF_ACC_HOST_GENRISC_IRQ_MASK_H 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hostGenriscIrqMaskH : 15; //Mask of Host GenRISC interrupts into group H, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
		uint32 hostGenriscIrqMaskHOperation : 1; //Mask of Host GenRISC interrupts into group H operation: 0 - OR, 1 - AND , reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccHostGenriscIrqMaskH_u;

/*REG_HOST_IF_ACC_DEBUG_REG 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInPopListEmpty : 1; //pop list empty signal indication, reset value: 0x1, access type: RO
		uint32 txOutPopListEmpty : 1; //pop list empty signal indication, reset value: 0x1, access type: RO
		uint32 rxInPopListEmpty : 1; //pop list empty signal indication, reset value: 0x1, access type: RO
		uint32 rxOutPopListEmpty : 1; //pop list empty signal indication, reset value: 0x1, access type: RO
		uint32 txInCoreBusy : 1; //core is busy indication, reset value: 0x0, access type: RO
		uint32 txOutCoreBusy : 1; //core is busy indication, reset value: 0x0, access type: RO
		uint32 rxInCoreBusy : 1; //core is busy indication, reset value: 0x0, access type: RO
		uint32 rxOutCoreBusy : 1; //core is busy indication, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccDebugReg_u;

/*REG_HOST_IF_ACC_GCLK_BYPASS_EN 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInCoreGclkBypassEn : 1; //gated clock bypass, reset value: 0x0, access type: RW
		uint32 txOutCoreGclkBypassEn : 1; //gated clock bypass, reset value: 0x0, access type: RW
		uint32 rxInCoreGclkBypassEn : 1; //gated clock bypass, reset value: 0x0, access type: RW
		uint32 rxOutCoreGclkBypassEn : 1; //gated clock bypass, reset value: 0x0, access type: RW
		uint32 regFileGclkBypassEn : 1; //gated clock bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 27;
	} bitFields;
} RegHostIfAccGclkBypassEn_u;

/*REG_HOST_IF_ACC_TTL_SCALE_SET 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ttlScale : 3; //no description, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegHostIfAccTtlScaleSet_u;

/*REG_HOST_IF_ACC_HOST_COUNTERS_CFG 0x130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 2;
		uint32 txInUniHdCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInMultiHdCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInBroadcastHdCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInUniBytesCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInMultiBytesCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInBroadcastBytesCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutUniHdCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutMultiHdCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutBroadcastHdCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutUniBytesCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutMultiBytesCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutBroadcastBytesCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutStaBytesCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 agerCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 agerPdNoTransmitCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidByteCountIncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidByteCountDecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidPdCountIncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidPdCountDecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidPdCountIncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidPdCountDecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidByteCountIncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidByteCountDecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
		uint32 txCountCleanFifo : 1; //no description, reset value: 0x0, access type: WO
	} bitFields;
} RegHostIfAccHostCountersCfg_u;

/*REG_HOST_IF_ACC_TX_IN_MULTICAST_CFG 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInByteCountLine : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 txInByteCountOffset : 6; //no description, reset value: 0x30, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegHostIfAccTxInMulticastCfg_u;

/*REG_HOST_IF_ACC_RX_OUT_MULTICAST_CFG 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutByteCountLine : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 rxOutByteCountOffset : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxOutMcBitLine : 2; //Multicast bit line at TX PD, reset value: 0x0, access type: RW
		uint32 rxOutMcBitOffset : 6; //Multicast bit offset in line at TX PD, reset value: 0x0, access type: RW
		uint32 rxOutBcBitLine : 2; //Group index field line at TX PD, reset value: 0x0, access type: RW
		uint32 rxOutBcBitOffset : 6; //Group index field offset in line at TX PD, reset value: 0x0, access type: RW
	} bitFields;
} RegHostIfAccRxOutMulticastCfg_u;

/*REG_HOST_IF_ACC_RD_THRESHOLD 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdThres : 17; //RD threshold limit for FW IRQ, reset value: 0x0, access type: RW
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccRdThreshold_u;

/*REG_HOST_IF_ACC_FREE_RD_COUNT 0x148 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freeRdCount : 17; //Free PD count, reset value: 0x0, access type: RO
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccFreeRdCount_u;

/*REG_HOST_IF_ACC_TX_HD_BUSY_COUNT 0x14C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txHdBusyCount : 17; //Busy Tx HD count, reset value: 0x0, access type: RO
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccTxHdBusyCount_u;

/*REG_HOST_IF_ACC_RX_HD_BUSY_COUNT 0x150 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxHdBusyCount : 17; //Busy Rx HD count, reset value: 0x0, access type: RO
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccRxHdBusyCount_u;

/*REG_HOST_IF_ACC_UMT_ORDER_CFG 0x154 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxInTxIn : 1; //Initial Free PD number, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegHostIfAccUmtOrderCfg_u;

/*REG_HOST_IF_ACC_HOST_LOGGER_CFG 0x158 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInLoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 txInLoggerShortEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInLoggerLongEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txOutLoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 txOutLoggerShortEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 txOutLoggerLongEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxInLoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 rxInLoggerShortEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxInLoggerLongEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutLoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 rxOutLoggerShortEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutLoggerLongEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegHostIfAccHostLoggerCfg_u;

/*REG_HOST_IF_ACC_HOST_LOGGER_BUSY 0x15C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInLoggerBusy : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 txOutLoggerBusy : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
		uint32 rxInLoggerBusy : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved2 : 7;
		uint32 rxOutLoggerBusy : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 7;
	} bitFields;
} RegHostIfAccHostLoggerBusy_u;

/*REG_HOST_IF_ACC_TX_OUT_MAX_HD 0x160 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutMaxHdNum : 12; //no description, reset value: 0x20, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegHostIfAccTxOutMaxHd_u;

/*REG_HOST_IF_ACC_RX_OUT_MAX_HD 0x164 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutMaxHdNum : 12; //no description, reset value: 0x20, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegHostIfAccRxOutMaxHd_u;

/*REG_HOST_IF_ACC_TX_OUT_CYCLIC_COUNTER_INIT 0x168 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutCyclicInitValue : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegHostIfAccTxOutCyclicCounterInit_u;

/*REG_HOST_IF_ACC_RX_OUT_CYCLIC_COUNTER_INIT 0x16C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutCyclicInitValue : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegHostIfAccRxOutCyclicCounterInit_u;

/*REG_HOST_IF_ACC_TX_OUT_BUFFER_LIMIT_CFG 0x170 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txOutBufferLimitEn : 1; //Enables buffer limit feature, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 txOutBufferMin : 8; //Minimum number of conversions (minus one) to enable flow done, reset value: 0x0, access type: RW
		uint32 txOutTimeout : 20; //If there is no new HD in the input list for this period of time (in cycles) the conversion flow is done, reset value: 0x100, access type: RW
	} bitFields;
} RegHostIfAccTxOutBufferLimitCfg_u;

/*REG_HOST_IF_ACC_RX_OUT_BUFFER_LIMIT_CFG 0x174 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutBufferLimitEn : 1; //Enables buffer limit feature, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 rxOutBufferMin : 8; //Minimum number of conversions (minus one) to enable flow done, reset value: 0x0, access type: RW
		uint32 rxOutTimeout : 20; //If there is no new HD in the input list for this period of time (in cycles) the conversion flow is done, reset value: 0x100, access type: RW
	} bitFields;
} RegHostIfAccRxOutBufferLimitCfg_u;

/*REG_HOST_IF_ACC_PD_LENGTH_LOCATION_CFG 0x178 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txLengthInPdLineNum : 3; //Line number in PD for "length" field. Used at TX Out core., reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 txLengthInPdOffset : 5; //Offset in PD for "length" field. Used at TX Out core., reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
		uint32 txLengthInHdLineNum : 3; //Line number in HD for "length" field. Used at TX In core., reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 txLengthInHdOffset : 5; //Offset in HD for "length" field. Used at TX In core., reset value: 0x0, access type: RW
		uint32 reserved3 : 7;
	} bitFields;
} RegHostIfAccPdLengthLocationCfg_u;

/*REG_HOST_IF_ACC_TX_PD_QOS_COUNTERS_UPDATE 0x17C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txPdQosCountersByteCountNum : 16; //Number of Bytes to inc/dec from STA-TID/VAP-TID counter. , Relevant only to STA-TID/VAP-TID byte counter., reset value: 0x0, access type: RW
		uint32 txPdQosCountersTidNum : 3; //TID index, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 txPdQosCountersStaVapNum : 8; //In case of STA counter: STA index , In case of VAP counter: VAP index, reset value: 0x0, access type: RW
		uint32 txPdQosCountersType : 2; //Which counter to update: , 00: TX_QOS_STA_BYTE_COUNT, , 01: TX_QOS_STA_EVENT, , 10: TX_QOS_VAP_EVENT, , 11: TX_QOS_VAP_BYTE_COUNT,, reset value: 0x0, access type: RW
		uint32 txPdQosCountersCountInc : 1; //no description, reset value: 0x0, access type: RW
		uint32 txPdQosCountersUpdateDone : 1; //no description, reset value: 0x1, access type: RO
	} bitFields;
} RegHostIfAccTxPdQosCountersUpdate_u;

/*REG_HOST_IF_ACC_GENRISC_HOST_LIST_IDX_FOR_IRQ 0x180 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 genriscHostPdListIdxForIrq : 7; //PD list index for Not empty IRQ to GenRisc HOST, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 genriscHostRdListIdxForIrq : 7; //RD list index for Not empty IRQ to GenRisc HOST, reset value: 0x0, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegHostIfAccGenriscHostListIdxForIrq_u;

/*REG_HOST_IF_ACC_AQM_CTRL 0x184 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aqmHwEna : 1; //'1' = enable AQM HW. Otherwise no packet drop performed in HW., reset value: 0x0, access type: RW
		uint32 aqmDropListId : 7; //List index of the dropped PD , MS bit of the list_id selects target QManager instance., reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegHostIfAccAqmCtrl_u;

/*REG_HOST_IF_ACC_AQM_RAND_SEED 0x188 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aqmRandSeed : 32; //Seed number of the HW random number generator in the AQM block., reset value: 0x87654321, access type: RW
	} bitFields;
} RegHostIfAccAqmRandSeed_u;

/*REG_HOST_IF_ACC_AQM_LOGGER_CTRL 0x18C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aqmLoggerEna : 1; //'1' enables AQM HW logger sampling. , reset value: 0x0, access type: RW
		uint32 aqmLoggerActive : 1; //'1' - AQM HW logger transaction ongoing., reset value: 0x0, access type: RO
		uint32 aqmLoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegHostIfAccAqmLoggerCtrl_u;

/*REG_HOST_IF_ACC_AQM_DBG 0x200 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aqmDbg : 32; //Various debug signals. Refer to the AQM HW RTL for the exact list., reset value: 0x00040000, access type: RO
	} bitFields;
} RegHostIfAccAqmDbg_u;

/*REG_HOST_IF_ACC_RD_THRESHOLD_HOST_GENRISC 0x204 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdThresholdHostGenrisc : 17; //RD free count threshold limit for Host GenRisc IRQ, reset value: 0x0, access type: RW
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccRdThresholdHostGenrisc_u;

/*REG_HOST_IF_ACC_RD_COUNT_NUM_UPDATE_CFG 0x208 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdCountNumUpdateCfg : 17; //Number of RDs to increment/decrement, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 freeRdCountCfgAddPulse : 1; //Free RD count increment, reset value: 0x0, access type: WO
		uint32 freeRdCountCfgSubPulse : 1; //Free RD count decrement, reset value: 0x0, access type: WO
		uint32 busyRdCountCfgAddPulse : 1; //Busy RD count increment, reset value: 0x0, access type: WO
		uint32 busyRdCountCfgSubPulse : 1; //Busy RD count decrement, reset value: 0x0, access type: WO
		uint32 rxOutInListRdCountCfgAddPulse : 1; //Temp list between Rx Out to Rx In RD count increment, reset value: 0x0, access type: WO
		uint32 rxOutInListRdCountCfgSubPulse : 1; //Temp list between Rx Out to Rx In RD count decrement, reset value: 0x0, access type: WO
		uint32 reserved1 : 2;
	} bitFields;
} RegHostIfAccRdCountNumUpdateCfg_u;

/*REG_HOST_IF_ACC_RX_OUT_IN_LIST_RD_COUNT 0x20C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxOutInListRdCount : 17; //RD count of the temp list between Rx Out to Rx In, reset value: 0x0, access type: RO
		uint32 reserved0 : 15;
	} bitFields;
} RegHostIfAccRxOutInListRdCount_u;

/*REG_HOST_IF_ACC_RD_COUNT_CLR 0x210 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 busyRdCountClr : 1; //Busy RD count Clear, reset value: 0x0, access type: WO
		uint32 freeRdCountClr : 1; //Free RD count Clear, reset value: 0x0, access type: WO
		uint32 rxOutInListRdCountClr : 1; //RD count of the temp list between Rx Out to Rx In RD count Clear, reset value: 0x0, access type: WO
		uint32 reserved0 : 29;
	} bitFields;
} RegHostIfAccRdCountClr_u;

/*REG_HOST_IF_ACC_HOST_IF_ACC_ERR_INT_EN 0x214 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 busyPdCountOverflowIntEn : 1; //Number of busy PDs overflow interrupt enable, reset value: 0x0, access type: RW
		uint32 txInOwnBitErrIntEn : 1; //Own bit error interrupt enable, reset value: 0x1, access type: RW
		uint32 busyRdCountOverflowIntEn : 1; //Busy RD count overflow interrupt enable, reset value: 0x1, access type: RW
		uint32 byteCountNegativeWriteErrEn : 1; //Negative Byte/PD counter update error enable, reset value: 0x1, access type: RW
		uint32 byteCountWraparoundErrEn : 1; //Byte/PD counter wraparound error enable, reset value: 0x1, access type: RW
		uint32 freeRdCountOverflowIntEn : 1; //Free RD count overflow interrupt enable, reset value: 0x1, access type: RW
		uint32 rxOutInListRdCountOverflowIntEn : 1; //RD count of the temp list between Rx Out to Rx In overflow interrupt enable, reset value: 0x1, access type: RW
		uint32 byteCount1NegativeWriteErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 byteCount1WraparoundErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegHostIfAccHostIfAccErrIntEn_u;

/*REG_HOST_IF_ACC_BYTE_COUNT_VIOLATION_ADDR 0x218 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 byteCountNegativeViolationAddr : 15; //Counter address of the first byte/pd counter negative violation. , Presents the memory address as appears in the counter excel of HOST IF QoS counters., reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 byteCountWraparoundViolationAddr : 15; //Counter address of the first byte/pd counter wraparound violation. , Presents the memory address as appears in the counter excel of HOST IF QoS counters., reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
	} bitFields;
} RegHostIfAccByteCountViolationAddr_u;

/*REG_HOST_IF_ACC_TX_IN_DIST_DEBUG 0x21C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txInDistDebug : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegHostIfAccTxInDistDebug_u;

/*REG_HOST_IF_ACC_TX_PD_QOS_COUNTERS1_UPDATE 0x220 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txPdQosCounters1ByteCountNum : 16; //Number of Bytes to inc/dec from STA-TID/VAP-TID counter. , Relevant only to STA-TID/VAP-TID byte counter., reset value: 0x0, access type: RW
		uint32 txPdQosCounters1TidNum : 3; //TID index, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 txPdQosCounters1StaVapNum : 8; //In case of STA counter: STA index (0-->STA256, 255-->STA511) , In case of VAP counter: VAP index (0-->VAP32, 31-->VAP63), reset value: 0x0, access type: RW
		uint32 txPdQosCounters1Type : 2; //Which counter to update: , 00: TX_QOS_STA_BYTE_COUNT, , 01: TX_QOS_STA_EVENT, , 10: TX_QOS_VAP_EVENT, , 11: TX_QOS_VAP_BYTE_COUNT,, reset value: 0x0, access type: RW
		uint32 txPdQosCounters1CountInc : 1; //no description, reset value: 0x0, access type: RW
		uint32 txPdQosCounters1UpdateDone : 1; //no description, reset value: 0x1, access type: RO
	} bitFields;
} RegHostIfAccTxPdQosCounters1Update_u;

/*REG_HOST_IF_ACC_HOST_COUNTERS1_CFG 0x224 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 2;
		uint32 txInUniHdCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInMultiHdCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInBroadcastHdCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInUniBytesCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInMultiBytesCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 txInBroadcastBytesCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutUniHdCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutMultiHdCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutBroadcastHdCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutUniBytesCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutMultiBytesCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutBroadcastBytesCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxOutStaBytesCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 agerCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 agerPdNoTransmitCount1En : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidByteCount1IncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidByteCount1DecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidPdCount1IncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxStaTidPdCount1DecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidPdCount1IncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidPdCount1DecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidByteCount1IncEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 qosTxVapTidByteCount1DecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
		uint32 txCount1CleanFifo : 1; //no description, reset value: 0x0, access type: WO
	} bitFields;
} RegHostIfAccHostCounters1Cfg_u;

/*REG_HOST_IF_ACC_BYTE_COUNT1_VIOLATION_ADDR 0x228 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 byteCount1NegativeViolationAddr : 15; //Counter address of the first byte/pd counter negative violation. , Presents the memory address as appears in the counter excel of HOST IF QoS counters., reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 byteCount1WraparoundViolationAddr : 15; //Counter address of the first byte/pd counter wraparound violation. , Presents the memory address as appears in the counter excel of HOST IF QoS counters., reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
	} bitFields;
} RegHostIfAccByteCount1ViolationAddr_u;



#endif // _HOST_IF_ACC_REGS_H_
