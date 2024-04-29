/*
 * 03APP_LCD.c
 *
 *  Created on: Aug 24, 2023
 *      Author: kareem ashraf
 */


#include "03APP_LCD.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include <avr/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"


void _03_LCD_APP(void)
{
	LCD_voidHWInit();
	LCD_voidSWInit();
	LCD_voidSendCommand(CLEAR);
	while(1)
	{
		LCD_voidSendCommand(0x80);
		for(u8 Number = 0 ; Number < 10 ; Number++)
		{
			LCD_voidSendData('Z');
			LCD_voidSendNumber(Number);
		}
	}
}
