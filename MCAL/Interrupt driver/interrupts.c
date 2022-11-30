/*
 * interrupts.c
 *
 * Created: 11/19/2022 6:29:31 PM
 *  Author: carlo
 */ 
#include "../../Utilities/registers.h"
#include "../../Utilities/BITMATH.h"
#include "../../ECUAL/BUTTON DRIVER/button.h"
#include "../../ECUAL/LED DRIVER/LED.h"
#include "../Timer Driver/Timer.h"
#include "interrupts.h"
Uint8 Button = 0;
void Test_Interrupt(void)

{
	BUTTON_INIT(button_port, button_pin);
	LED_INIT(LED_PEDESTRIANS, LED_GREEN);
	sei();
	RISING_EDGE();
	SETUP_INT0();
	BUTTON_READ(button_port,button_pin,&Button);
	if (Button==HIGH)
	{
		LED_OFF(LED_PEDESTRIANS,LED_GREEN);
	}
	else if (Button==LOW)
	{
		LED_ON(LED_PEDESTRIANS,LED_GREEN);
	}
}