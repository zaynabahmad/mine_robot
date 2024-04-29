/*
 * EXT_ISR_Interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: zaynab
 */

#ifndef MCAL_EXT_ISR_EXT_ISR_INTERFACE_H_
#define MCAL_EXT_ISR_EXT_ISR_INTERFACE_H_


void __vector_1(void)__attribute__((signal));

void __vector_2(void)__attribute__((signal));

void __vector_3(void)__attribute__((signal));

void EXT_ISR0voidInit(void);
void EXT_ISR1voidInit(void);
void EXT_ISR2voidInit(void);

void EXT_GIE_STATEvoidInit(void);


// initialize the isr0 ,1 ,2
// for any change and fallint and rising
// with clr and set
// void ext_isr0voidinit(void)
// the best is initisalze a mode in config file
// and do it with #if IST_MODE == low_level and #elif for other conditions
// do it for all isrs
// and enable or disabe the ist_state(read the data sheet )
// add function for the global interrupt enable and it could be a driver
// for the global interrupt enable
// void __vector_1(void)__attribute__((signal)); // this for the toolchain
// then we write void__vector_1(void){// and here the function }
// in main before the super loop we have to define the global and the extisr init
// then the code for the while 1
// then for the function vector1





#endif /* EXT_ISR_EXT_ISR_INTERFACE_H_ */
