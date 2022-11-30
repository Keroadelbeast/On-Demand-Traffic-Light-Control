/*
* APP.c
*
* Created: 11/10/2022 7:00:36 PM
*  Author: carlo
*/
#include "APP.h"
#include "../ECUAL/BUTTON DRIVER/button.h"
#include "../ECUAL/LED DRIVER/LED.h"
#include "../MCAL/DIO DRIVER/DIO.h"
#include "../MCAL/Timer Driver/Timer.h"
#include "../MCAL/Interrupt driver/interrupts.h"
#include "avr/interrupt.h"
#include <stdbool.h>

Uint8 normal_mode=1; //1 for normal 0 for ped
Uint8 led_no; //0 for green 1 for yellow 2 for red


//Uint8 mode=LOW;//low for normal high for pedestarian


void app_init(void){

	
	LED_INIT(LED_NORMAL,LED_GREEN);
	LED_INIT(LED_NORMAL,LED_YELLOW);
	LED_INIT(LED_NORMAL,LED_RED);
	//PEDESTERIAN MODE INIT
	LED_INIT(LED_PEDESTRIANS,LED_GREEN);
	LED_INIT(LED_PEDESTRIANS,LED_YELLOW);
	LED_INIT(LED_PEDESTRIANS,LED_RED);
	BUTTON_INIT(button_port,button_pin);
	TIMER_init();
	sei();
	RISING_EDGE();
	SETUP_INT0();
	
}

void app_start(void)
{
	//////////////////////normal mode////////////////////
	if (normal_mode==1)
	{
		TIMER_init();
		LED_ON(LED_NORMAL, LED_GREEN);
		LED_ON(LED_PEDESTRIANS,LED_RED);
		TIMER_delay(5000);
		LED_OFF(LED_NORMAL,LED_GREEN);
		led_no = 0;
		if (!normal_mode)
		return;
		for (Uint8 i=0;i<10;i++)
		{
			LED_TOGGLE(LED_NORMAL, LED_YELLOW);
			TIMER_delay(500);
			led_no = 1;
			if (!normal_mode)
			return;
		}
		LED_OFF(LED_NORMAL, LED_YELLOW);
		
		if (!normal_mode)
		return;
		LED_OFF(LED_PEDESTRIANS,LED_RED);
		LED_ON(LED_PEDESTRIANS,LED_GREEN);
		LED_ON(LED_NORMAL,LED_RED);
		TIMER_delay(5000);
		LED_OFF(LED_PEDESTRIANS,LED_GREEN);
		LED_OFF(LED_NORMAL,LED_RED);
		led_no = 2;
		if (!normal_mode)
		return;
		for (Uint8 i=0;i<10;i++)
		{
			LED_TOGGLE(LED_NORMAL, LED_YELLOW);
			TIMER_delay(500);
			led_no = 1;
			if (!normal_mode)
			return;
		}
		
		LED_OFF(LED_NORMAL, LED_YELLOW);
		LED_OFF(LED_NORMAL, LED_RED);
		if (!normal_mode)
		return;
		/////////////////////////////////////////////////////////////////
	}
	else {
		if (led_no == 2) //car led was red
		{
			TIMER_init();
			//car red led and pedestrain green led will be open for 5 seconds
// 			LED_ON(LED_NORMAL, LED_RED);
// 			LED_ON(LED_PEDESTRIANS, LED_GREEN);
// 			TIMER_delay(5000);
// 			LED_OFF(LED_NORMAL, LED_RED);
// 			LED_OFF(LED_PEDESTRIANS,LED_GREEN);
			for (Uint8 i=0;i<10;i++)
			{
				LED_TOGGLE(LED_PEDESTRIANS,LED_YELLOW);
				LED_TOGGLE(LED_NORMAL,LED_YELLOW);
				TIMER_delay(500);
			}
			LED_OFF(LED_PEDESTRIANS,LED_YELLOW);
			LED_OFF(LED_NORMAL,LED_YELLOW);
			LED_ON(LED_NORMAL,LED_GREEN);
			LED_ON(LED_PEDESTRIANS,LED_RED);
			TIMER_delay(5000);
			LED_OFF(LED_NORMAL,LED_GREEN);
			LED_OFF(LED_PEDESTRIANS,LED_RED);
			normal_mode=1;
			
		}else //led yellow or green
		{
			TIMER_init();
			LED_ON(LED_PEDESTRIANS,LED_RED);
			for(Uint8 i=0;i<10;i++)
			{
				LED_TOGGLE(LED_PEDESTRIANS,LED_YELLOW);
				LED_TOGGLE(LED_NORMAL,LED_YELLOW);
				TIMER_delay(500);
			}
			LED_OFF(LED_PEDESTRIANS,LED_RED);
			LED_OFF(LED_PEDESTRIANS,LED_YELLOW);
			LED_OFF(LED_NORMAL,LED_YELLOW);
			LED_OFF(LED_NORMAL,LED_GREEN);
			//normal redled and ped greenled on for 5sec
			LED_ON(LED_PEDESTRIANS,LED_GREEN);
			LED_ON(LED_NORMAL,LED_RED);
			TIMER_delay(5000);
			LED_OFF(LED_PEDESTRIANS,LED_GREEN);
			LED_OFF(LED_NORMAL,LED_RED);
			for (Uint8 i=0;i<10;i++)
			{
				LED_TOGGLE(LED_PEDESTRIANS,LED_YELLOW);
				LED_TOGGLE(LED_NORMAL,LED_YELLOW);
				TIMER_delay(500);
			}
			LED_OFF(LED_PEDESTRIANS,LED_YELLOW);
			LED_OFF(LED_NORMAL,LED_YELLOW);
			//ped redled and normal greenled on for 5sec
			LED_ON(LED_PEDESTRIANS,LED_RED);
			LED_ON(LED_NORMAL,LED_GREEN);
			TIMER_delay(5000);
			LED_OFF(LED_PEDESTRIANS,LED_RED);
			LED_OFF(LED_NORMAL,LED_GREEN);
			normal_mode=1;
			
		}
	}
	
}

ISR(INT0_vect)
{
	normal_mode=0;
	//mode=HIGH;
	//buttonst=HIGH;
	
}


