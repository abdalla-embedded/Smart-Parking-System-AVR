/*
 * EXTI_prog.c
 *
 * Created: 13/05/2026 20:39:58
 *  Author: aeab2
 */ 
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"

void (*EXTI0_PTR)(void) = null;
void (*EXTI1_PTR)(void) = null;
void (*EXTI2_PTR)(void) = null;


void EXTI_voidInit(u8 copy_u8num, u8 copy_u8sense){
	
	switch(copy_u8num)
	{
		case INT_0: 
							if(copy_u8sense == LOW_LEVEL)
							{
								CLR_BIT(MCUCR_REG, 0);
								CLR_BIT(MCUCR_REG, 1);
							}
							else if(copy_u8sense == ANY_LOGICAL_CHANGE)
							{
								SET_BIT(MCUCR_REG, 0);
								CLR_BIT(MCUCR_REG, 1);
							}	
							else if(copy_u8sense == RISING_EDGE)
							{
								CLR_BIT(MCUCR_REG, 0);
								SET_BIT(MCUCR_REG, 1);
							}			
							else if(copy_u8sense == FALLING_EDGE)
							{
								SET_BIT(MCUCR_REG, 0);
								SET_BIT(MCUCR_REG, 1);
							}
							
		case INT_1:
							if(copy_u8sense == LOW_LEVEL)
							{
								CLR_BIT(MCUCR_REG, 2);
								CLR_BIT(MCUCR_REG, 3);
							}
							else if(copy_u8sense == ANY_LOGICAL_CHANGE)
							{
								SET_BIT(MCUCR_REG, 2);
								CLR_BIT(MCUCR_REG, 3);
							}
							else if(copy_u8sense == RISING_EDGE)
							{
								CLR_BIT(MCUCR_REG, 2);
								SET_BIT(MCUCR_REG, 3);
							}
							else if(copy_u8sense == FALLING_EDGE)
							{
								SET_BIT(MCUCSR_REG, 2);
								SET_BIT(MCUCR_REG, 3);
							}	
							
		case INT_2:
							if(copy_u8sense == RISING_EDGE)
							{
								SET_BIT(MCUCSR_REG, 6);
							}
							else if(copy_u8sense == FALLING_EDGE)
							{
								CLR_BIT(MCUCSR_REG, 6);
							}		
	}
}

void EXTI0_voidEnable(void)
{
	SET_BIT(GICR_REG, 6);
}
void EXTI0_voidDisable(void)
{
	CLR_BIT(GICR_REG, 6);	
}

void EXTI1_voidEnable(void)
{
	SET_BIT(GICR_REG, 7);
}
void EXTI1_voidDisable(void)
{
	CLR_BIT(GICR_REG, 7);
}

void EXTI2_voidEnable(void)
{
	SET_BIT(GICR_REG, 5);
}
void EXTI2_voidDisable(void)
{
	CLR_BIT(GICR_REG, 5);
}


void EXTI_voidSetCallBack(void(*ptr)(void), u8 copy_u8num){
	
	switch (copy_u8num){
		
		case 0 : EXTI0_PTR = ptr; break;
		case 1 : EXTI1_PTR = ptr; break;
		case 2 : EXTI2_PTR = ptr; break;
		
	}
	
}

void __vector_1(void)__attribute__((signal));
void __vector_1(void){
	
	EXTI0_PTR();
	
}

void __vector_2(void)__attribute__((signal));
void __vector_2(void){
	
	EXTI1_PTR();
	
}

void __vector_3(void)__attribute__((signal));
void __vector_3(void){
	
	EXTI2_PTR();
	
}

