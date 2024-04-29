/*
 * pwm_test.c
 *
 *  Created on: Feb 11, 2024
 *      Author: zaynab
 */

#include "pwm_test.h"

void test_dutycycle_for_timer1(void)
{
	PWM1_init();


	while(1){
		for (u16 duty=200 ; duty<255;duty--)
		{
		PWM1_Adutycycle(duty);
		PWM1_Bdutycycle(duty);
		PWM0_dutycycle(duty);
		_delay_ms(20);
		}

	}

}


void test_led()
{
	 LED_voidInit(PORT_B, Pin_3);

	    while (1)
	    {
	        // Toggle the LED without using PWM
	        LED_voidToggle(PORT_B, Pin_3);

	        // Delay for a while
	        _delay_ms(500);
	    }

}
