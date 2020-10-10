/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 30 AUG 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : NVIC-Private.h  ****************/
/*********************************************************/




#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* NVIC_base_Adress  0xE000E100 */

#define NVIC_ISER0   *((u32*)0xE000E100) /*Enable External Interupts From 0  to 31 */
#define NVIC_ISER1   *((u32*)0xE000E104) /*Enable External Interupts From 32 to 61 */

#define NVIC_ICER0   *((u32*)0xE000E180) 
#define NVIC_ICER1   *((u32*)0xE000E184) 

#define NVIC_ISPR0   *((u32*)0xE000E200) 
#define NVIC_ISPR1   *((u32*)0xE000E204) 

#define NVIC_ICPR0   *((u32*)0xE000E280) 
#define NVIC_ICPR1   *((u32*)0xE000E284) 

#define NVIC_IABR0   *((volatile u32*)0xE000E300) 
#define NVIC_IABR1   *((volatile u32*)0xE000E304) 

#define NVIC_IPR     ((volatile u8 *)0xE000E100 + 0x300)

/* SCB_base_Adress  0xE000ED00  */

#define SCB_AIRCR   *((volatile u32*)0xE000ED00 + 0x0C )



#endif