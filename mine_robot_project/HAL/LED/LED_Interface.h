/*
   * Interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: kareem ashraf
 */


#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../Services/STD_LIB.h"

void LED_voidInit(u8 Copy_u8Port , u8 Copy_u8Pin);
void LED_voidOn(u8 Copy_u8Port , u8 Copy_u8Pin);
void LED_voidOff(u8 Copy_u8Port , u8 Copy_u8Pin);
void LED_voidToggle(u8 Copy_u8Port , u8 Copy_u8Pin);


#endif /* HAL_LED_LED_INTERFACE_H_ */
