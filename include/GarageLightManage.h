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


class GarageLightManage
{
	private:
		LcdManage displayInfo;
		ButtonManage button;
		COUNTDOWN_TIMER countDownTimer;
		DhtManage dhtSensor;
		LightManage light;
		LogTimeManage logTimer;
		PirManage pir;

		bool modality = AUTO_MODE;
		bool moveDetected;
    	bool lightStatus = OFF;
		bool lcdState;
		uint32_t logTime;
		uint32_t countDownTime;
		uint32_t powerUpTimes;
		float temperature;
		float humidity;
	
	public:

		void initSetup();
		void manageLight();
    

};


#endif
