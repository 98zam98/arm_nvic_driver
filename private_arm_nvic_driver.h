/******************************************************************************
 * Module: ARM_NVIC_DRIVER
 * File Name: Private_arm_nvic_driver.h
 * Version: 1
 * Date: 7/1/2022
 * Description: function prototypes and variables and macro functions that should not get called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

#ifndef __PRIVATE_ARM_NVIC_DRIVER_H__
#define __PRIVATE_ARM_NVIC_DRIVER_H__

/* function prototypes*/

//--------------------------------------	


/* variables */

//--------------------------------------	


/* macro function*/

#define MACRO_CONFIG_NVIC_IP_VALUE(GROUP,SUB)       (GROUP<<(SCB_AIRCR_PRIGROUP_TYPE-Group_16_SUB_0_u3_value_SCB_AIRCR_PRIGROUP))|SUB        
//--------------------------------------	


#endif /* __PRIVATE_ARM_NVIC_DRIVER_H__ */