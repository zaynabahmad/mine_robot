/*
 * LCD.config.h
 *
 *  Created on: Aug 14, 2023
 *      Author: kareem ashraf
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


#define ROW_ONE  			  (0x80)  // SET LOCATION ONE IN ROW ONE
#define ROW_TWO  			  (0xC0)  // SET LOCATION ONE IN ROW TWO

#define LINE_1_8BIT           (0x30)               //
#define LINE_2_8BIT           (0x38)
#define LINE_1_4BIT           (0x20)
#define LINE_2_4BIT           (0x28)
#define ENTRY_MODE_LEFT       (0x06)
#define ENTRY_MODE_RIGHT      (0x04)
#define DISPLY_OFF_CURSOR_OFF (0x08)
#define CURSOR_ON             (0x0E)
#define DISPALY_OFF           (0x0C)
#define BLINKING_CURSOR 	  (0x0F)
#define LEFT_SHIFT 		   	  (0x18)
#define RIGHT_SHIFT 		  (0x1C)
#define LEFT_CURSOR 		  (0x10)
#define RIGHT_CURSOR 		  (0x14)
#define CLEAR 				  (0x01)





#define CONTROL_PIN  PORT_A
#define DATA_PIN     PORT_D

#endif /* HAL_LCD_LCD_CONFIG_H_ */
