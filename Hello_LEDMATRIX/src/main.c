/*
 * main.c
 *
 *  Created on: Sep 14, 2020
 *      Author: Mahmoud_Korayem
 */
/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* MCAL includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMAT_interface.h"

u8 DateArray[8]={0,124,18,18,18,124,0,0};
void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA Clock */
	RCC_voidEnableClock(RCC_APB2,3); /* Enable GPIOB Clock */

	MSTK_voidInit();
	HLEDMAT_voidInit();
	HLEDMAT_voidDisplay(DateArray);
}
