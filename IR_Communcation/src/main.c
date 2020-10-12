/*
 * main.c
 *
 *  Created on: Sep 16, 2020
 *      Author: Mahmoud_Korayem
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

volatile u8 u8StartFlag       = 0;
volatile u32 u32FrameDate[50] ={0};
volatile u8 u8EdgeCounter     = 0 ;
volatile u8   u8Data          = 0;

void voidplay(void)
{
	switch (u8Data)
	{
	case 70:
	MGPIO_voidSetPinValue(GPIOA,1,GPIO_HIGH);
	MGPIO_voidSetPinValue(GPIOA,2,GPIO_HIGH);
	MGPIO_voidSetPinValue(GPIOA,3,GPIO_HIGH); break;

	case 69:
	MGPIO_voidSetPinValue(GPIOA,1,GPIO_HIGH);  break;


	}
}
void voidTakeAction(void)
{
	u8Data = 0;
	for(u8 i=0 ;i<8 ;i++)
	{
		if (u32FrameDate[17+i] >= 17000 && u32FrameDate[17+i] <= 23000)
		{
			SET_BIT(u8Data , i);
		}
		else
		{
			CLR_BIT(u8Data,i);
		}
	}

	voidplay();

	u8StartFlag       = 0;
	u32FrameDate[0]   = 0;
	u8EdgeCounter     = 0;


}
void voidGetFrame(void)
{
	if(u8StartFlag == 0)
	{
	/* Start Timer */
	MSTK_voidSetIntervalSingle(1000000 ,voidTakeAction);
	u8StartFlag = 1;
	}
	else
	{
	u32FrameDate[u8EdgeCounter] = MSTK_u32GetElapsedTime();
	MSTK_voidSetIntervalSingle(1000000 ,voidTakeAction);
	u8EdgeCounter++;
	}

}

void main(void)
{
	/* RCC Initialize */
    RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);/* GPIOA Enable Clock */

	MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOAT );		/* A0 Input Floating        */
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);/* A1 Output PP "RED"       */
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);/* A1 Output PP "GREEN"     */
	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);/* A1 Output PP "BLUE"      */
	MGPIO_voidSetPinValue(GPIOA,1,GPIO_HIGH);
	MGPIO_voidSetPinValue(GPIOA,2,GPIO_HIGH);
	MGPIO_voidSetPinValue(GPIOA,3,GPIO_HIGH);
	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(voidGetFrame);
    MEXTI_voidInit();   /*Enable EXTI0 Interrupt Falling Edge */
	//MSK_voidSetPeriority(6,GROUP5,0,0);
	MNVIC_voidEnableInerupt(6); /*EXTI0*/
	/* SysTick Init */
	MSTK_voidInit(); /*Enable SysTick AHP/8=1MHZ */
	while(1)
	{

	}

}
