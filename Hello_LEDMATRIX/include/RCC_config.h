/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 14 AUG 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : RCC-config.h    ****************/
/*********************************************************/
#ifndef   RCC_CONFIG_H
#define   RCC_CONFIG_H

/* Options:   	RCC_HSE_CRYSTAL 	
				RCC_HSE_RC
				RCC_HSI
				RCC_PLL				*/
#define		RCC_CLOCK_TYPE		RCC_HSE_CRYSTAL		

/* Options:		RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE		*/
/* Note:Select Only If Pll Is Selected As Input Clock Source */
#if			RCC_CLOCK_TYPE==RCC_PLL				
#define		RCC_PLL_INPUT		RCC_PLL_IN_HSE_DIV_2				
#endif

/* Options:PLL Multiblication Factor from 2:16*/
/* Note:Select Only If Pll Is Selected As Input Clock Source */
#if			RCC_CLOCK_TYPE==RCC_PLL				
#define		RCC_PLL_MUL_VAL		4				
#endif

#endif     