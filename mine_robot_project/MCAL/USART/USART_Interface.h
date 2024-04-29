/*
 * USART_Interface.h
 *
 *  Created on: Dec 12, 2023
 *      Author: zaynab
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#include "../../Services/STD_LIB.h"

// function to initialize the uart
void USART_voidInit(void);
// function to send data
void USART_voidSendData(u8 Copy_Data);
// function to receive data
u8 USART_u8RreceiveData(void);
// Function to disable the transmitter
void USART_voidDisableTransmitter(void);
// Function to enable the transmitter
void USART_voidEnableTransmitter(void);
#endif /* MCAL_USART_USART_INTERFACE_H_ */

// use the usb ttl with uart
