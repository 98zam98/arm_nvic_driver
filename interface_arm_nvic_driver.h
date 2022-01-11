/******************************************************************************
 * Module: ARM_NVIC_DRIVER
 * File Name: Interface_arm_nvic_driver.h
 * Version: 1
 * Date: 7/1/2022
 * Description: function prototypes and variables and macro functions that can be called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

#ifndef __INTERFACE_ARM_NVIC_DRIVER_H__
#define __INTERFACE_ARM_NVIC_DRIVER_H__

/* function prototypes*/

//--------------------------------------	


/* variables */

//--------------------------------------	


/* macro function*/
#define MACRO_ENABLE_INTERRUPT_NVIC(INTERRUPT_BIT)     SETBIT(NVIC_ISERx_REG((INTERRUPT_BIT/32)),(INTERRUPT_BIT%32))
#define MACRO_DISABLE_INTERRUPT_NVIC(INTERRUPT_BIT)     SETBIT(NVIC_ICERx_REG((INTERRUPT_BIT/32)),(INTERRUPT_BIT%32))
#define MACRO_SET_PENDING_INTERRUPT_NVIC(INTERRUPT_BIT)     SETBIT(NVIC_ISPRx_REG((INTERRUPT_BIT/32)),(INTERRUPT_BIT%32))
#define MACRO_CLEAR_PENDING_INTERRUPT_NVIC(INTERRUPT_BIT)     SETBIT(NVIC_ICPRx_REG((INTERRUPT_BIT/32)),(INTERRUPT_BIT%32))

#define MACRO_READ_ACTIVE_INTERRUPT_NVIC(INTERRUPT_BIT)     GETBIT(NVIC_IABRx_REG((INTERRUPT_BIT/32)),(INTERRUPT_BIT%32))


#define MACRO_CONFIG_NVIC_IPn(N,GROUP,SUB)      NVIC_IPn_U8(N) = (MACRO_CONFIG_NVIC_IP_VALUE(GROUP,SUB)<< 4)
//--------------------------------------	


#endif /* __INTERFACE_ARM_NVIC_DRIVER_H__ */