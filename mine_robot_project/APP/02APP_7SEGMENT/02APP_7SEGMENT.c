/*
 * 02APP_7SEGMENT.c
 *
 *  Created on: Aug 24, 2023
 *      Author: kareem ashraf
 */


#include "02APP_7SEGMENT.h"
#include "../../HAL/_7Segment/_7_Interface.h"
#include <avr/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"

void _02_7SEGMENT_APP(void)
{
	_7Segment_voidInit();
	_7Segment_Status(ON);
	while(1)
	{
		for(u8 Number = 0 ; Number<10 ; Number++)
		{
			_7Segment_SpecificNumber(Number);
			_delay_ms(1000);
		}
	}
}


