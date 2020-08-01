#include "GarageLighManage.h"

NewLCDLib Lcd;
DHT TempSensor(DHT_PIN, DHTTYPE);
TEMP_SENS TempVar;
Chrono TempHumidityTimer(Chrono::SECONDS), RelayTimer(Chrono::SECONDS), LogTime(Chrono::SECONDS);
RELAY_VAR Light;

uint32_t LastLoginTimeStamp;
bool DrawDisplay = false;

static void ReadTempHumidity(bool Init)
{
	if(Init)
	{
		TempVar.temperature = TempSensor.readTemperature();
		TempVar.humidity = TempSensor.readHumidity();
	}
	if(TempHumidityTimer.hasPassed(2, true))
	{
		TempVar.temperature = TempSensor.readTemperature();
		TempVar.humidity = TempSensor.readHumidity();
	}
}

static String FormatTime(uint32_t time)
{
	String timeStr = "";
	timeStr = (time / 86400) > 10 ? String(time / 86400) : "0" + String(time / 86400);
	timeStr += "d";
	timeStr += ((time / 3600) / 24) > 10 ? String(((time / 3600) / 24)) : "0" + String(((time / 3600) / 24));
	timeStr += "h";
	timeStr += ((time / 60)  % 60) > 10 ? String(((time / 60)  % 60)) : "0" + String(((time / 60)  % 60));
	timeStr += "m";
	// timeStr += ((time)  % 60) > 10 ? String(((time)  % 60)) : "0" + String(((time)  % 60));
	// timeStr += "s";
	return timeStr;
}


static uint8_t CheckButton()
{
	uint32_t PressDelay = 0;
	uint8_t ButtonPress = NO_PRESS;
	if(digitalRead(BUTTON_PIN))
	{
		PressDelay = millis();
		while(digitalRead(BUTTON_PIN))
		{
			if(millis() - PressDelay >= 1000)
			{
				ButtonPress = SWITCH_PIR_MODE;
				break;
			}
		}
		if(ButtonPress != SWITCH_PIR_MODE)
		{
			ButtonPress = PRESSED;
		}
	}
	delay(25);
	return ButtonPress;
}


static void SwitchLightStatus()
{
	if(Light.function == MANUAL_MODE)
	{
		if(Light.status == ON)
			digitalWrite(RELAY_PIN, HIGH);
		else
			digitalWrite(RELAY_PIN, LOW);
	}
	else
	{
		if(Light.autoTurnOffTimer == 0)
		{
			if(Light.status == ON)
			{
				digitalWrite(RELAY_PIN, LOW);
				LastLoginTimeStamp = 0;
			}
			Light.status = OFF;
			Light.OldStatus = Light.status;
		}
		else
		{
			if(Light.status == OFF)
				digitalWrite(RELAY_PIN, HIGH);
			Light.status = ON;
			Light.OldStatus = Light.status;
		}
	}
}

static void CheckPir()
{
	if(digitalRead(PIR_PIN) && Light.moveDetected == false && Light.function == AUTO_MODE)
	{
		Light.moveDetected = true;
		Light.autoTurnOffTimer = AUTO_ON_LIGHT_TIME;
	}
	if(Light.autoTurnOffTimer == 0 && Light.status == OFF)
		Light.moveDetected = false;
}

static void DecrementAutoTurnOffTimer()
{
	if(Light.autoTurnOffTimer != 0)
	{
		if(RelayTimer.hasPassed(1, true))
			Light.autoTurnOffTimer--;
	}
	else
		RelayTimer.restart();
}

static void CalcLastLog()
{
	if(Light.function == AUTO_MODE && !Light.moveDetected)
	{
		if(LogTime.hasPassed(1, true))
			LastLoginTimeStamp++;
	}
	else if(Light.function == MANUAL_MODE)
	{
		LastLoginTimeStamp = 0;
		LogTime.restart();
	}
	else
	{
		LogTime.restart();
	}
}

void GesWaitMode()
{
	if(Light.function == AUTO_MODE)
	{
		if(!Light.moveDetected)
		{
			Lcd.clearScreen();
			Lcd.setBackLight(false);
			DrawDisplay = false;
		}
		else
		{
			Lcd.setBackLight(true);
			DrawDisplay = true;
		}
	}
	else
	{
		if(!DrawDisplay)
		{
			DrawDisplay = true;
			Lcd.setBackLight(true);
		}
	}
}

void setup()
{
	Serial.begin(9600);
	pinMode(PIR_PIN, INPUT);
	pinMode(RELAY_PIN, OUTPUT);
	pinMode(BUTTON_PIN, INPUT);
	Lcd.begin();
	TempSensor.begin();
	Light.function = AUTO_MODE;
	Light.moveDetected = false;
	Light.status = OFF;
	ReadTempHumidity(true);
	Lcd.setBackLight(true);
}


void loop()
{
	uint8_t ButtonPress = NO_PRESS;
	ButtonPress = CheckButton();
	if(ButtonPress == PRESSED)
	{
		if(Light.function == MANUAL_MODE)
		{
			Light.status = !Light.status;
			Light.OldStatus = Light.status;
		}
		Lcd.clearLine(FOUR);
	}
	else if(ButtonPress == SWITCH_PIR_MODE)
	{
		(Light.function == AUTO_MODE) ? Light.function = MANUAL_MODE : Light.function = AUTO_MODE;
		if(Light.function == MANUAL_MODE)
		{
			Light.autoTurnOffTimer = 0;
			Light.moveDetected = false;
			Light.status = ON;
		}
		Lcd.clearLine(FOUR);
	}
	SwitchLightStatus();
	ReadTempHumidity(false);
	if(DrawDisplay)
	{
		String StringToStamp = "Last log: " + FormatTime(LastLoginTimeStamp);
		Lcd.printString(ONE, CENTER_ALIGN, StringToStamp.c_str());
		StringToStamp = String(TempVar.temperature, 1) + "C" + "  " + String(TempVar.humidity, 1) + "%";
		Lcd.printString(TWO, CENTER_ALIGN, StringToStamp.c_str());
		if(Light.function == AUTO_MODE)
		{
			if(Light.oldFunction != Light.function)
			{
				Lcd.clearLine(THREE);
				Light.oldFunction = Light.function;
			}
			StringToStamp = "PIR mode: AUTO";
		}
		else
		{
			if(Light.oldFunction != Light.function)
			{
				Lcd.clearLine(THREE);
				Light.oldFunction = Light.function;
			}
			StringToStamp = "PIR mode: MANUAL";
		}
		Lcd.printString(THREE, CENTER_ALIGN, StringToStamp.c_str());
		if(Light.function == AUTO_MODE && Light.status == ON)
		{
			// Stampare il tempo rimanente per lo spegnimento della luce
			StringToStamp = "Spegnimento in: " + String(Light.autoTurnOffTimer) + "s";
			Lcd.printString(FOUR, LEFT_ALIGN, StringToStamp.c_str());
		}
		else if(Light.function == MANUAL_MODE)
		{
			if(Light.status == ON)
			{
				StringToStamp = "Luce ACCESA";
			}
			else
			{
				StringToStamp = "Luce SPENTA";
			}
			Lcd.printString(FOUR, CENTER_ALIGN, StringToStamp.c_str());
		}
	}
	CheckPir();
	DecrementAutoTurnOffTimer();
	SwitchLightStatus();
	CalcLastLog();
	GesWaitMode();
}
