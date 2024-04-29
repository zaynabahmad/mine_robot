/*
 * IR_withMotors.c
 *
 *  Created on: Feb 18, 2024
 *      Author: zaynab
 */
#include "IR_withMotors.h"
// OC1A --> 4  OC1B--> 5 PORTD

void TEST_void001test(){
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
	MOTOR_voidSetSpeed(motor1,200);
	MOTOR_voidSetSpeed(motor2,200);




	bool obstical_right , obstical_left , obstical_forward;
	while (1){
		MOTOR_voidSetSpeed(motor1,200);
			MOTOR_voidSetSpeed(motor2,200);
		obstical_forward = IR_boolCheckObstical(PORT_B,Pin_0);
		obstical_left    = IR_boolCheckObstical(PORT_B,Pin_2);
		obstical_right   = IR_boolCheckObstical(PORT_B,Pin_1);

		if (obstical_forward){MOTOR_voidRight(motor1, motor2); }  // trun right
		if (obstical_right) { MOTOR_voidLeft(motor1 , motor2);}  // turn left
		else {
			MOTOR_voidForward(motor1);
			MOTOR_voidForward(motor2);
		 }  // move forward

		 }

	}

