/*
 * TIM1_interface.h
 *
 * Created: 28/06/2026 15:49:21
 *  Author: aeab2
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

/* TIMER 1 PWM PINS*/

#define		OC1A	0
#define		OC1B	1

/*PRESCALLER MODE'S*/

#define		TIM1_NO_PRESCALLER		1
#define		TIM1_8_PRESCALLER		2
#define		TIM1_64_PRESCALLER		3
#define		TIM1_256_PRESCALLER		4
#define		TIM1_1024_PRESCALLER	5

/*PRESCALLER MODE SELECT*/

#define		TIM1_PRESCALLER			TIM1_8_PRESCALLER

void TIM1_voidFastPWMICR(u8 copy_u8pin);

void TIM1_voidSetOCRval(u16 copy_u16val, u8 copy_u8pin);

/*ICR PIN SENCE*/

#define RISING		0
#define FALLING		1

void TIM1_voidInitICR(u8 copy_u8sence);

void TIM1_voidRestICR(void);

u16  TIM1_u16ReadICR(void);

void TIM1_voidICR_SetCallBack(void (*ptr)(void));

#endif /* TIM1_INTERFACE_H_ */