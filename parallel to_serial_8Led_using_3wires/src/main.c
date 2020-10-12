/*
 * main.c
 *
 *  Created on: Sep 26, 2020
 *      Author: Mahmoud_Korayem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_interface.h"
#include "STP_interface.h"
#include "STP_interface.h"

void main (void)
{
	/* clock intialization */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , 2);
	MGPIO_voidSetPinDirection( GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP );

	/* Timer Init */
	MSTK_voidInit();
	//HSTP_voidSendSynchronus(0xAA);
	while(1)
	{
		u8 i=0;
		for(i=0;i<8;i++)
		{
			HSTP_voidSendSynchronus(1<<i);
			MSTK_voidSetBusyWait(3000000);
		}

	}


}
