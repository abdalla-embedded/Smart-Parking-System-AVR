/*
 * DCMOTOR_interface.h
 *
 * Created: 23/06/2026 17:22:52
 *  Author: aeab2
 */ 


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

void DCMOTOR_voidInit(void);

void DCMOTOR_voidForward(u8 copy_u8speed);
void DCMOTOR_voidReverse(u8 copy_u8speed);
void DCMOTOR_voidRight(u8 copy_u8speed);
void DCMOTOR_voidLeft(u8 copy_u8speed);
void DCMOTOR_voidStop(u8 copy_u8speed);




#endif /* DCMOTOR_INTERFACE_H_ */