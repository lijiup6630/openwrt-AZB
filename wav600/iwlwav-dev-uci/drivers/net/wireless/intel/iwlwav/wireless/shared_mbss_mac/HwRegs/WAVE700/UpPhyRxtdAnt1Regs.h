
/***********************************************************************************
File:				UpPhyRxtdAnt1Regs.h
Module:				upPhyRxtdAnt1
SOC Revision:		A0.Rel1
Generated at:       2021-12-15 09:13:22
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _UP_PHY_RXTD_ANT1_REGS_H_
#define _UP_PHY_RXTD_ANT1_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define UP_PHY_RXTD_ANT1_BASE_ADDRESS                             MEMORY_MAP_UNIT_245_BASE_ADDRESS
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG00            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG01            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG02            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG03            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG04            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x10)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG05            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x14)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG06            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x18)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG07            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG08            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x20)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG09            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x24)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x28)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x30)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x34)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x38)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x3C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG10            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x40)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG11            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x44)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG12            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x48)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG13            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x4C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG14            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x50)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG15            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x54)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG16            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x58)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG17            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x5C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG18            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x60)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG19            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x64)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x68)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x6C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x70)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x74)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x78)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x7C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG20            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x80)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG21            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x84)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG22            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x88)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG23            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x8C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG24            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x90)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG25            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x94)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG26            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x98)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG27            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x9C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG28            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xA0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG29            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xA4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xA8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xAC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xB0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xB4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xB8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xBC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG30            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xC0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG31            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xC4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG32            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xC8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG33            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xCC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG34            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xD0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xEC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xF0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xF4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xF8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0xFC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG40            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x100)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG41            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x104)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG42            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x108)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG43            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x10C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG44            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x110)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG45            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x114)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG46            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x118)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG47            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x11C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG48            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x120)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG49            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x124)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x128)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x12C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x130)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x134)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x138)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x13C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG50            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x140)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG51            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x144)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG52            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x148)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG53            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x14C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG54            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x150)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG55            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x154)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG56            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x158)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG57            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x15C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG58            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x160)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG59            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x164)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x168)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x16C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x170)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x174)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x178)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x17C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG60            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x180)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG61            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x184)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG62            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x188)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG63            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x18C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG64            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x190)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG65            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x194)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG66            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x198)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG67            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x19C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG69            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1A4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1A8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1AC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1B0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1B4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1B8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1BC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG70            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1C0)
#define	REG_UP_PHY_RXTD_ANT1_RX_ABB_ANT_REG71              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1C4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG72            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1C8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG73            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1CC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG74            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1D0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG75            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1D4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG76            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1D8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG77            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1DC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG78            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1E0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG79            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1E4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1E8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1EC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1F0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1F4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1F8)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x1FC)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG80            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x200)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG81            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x204)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG82            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x208)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG83            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x20C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG84            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x210)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG85            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x214)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG86            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x218)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG87            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x21C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG88            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x220)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG89            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x224)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x228)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x22C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x230)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x234)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x238)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x23C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG90            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x240)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG91            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x244)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG92            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x248)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG93            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x24C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG94            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x250)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG95            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x254)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG96            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x258)
#define	REG_UP_PHY_RXTD_ANT1_CONTROL_11B                   (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x25C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG98            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x260)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG99            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x264)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9A            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x268)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9B            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x26C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9C            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x270)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9D            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x274)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9E            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x278)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9F            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x27C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA1            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x284)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA2            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x288)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA3            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x28C)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA4            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x290)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA5            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x294)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA6            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x298)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA7            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x29C)
#define	REG_UP_PHY_RXTD_ANT1_FORCE_OP_CH_ZERO              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2A0)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA9            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2A4)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGAA            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2A8)
#define	REG_UP_PHY_RXTD_ANT1_TB_BANDSELECT_BANDS           (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2AC)
#define	REG_UP_PHY_RXTD_ANT1_CONTROL_OVERRIDE              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2B0)
#define	REG_UP_PHY_RXTD_ANT1_ANT_SW_RESET_N_REG            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2B4)
#define	REG_UP_PHY_RXTD_ANT1_ANT_BLOCK_EN                  (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2B8)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_0              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2BC)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_1              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2C0)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_2              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2C4)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_3              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2C8)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_4              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2CC)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_5              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2D0)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_6              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2D4)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_7              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2D8)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_8              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2DC)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_9              (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2E0)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_10             (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2E4)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_11             (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2E8)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_12             (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2EC)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_13             (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2F0)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_14             (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2F4)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_15             (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2F8)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_0_3        (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x2FC)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_4_7        (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x300)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_8_11       (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x304)
#define	REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_12_15      (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x308)
#define	REG_UP_PHY_RXTD_ANT1_ACI_DET_RADAR_COUNTER_TH      (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x30C)
#define	REG_UP_PHY_RXTD_ANT1_LOOPBACK_PYPASS               (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x310)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGC5            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x314)
#define	REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGC6            (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x318)
#define	REG_UP_PHY_RXTD_ANT1_PM_ACIDET_BYPASS_OFFSETS      (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x31C)
#define	REG_UP_PHY_RXTD_ANT1_ANTENNA_320M_MODE_CONTROLS    (UP_PHY_RXTD_ANT1_BASE_ADDRESS + 0x320)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG00 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freqShiftSig3Bypass : 1; //freq_shift_sig3_bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg00_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG01 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchBypassIir : 1; //IQ Mismatch IIR Bypass, reset value: 0x0, access type: RW
		uint32 iqMismatchBypassEq : 1; //IQ Mismatch Equalizer Bypass, reset value: 0x0, access type: RW
		uint32 iqMismatchBypassEqI2Q : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 iqW12Sel : 1; //iq decorrelator w1 w2 coefficient selection: , 0: iq_w1_0, iq_w2_0 , 1: iq_w1_1, iq_w2_1, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg01_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG02 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchIirMu : 4; //IQ Mismatch IIR Mu I, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
		uint32 iqMismatchEstRegularISum : 1; //Rx TD IQ Mismatch I regular sum (not sqr), reset value: 0x0, access type: RW
		uint32 reserved1 : 3;
		uint32 iqMismatchEstRegularQSum : 1; //Rx TD IQ Mismatch Q regular sum (not sqr), reset value: 0x0, access type: RW
		uint32 reserved2 : 3;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg02_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG03 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 iqMismatchEqLengthQ : 3; //IQ equalizer FIR Q-path delay. , Range is 0 to 6. , Usually configured according to RF BW: , 1: BW = 20, 40 , 2: BW = 80, 160 , 4: BW = 320 , Should be similar to IQ equalizer FIR center tap (5th element) delay (iq_fir_delay)., reset value: 0x2, access type: RW
		uint32 reserved1 : 25;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg03_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG04 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstAccCounter : 24; //IQ Mismatch Est Acc Counter, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg04_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG05 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 iqMismatchEstStartWork : 1; //IQ Mismatch Est Start Work, reset value: 0x0, access type: WO
		uint32 reserved1 : 3;
		uint32 iqMismatchEstResetRegs : 1; //IQ Mismatch Est Reset Regs, reset value: 0x0, access type: RW
		uint32 reserved2 : 3;
		uint32 iqMismatchEstValidIq : 1; //Rx TD IQ Mismatch Est valid, reset value: 0x0, access type: RO
		uint32 reserved3 : 19;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg05_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG06 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRegIi : 32; //IQ Mismatch Est Reg II low, reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg06_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG07 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRegQq : 32; //IQ Mismatch Est Reg QQ low, reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg07_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG08 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRegIq : 32; //IQ Mismatch Est Reg IQ low, reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg08_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG09 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxIqSwap : 1; //IQ Swap, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg09_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0A 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 rxSpectrumFlip : 1; //Spectrum flip, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg0A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0B 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzelResetAcum : 1; //Geortzel Reset Acumulator., reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg0B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0C 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 geortzelLength : 12; //geortzel_length, reset value: 0x0, access type: RW
		uint32 reserved1 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg0C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0D 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel0MulI : 14; //Geortzel 0 Mult I Data., reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 geortzel0MulQ : 14; //Geortzel 0 Mult Q Data., reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg0D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0E 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel1MulI : 14; //Geortzel 1 Mult I Data., reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 geortzel1MulQ : 14; //Geortzel 1 Mult Q Data., reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg0E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG0F 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 8;
		uint32 geortzelValidThr : 7; //Geortzel Valid Threshold., reset value: 0x0, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg0F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG10 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap0 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg10_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG11 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap1 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 1., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg11_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG12 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap2 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 2., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg12_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG13 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap3 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 3., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg13_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG14 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap4 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 4., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg14_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG15 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap5 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 5., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg15_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG16 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap6 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 6., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg16_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG17 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap7 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 7., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg17_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG18 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap8 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 8., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg18_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG19 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap9 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 9., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg19_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1A 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap10 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 10., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg1A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1B 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap11 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 11., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg1B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1C 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 olaMode : 3; //ola mode: 0 -256, 1-512, 2-1024, 3-2048, 4-4096, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg1C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1D 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 olaFftInShift : 3; //Rx TD fft in shift OLA, reset value: 0x0, access type: RW
		uint32 olaFftInMult : 1; //Rx TD fft in mult OLA, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 olaNumOfWindows : 5; //2^(ola number of windows ), reset value: 0x0, access type: RW
		uint32 reserved1 : 3;
		uint32 olaZeroInput : 2; //ola zero input: , 00- regular mode , 01- Q-part zero , 10- I part zero, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 olaRound : 5; //ola round parameter, reset value: 0x0, access type: RW
		uint32 reserved3 : 3;
		uint32 olaRssi : 1; //ola rssi, reset value: 0x0, access type: RW
		uint32 olaBb : 1; //ola bb, reset value: 0x0, access type: RW
		uint32 olaTestBusDump : 1; //ola_test_bus_dump, reset value: 0x0, access type: RW
		uint32 reserved4 : 1;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg1D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1E 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 olaStart : 1; //ola_start_an0 pulse, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg1E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG1F 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 olaState : 3; //ola_state: , 000 - IDLE , 001 - FIRST WINDOW , 010 - LAST WINDOW , 011 - REGULAR WINDOW , 100 - FIRST LAST WINDOW , 101 - End OF WINDOWS , 110 - FFT working , 111 - dump to test bus, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 olaDone : 1; //ola_done_an0 pulse , reset value: 0x0, access type: RO
		uint32 reserved1 : 27;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg1F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG20 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 20;
		uint32 iqCoefRm : 3; //iq_coef_rm, reset value: 0x3, access type: RW
		uint32 reserved1 : 9;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg20_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG21 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxFifoRm : 3; //rx_fifo_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 1;
		uint32 fft0Rm : 3; //fft_0_rm, reset value: 0x3, access type: RW
		uint32 reserved1 : 1;
		uint32 fft1Rm : 3; //fft_1_rm, reset value: 0x3, access type: RW
		uint32 reserved2 : 1;
		uint32 bandselFirDpmemRm : 3; //bandsel_fir_dpmem_rm, reset value: 0x3, access type: RW
		uint32 reserved3 : 1;
		uint32 chanfiltMidDelayFifoRm : 3; //chanfilt_mid_delay_fifo_rm, reset value: 0x3, access type: RW
		uint32 reserved4 : 1;
		uint32 chanfiltCoeffLutRm : 3; //chanfilt_coeff_lut_rm, reset value: 0x3, access type: RW
		uint32 reserved5 : 1;
		uint32 bandselFirCoeffRm : 3; //bandsel_fir_coeff_rm, reset value: 0x3, access type: RW
		uint32 reserved6 : 5;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg21_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG22 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dcRegI : 18; //dc_reg_i_an0, reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg22_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG23 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dcRegQ : 18; //dc_reg_q_an0, reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg23_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG24 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 iqFdlBypass : 1; //iq_fdl_bypass, reset value: 0x0, access type: RW
		uint32 iqFdlBypassRam : 1; //iq_fdl_bypass_ram, reset value: 0x0, access type: RW
		uint32 reserved1 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg24_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG25 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 iqEqBypassRam : 1; //IQ equalizer bypass RAM. Use cofficients from prog model, reset value: 0x0, access type: RW
		uint32 iqW12Bypass : 1; //IQ W1, W2 De-correlator bypass, reset value: 0x0, access type: RW
		uint32 iqPgcFromAgcAcc : 1; //select PGC1,PGC2 source: , 0-progmodels, 1-AGC accelerator, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 iqFirDecorOrder : 1; //0: FIR -> Decorrelator , 1: Decorrelator -> FIR, reset value: 0x1, access type: RW
		uint32 reserved2 : 26;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg25_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG26 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRate : 1; //w1,w2 estimator work before (1 - @320MHz) or after the decimation filter (0 - @160MHZ), reset value: 0x0, access type: RW
		uint32 iqMismatchAccumRssi : 1; //use iq_mismatch w12_estimator's accumulator to accumulate rssi_data, reset value: 0x0, access type: RW
		uint32 iqMismatchEstIqFixSelect : 1; //Select input for IQ Estimator: 0 = Decimation Filter output, 1 = IQ-Fix output , , reset value: 0x0, access type: RW
		uint32 iqMismatchEstCalibtrationsCorrSelect : 1; //Select input for IQ Estimator: 0 = WAV700 Cal mode input rate 640MHz, 1 = WAV600-2 input modes after prefilter , , reset value: 0x1, access type: RW
		uint32 iqMismatchEstShift : 4; //w1,w2 estimator shift value antenna 0, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg26_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG27 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstOfIi : 1; //OverFlow indication on i^2 32-bit accumulation antenna 0, reset value: 0x0, access type: RO
		uint32 iqMismatchEstOfQq : 1; //OverFlow indication on q^2 32-bit accumulation antenna 0, reset value: 0x0, access type: RO
		uint32 iqMismatchEstOfIq : 1; //OverFlow indication on i*q 32-bit accumulation antenna 0, reset value: 0x0, access type: RO
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg27_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG28 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqRamReadTrigger : 1; //Upon writing '1' a RAM read is performed into IQ coefficients, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg28_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG29 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap0 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg29_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2A 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap1 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 1 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg2A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2B 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap2 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 2 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg2B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2C 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap3 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 3 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg2C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2D 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap4 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 4 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg2D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2E 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap5 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 5 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg2E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG2F 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap6 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 6 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg2F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG30 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap7 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 7 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg30_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG31 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap8 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 8 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg31_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG32 0xC8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap9 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 9 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg32_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG33 0xCC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap10 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 10 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg33_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG34 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap11 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 11 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg34_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3B 0xEC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxDifi2DcCancelEnable : 1; //DC Cancellation Enable, reset value: 0x0, access type: RW
		uint32 rxDifi2DcCancelHwSelect : 1; //Progmodel or Accelerator, reset value: 0x0, access type: RW
		uint32 rxDifi2RssiGainHwSelect : 1; //Progmodel or Accelerator, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg3B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3C 0xF0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi2DcCancelI : 14; //DC Offset I Ant 1, reset value: 0x0, access type: RW
		uint32 difi2DcCancelQ : 14; //DC Offset Q Ant 1, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg3C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3D 0xF4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel0IResult : 30; //Geortzel 0 I Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg3D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3E 0xF8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel0QResult : 30; //Geortzel 0 Q Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 geortzel0DataValid : 1; //Geortzel 0 Data Valid., reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg3E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG3F 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel1IResult : 30; //Geortzel 1 I Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg3F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG40 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel1QResult : 30; //Geortzel 1 Q Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 geortzel1DataValid : 1; //Geortzel 1 Data Valid., reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg40_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG41 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fftInShift26B : 3; //Rx TD fft in shift 26b, reset value: 0x5, access type: RW
		uint32 fftInShift52B : 3; //Rx TD fft in shift 52b, reset value: 0x7, access type: RW
		uint32 fftInShift106B : 3; //Rx TD fft in shift 106b, reset value: 0x6, access type: RW
		uint32 fftInShift20 : 3; //Rx TD fft in shift for hb2080, reset value: 0x0, access type: RW
		uint32 fftInShift40 : 3; //Rx TD fft in shift for hb4080, reset value: 0x7, access type: RW
		uint32 fftInShift80 : 3; //Rx TD fft in shift for hb80160, reset value: 0x7, access type: RW
		uint32 fftInShift160 : 3; //Rx TD fft in shift for 160, reset value: 0x1, access type: RW
		uint32 fftInShiftHestf : 3; //Rx TD fft in shift for he stf, reset value: 0x6, access type: RW
		uint32 fftInMult26B : 1; //Rx TD fft in mult 26b, reset value: 0x1, access type: RW
		uint32 fftInMult52B : 1; //Rx TD fft in mult 52b, reset value: 0x0, access type: RW
		uint32 fftInMult106B : 1; //Rx TD fft in mult 106b, reset value: 0x1, access type: RW
		uint32 fftInMult20 : 1; //Rx TD fft in mult for hb2080, reset value: 0x0, access type: RW
		uint32 fftInMult40 : 1; //Rx TD fft in mult for hb4080, reset value: 0x1, access type: RW
		uint32 fftInMult80 : 1; //Rx TD fft in mult for hb80160, reset value: 0x1, access type: RW
		uint32 fftInMult160 : 1; //Rx TD fft in mult for 160, reset value: 0x0, access type: RW
		uint32 fftInMultHestf : 1; //Rx TD fft in mult for he stf, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg41_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG42 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfCalMode : 1; //rf calibration mode, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg42_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG43 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 afeTpControl : 2; //timer in 20Mhz from sec detect till primary, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 decimatorTpControl : 1; //decimator hb sensitive:  , 1'b0 all strobe , 1'b1: case hb_mode , CB80: all strobes , HB4080:one every two samples , HB2080:one every four samples, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg43_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG44 0x110 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxDigitalGainEnable : 1; //Digital Gain Enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg44_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG45 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 memGlobalRm : 2; //mem_global_rm, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg45_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG46 0x118 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiGrAddr : 7; //fcsi_gr_addr, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 fcsiGrWrData : 16; //fcsi_gr_wr_data, reset value: 0x0, access type: RW
		uint32 reserved1 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg46_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG47 0x11C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiRdData : 16; //fcsi_rd_data, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg47_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG48 0x120 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiClkWrDivrExtRf : 6; //fcsi_clk_wr_divr_ext_rf, reset value: 0x4, access type: RW
		uint32 reserved0 : 2;
		uint32 fcsiClkRdDivrExtRf : 6; //fcsi_clk_rd_divr_ext_rf, reset value: 0xf, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg48_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG49 0x124 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiClkWrDivrAfe : 6; //fcsi_clk_wr_divr_afe, reset value: 0x4, access type: RW
		uint32 reserved0 : 2;
		uint32 fcsiClkRdDivrAfe : 6; //fcsi_clk_rd_divr_afe, reset value: 0xf, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg49_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4A 0x128 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 externalRfMode : 1; //external_rf_mode, reset value: 0x1, access type: RW
		uint32 reserved0 : 3;
		uint32 fcsiModeMs : 1; //fcsi_mode_ms, reset value: 0x1, access type: RW
		uint32 fcsiModeRfExt : 1; //fcsi_mode_rf_ext, reset value: 0x1, access type: RW
		uint32 reserved1 : 2;
		uint32 fcsiAdditionalCycles : 4; //fcsi_additional_cycles, reset value: 0x0, access type: RW
		uint32 reserved2 : 20;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg4A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4B 0x12C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiMsResetAntennasN : 1; //fcsi_ms_reset_antennas_n, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 fcsiRfResetN : 1; //fcsi_rf_reset_n, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg4B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4C 0x130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hypFcsiStateMachine : 3; //hyp_fcsi_state_machine, reset value: 0x0, access type: RO
		uint32 hypFcsiCounter : 5; //hyp_fcsi_counter, reset value: 0x0, access type: RO
		uint32 hypFcsiCounterLimit : 5; //hyp_fcsi_counter_limit, reset value: 0x0, access type: RO
		uint32 hypFcsiClockActive : 1; //hyp_fcsi_clock_active, reset value: 0x0, access type: RO
		uint32 hypFcsiClockEnable : 1; //hyp_fcsi_clock_enable, reset value: 0x0, access type: RO
		uint32 hypFcsiActive : 1; //hyp_fcsi_active, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg4C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4D 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiForceDefaultWlan2Ms : 1; //fcsi_force_default_wlan2ms, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg4D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4E 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antennaResetEnable : 1; //antenna_reset_enable, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg4E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG4F 0x13C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxLpbkSelect : 2; //Rx LoopBack Select, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg4F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG50 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfFreqMhz : 13; //rf_freq_mhz, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 fdlIqComp : 16; //fdl_iq_comp, reset value: 0x0, access type: RW
		uint32 fdlBypass : 1; //fdl_bypass, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg50_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG51 0x144 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoUpLim : 30; //fdl_nco_up_lim, reset value: 0x0, access type: RW
		uint32 freqShiftM1Bypass : 1; //freq_shift_m1_bypass, reset value: 0x0, access type: RW
		uint32 freqShiftM2Bypass : 1; //freq_shift_m2_bypass, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg51_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG52 0x148 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 chanfiltBypass : 1; //chanfilt_bypass, reset value: 0x0, access type: RW
		uint32 chanfiltChangePhase : 4; //chanfilt_change_phase, reset value: 0x0, access type: RW
		uint32 chanfiltLdSrc : 2; //chanfilt_ld_src, reset value: 0x0, access type: RW
		uint32 chanfiltCoefLoad : 1; //chanfilt_coef_load, reset value: 0x0, access type: WO
		uint32 chanfiltCoefDbg : 6; //chanfilt_coef_dbg, reset value: 0x0, access type: RW
		uint32 chanfiltFlexLength : 1; //chanfilt_flex_length, reset value: 0x1, access type: RW
		uint32 chanfiltDisZout : 1; //chanfilt_dis_zout, reset value: 0x0, access type: RW
		uint32 frcChangeLoad : 1; //frc_change_load, reset value: 0x0, access type: RW
		uint32 frcLutGainDis : 1; //frc_lut_gain_dis, reset value: 0x0, access type: RW
		uint32 frcRssiGainDis : 1; //frc_rssi_gain_dis, reset value: 0x0, access type: RW
		uint32 chanfiltGain : 7; //chanfilt_gain, reset value: 0x0, access type: RW
		uint32 chanfiltIirMode : 2; //Channel filter IIR operation mode: , 0 - never use IIR, (Use FIR) , 1 - from 1st sample, (force IIR from start) , 2 - from HESTF (only if channel is 320MHz wide), (default) , 3 - from HESTF if channel is 160MHz wide or 320MHz wide , , reset value: 0x2, access type: RW
		uint32 reserved0 : 4;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg52_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG53 0x14C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frcBypass : 1; //frc_bypass, reset value: 0x0, access type: RW
		uint32 sig3Bypass : 1; //sig3_bypass, reset value: 0x0, access type: RW
		uint32 frcOfdmBypass : 1; //frc_ofdm_bypass, reset value: 0x0, access type: RW
		uint32 bBypass : 1; //b_bypass, reset value: 0x0, access type: RW
		uint32 disablePrimaryDetection : 1; //disable_primary_detection, reset value: 0x0, access type: RW
		uint32 rxFreqShiftMode : 1; //rx_freq_shift_mode, reset value: 0x0, access type: RW
		uint32 rxFreqWaitForRas : 1; //rx_freq_wait_for_ras, reset value: 0x1, access type: RW
		uint32 reserved0 : 5;
		uint32 frcFwShift1 : 4; //frc_fw_shift1, reset value: 0x0, access type: RW
		uint32 frcFwShift2 : 4; //frc_fw_shift2, reset value: 0x0, access type: RW
		uint32 frcFwCntr : 12; //frc_fw_cntr, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg53_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG54 0x150 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frcOfdmCntr : 12; //frc_ofdm_cntr, reset value: 0x0, access type: RW
		uint32 frcSig3Cntr : 12; //frc_sig3_cntr, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg54_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG55 0x154 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frc11BCntr : 12; //frc_11b_cntr, reset value: 0x0, access type: RW
		uint32 chanfiltIdle20Mhz : 3; //chanfilt_idle_20mhz, reset value: 0x1, access type: RW
		uint32 chanfiltIdle40Mhz : 3; //chanfilt_idle_40mhz, reset value: 0x1, access type: RW
		uint32 chanfiltIdle80Mhz : 3; //chanfilt_idle_80mhz, reset value: 0x1, access type: RW
		uint32 chanfiltIdle160Mhz : 3; //chanfilt_idle_160mhz, reset value: 0x1, access type: RW
		uint32 chanfiltLegacy20Mhz : 3; //chanfilt_legacy_20mhz, reset value: 0x3, access type: RW
		uint32 chanfiltLegacy40Mhz : 3; //chanfilt_legacy_40mhz, reset value: 0x3, access type: RW
		uint32 reserved0 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg55_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG56 0x158 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 chanfiltLegacy80Mhz : 3; //chanfilt_legacy_80mhz, reset value: 0x3, access type: RW
		uint32 chanfiltLegacy160Mhz : 3; //chanfilt_legacy_160mhz, reset value: 0x3, access type: RW
		uint32 det80211BFilt : 3; //det_802_11b_filt, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 chanfiltForceAc : 1; //chanfilt_force_ac, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci20Mhz : 2; //chanfilt_force_aci_20mhz, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci40Mhz : 2; //chanfilt_force_aci_40mhz, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci80Mhz : 2; //chanfilt_force_aci_80mhz, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci160Mhz : 2; //chanfilt_force_aci_160mhz, reset value: 0x0, access type: RW
		uint32 chanfiltHeLowpassSel : 2; //chanfilt_he_lowpass_sel, reset value: 0x1, access type: RW
		uint32 chanfiltForceImmediate : 1; //chanfilt_force_immediate, reset value: 0x0, access type: RW
		uint32 chanfiltForceBw : 2; //chanfilt_force_bw, reset value: 0x0, access type: RW
		uint32 chanfiltForceFilt : 3; //chanfilt_force_filt, reset value: 0x0, access type: RW
		uint32 chanfiltForceNatural : 1; //chanfilt_force_natural, reset value: 0x0, access type: RW
		uint32 chanfiltFullSwCtrl : 1; //chanfilt_full_sw_ctrl, reset value: 0x0, access type: RW
		uint32 chanfiltHeLowpassWideSel : 2; //chanfilt_he_lowpass_wide_sel, reset value: 0x1, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg56_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG57 0x15C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bandsel160MhzShift : 1; //bandsel_160mhz_shift, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 bandselInitGain : 7; //bandsel_init_gain, reset value: 0x0, access type: RW
		uint32 reserved1 : 5;
		uint32 bandselInitGainValid : 1; //bandsel_init_gain_valid, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg57_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG58 0x160 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dcIirBandselBypass : 1; //dc_iir_bandsel_bypass, reset value: 0x0, access type: RW
		uint32 dcIirBandselAlpha : 4; //dc_iir_bandsel_alpha, reset value: 0x0, access type: RW
		uint32 dcIirDetBypass : 1; //dc_iir_det_bypass, reset value: 0x0, access type: RW
		uint32 dcIirDetAlpha : 4; //dc_iir_det_alpha, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg58_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG59 0x164 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi1DcOffset : 16; //difi1_dc_offset, reset value: 0x0, access type: RW
		uint32 difi1Gain : 4; //difi1_gain, reset value: 0x0, access type: RW
		uint32 difi1Config : 2; //difi1_config, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg59_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5A 0x168 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi1Coef0 : 8; //difi1_coef_0, reset value: 0xA, access type: RW
		uint32 difi1Coef1 : 8; //difi1_coef_1, reset value: 0x12, access type: RW
		uint32 difi1Coef2 : 10; //difi1_coef_2, reset value: 0x3FE, access type: RW
		uint32 reserved0 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg5A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5B 0x16C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi1Coef3 : 10; //difi1_coef_3, reset value: 0x3AA, access type: RW
		uint32 difi1Coef4 : 11; //difi1_coef_4, reset value: 0x713, access type: RW
		uint32 difi1Coef5 : 11; //difi1_coef_5, reset value: 0x682, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg5B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5C 0x170 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi1Coef6 : 12; //difi1_coef_6, reset value: 0xE93, access type: RW
		uint32 difi1Coef7 : 12; //difi1_coef_7, reset value: 0xFF9, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg5C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5D 0x174 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi1Coef8 : 13; //difi1_coef_8, reset value: 0x303, access type: RW
		uint32 difi1Coef9 : 13; //difi1_coef_9, reset value: 0x73C, access type: RW
		uint32 reserved0 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg5D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5E 0x178 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi1Coef10 : 14; //difi1_coef_10, reset value: 0xB67, access type: RW
		uint32 difi1Coef11 : 14; //difi1_coef_11, reset value: 0xE01, access type: RW
		uint32 reserved0 : 4;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg5E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG5F 0x17C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi2Coef0 : 6; //difi2_coef_0, reset value: 0x31, access type: RW
		uint32 difi2Coef1 : 9; //difi2_coef_1, reset value: 0x54, access type: RW
		uint32 difi2Coef2 : 11; //difi2_coef_2, reset value: 0x6D8, access type: RW
		uint32 reserved0 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg5F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG60 0x180 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi2Coef3 : 12; //difi2_coef_3, reset value: 0x4E3, access type: RW
		uint32 difi2OpGainDb : 7; //difi2_op_gain_db, reset value: 0x0, access type: RW
		uint32 rssiDifi2OpGainDb : 7; //rssi_difi2_op_gain_db, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg60_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG61 0x184 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 c64DiffMode : 1; // c64_diff_mode, reset value: 0x0, access type: RW
		uint32 detC64MrbEn : 1; //det_c64_mrb_en, reset value: 0x0, access type: RW
		uint32 det160MPhase : 1; //det_160m_phase, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg61_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG62 0x188 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 memGlobalTestMode : 2; //Global test mode for rams, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg62_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG63 0x18C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swBistStart : 1; //sw_bist_start, reset value: 0x0, access type: RW
		uint32 clearRamMode : 1; //clear_ram_mode, reset value: 0x0, access type: RW
		uint32 bistScrBypass : 1; //bist_scr_bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg63_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG64 0x190 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 detPpmFreqOffset : 20; //det_ppm_freq_offset, reset value: 0x0, access type: RW
		uint32 reserved0 : 12;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg64_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG65 0x194 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 14;
		uint32 iqPgc : 3; //iq_pgc , Note: Values from 0 to 5 are supported., reset value: 0x5, access type: RW
		uint32 reserved1 : 15;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg65_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG66 0x198 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqW10 : 13; //iq decorrelator w1 coefficient 0, reset value: 0x0, access type: RW
		uint32 iqW20 : 11; //iq decorrelator w2 coefficient 0, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg66_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG67 0x19C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqW11 : 13; //iq decorrelator w1 coefficient 1, reset value: 0x0, access type: RW
		uint32 iqW21 : 11; //iq decorrelator w2 coefficient 1, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg67_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG69 0x1A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 24;
		uint32 iqFirDelay : 3; //IQ equalizer FIR center tap (5th element) delay. , Range is 0 to 6. , Usually configured according to RF BW: , 1: BW = 20, 40 , 2: BW = 80, 160 , 4: BW = 320 , Should be similar to IQ equalizer FIR Q-path delay (iq_mismatch_eq_length_q)., reset value: 0x2, access type: RW
		uint32 reserved1 : 5;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg69_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6A 0x1A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaDbOffset : 12; //cca dB offset, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg6A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6B 0x1AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaBw : 2; //cca BW, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg6B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6C 0x1B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaAccSamples : 1; //cca acc samples 8/16 (16=1), reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg6C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6D 0x1B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection1600 : 6; //cca RF correction 160MHz band0 Upper 20MHz, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection1601 : 6; //cca RF correction 160MHz band1 , reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmCcaRfCorrection1602 : 6; //cca RF correction 160MHz band2, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmCcaRfCorrection1603 : 6; //cca RF correction 160MHz band3, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg6D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6E 0x1B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection1604 : 6; //cca RF correction 160MHz band4, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection1605 : 6; //cca RF correction 160MHz band5, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmCcaRfCorrection1606 : 6; //cca RF correction 160MHz band6, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmCcaRfCorrection1607 : 6; //cca RF correction 160MHz band7 Lower 20MHz, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg6E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG6F 0x1BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection800 : 6; //cca RF correction 80MHz band0 Upper 20MHz, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection801 : 6; //cca RF correction 80MHz band1 , reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmCcaRfCorrection802 : 6; //cca RF correction 80MHz band2, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmCcaRfCorrection803 : 6; //cca RF correction 80MHz band3 Lower 20MHz, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg6F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG70 0x1C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection400 : 6; //cca RF correction 40MHz band0 Upper 20MHz, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection401 : 6; //cca RF correction 40MHz band1 Lower 20MHz, reset value: 0x0, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg70_u;

/*REG_UP_PHY_RXTD_ANT1_RX_ABB_ANT_REG71 0x1C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxSc2FcPhaseRegfile : 2; //rx_sc2fc_phase_regfile, reset value: 0x0, access type: RW
		uint32 rxFc2ScPhaseRegfile : 2; //rx_fc2sc_phase_regfile, reset value: 0x0, access type: RW
		uint32 rxSc2FcRxon : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegUpPhyRxtdAnt1RxAbbAntReg71_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG72 0x1C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBypassSelLpbkAfeN : 1; //pm_bypass_sel_lpbk_afe_n, reset value: 0x0, access type: RW
		uint32 pmDifi1Bypass : 1; //pm_difi1_bypass, reset value: 0x0, access type: RW
		uint32 pmDifi2Bypass : 1; //pm_difi2_bypass, reset value: 0x0, access type: RW
		uint32 pmDifi1LpbkType : 1; //pm_difi1_lpbk_type, reset value: 0x0, access type: RW
		uint32 reserved0 : 12;
		uint32 pmDifi2ShiftBy320M : 1; //pm_difi2_shift_by_320m, reset value: 0x0, access type: RW
		uint32 pmDifi3Bypass : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 14;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg72_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG73 0x1CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetBlkSize : 8; //pm_acidet_blk_size, reset value: 0x0, access type: RW
		uint32 pmAcidetAciDetTrig : 1; //pm_acidet_aci_det_trig, reset value: 0x0, access type: WO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg73_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG74 0x1D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetThDb0 : 6; //pm_acidet_th_db_0, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmAcidetThDb1 : 6; //pm_acidet_th_db_1, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmAcidetThOffset : 6; //pm_acidet_th_offset, reset value: 0x0, access type: RW
		uint32 reserved2 : 10;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg74_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG75 0x1D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetRadarHighTh : 8; //pm_acidet_radar_high_th, reset value: 0x0, access type: RW
		uint32 pmAcidetRadarLowTh : 8; //pm_acidet_radar_low_th, reset value: 0x0, access type: RW
		uint32 pmAcidetRadarClear : 1; //pm_acidet_radar_clear, reset value: 0x0, access type: WO
		uint32 pmAcidetRadarAutoClearEn : 1; //pm_acidet_radar_auto_clear_en, reset value: 0x0, access type: RW
		uint32 pmAcidetAciDetTrigOnFineEn : 1; //pm_acidet_aci_det_trig_on_fine_en , reset value: 0x0, access type: RW
		uint32 reserved0 : 13;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg75_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG76 0x1D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciDetected : 1; //aci_detected, reset value: 0x0, access type: RO
		uint32 aciDetectedValid : 1; //aci_detected_valid, reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
		uint32 acidetPowPrim : 9; //acidet_pow_prim, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 acidetMaxPowBandReg : 8; //acidet_max_pow_band_reg, reset value: 0x0, access type: RO
		uint32 reserved2 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg76_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG77 0x1DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetPowBandReg0 : 8; //acidet_pow_band_reg0, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg1 : 8; //acidet_pow_band_reg1, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg2 : 8; //acidet_pow_band_reg2, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg3 : 8; //acidet_pow_band_reg3, reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg77_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG78 0x1E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetPowBandReg4 : 8; //acidet_pow_band_reg4, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg5 : 8; //acidet_pow_band_reg5, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg6 : 8; //acidet_pow_band_reg6, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg7 : 8; //acidet_pow_band_reg7, reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg78_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG79 0x1E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter0 : 12; //acidet_radar_counter0, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter1 : 12; //acidet_radar_counter1, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg79_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7A 0x1E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter2 : 12; //acidet_radar_counter2, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter3 : 12; //acidet_radar_counter3, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg7A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7B 0x1EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter4 : 12; //acidet_radar_counter4, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter5 : 12; //acidet_radar_counter5, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg7B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7C 0x1F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter6 : 12; //acidet_radar_counter6, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter7 : 12; //acidet_radar_counter7, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg7C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7D 0x1F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarEventMask : 8; //acidet_radar_event_mask, reset value: 0x0, access type: RO
		uint32 acidetRadarEventNodetMask : 8; //acidet_radar_event_nodet_mask, reset value: 0x0, access type: RO
		uint32 acidetRadarCompletedEventMask : 8; //acidet_radar_completed_event_mask, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg7D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7E 0x1F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAciSystemGain : 9; //pm_aci_system_gain, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 pmAciSystemGainHwOnMux : 1; //1- choose system gain from AGC HW. 0- from PM �pm_bs_system_gain, reset value: 0x1, access type: RW
		uint32 reserved1 : 1;
		uint32 pmAciRssiSatThr : 18; //threshold on RSSI for flag assert to AGC , reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg7E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG7F 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSystemGainCcaCtrlHw0 : 1; //pm_system_gain_cca_ctrl_hw0 , reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 pmSystemGainCca : 9; //pm_system_gain_cca , reset value: 0x0, access type: RW
		uint32 reserved1 : 19;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg7F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG80 0x200 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ccaPmBwPwrOut : 8; //cca_pm_bw_pwr_out, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg80_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG81 0x204 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 impulseResponseShift04 : 7; //impulse_response_shift_0_4, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 impulseResponseShift08 : 7; //impulse_response_shift_0_8, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 impulseResponseShift16 : 7; //impulse_response_shift_1_6, reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 impulseResponseShift32 : 7; //impulse_response_shift_3_2, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg81_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG82 0x208 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlResetHwSync : 10; //fdl_reset_hw_sync, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg82_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG83 0x20C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlRestartEn : 1; //fdl_restart_en, reset value: 0x0, access type: RW
		uint32 fdlCorrectionEnable : 1; //fdl_correction_enable, reset value: 0x0, access type: RW
		uint32 freqShiftPpmEnable : 1; //freq_shift_ppm_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg83_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG84 0x210 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrMax : 32; //fdl_nco_incr_max, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg84_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG85 0x214 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncr : 32; //fdl_nco_incr, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg85_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG86 0x218 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmFdlForceNcoIncr : 1; //pm_fdl_force_nco_incr, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg86_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG87 0x21C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrOut : 32; //fdl_nco_incr_out, reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg87_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG88 0x220 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrValidOut : 1; //fdl_nco_incr_valid_out, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg88_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG89 0x224 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrSat : 1; //fdl_nco_incr_sat, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg89_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8A 0x228 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoAccStsOut : 32; //fdl_nco_acc_sts_out, reset value: 0x0, access type: RO
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg8A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8B 0x22C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pm11BDecimPhase : 2; //decimation phase from 160M to 40M from Shifter-M2 to 11B core, reset value: 0x2, access type: RW
		uint32 pm11BDecimPathSelect : 1; //11b mux data path selection  , 0 - band select  , 1 - decimator path select ,  ,  , , reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg8B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8C 0x230 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fftShareOverrideControl : 1; //fft_share_override_control for digital loopback, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 fftControlRx : 1; //fft control rx mode or tx mode: 0 -TX, 1-RX, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg8C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8D 0x234 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antOfdmC16Rm : 3; //ant_ofdm_c16_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 1;
		uint32 antOfdmC64Rm : 3; //ant_ofdm_c64_rm, reset value: 0x3, access type: RW
		uint32 reserved1 : 1;
		uint32 antOfdmMrbRm : 3; //ant_ofdm_mrb_rm, reset value: 0x3, access type: RW
		uint32 reserved2 : 1;
		uint32 antAciDetAvgRm : 3; //ant_aci_det_avg_rm, reset value: 0x3, access type: RW
		uint32 reserved3 : 1;
		uint32 antIqParamsLutRm : 3; //ant_iq_params_lut_rm, reset value: 0x3, access type: RW
		uint32 reserved4 : 1;
		uint32 antIqFireqLutRm : 3; //ant_iq_fireq_lut_rm, reset value: 0x3, access type: RW
		uint32 reserved5 : 9;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg8D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8E 0x238 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 testPlugLen : 12; //test_plug_len, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg8E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG8F 0x23C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlDisableTimingUpdates : 1; //fdl_disable_timing_updates, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg8F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG90 0x240 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 heTrigStfGainBypass : 1; //he_trig_stf_gain_bypass, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg90_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG91 0x244 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rssiData : 15; //rssi_data, reset value: 0x0, access type: RO
		uint32 reserved0 : 17;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg91_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG92 0x248 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 stsFdlIqComp : 16; //sts_fdl_iq_comp, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg92_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG93 0x24C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 stsChanfiltCoef : 12; //sts_chanfilt_coef, reset value: 0x0, access type: RO
		uint32 stsChanfiltSetId : 5; //sts_chanfilt_set_id, reset value: 0x0, access type: RO
		uint32 stsChanfiltFiltLength : 8; //sts_chanfilt_filt_length, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg93_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG94 0x250 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarMaxCnt : 12; //acidet_radar_max_cnt, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg94_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG95 0x254 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPreFilterBypass : 1; //pm_pre_filter_bypass, reset value: 0x1, access type: RW
		uint32 pmPreFilterBypassWithDelay : 1; //pm_pre_filter_bypass_with_delay, reset value: 0x0, access type: RW
		uint32 pmPreFilterNarrowMode : 1; //pm_pre_filter_narrow_mode, reset value: 0x0, access type: RW
		uint32 pmPreFilterBypassWithGain : 1; //pm_pre_filter_bypass_no_delay_with_gain, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg95_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG96 0x258 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPreFilterGain : 7; //pm_pre_filter_gain, reset value: 0x0, access type: RW
		uint32 pmPreFilterGainEn : 1; //pm_pre_filter_gain_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg96_u;

/*REG_UP_PHY_RXTD_ANT1_CONTROL_11B 0x25C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bitShift11B : 2; //bit shift for 11b , reset value: 0x0, access type: RW
		uint32 bitShift11BHwEn : 1; //choose if taking hw or pm for bit shift, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegUpPhyRxtdAnt1Control11B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG98 0x260 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bandselFilterIndex : 1; //bandsel filter index to select between regular to narrow filter, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg98_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG99 0x264 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bandselToDetPmGainDb : 7; //bandsel_to_det_pm_gain_db, reset value: 0x0, access type: RW
		uint32 bandselToDetHwGainDbEn : 1; //bandsel_to_det_hw_gain_db_en, reset value: 0x0, access type: RW
		uint32 bandsel10MhzForce : 2; //bandsel_10mhz_force, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg99_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9A 0x268 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap0 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap1 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg9A_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9B 0x26C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap2 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap3 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg9B_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9C 0x270 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap4 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap5 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg9C_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9D 0x274 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap6 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap7 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg9D_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9E 0x278 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap8 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap9 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg9E_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REG9F 0x27C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap10 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap11 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntReg9F_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA1 0x284 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap0 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap1 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega1_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA2 0x288 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap2 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap3 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega2_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA3 0x28C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap4 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap5 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega3_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA4 0x290 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap6 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap7 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega4_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA5 0x294 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap8 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap9 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega5_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA6 0x298 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap10 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap11 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega6_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA7 0x29C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRamLs : 8; //pm_ram_ls, reset value: 0x0, access type: RW
		uint32 pmRamDs : 2; //pm_ram_ds, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 pmRamSd : 2; //pm_ram_sd, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
		uint32 pmRamPsHwEn : 8; //pm_ram_ps_hw_en, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega7_u;

/*REG_UP_PHY_RXTD_ANT1_FORCE_OP_CH_ZERO 0x2A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 forceOpChZero : 16; //force_op_zero, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegUpPhyRxtdAnt1ForceOpChZero_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGA9 0x2A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRamRop : 2; //pm_ram_rop, reset value: 0x0, access type: RO
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRega9_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGAA 0x2A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mrbOutForce0Enable : 1; //mrb_out_force_0_enable   , reset value: 0x0, access type: WO
		uint32 lengthOfMrbOutForce0 : 7; //length_of_mrb_out_force_0, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRegaa_u;

/*REG_UP_PHY_RXTD_ANT1_TB_BANDSELECT_BANDS 0x2AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tbBandselectBands : 16; //which bands to record in test bus, reset value: 0xFFFF, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegUpPhyRxtdAnt1TbBandselectBands_u;

/*REG_UP_PHY_RXTD_ANT1_CONTROL_OVERRIDE 0x2B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAntSwResetNRegSel : 1; //take sw_reset_n from ant vs common, reset value: 0x0, access type: RW
		uint32 pmAntBlockEnSel : 1; //take block_en from ant vs common, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1ControlOverride_u;

/*REG_UP_PHY_RXTD_ANT1_ANT_SW_RESET_N_REG 0x2B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antSwResetNReg : 32; //sw reset n from ant, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1AntSwResetNReg_u;

/*REG_UP_PHY_RXTD_ANT1_ANT_BLOCK_EN 0x2B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antBlockEn : 32; //block en ant, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1AntBlockEn_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_0 0x2BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower0 : 9; //aci_band_power_0, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower0_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_1 0x2C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower1 : 9; //aci_band_power_1, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower1_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_2 0x2C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower2 : 9; //aci_band_power_2, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower2_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_3 0x2C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower3 : 9; //aci_band_power_3, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower3_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_4 0x2CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower4 : 9; //aci_band_power_4, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower4_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_5 0x2D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower5 : 9; //aci_band_power_5, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower5_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_6 0x2D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower6 : 9; //aci_band_power_6, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower6_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_7 0x2D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower7 : 9; //aci_band_power_7, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower7_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_8 0x2DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower8 : 9; //aci_band_power_8, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower8_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_9 0x2E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower9 : 9; //aci_band_power_9, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower9_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_10 0x2E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower10 : 9; //aci_band_power_10, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower10_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_11 0x2E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower11 : 9; //aci_band_power_11, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower11_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_12 0x2EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower12 : 9; //aci_band_power_12, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower12_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_13 0x2F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower13 : 9; //aci_band_power_13, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower13_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_14 0x2F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower14 : 9; //aci_band_power_14, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower14_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_15 0x2F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower15 : 9; //aci_band_power_15, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPower15_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_0_3 0x2FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr0 : 7; //aci_band_power_ovr_0, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr0En : 1; //aci_band_power_ovr_0_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr1 : 7; //aci_band_power_ovr_1, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr1En : 1; //aci_band_power_ovr_1_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr2 : 7; //aci_band_power_ovr_2, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr2En : 1; //aci_band_power_ovr_2_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr3 : 7; //aci_band_power_ovr_3, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr3En : 1; //aci_band_power_ovr_3_en, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPowerOvr03_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_4_7 0x300 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr4 : 7; //aci_band_power_ovr_4, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr4En : 1; //aci_band_power_ovr_4_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr5 : 7; //aci_band_power_ovr_5, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr5En : 1; //aci_band_power_ovr_5_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr6 : 7; //aci_band_power_ovr_6, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr6En : 1; //aci_band_power_ovr_6_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr7 : 7; //aci_band_power_ovr_7, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr7En : 1; //aci_band_power_ovr_7_en, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPowerOvr47_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_8_11 0x304 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr8 : 7; //aci_band_power_ovr_8, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr8En : 1; //aci_band_power_ovr_8_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr9 : 7; //aci_band_power_ovr_9, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr9En : 1; //aci_band_power_ovr_9_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr10 : 7; //aci_band_power_ovr_10, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr10En : 1; //aci_band_power_ovr_10_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr11 : 7; //aci_band_power_ovr_11, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr11En : 1; //aci_band_power_ovr_11_en, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPowerOvr811_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_BAND_POWER_OVR_12_15 0x308 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr12 : 7; //aci_band_power_ovr_12, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr12En : 1; //aci_band_power_ovr_12_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr13 : 7; //aci_band_power_ovr_13, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr13En : 1; //aci_band_power_ovr_13_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr14 : 7; //aci_band_power_ovr_14, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr14En : 1; //aci_band_power_ovr_14_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr15 : 7; //aci_band_power_ovr_15, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr15En : 1; //aci_band_power_ovr_15_en, reset value: 0x0, access type: RW
	} bitFields;
} RegUpPhyRxtdAnt1AciBandPowerOvr1215_u;

/*REG_UP_PHY_RXTD_ANT1_ACI_DET_RADAR_COUNTER_TH 0x30C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciDetRadarCounterTh : 12; //aci_det_radar_counter_th, reset value: 0x16, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegUpPhyRxtdAnt1AciDetRadarCounterTh_u;

/*REG_UP_PHY_RXTD_ANT1_LOOPBACK_PYPASS 0x310 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLoopPrefilterBypass : 1; //pm_loop_prefilter_bypass, reset value: 0x0, access type: RW
		uint32 pmLoopFdlBypass : 1; //pm_loop_fdl_bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1LoopbackPypass_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGC5 0x314 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlFreqShiftScale : 24; //fdl_freq_shift_scale, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRegc5_u;

/*REG_UP_PHY_RXTD_ANT1_PHY_RXTD_ANT_REGC6 0x318 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tdNcoFreq : 24; //td_nco_freq, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegUpPhyRxtdAnt1PhyRxtdAntRegc6_u;

/*REG_UP_PHY_RXTD_ANT1_PM_ACIDET_BYPASS_OFFSETS 0x31C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetBypassOffsets : 1; //pm_acidet_bypass_offsets , reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegUpPhyRxtdAnt1PmAcidetBypassOffsets_u;

/*REG_UP_PHY_RXTD_ANT1_ANTENNA_320M_MODE_CONTROLS 0x320 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMixer80Bp : 1; //no description, reset value: 0x0, access type: RW
		uint32 pmSplitterBp : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegUpPhyRxtdAnt1Antenna320MModeControls_u;



#endif // _UP_PHY_RXTD_ANT1_REGS_H_