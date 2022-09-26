
/***********************************************************************************
File:				B1PhyRxBeIfRegs.h
Module:				b1PhyRxBeIf
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:11:59
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_PHY_RX_BE_IF_REGS_H_
#define _B1_PHY_RX_BE_IF_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_PHY_RX_BE_IF_BASE_ADDRESS                             MEMORY_MAP_UNIT_10201_BASE_ADDRESS
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF180          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1600)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF181          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1604)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF182          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1608)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF183          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x160C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF184          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1610)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF185          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1614)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF186          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1618)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF187          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x161C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF189          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1620)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF18D          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1634)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF18E          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1638)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF18F          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x163C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF190          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1640)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF192          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1648)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF193          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x164C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF194          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1650)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF195          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1654)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF196          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1658)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19B          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x166C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19C          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1670)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19D          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1674)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19E          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1678)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19F          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x167C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A0          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1680)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A1          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1684)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF_RISC_INT    (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1688)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A3          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x168C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A4          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1690)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A5          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1694)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A6          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1698)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A7          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x169C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A8          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16A0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A9          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16A4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AA          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16A8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AB          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16AC)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AC          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16B0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AD          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16B4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AE          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16B8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B0          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16C0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B2          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16C8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B3          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16CC)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B4          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16D0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B5          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16D4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B6          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16D8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B7          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16DC)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B8          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16E0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B9          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16E4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BA          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16E8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BB          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16EC)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BC          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16F0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BD          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16F4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BE          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16F8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BF          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x16FC)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C0          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1700)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C1          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1704)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C2          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1708)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C3          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x170C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C4          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1710)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C5          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1714)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C6          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1718)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C7          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x171C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C8          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1720)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C9          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1724)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CA          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1728)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CB          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x172C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CD          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1730)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CE          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1734)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CF          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1738)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D0          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x173C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D1          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1740)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D2          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1744)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D3          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1748)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D4          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x174C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D5          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1750)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D6          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1754)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D7          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1758)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D8          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x175C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DA          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1764)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DB          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1768)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DC          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x176C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DD          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1770)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DE          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1774)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DF          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1778)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E0          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x177C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E1          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1780)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E2          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1784)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E3          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1788)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E4          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x178C)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E5          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x1790)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E9          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17A0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EA          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17A4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EB          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17A8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EC          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17AC)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1ED          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17B0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EE          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17B4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CC          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17B8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EF          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17BC)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1F0          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17C0)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1F4          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17C4)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1F8          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17C8)
#define	REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1FC          (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17CC)
#define	REG_B1_PHY_RX_BE_IF_PAC_PHY_PACKET_TYPE     (B1_PHY_RX_BE_IF_BASE_ADDRESS + 0x17D0)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF180 0x1600 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swResetNReg : 12; //BE sub blocks sw reset, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf180_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF181 0x1604 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 blocksEn : 12; //BE_sub blocks block en, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf181_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF182 0x1608 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swResetGenerate : 12; //sw_reset_generate, reset value: 0x0, access type: WO
		uint32 reserved0 : 20;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf182_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF183 0x160C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 gsmSwResetMask : 12; //gsm_sw_reset_mask, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf183_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF184 0x1610 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant0AdRssi : 8; //ant0_ad_rssi, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf184_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF185 0x1614 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant1AdRssi : 8; //ant1_ad_rssi, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf185_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF186 0x1618 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant2AdRssi : 8; //ant2_ad_rssi, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf186_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF187 0x161C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant3AdRssi : 8; //ant3_ad_rssi, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf187_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF189 0x1620 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant4AdRssi : 8; //ant4_ad_rssi, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf189_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF18D 0x1634 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant0RfGain : 8; //ant0_rf_gain, reset value: 0x0, access type: RW
		uint32 ant1RfGain : 8; //ant1_rf_gain, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf18D_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF18E 0x1638 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant2RfGain : 8; //ant2_rf_gain, reset value: 0x0, access type: RW
		uint32 ant3RfGain : 8; //ant3_rf_gain, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf18E_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF18F 0x163C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 8;
		uint32 ant4RfGain : 8; //ant4_rf_gain, reset value: 0x0, access type: RW
		uint32 reserved1 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf18F_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF190 0x1640 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 riscModulation : 3; //risc_modulation, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 riscCodeRate : 2; //risc_code_rate, reset value: 0x2, access type: RW
		uint32 reserved1 : 2;
		uint32 riscViterbiNes : 2; //risc_viterbi_nes, reset value: 0x1, access type: RW
		uint32 reserved2 : 2;
		uint32 riscOverride : 1; //risc_override, reset value: 0x0, access type: RW
		uint32 riscMcsValid : 1; //risc_mcs_valid, reset value: 0x0, access type: RW
		uint32 reserved3 : 18;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf190_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF192 0x1648 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant0NoiseEst : 8; //antenna0 noise estimation, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf192_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF193 0x164C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant1NoiseEst : 8; //antenna1 noise estimation, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf193_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF194 0x1650 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant2NoiseEst : 8; //antenna2 noise estimation, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf194_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF195 0x1654 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant3NoiseEst : 8; //antenna3 noise estimation, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf195_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF196 0x1658 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ant4NoiseEst : 8; //antenna4 noise estimation, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf196_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19B 0x166C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aLength : 12; //a length, reset value: 0x0, access type: RO
		uint32 aRate : 4; //a rate, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf19B_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19C 0x1670 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lSigReserved : 1; //L-SIG reserved bit, reset value: 0x0, access type: RO
		uint32 sig1Parity : 1; //signal1 parity, reset value: 0x0, access type: RO
		uint32 reserved0 : 13;
		uint32 sig1InfoValid : 1; //signal1 info valid, reset value: 0x0, access type: RO
		uint32 reserved1 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf19C_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19D 0x1674 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 nLength : 16; //n packet length, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf19D_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19E 0x1678 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 nss : 3; //Nss, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 bw : 3; //bw, reset value: 0x0, access type: RO
		uint32 stbc : 2; //STBC, reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
		uint32 aggregation : 1; //Aggregation, reset value: 0x0, access type: RO
		uint32 shortGi : 1; //short GI, reset value: 0x0, access type: RO
		uint32 fecType : 1; //fec type, reset value: 0x0, access type: RO
		uint32 smoothing : 1; //Smoothing, reset value: 0x0, access type: RO
		uint32 sounding : 1; //Sounding, reset value: 0x0, access type: RO
		uint32 htSig2Reserved : 1; //HT-SIG2 reserved bit, reset value: 0x0, access type: RO
		uint32 reserved2 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf19E_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF19F 0x167C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 crcTx : 8; //Tx crc, reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
		uint32 numHtLtf : 3; //Num HT LTF, reset value: 0x0, access type: RO
		uint32 reserved1 : 2;
		uint32 sig3InfoValid : 1; //signal3 info valid, reset value: 0x0, access type: RO
		uint32 reserved2 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf19F_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A0 0x1680 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sig1ParityErr : 1; //Signal 1 parity Error, reset value: 0x0, access type: RO
		uint32 sig1InvalidRate : 1; //Signal 1 Invalid Rate, reset value: 0x0, access type: RO
		uint32 sig1MinLengthErr : 1; //Signal 1 minimum length Error, reset value: 0x0, access type: RO
		uint32 sig1ReservedErr : 1; //Signal 1 reserved bit Error, reset value: 0x0, access type: RO
		uint32 sig23CrcErr : 1; //signal23 Crc Error, reset value: 0x0, access type: RO
		uint32 sig23ReservedErr : 1; //signal23 reserved bits Error, reset value: 0x0, access type: RO
		uint32 sig3McsErr : 1; //sig3_mcs_err, reset value: 0x0, access type: RO
		uint32 sig3LengthErr : 1; //sig3_length_err, reset value: 0x0, access type: RO
		uint32 mcs : 7; //MCS, reset value: 0x0, access type: RO
		uint32 reserved0 : 17;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A0_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A1 0x1684 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcMaxChecks : 8; //LDPC max checks number, reset value: 0xa, access type: RW
		uint32 ldpcMaxSpare : 8; //LDPC max spare number, reset value: 0xa, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A1_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF_RISC_INT 0x1688 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxbeClearRiscCauseInt_rxbeRiscCauseInt : 11; //Rx BE Risc Cause int, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIfRiscInt_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A3 0x168C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxbeRiscIntEnable : 11; //Rx BE Risc Int Enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 21;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A3_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A4 0x1690 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swGclkBypass : 14; //sw_gclk_bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A4_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A5 0x1694 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcNData : 11; //ldpc_n_data, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 ldpcCwType : 2; //ldpc_cw_type, reset value: 0x3, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A5_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A6 0x1698 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 clearCounters : 1; //clear counters, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A6_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A7 0x169C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsErrPacketCnt : 16; //number of packets with PRBS error, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A7_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A8 0x16A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 crcErrPacketCnt : 16; //number of packets with CRC error, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A8_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1A9 0x16A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hypRxbeCtrlStm : 3; //RxBE state machine, reset value: 0x0, access type: RO
		uint32 phyMacIfMainStm : 5; //Phy MAC IF state machine, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 phyPacRxAggregate : 1; //aggregate bit connected to the mac, reset value: 0x0, access type: RO
		uint32 phyPacRxPhyReady : 1; //ready bit connected to the mac, reset value: 0x0, access type: RO
		uint32 reserved1 : 21;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1A9_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AA 0x16A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 ignoreSig1Error : 1; //RxBE general purpose register, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Aa_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AB 0x16AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyPacRxPhyError : 1; //Rx phy error, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ab_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AC 0x16B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 muNdp : 1; //mu_ndp, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 ndpMaxSupportedNss : 2; //mac control for ndp max allowed Nss, reset value: 0x0, access type: RO
		uint32 reserved1 : 26;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ac_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AD 0x16B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcNCw : 15; //ldpc_n_cw, reset value: 0x0, access type: RW
		uint32 reserved0 : 17;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ad_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1AE 0x16B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcRemNshrtNcw : 15; //ldpc_rem_nshrt_ncw, reset value: 0x0, access type: RW
		uint32 reserved0 : 17;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ae_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B0 0x16C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 ldpcNParity : 11; //ldpc_n_parity, reset value: 0x0, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B0_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B2 0x16C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcNRepeat : 13; //ldpc_n_repeat, reset value: 0x0, access type: RW
		uint32 reserved0 : 19;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B2_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B3 0x16CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcRemNrepNcw : 15; //ldpc_rem_nrep_ncw, reset value: 0x0, access type: RW
		uint32 reserved0 : 17;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B3_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B4 0x16D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lSigDuration : 16; //L-SIG Duration, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B4_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B5 0x16D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mcsUnsupported : 1; //MCS unsupported, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B5_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B6 0x16D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hwMcsUnsupported : 1; //HW decision MCS unsupported, reset value: 0x0, access type: RO
		uint32 hwMcsUnsupportedCause0 : 15; //HW decision MCS unsupported cause 0 , reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B6_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B7 0x16DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hwMcsUnsupportedCause1 : 3; //HW decision MCS unsupported cause 1, reset value: 0x0, access type: RO
		uint32 reserved0 : 29;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B7_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B8 0x16E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcRemNpuncNcw : 15; //ldpc_rem_npunc_ncw, reset value: 0x0, access type: RW
		uint32 reserved0 : 17;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B8_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1B9 0x16E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigA1GroupId : 6; //vht_sig_a1_group_id, reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
		uint32 vhtMuPacket : 1; //vht_mu_packet, reset value: 0x0, access type: RO
		uint32 reserved1 : 23;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1B9_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BA 0x16E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigA1PartialAid : 9; //vht_sig_a1_partial_aid, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 vhtSigA1TxopPsNotAllowed : 1; //vht_sig_a1_txop_ps_not_allowed, reset value: 0x0, access type: RO
		uint32 reserved1 : 19;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ba_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BB 0x16EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 vhtSigA2B1 : 1; //vht_sig_a2_b1, reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
		uint32 vhtSigA2B3 : 1; //vht_sig_a2_b3, reset value: 0x0, access type: RO
		uint32 reserved2 : 28;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Bb_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BC 0x16F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigAReserved : 3; //vht_sig_a_reserved, reset value: 0x0, access type: RO
		uint32 reserved0 : 29;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Bc_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BD 0x16F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigBLengthLow : 16; //vht_sig_b_length_low, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Bd_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BE 0x16F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigBLengthHigh : 5; //vht_sig_b_length_high, reset value: 0x0, access type: RO
		uint32 reserved0 : 27;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Be_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1BF 0x16FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dynBandwidthInNonHt : 1; //dyn_bandwidth_in_non_ht, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 chBandwidthInNonHt : 3; //ch_bandwidth_in_non_ht, reset value: 0x0, access type: RO
		uint32 reserved1 : 2;
		uint32 vhtSigBCrcErr : 1; //vht_sig_b_crc_err, reset value: 0x0, access type: RO
		uint32 vhtSigbErr : 1; //vht_sigb_err, reset value: 0x0, access type: RO
		uint32 vhtSigbDone : 1; //vht_sigb_done, reset value: 0x0, access type: RO
		uint32 reserved2 : 3;
		uint32 serviceValid : 1; //service_valid, reset value: 0x0, access type: RO
		uint32 reserved3 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Bf_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C0 0x1700 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeViterbiNes : 3; //air_time_viterbi_nes, reset value: 0x1, access type: RO
		uint32 reserved0 : 1;
		uint32 airTimeCodeRate : 2; //air_time_code_rate, reset value: 0x2, access type: RO
		uint32 reserved1 : 2;
		uint32 airTimeModulation : 3; //air_time_modulation, reset value: 0x0, access type: RO
		uint32 reserved2 : 4;
		uint32 airTimeResultHigh : 1; //air_time_result_high, reset value: 0x1, access type: RO
		uint32 reserved3 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C0_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C1 0x1704 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeResultLow : 16; //air_time_result_low, reset value: 0xffff, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C1_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C2 0x1708 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimePhyRate : 16; //air_time_phy_rate, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C2_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C3 0x170C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeNumSym : 15; //air_time_num_sym, reset value: 0x0, access type: RO
		uint32 reserved0 : 17;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C3_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C4 0x1710 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcNData : 11; //air_time_ldpc_n_data, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C4_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C5 0x1714 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcRemNshrtNcw : 16; //air_time_ldpc_rem_nshrt_ncw, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C5_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C6 0x1718 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcNParity : 11; //air_time_ldpc_n_parity, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C6_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C7 0x171C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcRemNpuncNcw : 16; //air_time_ldpc_rem_npunc_ncw, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C7_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C8 0x1720 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcNRepeat : 13; //air_time_ldpc_n_repeat, reset value: 0x0, access type: RO
		uint32 reserved0 : 19;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C8_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1C9 0x1724 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcRemNrepNcw : 16; //air_time_ldpc_rem_nrep_ncw, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1C9_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CA 0x1728 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcNCw : 16; //air_time_ldpc_n_cw, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ca_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CB 0x172C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcCwType : 2; //air_time_ldpc_cw_type, reset value: 0x0, access type: RO
		uint32 reserved0 : 30;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Cb_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CD 0x1730 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxTPe : 5; //phy_rx_t_pe, reset value: 0x0, access type: RO
		uint32 reserved0 : 27;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Cd_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CE 0x1734 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeNSdLast : 11; //air_time_n_sd_last, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ce_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CF 0x1738 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxAirTimeCyclesLow : 16; //phy_rx_air_time_cycles_low, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Cf_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D0 0x173C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxAirTimeCyclesHigh : 10; //phy_rx_air_time_cycles_high, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D0_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D1 0x1740 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxPhyRateResult : 16; //phy_rx_phy_rate_result, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D1_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D2 0x1744 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxAirTimeError : 1; //phy_rx_air_time_error, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D2_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D3 0x1748 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxNCbpsLow : 16; //phy_rx_n_cbps_low, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D3_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D4 0x174C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxNCbpsHigh : 1; //phy_rx_n_cbps_high, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D4_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D5 0x1750 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxNDbpsLow : 16; //phy_rx_n_dbps_low, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D5_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D6 0x1754 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxNDbpsHigh : 1; //phy_rx_n_dbps_high, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D6_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D7 0x1758 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxPreambleTimeLow : 16; //phy_rx_preamble_time_low, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D7_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1D8 0x175C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyRxPreambleTimeHigh : 2; //phy_rx_preamble_time_high, reset value: 0x0, access type: RO
		uint32 reserved0 : 30;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1D8_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DA 0x1764 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 baseLdpcMaxChecks : 8; //base_ldpc_max_checks, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Da_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DB 0x1768 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 8;
		uint32 baseLdpcMaxSpare : 8; //base_ldpc_max_spare, reset value: 0x0, access type: RO
		uint32 reserved1 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Db_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DC 0x176C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 enableDynamicMaxCheck : 1; //enable_dynamic_max_check, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Dc_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DD 0x1770 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 extraLdpcCycles : 12; //extra_ldpc_cycles, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Dd_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DE 0x1774 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhyStationId : 9; //station_id, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1De_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1DF 0x1778 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhyAbort : 1; //abort, reset value: 0x0, access type: RO
		uint32 pacPhyHalt : 1; //halt, reset value: 0x0, access type: RO
		uint32 pacPhyGpReq : 1; //gp request, reset value: 0x0, access type: RO
		uint32 reserved0 : 29;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Df_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E0 0x177C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcMinChecks : 8; //ldpc_min_checks, reset value: 0x0, access type: RW
		uint32 ldpcExtraChecks : 8; //ldpc_extra_checks, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1E0_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E1 0x1780 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcMaxRemCw : 8; //ldpc_max_rem_cw, reset value: 0x0, access type: RW
		uint32 ldpcLastCw : 8; //ldpc_last_cw, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1E1_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E2 0x1784 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhyTxop : 1; //pac_phy_txop, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1E2_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E3 0x1788 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 griscGpAck : 1; //grisc_gp_ack, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1E3_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E4 0x178C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lastVapIdx : 5; //last_vap_idx, reset value: 0x0, access type: RO
		uint32 reserved0 : 27;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1E4_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E5 0x1790 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 extendAirTime : 1; //extend_air_time, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1E5_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1E9 0x17A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 genRiscSpare0 : 16; //gen_risc_spare_0, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1E9_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EA 0x17A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 genRiscSpare1 : 16; //gen_risc_spare_1, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ea_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EB 0x17A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 genRiscSpare2 : 16; //gen_risc_spare_2, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Eb_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EC 0x17AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 genRiscSpare3 : 16; //gen_risc_spare_3, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ec_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1ED 0x17B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 genRiscSpare4 : 16; //gen_risc_spare_4, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ed_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EE 0x17B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 genRiscSpare5 : 16; //gen_risc_spare_5, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ee_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1CC 0x17B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 airTimeLdpcRate : 2; //air_time_ldpc_rate, reset value: 0x0, access type: RO
		uint32 reserved0 : 13;
		uint32 airTimeDone : 1; //air_time_done, reset value: 0x0, access type: RO
		uint32 reserved1 : 16;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Cc_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1EF 0x17BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ofdmSigError : 1; //ofdm_sig_error, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Ef_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1F0 0x17C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ndpSg3Err : 1; //ndp_sg3_err, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1F0_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1F4 0x17C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesFirstCwOverride : 12; //ldpc_cycles_first_cw_override , reset value: 0x0, access type: RW
		uint32 ldpcCyclesFirstCwOverrideEn : 1; //ldpc_cycles_first_cw_override_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 19;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1F4_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1F8 0x17C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesNewMode : 1; //ldpc_cycles_new_mode , reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1F8_u;

/*REG_B1_PHY_RX_BE_IF_PHY_RXBE_IF1FC 0x17CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcMaxCycles : 12; //ldpc_max_cycles, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB1PhyRxBeIfPhyRxbeIf1Fc_u;

/*REG_B1_PHY_RX_BE_IF_PAC_PHY_PACKET_TYPE 0x17D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhyPacketType : 6; //packet type and subtype, reset value: 0x0, access type: RO
		uint32 reserved0 : 26;
	} bitFields;
} RegB1PhyRxBeIfPacPhyPacketType_u;



#endif // _B1_PHY_RX_BE_IF_REGS_H_
