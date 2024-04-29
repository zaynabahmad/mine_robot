/*
 * MINE_ROBOT.c
 *
 *  Created on: Feb 4, 2024
 *      Author: zaynab
 */

#include "MINE_ROBOT.h"
#include "../../Services/STD_LIB.h"



void MINE_ROBOTvoidFullApp()
{
	// first init the sensors and actuators  (ultrasonic , mine detector)
	MINE_ROBOTvoidSensorsInit();
	MINE_ROBOTvoidActuatorsInit();







	// the application
	while (1)
	{
		// move forward until there is no obstical


		// if there is obstical on forward return right or left then move forward until there is no obstial


	}

}


void MINE_ROBOTvoidSensorsInit(){

	// init the ultrasonic

	// init the minedetector

}

void MINE_ROBOTvoidActuatorsInit(){

	// init the motors
	MOTOR_voidInit(motor1);
	MOTOR_voidInit(motor2);

}

u16 MINE_ROBTOvoidReadUltrasonic()
{

}
