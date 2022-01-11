/******************************************************************************
 * Module: ARM_NVIC_DRIVER
 * File Name: Hardware_arm_nvic_driver.h
 * Version: 1
 * Date: 7/1/2022
 * Description: registers or connection with their macros and data types
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/
#ifndef __HARDWARE_ARM_NVIC_DRIVER_H__
#define __HARDWARE_ARM_NVIC_DRIVER_H__

/* NVIC */

#define NVIC_BASE 0xE000E100

/* NVIC_ISERx start */
// Interrupt set-enable registers (NVIC_ISERx)
// Privileged
// 1: Enable interrupt

#define NVIC_ISER_OFFSET 0x00
#define NVIC_ISERx_OFFSET(X) NVIC_ISER_OFFSET + (X * 4)
#define NVIC_ISERx_BASE(X) (NVIC_BASE + NVIC_ISERx_OFFSET(X))
#define NVIC_ISERx_REG(X) (*(volatile u32 *)NVIC_ISERx_BASE(X))

/* NVIC_ISERx end */
//--------------------------------------

/* NVIC_ICERx start */
// Interrupt clear-enable registers (NVIC_ICERx)
/*
Required privilege: Privileged
The ICER0-ICER2 registers disable interrupts, and show which interrupts are enabled
CLRENA[31:0]: Interrupt clear-enable bits.
Write:
0: No effect
1: Disable interrupt
Read:
0: Interrupt disabled
1: Interrupt enabled
*/

#define NVIC_ICER_OFFSET 0x080
#define NVIC_ICERx_OFFSET(X) NVIC_ICER_OFFSET + (X * 4)
#define NVIC_ICERx_BASE(X) (NVIC_BASE + NVIC_ICERx_OFFSET(X))
#define NVIC_ICERx_REG(X) (*(volatile u32 *)NVIC_ICERx_BASE(X))

/* NVIC_ICERx end */
//--------------------------------------

/* NVIC_ISPRx start */
// Interrupt set-pending registers (NVIC_ISPRx)
/*
Required privilege: Privileged
The ISPR0-ISPR2 registers force interrupts into the pending state, and show which
interrupts are pending
SETPEND[31:0]: Interrupt set-pending bits
Write:
0: No effect
1: Changes interrupt state to pending
Read:
0: Interrupt is not pending
1: Interrupt is pending
Writing 1 to the ISPR bit corresponding to a disabled interrupt:
– sets the state of that interrupt to pending.
Writing 1 to the ISPR bit corresponding to an interrupt that is pending:
– has no effect.
*/

#define NVIC_ISPR_OFFSET 0x100
#define NVIC_ISPRx_OFFSET(X) NVIC_ISPR_OFFSET + (X * 4)
#define NVIC_ISPRx_BASE(X) (NVIC_BASE + NVIC_ISPRx_OFFSET(X))
#define NVIC_ISPRx_REG(X) (*(volatile u32 *)NVIC_ISPRx_BASE(X))

/* NVIC_ISPRx end */
//--------------------------------------

/* NVIC_ICPRx start */
// Interrupt clear-pending registers (NVIC_ICPRx)
/*
Required privilege: Privileged
The ICPR0-ICPR2 registers remove the pending state from interrupts, and show which
interrupts are pending
CLRPEND[31:0]: Interrupt clear-pending bits
Write:
0: No effect
1: Removes the pending state of an interrupt
Read:
0: Interrupt is not pending
1: Interrupt is pending
Writing 1 to an ICPR bit does not affect the active state of the corresponding interrupt.
*/

#define NVIC_ICPR_OFFSET 0x180
#define NVIC_ICPRx_OFFSET(X) NVIC_ICPR_OFFSET + (X * 4)
#define NVIC_ICPRx_BASE(X) (NVIC_BASE + NVIC_ICPRx_OFFSET(X))
#define NVIC_ICPRx_REG(X) (*(volatile u32 *)NVIC_ICPRx_BASE(X))

/* NVIC_ICPRx end */
//--------------------------------------

/* NVIC_IABRx start */
// Interrupt active bit registers (NVIC_IABRx)
/*
Required privilege: Privileged
The IABR0-IABR2 registers indicate which interrupts are active. 
ACTIVE[31:0]: Interrupt active flags
0: Interrupt not active
1: Interrupt active
*/

#define NVIC_IABR_OFFSET 0x200
#define NVIC_IABRx_OFFSET(X) NVIC_IABR_OFFSET + (X * 4)
#define NVIC_IABRx_BASE(X) (NVIC_BASE + NVIC_IABRx_OFFSET(X))
#define NVIC_IABRx_REG(X) (*(volatile u32 *)NVIC_IABRx_BASE(X))

/* NVIC_IABRx end */
//--------------------------------------

/* NVIC_IPRx start */
// Interrupt priority registers (NVIC_IPRx)
/*
Required privilege: Privileged
The IPR0-IPR16 registers provide a 4-bit priority field for each interrupt. These registers are
byte-accessible. Each register holds four priority fields, that map to four elements in the
CMSIS interrupt priority array IP[0] to IP[67]

Each priority field holds a priority value, 0-255. The lower the value,
the greater the priority of the corresponding interrupt. The processor
implements only bits[7:4] of each field, bits[3:0] read as zero and
ignore writes

Find the IPR number and byte offset for interrupt N as follows:
• The corresponding IPR number, M, is given by M = N DIV 4
M = N/4
• The byte offset of the required Priority field in this register is N MOD 4, where:
M = N%4
– byte offset 0 refers to register bits[7:0]
– byte offset 1 refers to register bits[15:8]
– byte offset 2 refers to register bits[23:16]
– byte offset 3 refers to register bits[31:24]
*/

#define NVIC_IPR_OFFSET 0x300
#define NVIC_IPRx_OFFSET(X) NVIC_IPR_OFFSET + (X * 4)
#define NVIC_IPRx_BASE(X) (NVIC_BASE + NVIC_IPRx_OFFSET(X))
#define NVIC_IPRx_REG(X) (*(volatile u32 *)NVIC_IPRx_BASE(X))
#define NVIC_IPn_U8(N) (*(volatile u8 *)(NVIC_IPRx_BASE(N / 4) + (N % 4)))


/* NVIC_IPRx end */
//--------------------------------------

/* NVIC_STIR start */
// Software trigger interrupt register (NVIC_STIR)
/*
Required privilege: When the USERSETMPEND bit in the SCR is set to 1, unprivileged
software can access the STIR, Only privileged software can enable unprivileged access to the STIR

NTID[8:0] Software generated interrupt ID
Write to the STIR to generate a Software Generated Interrupt (SGI). The value to be written is
the Interrupt ID of the required SGI, in the range 0-239. For example, a value of 0b000000011
specifies interrupt IRQ3
*/
#define NVIC_STIR_OFFSET 0xE00
#define NVIC_STIR_BASE (NVIC_BASE + NVIC_STIR_OFFSET)
#define NVIC_STIR_REG (*(volatile u32 *)NVIC_STIR_BASE)

/* NVIC_STIR end */
//--------------------------------------

//--------------------------------------

#endif /* __HARDWARE_ARM_NVIC_DRIVER_H__ */