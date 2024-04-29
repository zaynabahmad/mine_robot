/*
 * main.c
 *
 *  Created on: Nov 25, 2023
 *      Author: zaynab
 */

/* IMT_PROJECT
 * here will be the application for a mine robot
 * avoid obistical
 * if it found any obistaical just delay for a 2 sec then change its dir
 *
 * */
#include "../APP/TEST/pwm_test.h"
#include "avr/delay.h"
//#include "../APP/TEST/adc_test.h"
#include "../Services/STD_LIB.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../APP/03APP_LCD/03APP_LCD.h"
#include "../HAL/LED/LED_Interface.h"
#include "../APP/00APP_LED/00APP_LED.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../APP/TEST/IR_withMotors.h"
int main(void)
{

	// initialize IR
		IR_voidInit(PORT_B,Pin_0); // FORWARD IR
		IR_voidInit(PORT_B,Pin_1); // RIGHT IR
		IR_voidInit(PORT_B,Pin_2); // LEFT IR

		// init two motors
		motor1._PIN1=PIN_0;
		motor1._PIN2=PIN_1;  // right
		motor1._PORT=PORT_D;
		motor1._PWMPIN=PIN_4; // OC1A

		motor2._PIN1=PIN_2;
		motor2._PIN2=PIN_3;    // left
		motor2._PORT=PORT_D;
		motor2._PWMPIN=PIN_5;  // OC1B

		MOTOR_voidInit(motor1);
		MOTOR_voidInit(motor2);



		bool obstical_right , obstical_left , obstical_forward;
			while (1){
				MOTOR_voidSetSpeed(motor1,200);
					MOTOR_voidSetSpeed(motor2,200);
				obstical_forward = IR_boolCheckObstical(PORT_B,Pin_0);
				obstical_left    = IR_boolCheckObstical(PORT_B,Pin_2);
				obstical_right   = IR_boolCheckObstical(PORT_B,Pin_1);

				// the state machine for the move of the robot

				if (obstical_forward)
				{
					MOTOR_voidBackword(motor1);
					MOTOR_voidBackword(motor2);

					MOTOR_voidRight(motor1, motor2);
				}  // trun right

				if (obstical_right) {
					MOTOR_voidBackword(motor1);
					MOTOR_voidBackword(motor2);
					MOTOR_voidLeft(motor1 , motor2);
				}  // turn left
				else {
					MOTOR_voidForward(motor1);
					MOTOR_voidForward(motor2);
				 }  // move forward

				 }




	return 0;
}





