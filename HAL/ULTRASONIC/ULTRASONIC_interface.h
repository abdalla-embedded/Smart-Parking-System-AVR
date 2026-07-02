/*
 * ULTRASONIC_interface.h
 *
 * Created: 29/06/2026 18:21:41
 *  Author: aeab2
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#define ULTRA1			0
#define ULTRA2			1


void ULTRASONIC_voidInit(u8 copy_u8num);

u16 ULTRASONIC_voidGetDistance(u8 copy_u8num);


#endif /* ULTRASONIC_INTERFACE_H_ */