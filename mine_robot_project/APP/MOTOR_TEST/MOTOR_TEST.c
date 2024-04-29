/*
 * MOTOR_TEST.c
 *
 *  Created on: Dec 15, 2023
 *      Author: zaynab
 */

#include "MOTOR_TEST.h"
#include "avr/delay.h"


void MOTOR_TESTvoidSINGLE ()
{
	// pwm is not work even if jsut i get on it high

	TIMER0_voidInit();

	test_motor1._PIN1=PIN_0;
	test_motor1._PIN2=PIN_1;
	test_motor1._PORT=PORT_B;
	test_motor1._PWMPIN=PIN_3;

	MOTOR_voidInit(test_motor1);
	MOTOR_voidInit(test_motor2);

	// TO enable the motor nable pin



	while(1)
	{
			//MOTOR_voidSetSpeed(test_motor1,200);
		DIO_voidSetPinValue(test_motor1._PORT,test_motor1._PWMPIN,HIGH);

			MOTOR_voidForward(test_motor1);



	}

}
