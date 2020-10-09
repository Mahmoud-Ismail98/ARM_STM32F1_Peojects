/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* MCAL includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"




void Led_voidAnimation(void);

typedef enum {
		LED_LEFT  ,
		LED_RIGHT ,
		LED_IN    ,
		LED_OUT   ,
		LED_BLINK ,
}led_state_t ;

led_state_t Global_State = LED_LEFT;
u8 Global_Offset = 0 ;
u8 Global_Timer = 0 ;
u8 Global_Counter = 0 ;
u8 up = 4 ;
u8 down = 3 ;

int main (void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA Clock */

	/* Pin Mode */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);

	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);

	MGPIO_voidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);

	/* Enable Systick */
	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(1000000,Led_voidAnimation);
	
	while(1)
	{

	}


	 return 0;
}

void Led_voidAnimation(void)
{
	Global_Timer++;
	switch(Global_State)
	{
		case LED_LEFT :
			if(Global_Timer == 2)
			{
				Global_Timer = 0;
				MGPIO_voidSetPinValue(GPIOA,Global_Offset,GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA,(Global_Offset-1),GPIO_LOW);
				Global_Offset++;
				if(Global_Offset > 7){Global_State = LED_RIGHT ;}
			}
			break;

		case LED_RIGHT :
			if(Global_Timer == 2)
			{
				Global_Timer = 0;
				Global_Offset --;
				MGPIO_voidSetPinValue(GPIOA,Global_Offset,GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA,(Global_Offset+1),GPIO_LOW);
				if(Global_Offset == 0){Global_State = LED_LEFT ; Global_Counter++ ;}
				if(Global_Counter == 4){Global_State = LED_IN ; Global_Counter = 0;}
			}
			break;
		case LED_IN :
			if(Global_Timer == 2)
			{
				Global_Timer = 0;
				MGPIO_voidSetPinValue(GPIOA,up,GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA,down,GPIO_HIGH);
				++up ;
				--down ;
				if(up > 7){up = 7;down = 0 ; Global_State = LED_OUT;}
			}
			break;

		case LED_OUT :

			if(Global_Timer == 2)
			{
				Global_Timer = 0;
				MGPIO_voidSetPinValue(GPIOA,up,GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA,down,GPIO_LOW);
				up --;
				down ++;
				if(up < 4){up = 4 ;down = 3; Global_State = LED_IN; Global_Counter++ ;}
				if (Global_Counter == 4){
					Global_State = LED_BLINK ; Global_Counter = 0 ;}
			}
			break;

		case LED_BLINK :
			/* will execute every 500 ms */
			if (Global_Timer == 5){
				Global_Timer = 0 ;
				/* Toggle the 8 pins */
				MGPIO_voidTogglePinValue(GPIOA , 0 );
				MGPIO_voidTogglePinValue(GPIOA , 1 );
				MGPIO_voidTogglePinValue(GPIOA , 2 );
				MGPIO_voidTogglePinValue(GPIOA , 3 );
				MGPIO_voidTogglePinValue(GPIOA , 4 );
				MGPIO_voidTogglePinValue(GPIOA , 5 );
				MGPIO_voidTogglePinValue(GPIOA , 6 );
				MGPIO_voidTogglePinValue(GPIOA , 7 );
				Global_Counter++;
				if(Global_Counter > 8 ){
					//Global_state = LED_LEFT ; Global_counter = 0 ;
					//GPIO_voidWritePins(GPIOA , 0 , PINS_8 , 0X00);
					MSTK_voidStopInterval();
				}
			}
			break;
		default :
			/* Should not be here */
			break ;

	}

}

