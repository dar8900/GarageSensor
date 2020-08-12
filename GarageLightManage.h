#ifndef GARAGE_LIGHT_MANAGE_H
#define GARAGE_LIGHT_MANAGE_H

#include <Arduino.h>

#include <EEPROM.h>

#include "LcdManage.h"
#include "ButtonManage.h"
#include "CountDownTimerManage.h"
#include "DhtManage.h"
#include "LightManage.h"
#include "LogTimeManage.h"
#include "PirManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

#define ON          true
#define OFF         false

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

		bool modality = AUTO_MODE;
		bool moveDetected;
    	bool lightStatus = OFF;
		bool lcdState;
		uint32_t logTime;
		uint32_t countDownTime;
		float temperature;
		float humidity;
	
	public:

		void initSetup();
		void manageLight();
    

};


#endif
