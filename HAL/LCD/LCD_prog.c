/*
 * LCD_prog.c
 *
 * Created: 15/04/2026 19:54:08
 *  Author: aeab2
 */ 


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#define	 F_CPU 16000000
#include <util/delay.h>


void LCD_voidSHData(u8 copy_u8data){
	
	u8 LCD_pins[LCD_PINS] = {LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN};
	u8 Loc_i = 0;
	
	for(Loc_i = 0; Loc_i < LCD_PINS; Loc_i++){
		
		DIO_voidSetPinVal(LCD_DPORT, LCD_pins[Loc_i], GET_BIT(copy_u8data,Loc_i));
		
	}
}


void LCD_voidInit(void){
	
	DIO_voidSetPortDir(LCD_CPORT, 0x07);
	DIO_voidSetPortDir(LCD_DPORT, 0xf0);
	
	/* Function Set*/
	
#if LCD_MODE == LCD_8BIT_MODE

	LCD_voidSendCommand(0x38);
	
	
#elif	LCD_MODE == LCD_4BIT_MODE

	LCD_voidSHData(0b0010);
	LCD_voidSendEnablePulse();
	LCD_voidSHData(0b0010);
	LCD_voidSendEnablePulse();
	LCD_voidSHData(0b1000);
	LCD_voidSendEnablePulse();
	
#endif	
	
	/* display Mode and Cursor*/
	LCD_voidSendCommand(0x0C);
	/*Clr LSD*/
	LCD_voidSendCommand(1);
	//_delay_ms(1.53);
	//LCD_voidSendCommand(0x07);
	
}



void LCD_voidSendCommand(u8 copy_u8command){
	
	/* Clr RS pin To Send Command */
	DIO_voidSetPinVal(LCD_CPORT, LCD_RS_PIN,LOW);
	
	/* Clr RW pin To Write Data */
	DIO_voidSetPinVal(LCD_CPORT, LCD_RW_PIN,LOW);
	
	/* Send Command */
	
#if LCD_MODE == LCD_4BIT_MODE

	LCD_voidSHData(copy_u8command>>4);
	LCD_voidSendEnablePulse();
	LCD_voidSHData(copy_u8command);
	LCD_voidSendEnablePulse();
	
#elif LCD_MODE == LCD_8BIT_MODE

	DIO_voidSetPortVal(LCD_DPORT, copy_u8command);
	LCD_voidSendEnablePulse();	
	
#endif
	
}

void LCD_voidSendData(u8 copy_u8data){
	
	/* Clr RS pin To Send Data */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,HIGH);
	
	/* Clr RW pin To Write Data */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW);
	
	/* Send Data */
	#if LCD_MODE == LCD_4BIT_MODE

	LCD_voidSHData(copy_u8data>>4);
	LCD_voidSendEnablePulse();
	LCD_voidSHData(copy_u8data);
	LCD_voidSendEnablePulse();
	
	#elif LCD_MODE == LCD_8BIT_MODE

	DIO_voidSetPortVal(LCD_DPORT, copy_u8data);
	LCD_voidSendEnablePulse();
	
	#endif
}


void LCD_voidSendString(const char * string){
	
	u8 i = 0;
	
	while(string[i] != nul){
		
		LCD_voidSendData(string[i]);
		i++;
		
	}
}

void LCD_voidSendEnablePulse(void){
	
	DIO_voidSetPinVal(LCD_CPORT, LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinVal(LCD_CPORT, LCD_EN_PIN,LOW);
	
}

void LCD_voidGotoXY(u8 copy_u8x, u8 copy_u8y){
	
	u8 Loc_u8ddramAddress = 0;
	Loc_u8ddramAddress = (copy_u8x + (copy_u8y * 0x40));
	
	/* Set ddram*/
	
	SET_BIT(Loc_u8ddramAddress, 7);
	LCD_voidSendCommand(Loc_u8ddramAddress);
}

void LCD_voidDrawData(u8 * data, u8 pattern, u8 copy_u8x, u8 copy_u8y){
	
	u8 Loc_u8CGRAM_Address = pattern * 8;
	u8 Loc_i = 0;
	
	/* Set CGRAM */
	
	CLR_BIT(Loc_u8CGRAM_Address, 7);
	SET_BIT(Loc_u8CGRAM_Address, 6);
	LCD_voidSendCommand(Loc_u8CGRAM_Address);
	
	/* Set Data */
	
	for(Loc_i = 0; Loc_i < 8; Loc_i++){
		
		LCD_voidSendData(data[Loc_i]);
		
	}
	
	LCD_voidGotoXY(copy_u8x, copy_u8y);
	LCD_voidSendData(pattern);
	
}

void LCD_voidSendNum(u32 copy_u32num){
	
	
	s8 Loc_i = 0;
	u8 num[10];
	
	if(copy_u32num == 0){
		
		LCD_voidSendData('0');
		return ;
	}
	
	for(Loc_i = 0; copy_u32num != 0; Loc_i++){
	num[Loc_i] = copy_u32num % 10 + 48;
	copy_u32num /= 10;
	}
	Loc_i--;
	while(Loc_i >= 0){
		
		LCD_voidSendData(num[Loc_i]);
		Loc_i--;
		
	}
}



