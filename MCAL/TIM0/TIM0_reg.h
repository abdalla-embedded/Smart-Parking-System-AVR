/*
 * TIMER_reg.h
 *
 * Created: 08/06/2026 22:37:37
 *  Author: aeab2
 */ 


#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TCNT0_REG			*((volatile u8*)0x52)
#define TCCR0_REG			*((volatile u8*)0x53)
#define TIFR_REG			*((volatile u8*)0x58) //INTERRUPT FLAG
#define TIMSK_REG			*((volatile u8*)0x59) //Interrupt Mask Register
#define OCR0_REG			*((volatile u8*)0x5C)




#endif /* TIMER_REG_H_ */