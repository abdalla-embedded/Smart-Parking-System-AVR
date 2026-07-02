/*
 * TIMER_interface.h
 *
 * Created: 08/06/2026 22:37:51
 *  Author: aeab2
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*PRESCALLER MODE'S*/

#define		TIM0_NO_PRESCALLER		1
#define		TIM0_8_PRESCALLER		2
#define		TIM0_64_PRESCALLER		3
#define		TIM0_256_PRESCALLER		4
#define		TIM0_1024_PRESCALLER	5

/*PRESCALLER MODE SELECT*/

#define		TIM0_PRESCALLER			TIM0_8_PRESCALLER

/*TIM MODE*/

#define OV_MODE		0
#define CTC_MODE	1

#define CTC_VAL		125

void TIM0_voidInit(u8 copy_u8mode);

void TIM0_voidSetCallBack(void(*ptr)(void), u8 copy_u8mode);

void TIM0_voidFastPWM(u8 copy_u8duty);

#endif /* TIMER_INTERFACE_H_ */