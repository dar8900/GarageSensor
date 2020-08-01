#include "LcdManage.h"

void LCD_MANAGE::setup()
{
	Lcd.begin();
	Lcd.setBackLight(true);
}