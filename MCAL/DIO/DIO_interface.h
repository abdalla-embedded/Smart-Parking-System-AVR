/*
 * DIO_interface.h
 *
 * Created: 12/04/2026 20:59:36
 *  Author: aeab2
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Pin  Functions */

void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8dir);

void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8val);

u8	 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin);

void DIO_voidTogglePinVal(u8 copy_u8port, u8 copy_u8pin);


/* Port Functions */

void DIO_voidSetPortDir(u8 copy_u8port, u8 copy_u8dir);

void DIO_voidSetPortVal(u8 copy_u8port, u8 copy_u8val);

#endif /* DIO_INTERFACE_H_ */