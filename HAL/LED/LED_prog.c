/*
 * LED_prog.c
 *
 * Created: 13/04/2026 15:49:21
 *  Author: aeab2
 */ 

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "LED_interface.h"
#include "LED_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_reg.h"
#define	 F_CPU 16000000
#include <util/delay.h>

void LED_voidTurnLedon(u8 copy_u8ledport, u8 copy_u8ledpin){
	
	DIO_voidSetPinDir(copy_u8ledport, copy_u8ledpin, OUTPUT);
	DIO_voidSetPinVal(copy_u8ledport, copy_u8ledpin, HIGH);
	
}

void LED_voidTurnLedoff(u8 copy_u8ledport, u8 copy_u8ledpin){
	
	DIO_voidSetPinDir(copy_u8ledport, copy_u8ledpin, OUTPUT);
	DIO_voidSetPinVal(copy_u8ledport, copy_u8ledpin, LOW);
	
}

void LED_voidtoggleled(u8 copy_u8ledport, u8 copy_u8ledpin){
	
	DIO_voidSetPinDir(copy_u8ledport, copy_u8ledpin, OUTPUT);
	DIO_voidTogglePinVal(copy_u8ledport, copy_u8ledpin);
	
}

void LED_voidTurnLedonwithdelay(u8 copy_u8ledport, u8 copy_u8ledpin){
	
	DIO_voidSetPinDir(copy_u8ledport, copy_u8ledpin, OUTPUT);
	DIO_voidSetPinVal(copy_u8ledport, copy_u8ledpin, HIGH);
	_delay_ms(2000);
	DIO_voidSetPinVal(copy_u8ledport, copy_u8ledpin, LOW);
	
}

void LED_voidTurnLedoffwithdelay(u8 copy_u8ledport, u8 copy_u8ledpin){
	
	DIO_voidSetPinDir(copy_u8ledport, copy_u8ledpin, OUTPUT);
	DIO_voidSetPinVal(copy_u8ledport, copy_u8ledpin, LOW);
	_delay_ms(2000);
	DIO_voidSetPinVal(copy_u8ledport, copy_u8ledpin, HIGH);
	
}
