/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 30 AUG 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : NVIC-interface.h ***************/
/*********************************************************/

#ifndef  EXTI_CONFIG_H
#define  EXTI_CONFIG_H


/*
EXTI_LINE0
EXTI_LINE1
EXTI_LINE2
EXTI_LINE3
.
.
.
.
EXTI_LINE15
*/

#define  EXTI_LINE    EXTI_LINE0   /* 0:15 */

/*
FALLING_EDGE
RISING_EDGE
ON_CHANGE
*/
#define	 EXTI_SENSE_MODE    FALLING_EDGE

#endif
