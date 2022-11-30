/*
 * Timer.c
 *
 * Created: 11/10/2022 6:39:45 PM
 *  Author: carlo
 */ 
#include "Timer.h"
#include "../../Utilities/STD.h" 
#include "../../Utilities/BITMATH.h"

void TIMER_init(){
	TCCR0 = 0x00; //normal mode
}

void TIMER_delay(Uint16 millisec){
	Uint32 overFlowcnt=0;
	Uint16 Noverflows,TimerInitial;
	double Tmaxdelay,Ttick;
	Ttick = 256.0/1000.0; //ms    Ttick = Prescaler/FCPU
	Tmaxdelay= 65.536; //ms		Tmaxdelay = Ttick * 2^8
	if(millisec<Tmaxdelay){
		TimerInitial = (Tmaxdelay-millisec)/Ttick;
		Noverflows = 1;
		
		}else if(millisec == (int)Tmaxdelay){
		TimerInitial=0;
		Noverflows=1;
		}else{
		Noverflows = ceil((double)millisec/Tmaxdelay);
		TimerInitial = (1<<8) - ((double)millisec/Ttick)/Noverflows;
		
	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2); //set 256 prescaler
	while(overFlowcnt<Noverflows){
		//busy wait
		while(READ_BIT(TIFR,0)==0);
		//clear overflow flag
		SET_BIT(TIFR,0);
		//increment counter
		overFlowcnt++;
	}
	//Timer stop
	TCCR0 = 0x00;
}

void test_timer(void){
	TIMER_init();
	for (Uint8 i=0;i<10;i++)
	{
		LED_TOGGLE(LED_NORMAL,LED_GREEN);
		TIMER_delay(500);
	}
	LED_OFF(LED_NORMAL,LED_GREEN);
	
}