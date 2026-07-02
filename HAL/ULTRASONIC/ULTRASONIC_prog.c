/*
 * ULTRASONIC_prog.c
 *
 * Created: 29/06/2026 18:21:57
 *  Author: aeab2
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/TIM0/TIM0_reg.h"
#define	 F_CPU 16000000
#include <util/delay.h>

volatile u16 OV_Count = 0;

void ULTRASONIC_voidInit(u8 copy_u8num){
	
	switch(copy_u8num){
		
		case ULTRA1: 
		
	DIO_voidSetPinDir(ULTRA_PORT, ULTRA1_TRIG_PIN, OUTPUT);
	
	DIO_voidSetPinDir(ULTRA_PORT, ULTRA1_ECHO_PIN, INPUT);
	break;
		case ULTRA2:
		DIO_voidSetPinDir(ULTRA_PORT, ULTRA2_TRIG_PIN, OUTPUT);
		
		DIO_voidSetPinDir(ULTRA_PORT, ULTRA2_ECHO_PIN, INPUT);
	break;
	
	}
}

u16 ULTRASONIC_voidGetDistance(u8 copy_u8num){
	
	
		u32 Time_1=0;

		u16 Distance_1=0;
		
		u32 Time_2=0;

		u16 Distance_2=0;

       switch(copy_u8num){
		   
		   case ULTRA1:

		/* Trigger */

		DIO_voidSetPinVal(ULTRA_PORT,ULTRA1_TRIG_PIN,HIGH);

		_delay_us(10);

		DIO_voidSetPinVal(ULTRA_PORT,ULTRA1_TRIG_PIN,LOW);


		/* Wait Echo Start */

		while(DIO_u8ReadPinVal(ULTRA_PORT,ULTRA1_ECHO_PIN)==LOW);


		/* Reset Counter */

		OV_Count=0;

		TCNT0_REG=0;


		/* Measure */

		while(DIO_u8ReadPinVal(ULTRA_PORT,ULTRA1_ECHO_PIN)==HIGH);


		/* Read Time */

		Time_1=(OV_Count*256)+TCNT0_REG;


		/* Convert */

		Distance_1=Time_1/116;


		return Distance_1;
		break;
		
		case ULTRA2: 
		
		/* Trigger */

		DIO_voidSetPinVal(ULTRA_PORT,ULTRA2_TRIG_PIN,HIGH);

		_delay_us(10);

		DIO_voidSetPinVal(ULTRA_PORT,ULTRA2_TRIG_PIN,LOW);


		/* Wait Echo Start */

		while(DIO_u8ReadPinVal(ULTRA_PORT,ULTRA2_ECHO_PIN)==LOW);


		/* Reset Counter */

		OV_Count=0;

		TCNT0_REG=0;


		/* Measure */

		while(DIO_u8ReadPinVal(ULTRA_PORT,ULTRA2_ECHO_PIN)==HIGH);


		/* Read Time */

		Time_2=(OV_Count*256)+TCNT0_REG;


		/* Convert */

		Distance_2=(Time_2 + 58) / 116; // FOR PROTOUSE


		return Distance_2;
		break;
		
		default:
		return 0;
	}
}
	
