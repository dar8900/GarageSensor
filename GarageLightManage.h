#ifndef GARAGE_SENSOR_H
#define GARAGE_SENSOR_H

#include <Arduino.h>

#include <EEPROM.h>

#include "LcdManage.h"
#include "ButtonManage.h"
#include "CountDownTimerManage.h"
#include "DhtManage.h"
#include "LightManage.h"
#include "LogTimeManage.h"
#include "PirManage.h"



#define DEBUG

#ifdef DEBUG
#define DBG(msg) Serial.println(msg)
#else
#define DBG(msg)
#endif


class GARAGE_LIGHT_MANAGE
{
	private:
		LCD_MANAGE displayInfo;
		BUTTON_MANAGE button;
		COUNTDOWN_TIMER countDownTimer;
		DHT_MANAGE dhtSensor;
		LIGHT_MANAGE light;
		LOG_TIME_MANAGE logTimer;
		PIR_MANAGE pir;
	
	public:
    	bool modality;
		bool moveDetected;
    	bool lightStatus;
		uint32_t logTime;
		uint32_t countDown;
		float temperature;
		float humidity;
		initSetup();
		manageLight();
    

};


#endif
