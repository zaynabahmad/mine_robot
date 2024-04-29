/*
 * MOTOR_Interface.h
 *
 *  Created on: Dec 12, 2023
 *      Author: zaynab
 */

#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_

#include "MOTOR_Config.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMER0/TIMER0_Interface.h"
// a function to init the motor pins
void MOTOR_voidInit(struct MOTOR motor);

// forward move function
void MOTOR_voidForward(struct MOTOR motor);

// left move function
void MOTOR_voidLeft(struct MOTOR motor1 , struct MOTOR motor2);

// right move function
void MOTOR_voidRight(struct MOTOR motor1, struct MOTOR motor2);

// backword move function
void MOTOR_voidBackword(struct MOTOR motor);

// to stop the motor
void MOTOR_voidStopMotor(struct MOTOR motor);

// set the speed
void MOTOR_voidSetSpeed(struct MOTOR motor, u16 speed );



/* notes
 * motor 1 is in the right
 * motor 2 is in  the left
 * */
#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */
