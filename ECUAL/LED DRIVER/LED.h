/*
 * LED.h
 *
 * Created: 11/7/2022 10:54:07 AM
 *  Author: carlo
 */ 
#include "../../Utilities/STD.h"
#include "../../MCAL/DIO DRIVER/DIO.h"
#include "../../MCAL/Timer Driver/Timer.h"

#ifndef LED_H_
#define LED_H_
#define LED_GREEN PIN0			// Green Led
#define LED_YELLOW PIN1			// Yellow Led
#define LED_RED PIN2			// Red Led

#define LED_NORMAL PORT_A			// Led For Cars
#define LED_PEDESTRIANS PORT_B	// Led For Pedestrians

void LED_INIT(Uint8 LEDPORT,Uint8 LEDPIN);
void LED_ON(Uint8 LEDPORT,Uint8 LEDPIN);
void LED_OFF(Uint8 LEDPORT,Uint8 LEDPIN);
void LED_TOGGLE(Uint8 LEDPORT,Uint8 LEDPIN);
void LED_TEST(void);


#endif /* LED_H_ */