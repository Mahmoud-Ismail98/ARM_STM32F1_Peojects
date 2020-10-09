/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 30 AUG 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : main.c   ****************/
/*********************************************************/
/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* MCAL includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"



void Interrup(void);

void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA Clock */
	RCC_voidEnableClock(RCC_APB2,0); /* Enable AFIO Clock */

	/* Pin Mode */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_PULL_UP_DOWEN );
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_HIGH);

	//MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);


	MEXTI_voidSetCallBack(Interrup);

	/* Enable EXTI0 Interupt From NVIC */
    MNVIC_voidEnableInerupt(6);   /*EXTI 0 */

    MNVIC_voidSetPeriority(6,1,0,GROUP5); /*GROUP5 2BIT FOR GROUP ,2BIT FOR SUP GROUP */
	MEXTI_voidInit();
	MEXTI_voidSetSignalLatch( EXTI_LINE0 ,FALLING_EDGE);
	MNVIC_voidSetPendingFlag(6);
	while(1)
	{

	}

}

void Interrup(void)
{
	MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_HIGH);
	MSTK_voidSetBusyWait(1000000);
	MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_LOW);
	MSTK_voidSetBusyWait(1000000);

}
