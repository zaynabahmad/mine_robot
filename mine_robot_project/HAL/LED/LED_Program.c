/*
 * Program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: kareem ashraf
 */


#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Services/Bit_Math.h"
#include "../../Services/STD_LIB.h"


void LED_voidInit(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	DIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,Output);
}

void LED_voidOn(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,HIGH);
}

void LED_voidOff(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	DIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,LOW);
}
void LED_voidToggle(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	DIO_voidPinToggle(Copy_u8Port,Copy_u8Pin);
}


