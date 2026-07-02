/*
 * LCD_config.h
 *
 * Created: 15/04/2026 19:53:42
 *  Author: aeab2
 */ 

#include "../../MCAL/DIO/DIO_reg.h"


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



/* LCD Control (Port - Pin's) */

#define LCD_CPORT			DIO_PORTB

#define LCD_RS_PIN			DIO_PIN1
#define LCD_RW_PIN			DIO_PIN0
#define LCD_EN_PIN			DIO_PIN2



/* LCD Data Pin's*/

#if LCD_MODE == LCD_8BIT_MODE

	#define  LCD_DPORT			DIO_PORTA
	
#elif LCD_MODE == LCD_4BIT_MODE

	#define LCD_DPORT			DIO_PORTA
	#define LCD_D4_PIN			DIO_PIN4
	#define LCD_D5_PIN			DIO_PIN5
	#define LCD_D6_PIN			DIO_PIN6
	#define LCD_D7_PIN			DIO_PIN7
	
#endif

#define LCD_PINS				4

#endif /* LCD_CONFIG_H_ */