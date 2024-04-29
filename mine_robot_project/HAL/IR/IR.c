/*
 * IR.c
 *
 *  Created on: Feb 18, 2024
 *      Author: zaynab
 */


#include "IR_Interface.h"


/*
 * initialize the pin to use it with the ir
 * */
void IR_voidInit(u8 PORT_NAME, u8 PIN_NUM)
{
	DIO_voidSetPinDirection(PORT_NAME,PIN_NUM,Input);

}

/*
 * check if there is an obstical
 * return true if there is obstical (output = 0)
 * */
bool IR_boolCheckObstical(u8 PORT_NAME, u8 PIN_NUM){
	u8 out= DIO_u8GetPinValue(PORT_NAME,PIN_NUM);
	if (out==0){return true;}
	else {return false; }
}


