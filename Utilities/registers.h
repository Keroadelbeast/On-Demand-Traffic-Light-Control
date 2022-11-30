/*
 * DIO_private.h
 *
 * Created: 4/8/2022 2:02:58 PM
 *  Author: TEAM B
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "STD.h"
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
														
	#define PIND            *((volatile Uint8 *)0X30)
	#define DDRD			*((volatile Uint8 *)0X31)
	#define PORTD			*((volatile Uint8 *)0X32)
 
    #define PINC			*((volatile Uint8 *)0X33)
	#define DDRC			*((volatile Uint8 *)0X34)
	#define PORTC			*((volatile Uint8 *)0X35)
	
    #define PINB			*((volatile Uint8 *)0X36)
	#define DDRB			*((volatile Uint8 *)0X37)
	#define PORTB			*((volatile Uint8 *)0X38)
	
	#define PINA			*((volatile Uint8 *)0X39)
	#define DDRA			*((volatile Uint8 *)0X3A)
	#define PORTA			*((volatile Uint8 *)0X3B)

///timer registers/////

	#define TCCR0			*((volatile Uint8 *)0X53)
	#define TCNT0			*((volatile Uint8 *)0X52)
	#define TIFR			*((volatile Uint8 *)0X58)
	#define TIMSK	        *((volatile uint8*)0x59)
	// Interrupt Registers
	#define GICR	(*(volatile Uint8*)(0x5B))
	#define MCUCR	(*(volatile Uint8*)(0x55))
	#define ISC00   0
	#define ISC01   1
	#define INT0    6

#endif /* REGISTERS_H_ */