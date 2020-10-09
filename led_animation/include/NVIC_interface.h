/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 30 AUG 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : NVIC-interface.h ***************/
/*********************************************************/



#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void MNVIC_voidEnableInerupt    (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInerupt   (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8   MNVIC_u8GetActiveFlag		(u8 Copy_u8IntNumber);
void MNVIC_voidSetPeriority(s8 Copy_s8IntID , u8 Copy_u8tGroupPriority,u8 Copy_u8SubPriority,u32 Copy_u32Group_Sub);

#define    GROUP3			0x5FA0300 		// 4 Bits For Group  (IPR)=> Group
#define    GROUP4			0x5FA0400		// 3 Bits For Group 1 Bit For Sub
#define    GROUP5			0x5FA0500		// 2 Bits For Group 2 Bit For Sub
#define    GROUP6			0x5FA0600		// 1 Bits For Group 3 Bit For Sub
#define    GROUP7			0x5FA0700		// 0 Group 4 Bit For Sub
                
#endif
