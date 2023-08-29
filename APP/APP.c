/*
 * APP.c
 *
 *  Created on: Aug 10, 2023
 *      Author: hamada
 */


#include "APP.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/keypad/keypad.h"




u8 value = KPD_CHECK;
u8 first =0;
u8 second =0;
u8 operation ;

int main(void)
{

	KPD_VidInit();
	LCD_VidInitialize();
	LCD_VidSendString("Simple");
	LCD_VidSendLocation(LINE_2,0);
	LCD_VidSendString("Calculator");
	_delay_ms(1000);
	LCD_CLEAR();

	while(1)
	{
			while(1)
			{
				value = KPD_U8PressedKey();
				_delay_ms(150);
				if(value != KPD_CHECK && value =='#')
				{
					LCD_CLEAR();
					_delay_ms(20);
					value = KPD_CHECK;
				}
				if(value !=KPD_CHECK && value != '='&& value !='+'&& value !='-' && value !='*' && value !='/')
				{
					switch(value)
					{
						case '0': first =first*10 + 0; break;
						case '1': first =first*10 + 1; break;
						case '2': first =first*10 + 2; break;
						case '3': first =first*10 + 3; break;
						case '4': first =first*10 + 4; break;
						case '5': first =first*10 + 5; break;
						case '6': first =first*10 + 6; break;
						case '7': first =first*10 + 7; break;
						case '8': first =first*10 + 8; break;
						case '9': first =first*10 + 9; break;
					}
					LCD_VidSendChar(value);
					value = KPD_CHECK;
				}
				if(value=='+' || value=='-'|| value=='*' || value=='/')
				{
					operation = value;
					LCD_VidSendChar(value);
					value = KPD_CHECK;
					break;
				}
			}
			while(1)
			{
				value = KPD_U8PressedKey();
				_delay_ms(150);
				if(value !=KPD_CHECK && value != '='&& value !='+'&& value !='-' && value !='*' && value !='/')
				{
					switch(value)
					{
						case '0': second =second*10 + 0; break;
						case '1': second =second*10 + 1; break;
						case '2': second =second*10 + 2; break;
						case '3': second =second*10 + 3; break;
						case '4': second =second*10 + 4; break;
						case '5': second =second*10 + 5; break;
						case '6': second =second*10 + 6; break;
						case '7': second =second*10 + 7; break;
						case '8': second =second*10 + 8; break;
						case '9': second =second*10 + 9; break;
					}
					LCD_VidSendChar(value);
					value = KPD_CHECK;
				}
				else if(value=='=')
				{
					LCD_VidSendChar(value);
					switch(operation)
					{
						case '+' : LCD_VidSendNumberU16((uint16)(first+second));break;
						case '-' : LCD_VidSendNumberU16((uint16)(first-second));break;
						case '*' : LCD_VidSendNumberU16((uint16)(first*second));break;
						case '/' : LCD_VidSendNumberU16((uint16)(first/second));break;
					}
					value = KPD_CHECK;
					first =0 ;second =0;
					break;
				}
			}
			_delay_ms(100);
			//LCD_CLEAR();
	}


return 0;
}
