/*
 * main.h
 *
 * Created: 12/04/2026 23:12:55
 *  Author: aeab2
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define	 F_CPU 16000000
#include <util/delay.h>

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPE.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_reg.h"

#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_reg.h"

#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/SSD/SSD_config.h"

#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interface.h"

#include "../HAL/KPD/KPD_config.h"
#include "../HAL/KPD/KPD_interface.h"

#include "../MCAL/GI/GI_reg.h"
#include "../MCAL/GI/GI_interface.h"

#include "../MCAL/EXTI/EXTI_reg.h"
#include "../MCAL/EXTI/EXTI_interface.h"

#include "../MCAL/ADC/ADC_reg.h"
#include "../MCAL/ADC/ADC_interface.h"

#include "../MCAL/TIM0/TIM0_reg.h"
#include "../MCAL/TIM0/TIM0_interface.h"

#include "../HAL/DCMOTOR/DCMOTOR_config.h"
#include "../HAL/DCMOTOR/DCMOTOR_interface.h"

#include "../MCAL/TIM1/TIM1_reg.h"
#include "../MCAL/TIM1/TIM1_interface.h"

#include "../HAL/ULTRASONIC/ULTRASONIC_config.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_interface.h"

#endif /* MAIN_H_ */