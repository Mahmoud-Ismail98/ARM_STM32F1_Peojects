/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 26 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : STP_program.c   ****************/
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter; //this var from type s8 not u8 because next iteration in case u8 when Local_s8Counter reach 0 will be 255  
	u8 Local_u8Bit;
	for (Local_s8Counter = 7; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit strating from MSb bit7 First*/
		Local_u8Bit =  GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		
		/* Send Pulse to Shift Clock */
		/*AS OE pin connected to Low Always Enable so Any date transfer to storge register immeditely showing on pyhsical pins */
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_HIGH);
		MSTK_voidSetBusyWait(1); //1 micro
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_LOW);
		MSTK_voidSetBusyWait(1);
	}
	
		/* Send Pulse to Store Clock */
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	
}
