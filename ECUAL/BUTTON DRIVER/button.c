     /*
     * button.c
     *
     * Created: 11/7/2022 10:02:54 PM
     *  Author: carlo
     */
     #include "button.h"
     #include "avr/delay.h"
     #define NO_OF_PRESSES 2
     Uint8 buttonState ;

     void BUTTON_INIT(Uint8 BUTTONPORT,Uint8 BUTTONPIN){ //button is an input device
	     DIO_INIT(BUTTONPIN,BUTTONPORT,IN);
     }
     void BUTTON_READ(Uint8 BUTTONPORT,Uint8 BUTTONPIN, Uint8 *VALUE){
	     DIO_READ(BUTTONPIN,BUTTONPORT,VALUE);
     }

     
     void BUTTON_TEST(void){
	     BUTTON_INIT(button_port, button_pin);
	     LED_INIT(LED_PEDESTRIANS, LED_GREEN);
	     BUTTON_READ(button_port,button_pin,&buttonState);
	     if (buttonState==HIGH)
	     {
		     LED_OFF(LED_PEDESTRIANS,LED_GREEN);
	     }
	     else if (buttonState==LOW)
	     {
		     LED_ON(LED_PEDESTRIANS,LED_GREEN);
	     }
     }

   
     

     
     
     