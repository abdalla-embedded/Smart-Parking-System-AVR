/*
 * LED_interface.h
 *
 * Created: 13/04/2026 15:48:57
 *  Author: aeab2
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* Turn (ON - OFF) */

void LED_voidTurnLedon(u8 copy_u8ledport, u8 copy_u8ledpin);
void LED_voidTurnLedoff(u8 copy_u8ledport, u8 copy_u8ledpin);

/* Toggle Led */

void LED_voidtoggleled(u8 copy_u8ledport, u8 copy_u8ledpin);


/* Turn (ON - OFF) With Delay */

void LED_voidTurnLedonwithdelay(u8 copy_u8ledport, u8 copy_u8ledpin);
void LED_voidTurnLedoffwithdelay(u8 copy_u8ledport, u8 copy_u8ledpin);


#endif /* LED_INTERFACE_H_ */