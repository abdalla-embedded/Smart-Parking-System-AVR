/*
 * DIO_reg.h
 *
 * Created: 12/04/2026 20:59:53
 *  Author: aeab2
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_

/* Pin Dir*/

#define OUTPUT			1
#define INPUT			0

/* Pin Val*/

#define HIGH			1
#define LOW				0

/* DIO Ports*/

#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

/*DIO Pins*/

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7


/* Group A*/

#define	PORTA_REG				*((volatile u8*) 0x3B)
#define	DDRA_REG				*((volatile u8*) 0x3A)
#define	PINA_REG				*((volatile u8*) 0x39)

/* Group B*/

#define	PORTB_REG				*((volatile u8*) 0x38)
#define	DDRB_REG				*((volatile u8*) 0x37)
#define	PINB_REG				*((volatile u8*) 0x36)

/* Group C*/

#define	PORTC_REG				*((volatile u8*) 0x35)
#define	DDRC_REG				*((volatile u8*) 0x34)
#define	PINC_REG				*((volatile u8*) 0x33)

/* Group D*/

#define	PORTD_REG				*((volatile u8*) 0x32)
#define	DDRD_REG				*((volatile u8*) 0x31)
#define	PIND_REG				*((volatile u8*) 0x30)



#endif /* DIO_REG_H_ */