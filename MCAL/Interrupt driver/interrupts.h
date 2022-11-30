/*
 * interrupts.h
 *
 * Created: 11/16/2022 6:53:21 PM
 *  Author: carlo
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
// Including Files
#include "../../Utilities/registers.h"
#include "../../Utilities/BITMATH.h"
#include "../../ECUAL/BUTTON DRIVER/button.h"

// Enable interrupt
# define sei() __asm__ __volatile__ ("sei" ::: "memory")

// External Interrupt Request 0
#define INT0_vect  __vector_1

// Rising edge
#define RISING_EDGE() MCUCR |= (1<<ISC01) | (1<<ISC00)

// Setup use INT0
#define SETUP_INT0() SET_BIT(GICR,INT0)

// ISR
#define ISR(vector1)\
void vector1 (void) __attribute__ ((signal,used));\
void vector1 (void)

// Test
void Test_Interrupt(void);






#endif /* INTERRUPTS_H_ */