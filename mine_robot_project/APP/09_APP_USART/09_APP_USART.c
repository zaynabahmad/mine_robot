/*
 * 09_APP_USART.c
 *
 *  Created on: Dec 12, 2023
 *      Author: zaynab
 */

#include "09_APP_USART.h"
#include "../../MCAL/USART/USART_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
void _09_UART_APP(void)
{
	USART_voidInit();

	LCD_voidSWInit();
	LCD_voidHWInit();

	while (1)
	{
		u8 DATA = USART_u8RreceiveData();
		LCD_voidSendData(0X80);
		LCD_voidSendNumber(DATA);
	}

}
