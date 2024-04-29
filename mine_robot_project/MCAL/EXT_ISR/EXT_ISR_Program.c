/*
 * EXT_ISR_Program.c
 *
 *  Created on: Aug 24, 2023
 *      Author: zaynab
 */

#include "EXT_ISR_Config.h"
#include "EXT_ISR_Private.h"
#include "../../Services/Bit_Math.h"



void EXT_ISR0voidInit(void)
{
#if ISR0_MODE ==ANY_CHANGE
	// isr0 is on any_change mode
	Clr_Bit(MCUCR_REG,MCUCR_ISC01); // the mcuct is for the trigger option
	Set_Bit(MCUCR_REG,MCUCR_ISC00);

#elif ISR0_MODE ==FALLING
	// isr0 is on falling mode
	Set_Bit(MCUCR_REG,MCUCR_ISC01);
	Clr_Bit(MCUCR_REG,MCUCR_ISC00);

#elif ISR0_MODE ==RISING
	// isr0 is on rising mode
	Set_Bit(MCUCR_REG,MCUCR_ISC01);
	Set_Bit(MCUCR_REG,MCUCR_ISC00);

#elif ISR0_MODE ==LOW_LEVEL
	// isr0 is on low_level mode
	Clr_Bit(MCUCR_REG,MCUCR_ISC01);
	Clr_Bit(MCUCR_REG,MCUCR_ISC00);

#endif

#if ISR0_STATE==ENABLE
	Set_Bit(GICR_REG,GICR_INT0);
#elif ISR0_STATE==DISABLE
	Clr_Bit(GICR_REG,GICR_INT0);
#endif

}
void EXT_ISR1voidInit(void)
{

#if ISR1_MODE ==ANY_CHANGE
	// isr0 is on any_change mode
	Clr_Bit(MCUCR_REG,MCUCR_ISC11);
	Set_Bit(MCUCR_REG,MCUCR_ISC10);

#elif ISR1_MODE ==FALLING
	// isr0 is on falling mode
	Set_Bit(MCUCR_REG,MCUCR_ISC11);
	Clr_Bit(MCUCR_REG,MCUCR_ISC10);

#elif ISR1_MODE ==RISING
	// isr0 is on rising mode
	Set_Bit(MCUCR_REG,MCUCR_ISC11);
	Set_Bit(MCUCR_REG,MCUCR_ISC10);

#elif ISR1_MODE ==LOW_LEVEL
	// isr0 is on low_level mode
	Clr_Bit(MCUCR_REG,MCUCR_ISC11);
	Clr_Bit(MCUCR_REG,MCUCR_ISC10);

#endif


}
void EXT_ISR2voidInit(void) // is a level triggered int via isc2

{
#if ISR2_MODE == FALLING
	Clr_Bit(MCUCSR_REG,MCUCSR_ISC2);


#elif ISR2_MODE == RISING

	Set_Bit(MCUCSR_REG,MCUCSR_ISC2);


#endif


}


void EXT_GIE_STATEvoidInit(void)
{
	#if GIE_STATE==ENABLE
		Set_Bit(SREG_REG,SREG_I);
	#elif GIE_STATE==DISABLE
		Clr_Bit(SREG_REG,SREG_I);
	#endif
}

