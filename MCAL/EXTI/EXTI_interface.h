/*
 * EXTI_interface.h
 *
 * Created: 13/05/2026 20:40:37
 *  Author: aeab2
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*External Interrupt Pins*/

#define INT_0		0
#define INT_1		1
#define INT_2		2

/*EXTI Sense Mode's*/

#define LOW_LEVEL				0
#define ANY_LOGICAL_CHANGE		1
#define RISING_EDGE				2
#define FALLING_EDGE			3


void EXTI_voidInit(u8 copy_u8num, u8 copy_u8sense);

void EXTI0_voidEnable(void);
void EXTI0_voidDisable(void);

void EXTI1_voidEnable(void);
void EXTI1_voidDisable(void);

void EXTI2_voidEnable(void);
void EXTI2_voidDisable(void);

void EXTI_voidSetCallBack(void(*ptr)(void), u8 copy_u8num);

#endif /* EXTI_INTERFACE_H_ */