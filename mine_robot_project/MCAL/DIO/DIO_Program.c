/*
 * Program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: kareem ashraf
 */



#include "../../Services/STD_LIB.h"
#include "../../Services/Bit_Math.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"


#include "DIO_Private.h"

/**/
void DIO_voidSetPinDirection(u8 Copy_Port,u8 Copy_Pin,u8 Copy_Direction)
{
	if(Copy_Direction == Output)
	{
		switch(Copy_Port)
		{
		case PORT_A : Set_Bit(DDRA_REG,Copy_Pin); break;
		case PORT_B : Set_Bit(DDRB_REG,Copy_Pin); break;
		case PORT_C : Set_Bit(DDRC_REG,Copy_Pin); break;
		case PORT_D : Set_Bit(DDRD_REG,Copy_Pin); break;
		}
	}
	else if(Copy_Direction == Input)
	{
		switch(Copy_Port)
		{
		case PORT_A : Clr_Bit(DDRA_REG,Copy_Pin); break;
		case PORT_B : Clr_Bit(DDRB_REG,Copy_Pin); break;
		case PORT_C : Clr_Bit(DDRC_REG,Copy_Pin); break;
		case PORT_D : Clr_Bit(DDRD_REG,Copy_Pin); break;
		}
	}
}

/* */
void DIO_voidSetPinValue(u8 Copy_Port, u8 Copy_Pin, u8 Copy_Value)
{
	if(Copy_Value == HIGH)
	{
		switch(Copy_Port)
		{
		case PORT_A : Set_Bit(PORTA_REG,Copy_Pin); break;
		case PORT_B : Set_Bit(PORTB_REG,Copy_Pin); break;
		case PORT_C : Set_Bit(PORTC_REG,Copy_Pin); break;
		case PORT_D : Set_Bit(PORTD_REG,Copy_Pin); break;
		}
	}
	else if(Copy_Value == LOW)
	{
		switch(Copy_Port)
		{
		case PORT_A : Clr_Bit(PORTA_REG,Copy_Pin); break;
		case PORT_B : Clr_Bit(PORTB_REG,Copy_Pin); break;
		case PORT_C : Clr_Bit(PORTC_REG,Copy_Pin); break;
		case PORT_D : Clr_Bit(PORTD_REG,Copy_Pin); break;
		}
	}
}

void DIO_voidPinToggle(u8 Copy_Port , u8 Copy_Pin)
{
	switch(Copy_Port)
	{
	case PORT_A : Toggle_Bit(PORTA_REG,Copy_Pin); break;
	case PORT_B : Toggle_Bit(PORTB_REG,Copy_Pin); break;
	case PORT_C : Toggle_Bit(PORTC_REG,Copy_Pin); break;
	case PORT_D : Toggle_Bit(PORTD_REG,Copy_Pin); break;
	}
}

u8 DIO_u8GetPinValue(u8 Copy_Port,u8 Copy_Pin)
{
	u8 Local_var ;
	switch(Copy_Port)
	{
	case PORT_A: Local_var = Get_Bit(PINA_REG,Copy_Pin); break;
	case PORT_B: Local_var = Get_Bit(PINB_REG,Copy_Pin); break;
	case PORT_C: Local_var = Get_Bit(PINC_REG,Copy_Pin); break;
	case PORT_D: Local_var = Get_Bit(PIND_REG,Copy_Pin); break;
	}

	return Local_var ;
}




void DIO_voidSetPortDirection(u8 Copy_Port , u8 Copy_Direction)
{
	switch(Copy_Port)
	{
	case PORT_A : DDRA_REG = Copy_Direction; break;
	case PORT_B : DDRB_REG = Copy_Direction; break;
	case PORT_C : DDRC_REG = Copy_Direction; break;
	case PORT_D : DDRD_REG = Copy_Direction; break;
	}
}


void DIO_voidSetPortValue    (u8 Copy_Port , u8 Copy_Value)
{
	switch(Copy_Port)
	{
	case PORT_A : PORTA_REG = Copy_Value; break;
	case PORT_B : PORTB_REG = Copy_Value; break;
	case PORT_C : PORTC_REG = Copy_Value; break;
	case PORT_D : PORTD_REG = Copy_Value; break;
	}
}









