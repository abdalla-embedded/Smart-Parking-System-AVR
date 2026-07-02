/*
 * GI_prog.c
 *
 * Created: 11/05/2026 22:28:28
 *  Author: aeab2
 */ 

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "GI_reg.h"

void GI_voidEnable(){
	
	SET_BIT(SREG_REG, 7);
	
}

void GI_voidDisable(){
	
	CLR_BIT(SREG_REG, 7);
	
}

