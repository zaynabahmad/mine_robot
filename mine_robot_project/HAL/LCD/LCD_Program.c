/*
 * LCD_Program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: kareem ashraf
 */


#include "LCD_Interface.h"
#include <avr/delay.h>

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Services/STD_LIB.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(CONTROL_PIN,Pin_0,LOW); 		     // RS
	DIO_voidSetPinValue(CONTROL_PIN,Pin_1,LOW);             // RW
	DIO_voidSetPortValue(DATA_PIN,Copy_u8Command);          // COMMAND

	DIO_voidSetPinValue(CONTROL_PIN,Pin_2,HIGH);            // Enable
	_delay_ms(2);
	DIO_voidSetPinValue(CONTROL_PIN,Pin_2,LOW);             // Disable

}
void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(CONTROL_PIN,Pin_0,HIGH); 			  // RS
	DIO_voidSetPinValue(CONTROL_PIN,Pin_1,LOW);              // RW
	DIO_voidSetPortValue(DATA_PIN,Copy_u8Data);              // DATA

	DIO_voidSetPinValue(CONTROL_PIN,Pin_2,HIGH);             // Enable
	_delay_ms(2);
	DIO_voidSetPinValue(CONTROL_PIN,Pin_2,LOW);              // Disable
}

void LCD_voidHWInit(void)
{
	DIO_voidSetPinDirection(CONTROL_PIN,Pin_0,Output); 	  // RS
	DIO_voidSetPinDirection(CONTROL_PIN,Pin_1,Output); 	  // RW
	DIO_voidSetPinDirection(CONTROL_PIN,Pin_2,Output); 	  // E

	DIO_voidSetPortDirection(DATA_PIN,0xFF);           	  // DATA
}


void LCD_voidSWInit(void)
{
	_delay_ms(40);
	LCD_voidSendCommand(0X38);

	_delay_us(40);
	LCD_voidSendCommand(DISPALY_OFF);

	_delay_us(40);
	LCD_voidSendCommand(CLEAR);
}



void LCD_voidSendString(u8 *Copy_u8String)
{
	u8 Local_u8Couter = 0 ;
	while(Copy_u8String[Local_u8Couter] != '\0')
	{
		LCD_voidSendData(Copy_u8String[Local_u8Couter]);
		Local_u8Couter++;
	}
}

void LCD_voidSendNumber(u16 Copy_u8Number)
{
    u16 str[5]; // Assuming the maximum number is 4 digits
    itoa(Copy_u8Number, str, 10); // Convert the number to a string
    LCD_voidSendString(str);

}
