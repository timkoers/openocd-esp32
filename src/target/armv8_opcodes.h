/*
 * Copyright (C) 2015 by pierrr kuo
 * vichy.kuo@gmail.com
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef OPENOCD_TARGET_ARMV8_OPCODES_H
#define OPENOCD_TARGET_ARMV8_OPCODES_H

#include "arm_opcodes.h"

/* ARM V8 Move from system register to general purpose register
 * R = 1: SPSR R = 0: CPSR
 * Rn: target register
 */
#define SYSTEM_CUREL			0b1100001000010010
#define SYSTEM_CUREL_MASK		0xC0
#define SYSTEM_CUREL_SHIFT		6
#define SYSTEM_CUREL_EL0		0x0
#define SYSTEM_CUREL_EL1		0x1
#define SYSTEM_CUREL_EL2		0x2
#define SYSTEM_CUREL_EL3		0x3
#define SYSTEM_CUREL_NONCH		0xF
#define SYSTEM_AARCH64			0x1

#define SYSTEM_AAR64_MODE_EL0t	0x0
#define SYSTEM_AAR64_MODE_EL1t	0x4
#define SYSTEM_AAR64_MODE_EL1h	0x5
#define SYSTEM_AAR64_MODE_EL2t	0x8
#define SYSTEM_AAR64_MODE_EL2h	0x9
#define SYSTEM_AAR64_MODE_EL3t	0xC
#define SYSTEM_AAR64_MODE_EL3h	0xd

#define SYSTEM_DAIF			0b1101101000010001
#define SYSTEM_DAIF_MASK		0x3C0
#define SYSTEM_DAIF_SHIFT		6

#define SYSTEM_ELR_EL1			0b1100001000000001
#define SYSTEM_ELR_EL2			0b1110001000000001
#define SYSTEM_ELR_EL3			0b1111001000000001

#define SYSTEM_FPCR			0b1101101000100000
#define SYSTEM_FPSR			0b1101101000100001
#define SYSTEM_DAIF			0b1101101000010001
#define SYSTEM_NZCV			0b1101101000010000
#define SYSTEM_SP_EL0			0b1100001000001000
#define SYSTEM_SP_EL1			0b1110001000001000
#define SYSTEM_SP_EL2			0b1111001000001000
#define SYSTEM_SP_SEL			0b1100001000010000
#define SYSTEM_SPSR_ABT			0b1110001000011001
#define SYSTEM_SPSR_FIQ			0b1110001000011011
#define SYSTEM_SPSR_IRQ			0b1110001000011000
#define SYSTEM_SPSR_UND			0b1110001000011010

#define SYSTEM_SPSR_EL1			0b1100001000000000
#define SYSTEM_SPSR_EL2			0b1110001000000000
#define SYSTEM_SPSR_EL3			0b1111001000000000

#define SYSTEM_ISR_EL1			0b1100011000001000


#define SYSTEM_DBG_DSPSR_EL0    0b1101101000101000
#define SYSTEM_DBG_DLR_EL0		0b1101101000101001
#define SYSTEM_DBG_DTRRX_EL0	0b1001100000101000
#define SYSTEM_DBG_DTRTX_EL0	0b1001100000101000
#define SYSTEM_DBG_DBGDTR_EL0	0b1001100000100000

#define SYSTEM_CCSIDR			0b1100100000000000
#define SYSTEM_CLIDR			0b1100100000000001
#define SYSTEM_CSSELR			0b1101000000000000
#define SYSTEM_CTYPE			0b1101100000000001

#define SYSTEM_DCCISW			0b0100001111110010
#define SYSTEM_DCCSW			0b0100001111010010
#define SYSTEM_ICIVAU			0b0101101110101001
#define SYSTEM_DCCVAU			0b0101101111011001

#define SYSTEM_MPIDR			0b1100000000000101

#define SYSTEM_TCR_EL1			0b1100000100000010
#define SYSTEM_TCR_EL2			0b1110000100000010
#define SYSTEM_TCR_EL3			0b1111000100000010

#define SYSTEM_TTBR0_EL1		0b1100000100000000
#define SYSTEM_TTBR0_EL2		0b1110000100000000
#define SYSTEM_TTBR0_EL3		0b1111000100000000
#define SYSTEM_TTBR1_EL1		0b1100000100000001



#define ARMV8_MRS_DSPSR(Rt)	(0xd53b4500 | (Rt))
#define ARMV8_MSR_DSPSR(Rt)	(0xd51b4500 | (Rt))
#define ARMV8_MRS_DLR(Rt)	(0xd53b4520 | (Rt))
#define ARMV8_MSR_DLR(Rt)	(0xd51b4520 | (Rt))

/* T32 ITR format */
#define T32_FMTITR(instr) (((instr & 0x0000FFFF) << 16) | ((instr & 0xFFFF0000) >> 16))

#define ARMV8_DCPS1(IM)	(0xd4a00001 | (((IM) & 0xFFFF) << 5))
#define ARMV8_DCPS2(IM)	(0xd4a00002 | (((IM) & 0xFFFF) << 5))
#define ARMV8_DCPS3(IM)	(0xd4a00003 | (((IM) & 0xFFFF) << 5))

#define DSB_SY				0xd5033F9F
#define ARMV8_MRS(System, Rt)	(0xd5300000 | ((System) << 5) | (Rt))
/* ARM V8 Move to system register. */
#define ARMV8_MSR_GP(System, Rt) \
	(0xd5100000 | ((System) << 5) | (Rt))
/* ARM V8 Move immediate to process state field. */
#define ARMV8_MSR_IM(Op1, CRm, Op2) \
	(0xd500401f | ((Op1) << 16)  | ((CRm) << 8) | ((Op2) << 5))

#define ARMV8_BKPT(Im) (0xD4200000 | ((Im & 0xffff) << 5))
#define ARMV8_HLT(Im) (0x0D4400000 | ((Im & 0xffff) << 5))

#define ARMV8_MOVFSP_64(Rt) ((1 << 31) | 0x11000000 | (0x1f << 5) | (Rt))
#define ARMV8_MOVTSP_64(Rt) ((1 << 31) | 0x11000000 | (Rt << 5) | (0x1F))
#define ARMV8_MOVFSP_32(Rt) (0x11000000 | (0x1f << 5) | (Rt))
#define ARMV8_MOVTSP_32(Rt) (0x11000000 | (Rt << 5) | (0x1F))


#endif /* __ARM_OPCODES_H */
