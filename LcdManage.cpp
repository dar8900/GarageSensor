#include <Chrono.h>
#include "LcdManage.h"
#include "CountDownTimerManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

#define ON          true
#define OFF         false

Chrono ClearDisplayTimer(Chrono::SECONDS);

static String FormatTime(uint32_t time)
{
	String timeStr = "";
	timeStr = (time / 86400) > 10 ? String(time / 86400) : "0" + String(time / 86400);
	timeStr += "d";
	timeStr += ((time / 3600) / 24) > 10 ? String(((time / 3600) / 24)) : "0" + String(((time / 3600) / 24));
	timeStr += "h";
	timeStr += ((time / 60)  % 60) > 10 ? String(((time / 60)  % 60)) : "0" + String(((time / 60)  % 60));
	timeStr += "m";
	return timeStr;
}


void LCD_MANAGE::setup()
{
	Lcd.begin();
	Lcd.setBackLight(true);
}

void LCD_MANAGE::setState(bool DisplayState)
{
	Lcd.setBackLight(DisplayState);
}

void LCD_MANAGE::shoInfoPirMod(bool Modality)
{
	if(oldModality != Modality)
	{
		Lcd.clearLine(THREE);
		oldModality = Modality;
	}
	stringToStamp = "PIR mode: ";
	if(Modality == AUTO_MODE)
	{
		stringToStamp += "AUTO";
	}
	else
	{
		stringToStamp += "MANUAL";
	}
	Lcd.printString(THREE, CENTER_ALIGN, stringToStamp.c_str());
}

void LCD_MANAGE::showInfoLogTime(uint32_t LogTime)
{
	stringToStamp = "Last log: " + FormatTime(LogTime);
	Lcd.printString(ONE, CENTER_ALIGN, stringToStamp.c_str());
}

void LCD_MANAGE::showInfoCountDownLightState(bool Modality, uint32_t CountTimer, bool LightStatus)
{
	if(Modality == AUTO_MODE)
	{	
		if(oldModality != Modality)
		{
			Lcd.clearLine(FOUR);
			oldModality = Modality;
		}
		if(CountTimer < 10)
		{
			Lcd.clearChar(FOUR, 16);
		}
		stringToStamp = "Spegnimento in: " + String(CountTimer) + "s";
		Lcd.printString(FOUR, LEFT_ALIGN, stringToStamp.c_str());
	}
	else
	{
		if(oldModality != Modality)
		{
			Lcd.clearLine(FOUR);
			oldModality = Modality;
		}
		if(oldLightStatus != LightStatus)
		{
			Lcd.clearLine(FOUR);
			oldLightStatus = LightStatus;
		}
		if(LightStatus == ON)
		{
			stringToStamp = "Luce ACCESA";
		}
		else
		{
			stringToStamp = "Luce SPENTA";
		}
		Lcd.printString(FOUR, CENTER_ALIGN, stringToStamp.c_str());
	}
}

void LCD_MANAGE::showTempSensorData(float Temp, float Humidity)
{
	stringToStamp = String(Temp, 1) + "C" + "  " + String(Humidity, 1) + "%";
	Lcd.printString(TWO, CENTER_ALIGN, stringToStamp.c_str());
}

void LCD_MANAGE::showLcdInfo(bool Modality, bool LightStatus, bool &LcdState, uint32_t LogTime, uint32_t CountTimer, float Temp, float Humidity)
{
	if(CountTimer == AUTO_ON_LIGHT_TIME && Modality == AUTO_MODE)
	{
		LcdState = false;
	}
	else
	{
		LcdState = true;
	}
	
	if(oldLcdState != LcdState)
	{
		setState(LcdState);
		drawDisplay = LcdState;
		Lcd.clearScreen();
		oldLcdState = LcdState;
	}
	
	if(drawDisplay)
	{
		if(ClearDisplayTimer.hasPassed(5, true))
		{
			Lcd.clearScreen();
		}
		shoInfoPirMod(Modality);
		showInfoCountDownLightState(Modality, CountTimer, LightStatus);
		showInfoLogTime(LogTime);
		showTempSensorData(Temp, Humidity);
	}
	else
	{
		ClearDisplayTimer.restart();
	}
	
}