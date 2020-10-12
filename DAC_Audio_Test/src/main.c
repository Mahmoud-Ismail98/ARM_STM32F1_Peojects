/*
 * main.c
 *
 *  Created on: Sep 18, 2020
 *      Author: Mahmoud_Korayem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "STK_interface.h"
#include "file.h"

#include "GPIO_private.h"

volatile u16 i=0;
void voidSetDAC(void)
{
	GPIOA_ODR =  Amaren_raw[i];
	i++;
	if (i == 39660)
	{
		i = 0;
	}
}

void main(void)
{

	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2 , 2);

	MGPIO_voidSetPinDirection( GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN3 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN4 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN5 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN6 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection( GPIOA , PIN7 , OUTPUT_SPEED_2MHZ_PP );

	MSTK_voidInit();

	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);
	while(1)
	{

	}
}


