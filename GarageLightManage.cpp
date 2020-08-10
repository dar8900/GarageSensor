#include "GarageLightManage.h"

void GARAGE_LIGHT_MANAGE::initSetup()
{
	displayInfo.setup();
	button.setup();
	countDownTimer.setup(countDownTime);
	dhtSensor.setup();
	light.setup();
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
	displayInfo.showLcdInfo(modality, lightStatus, logTime, countDownTime, temperature, humidity);
}