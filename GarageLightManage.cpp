#include "GarageLightManage.h"

void GARAGE_LIGHT_MANAGE::initSetup()
{
	dhtSensor.setup();
	displayInfo.setup();
	button.setup();
	light.setup();
	countDownTimer.setup(countDownTime);
	logTimer.setup(logTime);
	pir.setup();
}


void GARAGE_LIGHT_MANAGE::manageLight()
{
	dhtSensor.readData(temperature, humidity);
	button.buttonRead(modality, lightStatus);
	pir.checkMovement(modality, moveDetected);
	light.changeLightState(lightStatus);
	logTimer.checkLogTime(modality, moveDetected, countDownTime, logTime);
	countDownTimer.checkCountDown(modality, moveDetected, countDownTime, lightStatus);
	displayInfo.showLcdInfo(modality, lightStatus, lcdState,logTime, countDownTime, temperature, humidity);
}