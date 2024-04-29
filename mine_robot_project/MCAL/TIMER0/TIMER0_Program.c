/*
 * TIMER0_Program.c
 *
 *  Created on: Nov 26, 2023
 *      Author: zaynab
 */


#include "../../Services/Bit_Math.h"
#include "TIMER0_Interface.h"
#include <avr/interrupt.h>


void TIMER0_voidInit(void)
{
	// for the mode
#if TIMER0_MODE == NORMAL_MODE
	Set_Bit(TIMSK_REG, TIMSK_TOIE0); // nable the isr oferflow mode
	Clr_Bit(TCCR0_REG,TCCR0_WGM00);
	Clr_Bit(TCCR0_REG,TCCR0_WGM01);
	TCNT0_REG=192; // THE PRELOAD VALUE
	// the flag is set at the same clock source the
#elif TIMER0_MODE == CTC_MODE
	Set_Bit(TIMSK_REG,TIMSK_OCIE0); // set the isr of ctc (compare match)
	Clr_Bit(TCCR0_REG,TCCR0_WGM00);
	Set_Bit(TCCR0_REG,TCCR0_WGM01);
	TCNT0_REG= 250 ; // COMPARING MATCK VALUE
	// we have to set the ocr0 to be connected


#if CTC_OC0_STATE == OC0_disconnected_CTC
	Clr_Bit(TCCR0_REG,TCCR0_COM00);
	Clr_Bit(TCCR0_REG,TCCR0_COM01);
#elif CTC_OC0_STATE==Toggle_OC0_CTC
	Set_Bit(TCCR0_REG,TCCR0_COM00);
	Clr_Bit(TCCR0_REG,TCCR0_COM01);
#elif CTC_OC0_STATE == Clear_OC0_CTC
	Clr_Bit(TCCR0_REG,TCCR0_COM00);
	Set_Bit(TCCR0_REG,TCCR0_COM01);
#elif CTC_OC0_STATE == Set_OC0_CTC
	Set_Bit(TCCR0_REG,TCCR0_COM00);
	Set_Bit(TCCR0_REG,TCCR0_COM01);
#endif


#elif TIMER0_MODE == PWM_PHASECORECT

	Set_Bit(TCCR0_REG,TCCR0_WGM00);
	Clr_Bit(TCCR0_REG,TCCR0_WGM01);

#if PHASECORRECT_PWM_OC0_STATE ==OC0_disconnected
	Clr_Bit(TCCR0_REG,TCCR0_COM00);
	Clr_Bit(TCCR0_REG,TCCR0_COM01);
#elif FAST_PWM_OC0_STATE== Reserved
	Set_Bit(TCCR0_REG,TCCR0_COM00);
	Clr_Bit(TCCR0_REG,TCCR0_COM01);
#elif FAST_PWM_OC0_STATE == Clear_OC0
	Clr_Bit(TCCR0_REG,TCCR0_COM00);
	Set_Bit(TCCR0_REG,TCCR0_COM01);
#elif FAST_PWM_OC0_STATE == Set_OC0
	Set_Bit(TCCR0_REG,TCCR0_COM00);
	Set_Bit(TCCR0_REG,TCCR0_COM01);
#endif


#elif TIMER0_MODE == PWM_FAST

	Set_Bit(TCCR0_REG,TCCR0_WGM00);
	Set_Bit(TCCR0_REG,TCCR0_WGM01);

#if FAST_PWM_OC0_STATE ==OC0_disconnected
	Clr_Bit(TCCR0_REG,TCCR0_COM00);
	Clr_Bit(TCCR0_REG,TCCR0_COM01);
#elif FAST_PWM_OC0_STATE== Reserved
	Set_Bit(TCCR0_REG,TCCR0_COM00);
	Clr_Bit(TCCR0_REG,TCCR0_COM01);
#elif FAST_PWM_OC0_STATE == Clear_OC0
	Clr_Bit(TCCR0_REG,TCCR0_COM00);
	Set_Bit(TCCR0_REG,TCCR0_COM01);
#elif FAST_PWM_OC0_STATE == Set_OC0
	Set_Bit(TCCR0_REG,TCCR0_COM00);
	Set_Bit(TCCR0_REG,TCCR0_COM01);
#endif

#endif

//using the TCCR0 with bits TCCR0_CS00

#if Timer_prescaler == No_clocksource
	Clr_Bit(TCCR0_REG,TCCR0_CS00);
	Clr_Bit(TCCR0_REG,TCCR0_CS01);
	Clr_Bit(TCCR0_REG,TCCR0_CS02);


#elif Timer_prescaler == No_prescaler
	Set_Bit(TCCR0_REG,TCCR0_CS00);
	Clr_Bit(TCCR0_REG,TCCR0_CS01);
	Clr_Bit(TCCR0_REG,TCCR0_CS02);

#elif Timer_prescaler == prescaler_8
	Clr_Bit(TCCR0_REG,TCCR0_CS00);
	Set_Bit(TCCR0_REG,TCCR0_CS01);
	Clr_Bit(TCCR0_REG,TCCR0_CS02);

#elif Timer_prescaler == prescaler_64
	Set_Bit(TCCR0_REG,TCCR0_CS00);
	Set_Bit(TCCR0_REG,TCCR0_CS01);
	Clr_Bit(TCCR0_REG,TCCR0_CS02);
#elif Timer_prescaler == prescaler_256
	Clr_Bit(TCCR0_REG,TCCR0_CS00);
	Clr_Bit(TCCR0_REG,TCCR0_CS01);
	Set_Bit(TCCR0_REG,TCCR0_CS02);
#elif Timer_prescaler == prescaler_1024
	Set_Bit(TCCR0_REG,TCCR0_CS00);
	Clr_Bit(TCCR0_REG,TCCR0_CS01);
	Set_Bit(TCCR0_REG,TCCR0_CS02);
#elif Timer_prescaler == prescaler_T0_pinfallingedge
	Clr_Bit(TCCR0_REG,TCCR0_CS00);
	Set_Bit(TCCR0_REG,TCCR0_CS01);
	Set_Bit(TCCR0_REG,TCCR0_CS02);
#elif Timer_prescaler == prescaler_T0_pinrisingedge
	Set_Bit(TCCR0_REG,TCCR0_CS00);
	Set_Bit(TCCR0_REG,TCCR0_CS01);
	Set_Bit(TCCR0_REG,TCCR0_CS02);
#endif












}



// for timer 0
void PWM0_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}
void PWM0_dutycycle(u16 duty)
{
	OCR0=duty;
}


// for timer1
void PWM1_init(void)
{

	    // Clear TCCR1A and TCCR1B registers
	    TCCR1A = 0;
	    TCCR1B = 0;

	    // Set Fast PWM mode with non-inverted output on channels A and B
	    TCCR1A |= (1 << WGM10) | (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
	    TCCR1B |= (1 << WGM12) |  (1 << CS10);

	    // Set PD4 and PD5 as output
	    DDRD |= (1 << PD4) | (1 << PD5);



}

void PWM1_Adutycycle(u16 duty) {
    // Set duty cycle for channel A (OCR1A)
    OCR1AH = (u8)(duty >> 8); // High byte
    OCR1AL = (u8)duty;        // Low byte
}

void PWM1_Bdutycycle(u16 duty) {
    // Set duty cycle for channel B (OCR1B)
    OCR1BH = (u8)(duty >> 8); // High byte
    OCR1BL = (u8)duty;        // Low byte
}






















//
//void(*Global_pvCallBackFunction[8])(void)={NULL};
//
//u8 TIMER0_u8Init(Timer0_Cnfg* Ptr_CnfgStruct)
//{
//	u8 Local_u8ErrState=OK;
//	if(Ptr_CnfgStruct!=NULL)
//	{
//		/*Set Timer Mode*/
//		if(Ptr_CnfgStruct->Mode==Timer0FastPwmNonInverted)
//		{
//			/*Enable Fast PWM Mode*/
//			Set_Bit(TCCR0,TCCR0_WGM00);
//			Set_Bit(TCCR0,TCCR0_WGM01);
//			/*Set NonInverted Mode*/
//			Set_Bit(TCCR0,TCCR0_COM00);
//			Set_Bit(TCCR0,TCCR0_COM01);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer0FastPwmInverted)
//		{
//			/*Enable Fast PWM Mode*/
//			Set_Bit(TCCR0,TCCR0_WGM00);
//			Set_Bit(TCCR0,TCCR0_WGM01);
//			/*Set Inverted Mode*/
//			Clr_Bit(TCCR0,TCCR0_COM00);
//			Set_Bit(TCCR0,TCCR0_COM01);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer0PhaseCorrectPwmNonInverted)
//		{
//			/*Enable PhaseCorrect PWM Mode*/
//			Set_Bit(TCCR0,TCCR0_WGM00);
//			Clr_Bit(TCCR0,TCCR0_WGM01);
//			/*Set NON Inverted Mode*/
//			Set_Bit(TCCR0,TCCR0_COM00);
//			Set_Bit(TCCR0,TCCR0_COM01);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer0PhaseCorrectPwmInverted)
//		{
//			/*Enable PhaseCorrect PWM Mode*/
//			Set_Bit(TCCR0,TCCR0_WGM00);
//			Clr_Bit(TCCR0,TCCR0_WGM01);
//			/*Set Inverted Mode*/
//			Clr_Bit(TCCR0,TCCR0_COM00);
//			Set_Bit(TCCR0,TCCR0_COM01);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer0NormalMode)
//		{
//			/*SET TIMER TO NORMAL MODE*/
//			Clr_Bit(TCCR0,TCCR0_WGM00);
//			Clr_Bit(TCCR0,TCCR0_WGM01);
//			/*ENABLE OVERFLOW INTERRUPT*/
//			Set_Bit(TIMSK,TIMSK_TOIE0);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer0CTCMode)
//		{
//			/*SET TIMER TO CTC MODE*/
//			Clr_Bit(TCCR0,TCCR0_WGM00);
//			Set_Bit(TCCR0,TCCR0_WGM01);
//			/*ENABLE ONCOMPARE INTERRUPT*/
//			Set_Bit(TIMSK,TIMSK_OCIE0);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer0FallingEdgeCounter)
//		{
//			/*CLEAR PRESCALER BIT*/
//			TCCR0&=BIT_MASK;
//			/*Set Falling Edge Counter Mode*/
//			TCCR0|=TIMER0_COUNTER_ON_FALLING_EDGE;
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer0RisingEdgeCounter)
//		{
//			/*CLEAR PRESCALER BIT*/
//			TCCR0&=BIT_MASK;
//			/*Set Rising Edge Counter Mode*/
//			TCCR0|=TIMER0_COUNTER_ON_RISING_EDGE;
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//		if((Ptr_CnfgStruct->Mode!=Timer0RisingEdgeCounter)&&(Ptr_CnfgStruct->Mode!=Timer0FallingEdgeCounter)&&(Local_u8ErrState==OK))
//		{
//			switch(Ptr_CnfgStruct->Clk)
//			{
//			case Timer0NO_PRESCALING: TCCR0&=BIT_MASK; TCCR0|=Timer0NO_PRESCALING; break;
//			case Timer0DIVISION_BY_8: TCCR0&=BIT_MASK; TCCR0|=Timer0DIVISION_BY_8; break;
//			case Timer0DIVISION_BY_64: TCCR0&=BIT_MASK; TCCR0|=Timer0DIVISION_BY_64; break;
//			case Timer0DIVISION_BY_256: TCCR0&=BIT_MASK; TCCR0|=Timer0DIVISION_BY_256; break;
//			case Timer0DIVISION_BY_1024: TCCR0&=BIT_MASK; TCCR0|=Timer0DIVISION_BY_1024; break;
//			default:Local_u8ErrState=NOK; break;
//			}
//		}
//	}
//	else
//	{
//		Local_u8ErrState=NULL_PTR;
//	}
//	return Local_u8ErrState;
//}
//
//u8 TIMER1_u8Init(Timer1_Cnfg* Ptr_CnfgStruct)
//{
//	u8 Local_u8ErrState=OK;
//	if(Ptr_CnfgStruct!=NULL)
//	{
//		if(Ptr_CnfgStruct->Mode==Timer1Normal)
//		{
//			/*Enable Normal Mode*/
//			Clr_Bit(TCCR1A,TCCR1A_WGM10);
//			Clr_Bit(TCCR1A,TCCR1A_WGM11);
//			Clr_Bit(TCCR1B,TCCR1B_WGM12);
//			Clr_Bit(TCCR1B,TCCR1B_WGM13);
//			/*Enable OverFlow Interrupt*/
//			Set_Bit(TIMSK,TIMSK_TOIE1);
//		}
//		if(Ptr_CnfgStruct->Mode==Timer1ICU)
//		{
//			/*Enable Normal Mode*/
//			Clr_Bit(TCCR1A,TCCR1A_WGM10);
//			Clr_Bit(TCCR1A,TCCR1A_WGM11);
//			Clr_Bit(TCCR1B,TCCR1B_WGM12);
//			Clr_Bit(TCCR1B,TCCR1B_WGM13);
//			/*Enable OverFlow Interrupt*/
//			Set_Bit(TIMSK,TIMSK_TOIE1);
//			/*Enable ICU Interrupt*/
//			Set_Bit(TIMSK,TIMSK_TICIE1);
//			/*Set interrupt to Rising edge*/
//			Set_Bit(TCCR1B,TCCR1B_ICES1);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer1CTCOcr1)
//		{
//			/*Enable On Compare Mode*/
//			Clr_Bit(TCCR1A,TCCR1A_WGM10);
//			Clr_Bit(TCCR1A,TCCR1A_WGM11);
//			Set_Bit(TCCR1B,TCCR1B_WGM12);
//			Clr_Bit(TCCR1B,TCCR1B_WGM13);
//			/*Enable On Compare Interrupt*/
//
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer1CTCIcr1)
//		{
//			/*Enable Timer1 CTC Icr1 Mode*/
//			Clr_Bit(TCCR1A,TCCR1A_WGM10);
//			Clr_Bit(TCCR1A,TCCR1A_WGM11);
//			Set_Bit(TCCR1B,TCCR1B_WGM12);
//			Set_Bit(TCCR1B,TCCR1B_WGM13);
//			/*Enable On Compare Interrupt*/
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer1FallingEdgeCounter)
//		{
//			/*CLEAR PRESCALER BIT*/
//			TCCR1B&=BIT_MASK;
//			/*Set Falling Edge Counter Mode*/
//			TCCR1B|=Timer1FallingEdgeCounter;
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer1RisingEdgeCounter)
//		{
//			/*CLEAR PRESCALER BIT*/
//			TCCR1B&=BIT_MASK;
//			/*Set Rising Edge Counter Mode*/
//			TCCR1B|=Timer1RisingEdgeCounter;
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//		if((Ptr_CnfgStruct->Mode!=Timer1RisingEdgeCounter)&&(Ptr_CnfgStruct->Mode!=Timer1FallingEdgeCounter)&&(Local_u8ErrState==OK))
//		{
//			switch(Ptr_CnfgStruct->Clk)
//			{
//			case Timer1NO_PRESCALING: TCCR1B&=BIT_MASK; TCCR1B|=Timer1NO_PRESCALING; break;
//			case Timer1DIVISION_BY_8: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_8; break;
//			case Timer1DIVISION_BY_64: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_64; break;
//			case Timer1DIVISION_BY_256: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_256; break;
//			case Timer1DIVISION_BY_1024: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_1024; break;
//			default:Local_u8ErrState=NOK; break;
//			}
//		}
//	}
//	else
//	{
//		Local_u8ErrState=NULL_PTR;
//	}
//	return Local_u8ErrState;
//}
//u8 TIMER2_u8Init(Timer2_Cnfg* Ptr_CnfgStruct)
//{
//	u8 Local_u8ErrState=OK;
//	if(Ptr_CnfgStruct!=NULL)
//	{
//		/*Set Timer Mode*/
//		if(Ptr_CnfgStruct->Mode==Timer2FastPwmNonInverted)
//		{
//			/*Enable Fast PWM Mode*/
//			Set_Bit(TCCR2,TCCR2_WGM20);
//			Set_Bit(TCCR2,TCCR2_WGM21);
//			/*Set NonInverted Mode*/
//			Set_Bit(TCCR2,TCCR2_COM20);
//			Set_Bit(TCCR2,TCCR2_COM21);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer2FastPwmInverted)
//		{
//			/*Enable Fast PWM Mode*/
//			Set_Bit(TCCR2,TCCR2_WGM20);
//			Set_Bit(TCCR2,TCCR2_WGM21);
//			/*Set Inverted Mode*/
//			Clr_Bit(TCCR2,TCCR2_COM20);
//			Set_Bit(TCCR2,TCCR2_COM21);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer2PhaseCorrectPwmNonInverted)
//		{
//			/*Enable PhaseCorrect PWM Mode*/
//			Set_Bit(TCCR2,TCCR2_WGM20);
//			Clr_Bit(TCCR2,TCCR2_WGM21);
//			/*Set Inverted Mode*/
//			Set_Bit(TCCR2,TCCR2_COM20);
//			Set_Bit(TCCR2,TCCR2_COM21);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer2PhaseCorrectPwmInverted)
//		{
//			/*Enable PhaseCorrect PWM Mode*/
//			Set_Bit(TCCR2,TCCR2_WGM20);
//			Clr_Bit(TCCR2,TCCR2_WGM21);
//			/*Set Inverted Mode*/
//			Clr_Bit(TCCR2,TCCR2_COM20);
//			Set_Bit(TCCR2,TCCR2_COM21);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer2NormalMode)
//		{
//			/*SET TIMER TO NORMAL MODE*/
//			Clr_Bit(TCCR2,TCCR2_WGM20);
//			Clr_Bit(TCCR2,TCCR2_WGM21);
//			/*ENABLE OVERFLOW INTERRUPT*/
//			Set_Bit(TIMSK,TIMSK_TOIE2);
//		}
//		else if(Ptr_CnfgStruct->Mode==Timer2CTCMode)
//		{
//			/*SET TIMER TO CTC MODE*/
//			Clr_Bit(TCCR2,TCCR2_WGM20);
//			Set_Bit(TCCR2,TCCR2_WGM21);
//			/*ENABLE ONCOMPARE INTERRUPT*/
//			Set_Bit(TIMSK,TIMSK_OCIE2);
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//		if(Local_u8ErrState==OK)
//		{
//			switch(Ptr_CnfgStruct->Clk)
//			{
//			case Timer2NO_PRESCALING: TCCR2&=BIT_MASK; TCCR2|=Timer2NO_PRESCALING; break;
//			case Timer2DIVISION_BY_8: TCCR2&=BIT_MASK; TCCR2|=Timer2DIVISION_BY_8; break;
//			case Timer2DIVISION_BY_32: TCCR2&=BIT_MASK; TCCR2|=Timer2DIVISION_BY_32; break;
//			case Timer2DIVISION_BY_64: TCCR2&=BIT_MASK; TCCR2|=Timer2DIVISION_BY_64; break;
//			case Timer2DIVISION_BY_128: TCCR2&=BIT_MASK; TCCR2|=Timer2DIVISION_BY_128; break;
//			case Timer2DIVISION_BY_256: TCCR2&=BIT_MASK; TCCR2|=Timer2DIVISION_BY_256; break;
//			case Timer2DIVISION_BY_1024: TCCR2&=BIT_MASK; TCCR2|=Timer2DIVISION_BY_1024; break;
//			default:Local_u8ErrState=NOK; break;
//			}
//		}
//	}
//	else
//	{
//		Local_u8ErrState=NULL_PTR;
//	}
//	return Local_u8ErrState;
//}
//
//u8 TIMER_u8SetCallBackFunction(Interrupt_Functions Cpy_sInterruptFunction,void(*Cpy_pvCallBackFunction)(void))
//{
//	u8 Local_u8ErrState=OK;
//	if(Cpy_pvCallBackFunction!=NULL)
//	{
//		if((Cpy_sInterruptFunction>=Timer0OverFlowInterrupt)&&(Cpy_sInterruptFunction<=Timer1OverFlowInterrupt))
//		{
//			Global_pvCallBackFunction[Cpy_sInterruptFunction]=Cpy_pvCallBackFunction;
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//	}
//	else
//	{
//		Local_u8ErrState=NULL_PTR;
//	}
//	return Local_u8ErrState;
//}
//u8 TIMER_u8SetCompareValue(TimerChannel Cpy_Timer,u16 Cpy_u16CompareValue)
//{
//	u8 Local_u8ErrState=OK;
//	if(Cpy_Timer==Timer0)
//	{
//		if(Cpy_u16CompareValue>255)
//		{
//			Local_u8ErrState=COMPARE_VALUE_OVERFLOW;
//		}
//		else
//		{
//			/*SET COMPARE VALUE*/
//			OCR0=Cpy_u16CompareValue;
//		}
//	}
//	else if(Cpy_Timer==Timer1ChannelA)
//	{
//
//	}
//	else if(Cpy_Timer==Timer1ChannelB)
//	{
//
//	}
//	else if(Cpy_Timer==Timer2)
//	{
//		if(Cpy_u16CompareValue>255)
//		{
//			Local_u8ErrState=COMPARE_VALUE_OVERFLOW;
//		}
//		else
//		{
//			/*SET COMPARE VALUE*/
//			OCR2=Cpy_u16CompareValue;
//		}
//	}
//	else
//	{
//		Local_u8ErrState=NOK;
//	}
//	return Local_u8ErrState;
//}
//u8 TIMER2_u8SetPwmMode(Pwm_Type Cpy_sPwmType,u8 Cpy_u8DutyCycle)
//{
//	u8 Local_u8ErrState=OK;
//	if(Cpy_sPwmType==Inverted)
//	{
//		if(Cpy_u8DutyCycle<=99)
//		{
//			OCR2=MAP(0,100,0,255,Cpy_u8DutyCycle);
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//	}
//	else if(Cpy_sPwmType==NonInverted)
//	{
//		if(Cpy_u8DutyCycle<=99)
//		{
//			OCR2=255-(MAP(0,100,0,255,Cpy_u8DutyCycle));
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//	}
//	else
//	{
//		Local_u8ErrState=NOK;
//	}
//	return Local_u8ErrState;
//}
//
//u8 TIMER0_u8SetPwmMode(Pwm_Type Cpy_sPwmType,u8 Cpy_u8DutyCycle)
//{
//	u8 Local_u8ErrState=OK;
//	if(Cpy_sPwmType==Inverted)
//	{
//		if(Cpy_u8DutyCycle<=99)
//		{
//			OCR0=MAP(0,100,0,255,Cpy_u8DutyCycle);
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//	}
//	else if(Cpy_sPwmType==NonInverted)
//	{
//		if(Cpy_u8DutyCycle<=99)
//		{
//			OCR0=255-(MAP(0,100,0,255,Cpy_u8DutyCycle));
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//	}
//	else
//	{
//		Local_u8ErrState=NOK;
//	}
//	return Local_u8ErrState;
//}
//
//u8 TIMER1_u8SetPwmMode(Timer1Pwm_Cnfg* Ptr_CfgStruct)
//{
//	u8 Local_u8ErrState=OK;
//	if(Ptr_CfgStruct!=NULL)
//	{
//		u32 Local_u32PeriodValue=(u32)(((u32)MCU_CLK * (u32)1000000)/(u32)(Ptr_CfgStruct->PwmPrescaler));
//		Local_u32PeriodValue=(u32)(((u32)Local_u32PeriodValue*(u32)(Ptr_CfgStruct->PeriodicTime))/(u32)(1000));
//		if(Local_u32PeriodValue>PHASE_CORRECT_PWM_MAX)
//		{
//			Local_u8ErrState=NOK;
//		}
//		else if(Local_u32PeriodValue>FAST_PWM_MAX)
//		{
//			/*Enable Timer1 PWM Phase Correct Icr1 Mode*/
//			Clr_Bit(TCCR1A,TCCR1A_WGM10);
//			Set_Bit(TCCR1A,TCCR1A_WGM11);
//			Clr_Bit(TCCR1B,TCCR1B_WGM12);
//			Set_Bit(TCCR1B,TCCR1B_WGM13);
//			/*Set Period Value*/
//			ICR1=(u32)(Local_u32PeriodValue/2);
//			Local_u32PeriodValue=Local_u32PeriodValue/2;
//		}
//		else
//		{
//			/*Enable Timer1 Fast Pwm Icr1 Mode*/
//			Clr_Bit(TCCR1A,TCCR1A_WGM10);
//			Set_Bit(TCCR1A,TCCR1A_WGM11);
//			Set_Bit(TCCR1B,TCCR1B_WGM12);
//			Set_Bit(TCCR1B,TCCR1B_WGM13);
//			/*Set Period Value*/
//			ICR1=Local_u32PeriodValue;
//		}
//		if(Ptr_CfgStruct->Channel==PwmTimer1ChannelA)
//		{
//			/*Set NonInverted Mode*/
//			Set_Bit(TCCR1A,TCCR1A_COM1A1);
//			Clr_Bit(TCCR1A,TCCR1A_COM1A0);
//
//			if(Ptr_CfgStruct->DutyCyclePercentage<=99)
//			{
//				OCR1A=(MAP(0,100,0,Local_u32PeriodValue,Ptr_CfgStruct->DutyCyclePercentage));
//			}
//			else
//			{
//				Local_u8ErrState=NOK;
//			}
//		}
//		else if(Ptr_CfgStruct->Channel==PwmTimer1ChannelB)
//		{
//			/*Set NonInverted Mode*/
//			Set_Bit(TCCR1A,TCCR1A_COM1B1);
//			Clr_Bit(TCCR1A,TCCR1A_COM1B0);
//
//			if(Ptr_CfgStruct->DutyCyclePercentage<=99)
//			{
//				OCR1B=MAP(0,100,0,Local_u32PeriodValue,Ptr_CfgStruct->DutyCyclePercentage);
//			}
//			else
//			{
//				Local_u8ErrState=NOK;
//			}
//		}
//		else
//		{
//			Local_u8ErrState=NOK;
//		}
//		switch(Ptr_CfgStruct->PwmPrescaler)
//		{
//		case NO_PRESCALING: TCCR1B&=BIT_MASK; TCCR1B|=Timer1NO_PRESCALING; break;
//		case DIVISION_BY_8: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_8; break;
//		case DIVISION_BY_64: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_64; break;
//		case DIVISION_BY_256: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_256; break;
//		case DIVISION_BY_1024: TCCR1B&=BIT_MASK; TCCR1B|=Timer1DIVISION_BY_1024; break;
//		default:Local_u8ErrState=NOK; break;
//		}
//	}
//	return Local_u8ErrState;
//}
//__attribute__((signal)) void __vector_4(void);
//void __vector_4(void)
//{
//	if(Global_pvCallBackFunction[Timer2OnCompareInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer2OnCompareInterrupt]();
//	}
//	return;
//}
//__attribute__((signal)) void __vector_5(void);
//void __vector_5(void)
//{
//	if(Global_pvCallBackFunction[Timer2OverFlowInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer2OverFlowInterrupt]();
//	}
//	return;
//}
//__attribute__((signal)) void __vector_6(void);
//void __vector_6(void)
//{
//	if(Global_pvCallBackFunction[Timer1InputCaptureInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer1InputCaptureInterrupt]();
//	}
//	return;
//}
//__attribute__((signal)) void __vector_7(void);
//void __vector_7(void)
//{
//	if(Global_pvCallBackFunction[Timer1OnCompareAInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer1OnCompareAInterrupt]();
//	}
//	return;
//}
//__attribute__((signal)) void __vector_8(void);
//void __vector_8(void)
//{
//	if(Global_pvCallBackFunction[Timer1OnCompareBInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer1OnCompareBInterrupt]();
//	}
//	return;
//}
//__attribute__((signal)) void __vector_9(void);
//void __vector_9(void)
//{
//	if(Global_pvCallBackFunction[Timer1OverFlowInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer1OverFlowInterrupt]();
//	}
//	return;
//}
//__attribute__((signal)) void __vector_10(void);
//void __vector_10(void)
//{
//	if(Global_pvCallBackFunction[Timer0OnCompareInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer0OnCompareInterrupt]();
//	}
//	return;
//}
//__attribute__((signal)) void __vector_11(void);
//void __vector_11(void)
//{
//	if(Global_pvCallBackFunction[Timer0OverFlowInterrupt]!=NULL)
//	{
//		Global_pvCallBackFunction[Timer0OverFlowInterrupt]();
//	}
//	return;
//}





