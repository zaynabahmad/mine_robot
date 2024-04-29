/*
 * MINE_ROBOT.h
 *
 *  Created on: Feb 4, 2024
 *      Author: zaynab
 */

#ifndef APP_MINE_ROBOT_MINE_ROBOT_H_
#define APP_MINE_ROBOT_MINE_ROBOT_H_

#include "../../HAL/MOTOR/MOTOR_Interface.h"


void MINE_ROBOTvoidFullApp();
void MINE_ROBOTvoidSensorsInit();
void MINE_ROBOTvoidActuatorsInit();

// DATA FOR MOTORS
struct MOTOR motor1={Pin_1,Pin_2,PORT_A,Pin_2};
struct MOTOR motor2={Pin_1,Pin_2,PORT_B,Pin_2};




#endif /* APP_MINE_ROBOT_MINE_ROBOT_H_ */
