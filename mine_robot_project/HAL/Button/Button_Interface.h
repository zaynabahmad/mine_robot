/*
 * Button_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: kareem ashraf
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

#include "../../Services/STD_LIB.h"
#include "Button_Config.h"


void Button_voidInit(u8 Copy_Port , u8 Copy_Pin);
u8 Button_voidPullUp(u8 Copy_Port , u8 Copy_Pin);
u8 Button_voidPullDown(u8 Copy_Port , u8 Copy_Pin);



#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
