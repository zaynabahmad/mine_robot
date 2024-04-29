/*
 * _7_Program.c
 *
 *  Created on: Aug 15, 2023
 *      Author: kareem ashraf
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Services/STD_LIB.h"
#include "_7_Interface.h"
#include "_7_Private.h"
#include "_7_Config.h"

void _7Segment_voidInit(void)
{
	DIO_voidSetPortDirection(_7SEGMENT_PORT,0xFF);
}

/*on or off the 7 segment*/
void _7Segment_Status(u8 Copy_Status)
{
	if(_7SEGMENT_TYPE == COMMON_ANOD)
	{
		if(Copy_Status == ON)
		{
			DIO_voidSetPinValue(_7SEGMENT_PORT ,Pin_7,HIGH);
		}
		else if(Copy_Status == OFF)
		{
			DIO_voidSetPinValue(_7SEGMENT_PORT ,Pin_7,LOW);
		}
	}
	else if(_7SEGMENT_TYPE == COMMON_CATHOD)
	{
		if(Copy_Status == ON)
		{
			DIO_voidSetPinValue(_7SEGMENT_PORT ,Pin_7,LOW);
		}
		else if(Copy_Status == OFF)
		{
			DIO_voidSetPinValue(_7SEGMENT_PORT ,Pin_7,HIGH);
		}
	}

}

void _7Segment_SpecificNumber(u8 Copy_Number)
{

	u8  _7SegmentCathode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	u8  _7SegmentAnode[10]={~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F};

	if(_7SEGMENT_TYPE == COMMON_ANOD)
	{
		DIO_voidSetPortValue(_7SEGMENT_PORT,_7SegmentAnode[Copy_Number]);
	}
	else if(_7SEGMENT_TYPE == COMMON_CATHOD)
	{

		DIO_voidSetPortValue(_7SEGMENT_PORT,_7SegmentCathode[Copy_Number]);
	}
}

void _7Segment0To9(void)
{
	u8  _7SegmentCathode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	u8  _7SegmentAnode[10]={~0x3F,~0x06,~0x5B,~0x4F,~0x66,~0x6D,~0x7D,~0x07,~0x7F,~0x6F};

	if(_7SEGMENT_TYPE == COMMON_ANOD)
	{
		for(u8 i=0 ;i<10;i++)
		{
			DIO_voidSetPortValue(_7SEGMENT_PORT,_7SegmentAnode[i]);
		}
	}
	else if(_7SEGMENT_TYPE == COMMON_CATHOD)
	{
		for(u8 i=0 ;i<10;i++)
		{
			DIO_voidSetPortValue(_7SEGMENT_PORT,_7SegmentCathode[i]);
		}
	}
}
