/*
* DIO.c
*
* Created: 11/6/2022 10:33:18 PM
*  Author: carlo
*/
#include "../../Utilities/STD.h"
#include "../Timer Driver/Timer.h"
#include "DIO.h"
void DIO_INIT(Uint8 PINNO,Uint8 PORTNO ,Uint8 DIR)
{
	switch(PORTNO){
		case PORT_A:
		if(DIR==IN){
			DDRA &= ~(1<<PINNO);//INPUT
			}else if(DIR==OUT){
			DDRA |= (1<<PINNO);//OUTPUT
			}else{
			//error handling
		}
		break;
		case PORT_B:
		if(DIR==IN){
			DDRB &= ~(1<<PINNO);
			}else if(DIR==OUT){
			DDRB |= (1<<PINNO);
			}else{
			//error handling
		}
		
		break;
		case PORT_C:
		if(DIR==IN){
			DDRC &= ~(1<<PINNO);
			}else if(DIR==OUT){
			DDRC |= (1<<PINNO);
			}else{
			//error handling
		}
		break;
		case PORT_D:
		if(DIR==IN){
			DDRD &= ~(1<<PINNO);
			}else if(DIR==OUT){
			DDRD |= (1<<PINNO);
			}else{
			//error handling
		}
		break;
	}
	
}
void DIO_WRITE(Uint8 PINNO,Uint8 PORTNO ,Uint8 VAL){
	
	switch(PORTNO){
		case PORT_A:
		if(VAL==LOW){
			PORTA &= ~(1<<PINNO);//WRITE 0
			}else if(VAL==HIGH){
			PORTA|= (1<<PINNO);//WRITE 1
			}else{
			//error handling
		}
		break;
		case PORT_B:
		if(VAL==LOW){
			PORTB &= ~(1<<PINNO);
			}else if(VAL==HIGH){
			PORTB |= (1<<PINNO);
			}else{
			//error handling
		}
		
		break;
		case PORT_C:
		if(VAL==LOW){
			PORTC &= ~(1<<PINNO);
			}else if(VAL==HIGH){
			PORTC |= (1<<PINNO);
			}else{
			//error handling
		}
		break;
		case PORT_D:
		if(VAL==LOW){
			PORTD &= ~(1<<PINNO);
		}
		else if(VAL==HIGH)
		{
			PORTD |= (1<<PINNO);
		}
		else{
			//error handling
		}
		break;
	}
	
}
void DIO_TOGGLE(Uint8 PINNO,Uint8 PORTNO ){
	switch(PORTNO){
	case PORT_A:
	PORTA^=(1<<PINNO);

	break;
	case PORT_B:
	PORTB^=(1<<PINNO);
	
	break;
	case PORT_C:
	PORTC^=(1<<PINNO);
	
	break;
	case PORT_D:
	PORTD^=(1<<PINNO);

	break;
	}
}
Uint8 DIO_READ(Uint8 PINNO,Uint8 PORTNO ,Uint8 * VAL){
	switch(PORTNO){
		case PORT_A:
			*VAL = ((PINA&(1<<PINNO))>>PINNO);//get state-->read bit
			
		break;
		case PORT_B:
			*VAL = ((PINB&(1<<PINNO))>>PINNO);
			
		break;
		case PORT_C:
			*VAL = ((PINC&(1<<PINNO))>>PINNO);
		
		break;
		case PORT_D:
			*VAL = ((PIND&(1<<PINNO))>>PINNO);
			
		break;
	}
}
void DIO_TEST(void){
	DIO_INIT(0,'A',OUT);
	DIO_INIT(1,'A',OUT);
	DIO_INIT(2,'A',OUT);
	DIO_WRITE(1,'A',HIGH);
	
	for (Uint8 i=0;i<10;i++)
	{
		
		DIO_TOGGLE(0,'A');
		TIMER_delay(500);
	}
	DIO_WRITE(2,'A',HIGH);
	TIMER_delay(5000);
	DIO_WRITE(2,'A',LOW);
}