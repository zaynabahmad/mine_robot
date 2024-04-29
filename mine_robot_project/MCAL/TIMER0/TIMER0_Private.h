/*
 * TIMER_Private.h
 *
 *  Created on: Nov 26, 2023
 *      Author: zaynab
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_



#define TCCR0_REG *((volatile u8*)0x53)
	#define TCCR0_CS00 0
	#define TCCR0_CS01 1
	#define TCCR0_CS02 2
	#define TCCR0_WGM01 3
	#define TCCR0_COM00 4
	#define TCCR0_COM01 5
	#define TCCR0_WGM00 6
	#define TCCR0_FOC0 7

#define TCNT0_REG *((volatile u8*)0X52)

#define OCR0_REG *((volatile u8*)0x5C)

#define TIFR_REG *((volatile u8*)0x58)
	#define TIFR_TOV0 0
	#define TIFR_OCF0 1
	#define TIFR_TOV1 2
	#define TIFR_OCF1B 3
	#define TIFR_OCF1A 4
	#define TIFR_ICF1 5
	#define TIFR_TOV2 6
	#define TIFR_OCF2 7

#define TIMSK_REG *((volatile u8*) 0x59)
	#define TIMSK_TOIE0 0
	#define TIMSK_OCIE0 1
	#define TIMSK_TOIE1 2
	#define TIMSK_OCIE1B 3
	#define TIMSK_OCIE1A 4
	#define TIMSK_TICIE1 5
	#define TIMSK_TOIE2 6
	#define TIMSK_OCIE2 7

//
//#define TIMER1_COM_MASK_A			0b00111111
//#define TIMER1_COM_MASK_B			0b11001111

//
//#define BIT_MASK								0b11111000
//
//#define TIMER0_COUNTER_ON_FALLING_EDGE 		    6
//#define TIMER0_COUNTER_ON_RISING_EDGE	 		7
//
//#define FAST_PWM_MAX							65535ul
//#define PHASE_CORRECT_PWM_MAX					131071ul
//
//#define DONE									1u
//#define NOT_DONE								0u
//
//#define TCCR0                (*((volatile uint8 *)0x53))
//#define TCNT0                (*((volatile uint8 *)0x52))
//#define OCR0                 (*((volatile uint8 *)0x5C))
//#define TIMSK                (*((volatile uint8 *)0x59))
//#define TCCR2                (*((volatile uint8 *)0x45))
//#define OCR2                 (*((volatile uint8 *)0x43))
//#define TCCR1A               (*((volatile uint8 *)0x4F))
//#define TCCR1B               (*((volatile uint8 *)0x4E))
//#define OCR1A                (*((volatile uint16 *)0x4A))
//#define OCR1B                (*((volatile uint16 *)0x48))
//#define ICR1                 (*((volatile uint16 *)0x46))
//#define TIMSK                (*((volatile uint8 *)0x59))
//
//#define TCCR1A_COM1B0              4
//#define TCCR1A_COM1B1              5
//#define TCCR1A_COM1A0              6
//#define TCCR1A_COM1A1              7
//#define TCCR1A_WGM11               1
//#define TCCR1A_WGM10               0
//#define TCCR1A_FOC1A			   3
//#define TCCR1A_FOC1B			   4
//
//#define TCCR1B_CS10                0
//#define TCCR1B_CS11                1
//#define TCCR1B_CS12                2
//#define TCCR1B_WGM13               4
//#define TCCR1B_WGM12               3
//#define TCCR1B_ICES1               6
//
//#define TCCR0_WGM00               6
//#define TCCR0_WGM01               3
//#define TCCR0_COM00				  4
//#define TCCR0_COM01				  5
//#define TCCR0_FOC0				  7
//
//#define TIMSK_TOIE0				  0
//#define TIMSK_OCIE0				  1
//#define TIMSK_OCIE2				  7
//#define TIMSK_TOIE2				  6
//#define TIMSK_TOIE1				  2
//#define TIMSK_OCIE1B			  3
//#define TIMSK_OCIE1A			  4
//#define TIMSK_TICIE1			  5
//
//#define TCCR2_WGM20               6
//#define TCCR2_WGM21				  3
//#define TCCR2_COM20				  4
//#define TCCR2_COM21				  5
//#define TCCR2_CS20				  0
//#define TCCR2_CS21				  1
//#define TCCR2_CS22				  2


#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
