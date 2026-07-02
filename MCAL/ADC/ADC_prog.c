/*
 * ADC_prog.c
 *
 * Created: 01/06/2026 21:20:48
 *  Author: aeab2
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "ADC_interface.h"
#include "ADC_reg.h"
#define	 F_CPU 16000000
#include <util/delay.h>

void ADC_voidInit(void){
	
	/* Reference Selection : AVCC with external capacitor at AREF pin*/
	
	CLR_BIT(ADMUX_REG, 7);
	SET_BIT(ADMUX_REG, 6);
	
	/* Prescaller Selection*/
	
	ADCSRA_REG &= 0b11111000;
	ADCSRA_REG |= ADC_PRESCALLER;
	
	/*ADC Enable*/
	
	SET_BIT(ADCSRA_REG, 7);
	
}

u16 ADC_u16ReadChannel(u8 copy_u8channel){
	
	/* Select ADC Channel*/
	
	ADMUX_REG &= 0b11100000;
	ADMUX_REG |= copy_u8channel;
	
	/* Start ADC Conversion*/
	
	SET_BIT(ADCSRA_REG, 6);
	
	while(GET_BIT(ADCSRA_REG, 4) == 0);
	SET_BIT(ADCSRA_REG, 4);
	return ADC_REG;
	
}