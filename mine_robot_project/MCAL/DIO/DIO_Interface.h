/*
 * Interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: kareem ashraf
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../Services/STD_LIB.h"
#include "DIO_Config.h"
#include "DIO_Private.h"

void DIO_voidSetPinDirection (u8 Copy_Port , u8 Copy_Pin , u8 Copy_Direction);
void DIO_voidSetPinValue (u8 Copy_Port , u8 Copy_Pin , u8 Copy_Value);
void DIO_voidPinToggle(u8 Copy_Port , u8 Copy_Pin);
u8   DIO_u8GetPinValue(u8 Copy_Port , u8 Copy_Pin);


void DIO_voidSetPortDirection(u8 Copy_Port , u8 Copy_Direction);
void DIO_voidSetPortValue    (u8 Copy_Port , u8 Copy_Value);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
