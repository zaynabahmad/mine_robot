/*
 * MOTOR_Program.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Zaynab
 */
#include "MOTOR_Interface.h"


// a function to init the motor pins
void MOTOR_voidInit(struct MOTOR motor)
{
	// create a motor
	// in the app creat a struct of motor and pass it here
// pin1 and pin2 as digital output
	DIO_voidSetPinDirection(motor._PORT,motor._PIN1,Output);
	DIO_voidSetPinDirection(motor._PORT,motor._PIN2,Output);
// pwm pin as a pwm output
	DIO_voidSetPinDirection(motor._PORT,motor._PWMPIN,Output);


}

// forward move function
void MOTOR_voidForward(struct MOTOR motor)
{
	// 1 is high and 2 is low
	DIO_voidSetPinValue(motor._PORT,motor._PIN1,HIGH);
	DIO_voidSetPinValue(motor._PORT,motor._PIN2,LOW);

}

// left move function
void MOTOR_voidLeft(struct MOTOR motor1 , struct MOTOR motor2)
{
	// motor 1 forward and 2 stop
	DIO_voidSetPinValue(motor1._PORT,motor1._PIN1,HIGH);
	DIO_voidSetPinValue(motor2._PORT,motor2._PIN2,LOW);
	DIO_voidSetPinValue(motor2._PORT,motor2._PIN1,LOW);


}

// right move function
void MOTOR_voidRight(struct MOTOR motor1, struct MOTOR motor2)
{
	// motor 2 forward and 1 stop
	DIO_voidSetPinValue(motor2._PORT,motor2._PIN1,HIGH);
	DIO_voidSetPinValue(motor1._PORT,motor1._PIN2,LOW);
	DIO_voidSetPinValue(motor1._PORT,motor1._PIN1,LOW);

}

// backword move function
void MOTOR_voidBackword(struct MOTOR motor)
{
	// 1 is low 2 is high
	DIO_voidSetPinValue(motor._PORT,motor._PIN1,LOW);
	DIO_voidSetPinValue(motor._PORT,motor._PIN2,HIGH);



}

// function to stop the motor speed
void MOTOR_voidStopMotor(struct MOTOR motor)
{
	// the two pins is low
	DIO_voidSetPinValue(motor._PORT,motor._PIN1,LOW);
	DIO_voidSetPinValue(motor._PORT,motor._PIN2,LOW);


}

/**
 * change this if not work
 * */
void MOTOR_voidSetSpeed(struct MOTOR motor, u16 speed )
{
	if (motor._PWMPIN == 4) {
		PWM1_init();
		PWM1_Bdutycycle(speed);

	 } // TIMER 1 CHANNEL B

	else if (motor._PWMPIN == 5){
		PWM1_init();
		PWM1_Adutycycle(speed);
	} // TIMER1 CHANNEL A
	else if (motor._PWMPIN == 3){
		PWM0_init();
		PWM0_dutycycle(speed);
	} // TIMER 0
}
