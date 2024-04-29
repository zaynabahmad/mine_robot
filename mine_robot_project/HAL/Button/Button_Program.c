/*
 * Button_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: kareem ashraf
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Services/STD_LIB.h"
#include "Button_Interface.h"



void Button_voidInit(u8 Copy_Port , u8 Copy_Pin)
{
	DIO_voidSetPinDirection(Copy_Port,Copy_Pin,Input);
	DIO_voidSetPinValue(Copy_Port,Copy_Pin,HIGH); // input pull up
}
u8 Button_voidPullUp(u8 Copy_Port , u8 Copy_Pin)
{
	return DIO_u8GetPinValue(Copy_Port,Copy_Pin);
}
u8 Button_voidPullDown(u8 Copy_Port , u8 Copy_Pin)
{
	return DIO_u8GetPinValue(Copy_Port,Copy_Pin);
}
