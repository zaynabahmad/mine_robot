/*
 * pwm_test.h
 *
 *  Created on: Feb 11, 2024
 *      Author: zaynab
 */

#ifndef APP_TEST_PWM_TEST_H_
#define APP_TEST_PWM_TEST_H_

#include "../../Services/STD_LIB.h"
#include "../../MCAL/TIMER0/TIMER0_Interface.h"
#include "../../HAL/LED/LED_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "avr/delay.h"


void test_dutycycle_for_timer1(void);
void test_led();




#endif /* APP_TEST_PWM_TEST_H_ */
