/*
 * _7_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: kareem ashraf
 */

#ifndef HAL__7SEGMENT__7_INTERFACE_H_
#define HAL__7SEGMENT__7_INTERFACE_H_

#include "../../Services/STD_LIB.h"
#include "_7_Private.h"
#include "_7_Config.h"

void _7Segment_voidInit(void);

/*on or off the 7 segment*/
void _7Segment_Status(u8 Copy_Status);

void _7Segment_SpecificNumber(u8 Copy_Number);

void _7Segment0To9(void);



#endif /* HAL__7SEGMENT__7_INTERFACE_H_ */
