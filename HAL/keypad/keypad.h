/*
 * keypad.h
 *
 *  Created on: Aug 14, 2023
 *      Author: hamada
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../MCAL/DIO/DIO.h"


#define KPD_PORT		PORT_C

#define KPD_R1_PIN 		PIN_0
#define KPD_R2_PIN 		PIN_1
#define KPD_R3_PIN 		PIN_2
#define KPD_R4_PIN 		PIN_3

#define KPD_C1_PIN 		PIN_4
#define KPD_C2_PIN 		PIN_5
#define KPD_C3_PIN 		PIN_6
#define KPD_C4_PIN 		PIN_7


#define KPD_CHECK	 	0XFF

#define KPD_KEYS 	{{'7','8','9','/'}, \
					 {'4','5','6','*'}, \
					 {'1','2','3','-'}, \
					 {'#','0','=','+'}}

void KPD_VidInit(void);
u8 KPD_U8PressedKey();


#endif /* HAL_KEYPAD_KEYPAD_H_ */
