/*
 * TIMER_prog.c
 *
 * Created: 08/06/2026 22:38:14
 *  Author: aeab2
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/InterruptVectorNum.h"
#include "TIM0_interface.h"
#include "TIM0_reg.h"

void (*OV_PTR)(void) = null;
void (*CTC_PTR)(void) = null;

void TIM0_voidInit(u8 copy_u8mode){
	
	/* Selected Mode Init*/
	
	switch(copy_u8mode){
		
		case 0: CLR_BIT(TCCR0_REG, 3); CLR_BIT(TCCR0_REG, 6); SET_BIT(TIMSK_REG, 0); break;
		
		case 1: OCR0_REG = CTC_VAL; SET_BIT(TCCR0_REG, 3); CLR_BIT(TCCR0_REG, 6); SET_BIT(TIMSK_REG, 1); break;
	}
	
	
	/* Set Prescaller*/
	
	TCCR0_REG &= 0b11111000;
	TCCR0_REG |= TIM0_PRESCALLER;
	
	
	
}

void TIM0_voidSetCallBack(void(*ptr)(void), u8 copy_u8mode){
	
	switch(copy_u8mode){
		
	case 0: OV_PTR = ptr; break;
	case 1: CTC_PTR = ptr; break;
	}
}

void TIM0_voidFastPWM(u8 copy_u8duty){
	
	SET_BIT(TCCR0_REG, 3);
	SET_BIT(TCCR0_REG, 6);
	SET_BIT(TCCR0_REG, 5);
	CLR_BIT(TCCR0_REG, 4);
	
	TCCR0_REG &= 0b11111000;
	TCCR0_REG |= TIM0_PRESCALLER;
	
	OCR0_REG = copy_u8duty * 2.55;
}

ISR(TIMER0_OV){
	
	OV_PTR();
	
}

ISR(TIMER0_COMP){
	
	CTC_PTR();
	
}
