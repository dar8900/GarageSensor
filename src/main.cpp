#include "GarageLightManage.h"

GarageLightManage GarageLight;

void setup()
{
	GarageLight.initSetup();
}


void loop()
{
	GarageLight.manageLight();
}