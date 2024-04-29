/*
 * USART_Config.h
 *
 *  Created on: Dec 11, 2023
 *      Author: zaynab
 */

#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

// for syncronization
#define syncrnous_mode 0
#define asyncronous_mode 1
#define mode asyncronous_mode

// for the parity bit
#define Disabled 0
#define Reserved 1
#define Even_parity 2
#define Odd_parity 3
#define parity_mode Disabled

//for stop bit
#define _1bit 0
#define _2bit 1
#define Stop_bit _2bit

// for bit size
#define _5bit 0
#define _6bit 1
#define _7bit 2
#define _8bit 3
#define _9bit 4
#define char_size _8bit

//




#endif /* MCAL_USART_USART_CONFIG_H_ */
