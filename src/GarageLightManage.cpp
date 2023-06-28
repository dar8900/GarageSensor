#include "GarageLightManage.h"

void GarageLightManage::initSetup()
{
	dhtSensor.setup();
	displayInfo.setup();
	button.setup();
	light.setup();
	countDownTimer.setup(countDownTime);
	logTimer.setup(logTime, modality);
	pir.setup();
}


void GarageLightManage::manageLight()
{
	dhtSensor.readData(temperature, humidity);
	button.buttonRead(modality, lightStatus, powerUpTimes);
	pir.checkMovement(modality, moveDetected);
	light.changeLightState(lightStatus, powerUpTimes);
	logTimer.checkLogTime(modality, moveDetected, countDownTime, logTime);
	countDownTimer.checkCountDown(modality, moveDetected, countDownTime, lightStatus);
	displayInfo.showLcdInfo(modality, lightStatus, lcdState,logTime, countDownTime, temperature, humidity, powerUpTimes);
}