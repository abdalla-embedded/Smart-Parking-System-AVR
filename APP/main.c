/*
 * DRIVERS.c
 *
 * Created: 12/04/2026 20:58:08
 * Author : aeab2
 */ 

#include "main.h"

typedef enum
{
	available_MODE,
	FULL_MODE
}SystemMode_t;

extern volatile u16 OV_Count;

void OV_Function(void)
{
	
	OV_Count++;
	
}



int main(void)
{
	u8 available = 4;
	u16 Distance_1;
	u16 Distance_2;
	u8 EntryFlag = 0;
	u8 ExitFlag = 0;
	u8 BuzzerFlag = 0;
	DIO_voidSetPinDir(LED1_PORT,LED1_PIN,OUTPUT);
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN0,OUTPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN5, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN4, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN7,INPUT);
	TIM1_voidFastPWMICR(OC1A);
	_delay_ms(500);
	TIM1_voidFastPWMICR(OC1B);
	GI_voidEnable();
	TIM0_voidInit(OV_MODE);
	TIM0_voidSetCallBack(OV_Function, OV_MODE);
	ULTRASONIC_voidInit(ULTRA1);
	ULTRASONIC_voidInit(ULTRA2);
	LCD_voidInit();
	TIM1_voidSetOCRval(1000, OC1A);
	_delay_ms(500);
	TIM1_voidSetOCRval(1000, OC1B);
	
		SystemMode_t CurrentMode = available_MODE;  
    while (1) 
   {
	  
	  LCD_voidGotoXY(0,0);
	  LCD_voidSendNum(available);
	  
	  switch(CurrentMode){
		  
		  case available_MODE:
		  
		  while(CurrentMode == available_MODE){
			  
			 Distance_1 = ULTRASONIC_voidGetDistance(ULTRA1);

			 _delay_ms(20);

			 Distance_2 = ULTRASONIC_voidGetDistance(ULTRA2);
			  
			  LCD_voidGotoXY(0,0);
			  LCD_voidSendNum(available);
			  LCD_voidGotoXY(0,1);
			  LCD_voidSendString("IN:");
			  LCD_voidGotoXY(3,1);
			  LCD_voidSendNum(Distance_1);
			  LCD_voidGotoXY(9,1);
			  LCD_voidSendString("OUT:");
			  LCD_voidGotoXY(13,1);
			  LCD_voidSendNum(Distance_2);
			  
			  if(available > 0 && Distance_1 <= 10 && EntryFlag == 0){
					
				  EntryFlag = 1;
				  TIM1_voidSetOCRval(5100, OC1A);
				  available--;
				  	
				  _delay_ms(5000);
				  TIM1_voidSetOCRval(1000, OC1A);
				  
			  }
			else if(available < 4 && Distance_2 <= 10 && ExitFlag == 0)
			{
				
				ExitFlag = 1;
				TIM1_voidSetOCRval(5100, OC1B);
				available++;

				_delay_ms(5000);
				TIM1_voidSetOCRval(1000, OC1B);

			}
			
			if(Distance_1 > 10)
			{
				EntryFlag = 0;
			}

			if(Distance_2 > 10)
			{
				ExitFlag = 0;
			}
			
				  if(available == 0){CurrentMode = FULL_MODE;} 
			  
		  }
		  break;
		  
		  case FULL_MODE:
		   
		  LCD_voidSendCommand(1);
		  
		  while(CurrentMode == FULL_MODE){
			   
			    
			  
			  
			  	LED_voidTurnLedon(LED1_PORT,LED1_PIN);
			  	LCD_voidGotoXY(0,0);
			  	
			  	LCD_voidSendString("FULL");
				  
				  if(BuzzerFlag == 0)
				  {
					  DIO_voidSetPinVal(DIO_PORTB,DIO_PIN0,HIGH);
					  _delay_ms(500);
					  DIO_voidSetPinVal(DIO_PORTB,DIO_PIN0,LOW);

					  BuzzerFlag = 1;
				  }
				  
				Distance_2 = ULTRASONIC_voidGetDistance(ULTRA2);
			  	if(available < 4 && Distance_2 <= 10){
					  available++;
					  LCD_voidSendCommand(1); 
					  LED_voidTurnLedoff(LED1_PORT,LED1_PIN);
					  }
				  if(available != 0){BuzzerFlag = 0; CurrentMode = available_MODE;}
	  }
	  break;
  
  }	  
 }
}
	  






