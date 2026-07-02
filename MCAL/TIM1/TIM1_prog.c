/*
 * TIM1_prog.c
 *
 * Created: 28/06/2026 15:49:37
 *  Author: aeab2
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/InterruptVectorNum.h"
#include "TIM1_reg.h"
#include "TIM1_interface.h"

void (*ICR_PTR)(void) = null;

void TIM1_voidFastPWMICR(u8 copy_u8pin){
	
	/*SET FAST PWM ICR MODE*/
	
	CLR_BIT(TCCR1A_REG, 0); 
	SET_BIT(TCCR1A_REG, 1);
	
	SET_BIT(TCCR1B_REG, 3);
	SET_BIT(TCCR1B_REG, 4);
	
	/* SET PRESCALLER */
	
	TCCR1B_REG &= 0b11111000;
	TCCR1B_REG |= TIM1_PRESCALLER;
	
	switch(copy_u8pin){
		
		case OC1A: SET_BIT(TCCR1A_REG, 7);
				   CLR_BIT(TCCR1A_REG, 6); break;
		case OC1B: CLR_BIT(TCCR1A_REG, 4);
				   SET_BIT(TCCR1A_REG, 5); break;
	}
	
	/*SET TOP VAL*/
	
	ICR1_REG = 40000;
	
}

void TIM1_voidSetOCRval(u16 copy_u16val, u8 copy_u8pin){
	
	switch(copy_u8pin){
		
		case OC1A: OCR1A_REG = copy_u16val; break;
		case OC1B: OCR1B_REG = copy_u16val; break;
		
	}
	
}

	/*INPUT CAPTURE UNIT*/
void TIM1_voidInitICR(u8 copy_u8sence){
	
		/* SET PRESCALLER */
		
		TCCR1B_REG &= 0b11111000;
		TCCR1B_REG |= TIM1_PRESCALLER;
		
		/* ENABLE ICR*/
		SET_BIT(TCCR1B_REG, 6);
		
	switch(copy_u8sence){
		
		case RISING: SET_BIT(TCCR1B_REG, 6); break;
		case FALLING: CLR_BIT(TCCR1B_REG, 6); break;
		
	}
	
		/*INTERRUPT ENABLE*/
		SET_BIT(TIMSK_REG, 5);
		
		
}

void TIM1_voidRestICR(void){
	
	ICR1_REG = 0x0000;
	
}

u16  TIM1_u16ReadICR(void){
	
	return ICR1_REG;
	
}


void TIM1_voidICR_SetCallBack(void (*ptr)(void)){
	
	ICR_PTR = ptr;
	
}

ISR(TIMER1_CAPT){
	
	ICR_PTR();
	
}