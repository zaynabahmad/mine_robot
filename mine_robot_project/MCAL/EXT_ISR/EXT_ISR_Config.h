/*
 * EXT_ISR_Config.h
 *
 *  Created on: Aug 24, 2023
 *      Author: zaynab
 */

#ifndef MCAL_EXT_ISR_EXT_ISR_CONFIG_H_
#define MCAL_EXT_ISR_EXT_ISR_CONFIG_H_

#define ANY_CHANGE 0
#define LOW_LEVEL 1
#define FALLING 2
#define RISING 3

#define ISR0_MODE ANY_CHANGE
#define ISR1_MODE ANY_CHANGE
#define ISR2_MODE FALLING  // only falling or rising

#define ENABLE 0
#define DISABLE 1

#define ISR0_STATE ENABLE

#define GIE_STATE ENABLE




#endif /* EXT_ISR_EXT_ISR_CONFIG_H_ */
