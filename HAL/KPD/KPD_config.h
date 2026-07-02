/*
 * KPD_config.h
 *
 * Created: 29/04/2026 20:55:22
 *  Author: aeab2
 */ 

#include "../../MCAL/DIO/DIO_reg.h"


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/* (Row - Cl) Port's */

#define KPD_PORT_ROW			DIO_PORTA

			
#define KPD_PORT_CL			DIO_PORTD


/* (Row - Col) Pin's */

#define KPD_PIN_ROW1			DIO_PIN1
#define KPD_PIN_ROW2			DIO_PIN2
#define KPD_PIN_ROW3			DIO_PIN3

#define KPD_PIN_CL1				DIO_PIN2
#define KPD_PIN_CL2				DIO_PIN3
#define KPD_PIN_CL3				DIO_PIN7

#endif /* KPD_CONFIG_H_ */