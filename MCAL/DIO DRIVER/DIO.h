/*
 * DIO.h
 *
 * Created: 11/6/2022 10:33:56 PM
 *  Author: carlo
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
// ALL INTERNAL DRIVER TYPEDEFS
//all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
//DIRECTION DEFINES
#define IN 0
#define OUT 1
//VALUE DEFINES
#define LOW 0
#define HIGH 1
//all driver function prototypes
void DIO_INIT(Uint8 PINNO,Uint8 PORTNO ,Uint8 DIR);
void DIO_WRITE(Uint8 PINNO,Uint8 PORTNO ,Uint8 VAL);
void DIO_TOGGLE(Uint8 PINNO,Uint8 PORTNO );
Uint8 DIO_READ(Uint8 PINNO,Uint8 PORTNO ,Uint8 * VAL);
void DIO_TEST(void);
	







#endif /* DIO_H_ */