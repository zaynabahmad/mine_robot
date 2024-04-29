/*
 * TIMER0_APP.c
 *
 *  Created on: Dec 7, 2023
 *      Author: zaynab
 */
#include <avr/interrupt.h>
#include "../../MCAL/TIMER0/TIMER0_Interface.h"
#include "_01_TIMER0_APP.h"
#include  "../../HAL/LED/LED_Interface.h" // create a led app and include it here
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/EXT_ISR/EXT_ISR_Interface.h"
#include <avr/delay.h>


// THIS APP MAKE THE LED TURNED OFF EVERY 5 SEC
// IF WE WANT TO USE IT WE HAVE TO PUT IT IN THE MAIN FILE
void _01_TIEMR0_APP(void ){
	EXT_GIE_STATEvoidInit();  // here to enable the global interrupt
	TIMER0_voidInit();
	LED_voidInit(PORTA_REG, PINA_REG);



	while (1)
	{

		LED_voidOn(PORTA_REG,PINA_REG);

	}


}



// HREE WITH MORMAL MODE

// timer 8 bit = 0 to 255  , resolution = 256 ;
// prescaller = 8          , required time = 5sec
// system clock = 5 MHZ

ISR(TIMER0_OVF_vect){ // if we use this kind of difintiion we have use avr/interrrupt.h

	static u16 Counter =0 ;
	Counter ++;
	if (Counter == 19532 ) // HERE THE OVER FLOW COUNT (this the important thing )
	{
		TCNT0=192; // THE PRELOAD VALUE
		// here the app after the delay ends
		LED_voidOff(PORTA_REG, PINA_REG);
		_delay_ms(500); // here just to notice the change
		Counter =0 ;
	}


}



// here with the CTC MODE

// timer 8 bit = 0 to 255  , resolution = 256 ;
// prescaller = 8          , required time = 1 sec
// system clock = 5 MHZ
// COMPARING MATCH VALUE = 250 ;

void __vector_10(void)__attribute__((signal));
void __vector_10(void)
{
	static u16 Counter =0 ;
	Counter ++;
	if (Counter == 4000 ) // HERE THE OVER FLOW COUNT (this the important thing )
	{
		TCNT0=0; // THE PRELOAD VALUE
		// here the app after the delay ends
		LED_voidOff(PORTA_REG, PINA_REG);
		_delay_ms(500); // here just to notice the change
		Counter =0 ;
	}

}
