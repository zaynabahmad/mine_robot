/*
 * 01APP_BUTTON.c
 *
 *  Created on: Aug 24, 2023
 *      Author: kareem ashraf
 */


#include "01APP_BUTTON.h"
#include "../../HAL/Button/Button_Interface.h"
#include "../../Services/STD_LIB.h"

#include <avr/delay.h>

#include "../../HAL/LED/LED_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void _01_BUTTON_APP(void)
{
    Button_voidInit(PORT_B,Pin_0);
    LED_voidInit(PORT_A,Pin_0);
	while(1)
	{
		u8 Button_Value = Button_voidPullUp(PORT_B,Pin_0);
		if(Button_Value == BUTTON_OPEN) // 1
		{
			LED_voidOff(PORT_A,Pin_0);
		}
		else if(Button_Value == BUTTON_CLOSE) //0
		{
			LED_voidOn(PORT_A,Pin_0);
		}
	}
}

void _02_BUTTON_APP(void) // buttons for three diffreent leds(homework)
{
	Button_voidInit(PORT_B,Pin_0);
	LED_voidInit(PORT_A,Pin_0);

	Button_voidInit(PORT_B,Pin_0);
	LED_voidInit(PORT_A,Pin_0);

	Button_voidInit(PORT_B,Pin_0);
	LED_voidInit(PORT_A,Pin_0);
		while(1)
		{
			u8 Button_Value = Button_voidPullUp(PORT_B,Pin_0);
			if(Button_Value == BUTTON_OPEN) // 1
			{
				LED_voidOff(PORT_A,Pin_0);
			}
			else if(Button_Value == BUTTON_CLOSE) //0
			{
				LED_voidOn(PORT_A,Pin_0);
			}
		}

}
