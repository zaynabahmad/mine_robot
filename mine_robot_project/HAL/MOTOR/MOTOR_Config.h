/*
 * MOTOR_Config.h
 *
 *  Created on: Dec 12, 2023
 *      Author: zaynab
 */

#ifndef HAL_MOTOR_MOTOR_CONFIG_H_
#define HAL_MOTOR_MOTOR_CONFIG_H_

#include "../../Services/STD_LIB.h"

#define MOTOR_CLK_W 1
#define MOTOR_UNTI_CLK_W 2

// define the motor used
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3


// define the pins used
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

//
struct MOTOR
{
	u8 _PIN1;
	u8 _PIN2;
	u8 _PORT;
	u8 _PWMPIN;
};




#endif /* HAL_MOTOR_MOTOR_CONFIG_H_ */
