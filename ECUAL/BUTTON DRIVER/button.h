/*
 * button.h
 *
 * Created: 11/7/2022 10:02:40 PM
 *  Author: carlo
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO DRIVER/DIO.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/STD.h"
#include "../LED DRIVER/LED.h"
#include <stdbool.h>
#define button_port PORT_D
#define button_pin PIN2

#define BUTTON_LOW 0
#define BUTTON_HIGH 1
void BUTTON_INIT(Uint8 BUTTONPORT,Uint8 BUTTONPIN);
void BUTTON_READ(Uint8 BUTTONPORT,Uint8 BUTTONPIN, Uint8 *VALUE);
void BUTTON_TEST(void);
bool buttonst();


#endif /* BUTTON_H_ */