/*
 * Keybad_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: kareem ashraf
 */


#include "../../Services/STD_LIB.h"
#include <avr/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"


static u8 Keybad_u8Value(u8 Copy_Number)
{
    switch(Copy_Number)
    {
    case 1 :   return  '1'  ; break ;
    case 2 :   return  '2'  ; break ;
    case 3 :   return  '3'  ; break ;
    case 4 :   return 'A' ; break ;
    case 5 :   return  '4'  ; break ;
    case 6 :   return  '5'  ; break ;
    case 7 :   return  '6'  ; break ;
    case 8 :   return 'B' ; break ;
    case 9 :   return  '7'  ; break ;
    case 10 :  return  '8'  ; break ;
    case 11 :  return  '9'  ; break ;
    case 12 :  return 'C' ; break ;
    case 13 :  return '*' ; break ;
    case 14 :  return  '0'  ; break ;
    case 15 :  return '#' ; break ;
    case 16 :  return 'D' ; break ;
    default :  return '%'         ;
    }
}

//0x0F
void Keybad_voidInit(u8 Copy_Port)
{
	DIO_voidSetPortDirection(Copy_Port,0x0F);
	DIO_voidSetPortValue(Copy_Port,0xF0); // input pull up
}

u8 Keybad_u8ReturnData(u8 Copy_Port)
{
	for(u8 Colume = 0 ; Colume < 4 ; Colume++)
	{

		DIO_voidSetPortValue(Copy_Port,(~(0b00000001<< Colume)) ); // colume 0

		for(u8 Row = 0 ; Row < 4 ; Row++)
		{
			if(DIO_u8GetPinValue(Copy_Port , Row+4) == 0 ) // row 0
			{
				_delay_ms(30);
				return Keybad_u8Value((Row*4)+Colume+1) ;
			}
		}
	}
}





