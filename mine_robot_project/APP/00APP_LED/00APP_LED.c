/*
 * 00APP_LED.c
 *
 *  Created on: Aug 24, 2023
 *      Author: kareem ashraf
 */

#include "00APP_LED.h"
#include <avr/delay.h>

#include "../../HAL/LED/LED_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void _00_LED_APP1(void)
{
	LED_voidInit(PORT_A,Pin_0);
	while(1)
	{
		LED_voidOn(PORT_A,Pin_0);
		_delay_ms(1000);
		LED_voidOff(PORT_A,Pin_0);
		_delay_ms(1000);
	}
}


void _00_LED_APP2(void)
{
	LED_voidInit(PORT_A,Pin_0);
	LED_voidInit(PORT_A,Pin_1);
	LED_voidInit(PORT_A,Pin_2);
	LED_voidInit(PORT_A,Pin_3);
	LED_voidInit(PORT_A,Pin_4);
	LED_voidInit(PORT_A,Pin_5);
	LED_voidInit(PORT_A,Pin_6);
	LED_voidInit(PORT_A,Pin_7);
	while(1){
	for (u8 Local_u8PinNumber =0 ; Local_u8PinNumber<8 ; Local_u8PinNumber++)
		{
			LED_voidOn(PORT_A,Local_u8PinNumber);
			_delay_ms(1000);

		}
	for (u8 Local_u8PinNumber =7 ; Local_u8PinNumber>=0 ; Local_u8PinNumber--)
		{
			LED_voidOff(PORT_A,Local_u8PinNumber);
			_delay_ms(1000);

		}
}
}
