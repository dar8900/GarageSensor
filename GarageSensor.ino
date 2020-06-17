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

}

void setup()
{
	Serial.begin(9600);
	pinMode(PIR_PIN, INPUT);
	pinMode(RELAY_PIN, OUTPUT);
	pinMode(BUTTON_PIN, INPUT);
	Lcd.begin();
	TempSensor.begin();
	Ligh.function = AUTO_MODE;
	Ligh.moveDetected = false;
	Light.status = OFF;
}


void loop()
{
	String LastLogin = "Last log: "
	Lcd.printString(ONE, CENTER_ALIGN, )
}
