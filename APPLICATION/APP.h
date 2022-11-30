/*
 * APP.h
 *
 * Created: 11/10/2022 7:00:47 PM
 *  Author: carlo
 */ 


#ifndef APP_H_
#define APP_H_
#include "../ECUAL/BUTTON DRIVER/button.h"
#include "../ECUAL/LED DRIVER/LED.h"
#include "../MCAL/Interrupt driver/interrupts.h"
#include "../MCAL/Timer Driver/Timer.h"

void app_init(void);
void app_start(void);
void clickOnRed(void);
void clickOnYelloworGreen(Uint8 state);



#endif /* APP_H_ */