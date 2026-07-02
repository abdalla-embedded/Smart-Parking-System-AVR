/*
 * InterruptVectorNum.h
 *
 * Created: 15/06/2026 20:41:18
 *  Author: aeab2
 */ 


#ifndef INTERRUPTVECTORNUM_H_
#define INTERRUPTVECTORNUM_H_

#define ISR(__vector_NUM)				void __vector_NUM(void)__attribute__((signal));\
										void __vector_NUM(void)

#define		INT0			__vector_1
#define		INT1			__vector_2
#define		INT2			__vector_3
#define		TIMER2_COMP		__vector_4
#define		TIMER2_OVF		__vector_5
#define		TIMER1_CAPT		__vector_6
#define		TIMER1_COMPA	__vector_7
#define		TIMER1_COMPB	__vector_8
#define		TIMER1_OVF		__vector_9
#define		TIMER0_COMP		__vector_10
#define		TIMER0_OV		__vector_11



#endif /* INTERRUPTVECTORNUM_H_ */