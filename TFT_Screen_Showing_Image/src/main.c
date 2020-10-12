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
#include "STK_interface.h"
#include "SPI_interface.h"
#include "image.h"

void main(void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2 , 2);
	RCC_voidEnableClock(RCC_APB2 , 12); /* SPI Enable Clock */


	MGPIO_voidSetPinDirection(GPIOA,PIN1 ,OUTPUT_SPEED_2MHZ_PP); 	   //A0
	MGPIO_voidSetPinDirection(GPIOA,PIN2 ,OUTPUT_SPEED_2MHZ_PP);	  //RST
	MGPIO_voidSetPinDirection(GPIOA,PIN5 ,OUTPUT_SPEED_10MHZ_AFPP);	  //CLK
	MGPIO_voidSetPinDirection(GPIOA,PIN7 ,OUTPUT_SPEED_10MHZ_AFPP);	  //MOSI

	/* Init STK */
	MSTK_voidInit();

	/* SPI Init */
	MSPI1_voidInit();

	/* TFT Init */
	HTFT_voidInitialize();

	/* Display Image */
	//HTFT_voidDisplayImage(image);
	HTFT_voidFillColor(0xffff);
	HTFT_voidDrawRect(10,60,10,100,0x0000);


	while(1);

}
