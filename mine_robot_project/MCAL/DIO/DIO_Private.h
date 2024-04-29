/*
 * Private.h
 *
 *  Created on: Aug 10, 2023
 *      Author: kareem ashraf
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#include "../../Services/STD_LIB.h"

// Register of port A
#define PORTA_REG   *((volatile u8*)0x3B)
#define DDRA_REG    *((volatile u8*)0x3A)
#define PINA_REG    *((volatile u8*)0x39)

// Register of port B
#define PORTB_REG   *((volatile u8*)0x38)
#define DDRB_REG	 *((volatile u8*)0x37)
#define PINB_REG	 *((volatile u8*)0x36)

// Register of port C
#define PORTC_REG	 *((volatile u8*)0x35)
#define DDRC_REG	 *((volatile u8*)0x34)
#define PINC_REG	 *((volatile u8*)0x33)

// Register of port D
#define PORTD_REG	 *((volatile u8*)0x32)
#define DDRD_REG	 *((volatile u8*)0x31)
#define PIND_REG	 *((volatile u8*)0x30)



#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
