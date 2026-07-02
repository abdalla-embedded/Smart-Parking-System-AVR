/*
 * DCMOTOR_prog.c
 *
 * Created: 23/06/2026 17:23:25
 *  Author: aeab2
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "DCMOTOR_config.h"
#include "DCMOTOR_interface.h"
#include "../../MCAL/TIM0/TIM0_interface.h"

void DCMOTOR_voidInit(void){
	
	DIO_voidSetPinDir(DCMOTOR_EN1_PORT, DCMOTOR_EN1_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_EN2_PORT, DCMOTOR_EN2_PIN, OUTPUT);
	
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A1_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A2_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A3_PIN, OUTPUT);
	DIO_voidSetPinDir(DCMOTOR_PORT, DCMOTOR_A4_PIN, OUTPUT);
	
}

void DCMOTOR_voidForward(u8 copy_u8speed){
	
	TIM0_voidFastPWM(copy_u8speed);
	
	/*MOTOR 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	/*MOTOR 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
	
}

void DCMOTOR_voidReverse(u8 copy_u8speed){
	
	TIM0_voidFastPWM(copy_u8speed);
	
	/*MOTOR 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, HIGH);
	/*MOTOR 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, HIGH);
	
}

void DCMOTOR_voidRight(u8 copy_u8speed){
	
	TIM0_voidFastPWM(copy_u8speed);
	
	/*MOTOR 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	/*MOTOR 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
	
}
void DCMOTOR_voidLeft(u8 copy_u8speed){
	
	TIM0_voidFastPWM(copy_u8speed);
	
	/*MOTOR 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	/*MOTOR 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, HIGH);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
	
}

void DCMOTOR_voidStop(u8 copy_u8speed){
	
	TIM0_voidFastPWM(copy_u8speed);
	
	/*MOTOR 1*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A1_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A2_PIN, LOW);
	/*MOTOR 2*/
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A3_PIN, LOW);
	DIO_voidSetPinVal(DCMOTOR_PORT, DCMOTOR_A4_PIN, LOW);
	
}