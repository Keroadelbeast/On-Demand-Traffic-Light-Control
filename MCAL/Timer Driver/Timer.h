/*
 * Timer.h
 *
 * Created: 11/10/2022 6:40:01 PM
 *  Author: carlo
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../../Utilities/registers.h"
#include "../../ECUAL/LED DRIVER/LED.h"

#define MAX_NO_OF_OVERFLOWS 4

void TIMER_init();//initialize Timer0
void TIMER_delay(Uint16 millisec);
/*void button_timer(millisec);*/
void test_timer(void);


#endif /* TIMER_H_ */