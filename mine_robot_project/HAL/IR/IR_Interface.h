/*
 * IR.h
 *
 *  Created on: Feb 18, 2024
 *      Author: zaynab
 */

#ifndef HAL_IR_IR_INTERFACE_H_
#define HAL_IR_IR_INTERFACE_H_
#include "../../MCAL/DIO/DIO_Interface.h"
#include "stdbool.h"

void IR_voidInit(u8 PORT_NAME, u8 PIN_NUM);

bool IR_boolCheckObstical(u8 PORT_NAME, u8 PIN_NUM);



#endif /* HAL_IR_IR_INTERFACE_H_ */
