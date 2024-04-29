/*
 * 04APP_KEYBAD.c
 *
 *  Created on: Aug 24, 2023
 *      Author: kareem ashraf
 */


#include "04APP_KEYBAD.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/Keybad/Keybad_Interface.h"
#include <avr/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"


void _04_KEYBAD_APP(void)
{
	Keybad_voidInit(PORT_C);
	LCD_voidHWInit();
	LCD_voidSWInit();
	LCD_voidSendCommand(CLEAR);
	while(1)
	{
		u8 Keybad_Value = Keybad_u8ReturnData();
		LCD_voidSendCommand(0x80);
		LCD_voidSendData(Keybad_Value);
	}
}


void Keybad_voidInit(u8 Copy_Port);
u8 Keybad_u8ReturnData(void);
