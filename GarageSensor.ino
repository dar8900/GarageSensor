#include "GarageSensor.h"

NewLCDLib Lcd;
DHT TempSensor(DHT_PIN, DHTTYPE);
TEMP_SENS TempVar;
Chrono TempHumidityTimer(Chrono::SECONDS), RelayTimer(Chrono::SECONDS);
RELAY_VAR Light;

uint32_t LastLoginTimeStamp;

static void ReadTempHumidity()
{
	if(TempHumidityTimer.hasPassed(5, true))
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
	timeStr += "s";
	return timeStr;
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
}


void loop()
{
	String StringToStamp = "Last log: " + FormatTime(LastLoginTimeStamp);
	Lcd.printString(ONE, CENTER_ALIGN, StringToStamp.c_str());
	StringToStamp = String(TempVar.temperature, 1) + "C" + "  " + String(TempVar.humidity, 1) + "%";
	Lcd.printString(TWO, CENTER_ALIGN, StringToStamp.c_str());
	if(Light.function == AUTO_MODE)
		StringToStamp = "PIR mode: AUTO";
	else
		StringToStamp = "PIR mode: MANUAL";
	Lcd.printString(THREE, CENTER_ALIGN, StringToStamp.c_str());
	if(Light.function == AUTO_MODE && Light.status == ON)
	{
		// Stampare il tempo rimanente per lo spegnimento della luce
		// Lcd.printString(FOUR, CENTER_ALIGN, LastLogin.c_str());
	}
}
