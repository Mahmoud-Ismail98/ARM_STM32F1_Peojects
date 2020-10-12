/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MIK-PC
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"


void main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , 2);
	RCC_voidEnableClock(RCC_APB2 , 14); /* USART1 Enable Clock */


	MGPIO_voidSetPinDirection(GPIOA,PIN9 ,OUTPUT_SPEED_50MHZ_AFPP); //TX
	MGPIO_voidSetPinDirection(GPIOA ,PIN10 , INPUT_FLOAT);	  //RX

	MUSART1_voidInit();

	u8 x;
	while(1)
	{
		MUSART1_voidTransmit("97");
		x = MUSART1_u8Receive() ;
		if(x == '5')
		{
			MGPIO_voidSetPinValue(GPIOA , PIN0 ,GPIO_HIGH);
		}
		else if (x == '6')
		{
			MGPIO_voidSetPinValue(GPIOA , PIN0 , GPIO_LOW);
		}
	}


}
