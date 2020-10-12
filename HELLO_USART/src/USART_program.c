
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	/*	baud rate = 9600		*/
	USART1 -> BRR = 0x341;
	/*Enable Rx */
	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	/*Enable Tx */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	/*Enable USART1 */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */

	/* Clear Status Register */
	USART1 -> SR = 0;				
}

void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0'){
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
	/* or 	while((USART1 -> SR & 0x40) == 0);  */
		i++;
	}
	
}

u8 MUSART1_u8Receive(void)
{
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	/* or 	while((USART1 -> SR & (1<<5)) == 0);  */
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);
}




















