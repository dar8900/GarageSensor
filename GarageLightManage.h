#ifndef GARAGE_SENSOR_H
#define GARAGE_SENSOR_H

#include <Arduino.h>

#include <Chrono.h>
#include <DHT.h>

#include <EEPROM.h>
#include <Wire.h>


#define DEBUG

#ifdef DEBUG
#define DBG(msg) Serial.println(msg)
#else
#define DBG(msg)
#endif

#define DHTTYPE DHT11

#define PIR_PIN     2
#define RELAY_PIN   3
#define DHT_PIN     4
#define BUTTON_PIN  5

#define AUTO_MODE   true
#define MANUAL_MODE false

#define ON          true
#define OFF         false

#define AUTO_ON_LIGHT_TIME  60

typedef enum
{
    PRESSED = 0,
    SWITCH_PIR_MODE,
    NO_PRESS,
    MAX_BUTTON_STATUS
}BUTTON_STATUS;

typedef struct
{
  float temperature;
  float humidity;
}TEMP_SENS;

typedef struct
{
    bool function;
    bool oldFunction;
    bool moveDetected;
    bool status;
    bool OldStatus;
    uint32_t autoTurnOffTimer;
}RELAY_VAR;

class GARAGE_LIGHT_MANAGE
{
	private:
		bool modality;
		bool moveDetected;
		uint32_t logTime;
		uint32_t countDown;
		float temperature;
		float humidity;
	
	public:
		initSetup();
		manageLight();

};


#endif