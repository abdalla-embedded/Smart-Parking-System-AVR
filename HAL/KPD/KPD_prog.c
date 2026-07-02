/*
 * KPD_prog.c
 *
 * Created: 29/04/2026 20:55:43
 *  Author: aeab2
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"

u8 KPD[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

/* KPD Init */

void KPD_voidInit(void){
	
	DIO_voidSetPinDir(KPD_PORT_ROW,KPD_PIN_ROW1,INPUT);
	DIO_voidSetPinDir(KPD_PORT_ROW,KPD_PIN_ROW2,INPUT);
	DIO_voidSetPinDir(KPD_PORT_ROW,KPD_PIN_ROW3,INPUT);

	DIO_voidSetPinVal(KPD_PORT_ROW,KPD_PIN_ROW1,HIGH);
	DIO_voidSetPinVal(KPD_PORT_ROW,KPD_PIN_ROW2,HIGH);
	DIO_voidSetPinVal(KPD_PORT_ROW,KPD_PIN_ROW3,HIGH);
	
	DIO_voidSetPinDir(KPD_PORT_CL,KPD_PIN_CL1,OUTPUT);
	DIO_voidSetPinDir(KPD_PORT_CL,KPD_PIN_CL2,OUTPUT);
	DIO_voidSetPinDir(KPD_PORT_CL,KPD_PIN_CL3,OUTPUT);

	DIO_voidSetPinVal(KPD_PORT_CL,KPD_PIN_CL1,HIGH);
	DIO_voidSetPinVal(KPD_PORT_CL,KPD_PIN_CL2,HIGH);
	DIO_voidSetPinVal(KPD_PORT_CL,KPD_PIN_CL3,HIGH);
}

/* KPD Get Key */

u8 KPD_u8GetKey(void){
	
	u8 ROW_arr[3] = {KPD_PIN_ROW1,KPD_PIN_ROW2,KPD_PIN_ROW3};
	u8 CL_arr[3] = {KPD_PIN_CL1,KPD_PIN_CL2,KPD_PIN_CL3};
		
	u8 col = 0 , row = 0;
	u8 val = 0xff;
	
	for(col = 0; col < 3; col++){
		
		DIO_voidSetPinVal(KPD_PORT_CL,CL_arr[col],LOW);
		
		for(row = 0; row < 3; row++){
			
			if(DIO_u8ReadPinVal(KPD_PORT_ROW,ROW_arr[row]) == 0){
				val = KPD[row][col];
				while(DIO_u8ReadPinVal(KPD_PORT_ROW,ROW_arr[row]) == 0);
				 //DIO_voidSetPinVal(KPD_PORT_CL, CL_arr[col], HIGH);
				return val;
			}
		  }
			DIO_voidSetPinVal(KPD_PORT_CL,CL_arr[col], HIGH);
		}
		return val;
	}		
	


