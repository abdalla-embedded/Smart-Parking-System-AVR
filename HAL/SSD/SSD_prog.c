/*
 * SSD_prog.c
 *
 * Created: 13/04/2026 19:20:43
 *  Author: aeab2
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_config.h"


void SSD_voidDesplayNum(u8 copy_u8num){
	
	u8 ssd[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
		
		DIO_voidSetPortDir(SSD_PORT,0xff);
		DIO_voidSetPortVal(SSD_PORT,ssd[copy_u8num]);	
}

void SSD_voidDesplayNumBcdCode(u8 copy_u8num){
	
	DIO_voidSetPortDir(SSD_PORT, 0x0f);
	DIO_voidSetPortVal(SSD_PORT, copy_u8num);
}
