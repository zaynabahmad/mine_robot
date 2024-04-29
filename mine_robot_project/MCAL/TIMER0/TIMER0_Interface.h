/*
 * TIMER0_Interface.h
 *
 *  Created on: Nov 26, 2023
 *      Author: zaynab
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "TIMER0_Config.h"
#include "TIMER0_Private.h"
#include "../../Services/STD_LIB.h"
#include "../../Services/Err_Type.h"
#include "avr/io.h"


//void TIMER0_voidInit(void);
//
// for the project
//void PWM0_init();
//void PWM0_dutycycle(u16 duty);
//void PWM1_init(void);
//void PWM1_Adutycycle(u16 duty);
//
//void PWM1_Bdutycycle(u16 duty);
//

typedef enum
{
	Timer0FastPwmNonInverted,
	Timer0FastPwmInverted,
	Timer0PhaseCorrectPwmNonInverted,
	Timer0PhaseCorrectPwmInverted,
	Timer0NormalMode,
	Timer0CTCMode,
	Timer0FallingEdgeCounter,
	Timer0RisingEdgeCounter
}Timer0Modes;

typedef enum
{
	Timer1Normal,
	Timer1ICU,
	Timer1CTCOcr1,
	Timer1CTCIcr1,
	Timer1FallingEdgeCounter=6,
	Timer1RisingEdgeCounter=7
}Timer1Modes;

typedef enum
{
	Timer2FastPwmNonInverted,
	Timer2FastPwmInverted,
	Timer2PhaseCorrectPwmNonInverted,
	Timer2PhaseCorrectPwmInverted,
	Timer2NormalMode,
	Timer2CTCMode
}Timer2Modes;

typedef enum
{
	Timer0NO_PRESCALING=1,
	Timer0DIVISION_BY_8=2,
	Timer0DIVISION_BY_64=3,
	Timer0DIVISION_BY_256=4,
	Timer0DIVISION_BY_1024=5
}Timer0Clk;

typedef enum
{
	Timer1NO_PRESCALING=1,
	Timer1DIVISION_BY_8=2,
	Timer1DIVISION_BY_64=3,
	Timer1DIVISION_BY_256=4,
	Timer1DIVISION_BY_1024=5
}Timer1Clk;

typedef enum
{
	Timer2NO_PRESCALING=1,
	Timer2DIVISION_BY_8=2,
	Timer2DIVISION_BY_32=3,
	Timer2DIVISION_BY_64=4,
	Timer2DIVISION_BY_128=5,
	Timer2DIVISION_BY_256=6,
	Timer2DIVISION_BY_1024=7
}Timer2Clk;

typedef struct
{
	Timer0Modes Mode;
	Timer0Clk Clk;
}Timer0_Cnfg;

typedef struct
{
	Timer1Modes Mode;
	Timer1Clk Clk;
}Timer1_Cnfg;

typedef struct
{
	Timer2Modes Mode;
	Timer2Clk Clk;
}Timer2_Cnfg;

typedef enum
{
	Timer0,
	Timer1ChannelA,
	Timer1ChannelB,
	Timer2
}TimerChannel;
typedef enum
{
	Timer0OverFlowInterrupt=0,
	Timer0OnCompareInterrupt=1,
	Timer2OverFlowInterrupt=2,
	Timer2OnCompareInterrupt=3,
	Timer1InputCaptureInterrupt=4,
	Timer1OnCompareAInterrupt=5,
	Timer1OnCompareBInterrupt=6,
	Timer1OverFlowInterrupt=7,
}Interrupt_Functions;

typedef enum
{
	PwmTimer1ChannelA,
	PwmTimer1ChannelB
}Pwm_Channel;

typedef enum
{
	Inverted,
	NonInverted
}Pwm_Type;

typedef enum
{
	NO_PRESCALING=1,
	DIVISION_BY_8=8,
	DIVISION_BY_64=64,
	DIVISION_BY_256=256,
	DIVISION_BY_1024=1024
}PwmClk;
typedef struct
{
	Pwm_Channel Channel;
	u16 PeriodicTime;
	u8 DutyCyclePercentage;
	PwmClk PwmPrescaler;
}Timer1Pwm_Cnfg;

u8 TIMER0_u8Init(Timer0_Cnfg* Ptr_CnfgStruct);

u8 TIMER1_u8Init(Timer1_Cnfg* Ptr_CnfgStruct);

u8 TIMER2_u8Init(Timer2_Cnfg* Ptr_CnfgStruct);

u8 TIMER1_u8SetPwmMode(Timer1Pwm_Cnfg* Ptr_CfgStruct);

u8 TIMER2_u8SetPwmMode(Pwm_Type Cpy_sPwmType,u8 Cpy_u8DutyCycle);

u8 TIMER0_u8SetPwmMode(Pwm_Type Cpy_sPwmType,u8 Cpy_u8DutyCycle);

u8 TIMER_u8SetCallBackFunction(Interrupt_Functions Cpy_sInterruptFunction,void(*Cpy_pvCallBackFunction)(void));

u8 TIMER_u8SetCompareValue(TimerChannel Cpy_Timer,u16 Cpy_u16CompareValue);



#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
