/*
 * ADC_interface.h
 *
 * Created: 01/06/2026 21:20:32
 *  Author: aeab2
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define		ADC0		0
#define		ADC1		1
#define		ADC2		2
#define		ADC3		3
#define		ADC4		4
#define		ADC5		5
#define		ADC6		6
#define		ADC7		7

#define		ADC_2_PRESCALLER		1
#define		ADC_4_PRESCALLER		2
#define		ADC_8_PRESCALLER		3
#define		ADC_16_PRESCALLER		4
#define		ADC_32_PRESCALLER		5
#define		ADC_64_PRESCALLER		6
#define		ADC_128_PRESCALLER		7


#define		ADC_PRESCALLER			ADC_128_PRESCALLER

#define		ADC_POLLING				0
#define		ADC_INT					1

#define		ADC_METHOD				ADC_POLLING


void ADC_voidInit(void);

u16 ADC_u16ReadChannel(u8 copy_u8channel);


#endif /* ADC_INTERFACE_H_ */