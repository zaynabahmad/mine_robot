/*
 * LCD_Interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: kareem ashraf
 */
#include "../../Services/STD_LIB.h"
#include "LCD_config.h"
#include "LCD_Private.h"

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_



void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSWInit(void);
void LCD_voidHWInit(void);


void LCD_voidSendString(u8 *Copy_u8String);
void LCD_voidSendNumber(u16 Copy_u8Number);
void LCD_voidSendSpicialCharacter();
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
