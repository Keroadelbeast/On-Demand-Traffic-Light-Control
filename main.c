/*
* Myfwdproject.c
*
* Created: 11/4/2022 8:08:10 PM
* Author : carlo
*/

#include "ECUAL/LED DRIVER/LED.h"

//#include <avr/io.h>
#define F_CPU 1000000U //1 mhz
#include <util/delay.h>//to use delay in function
#include "ECUAL/BUTTON DRIVER/button.h"
#include "APPLICATION/APP.h"
int main(void)
{
	app_init();

	while (1)
	{
		
		app_start();
		//DIO_TEST();
		//LED_TEST();
		//BUTTON_TEST();
		//test_timer();
		//Test_Interrupt();
		


	}
}

