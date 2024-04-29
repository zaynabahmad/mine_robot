/*
 * TIMER0_Config.h
 *
 *  Created on: Nov 26, 2023
 *      Author: zaynab
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_


#define MCU_CLK				16

// configrations for the mode
#define NORMAL_MODE 0
#define CTC_MODE 1
#define PWM_PHASECORECT 2
#define PWM_FAST 3
#define TIMER0_MODE PWM_FAST

// configrations for the compare match mode
#define OC0_disconnected_CTC 0
#define Toggle_OC0_CTC 1
#define Clear_OC0C_CTC 2
#define Set_OC0_CTC 3
#define CTC_OC0_STATE Set_OC0_CTC


// for timer 1
#define OC1_disconnected_CTC 0
#define Toggle_OC1_CTC 1
#define Clear_OC1_CTC 2
#define Set_OC1_CTC 3
#define CTC_OC1_STATE Set_OC1_CTC

// configrations for fastpwm and phase correct
#define OC0_disconnected 0
#define Reserved 1
#define Clear_OC0 2
#define Set_OC0 3
#define FAST_PWM_OC0_STATE Set_OC0
#define PHASECORRECT_PWM_OC0_STATE Set_OC0

// configration for the prescaler
#define No_clocksource 0
#define No_prescaler 1
#define prescaler_8 2
#define prescaler_64 3
#define prescaler_256 4
#define prescaler_1024 5
#define prescaler_T0_pinfallingedge 6
#define prescaler_T0_pinrisingedge 7
#define Timer_prescaler No_prescaler



#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
