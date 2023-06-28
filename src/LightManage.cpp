#include "LightManage.h"

#define ON          true
#define OFF         false

#define AUTO_MODE   true
#define MANUAL_MODE false

void LightManage::setup()
{
    pinMode(RELAY_PIN, OUTPUT);
}

void LightManage::changeLightState(bool LightStatus, uint32_t &PowerUpTimes)
{
    if(LightStatus == ON)
    {
        digitalWrite(RELAY_PIN, HIGH);
        PowerUpTimes++;
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW);
    }   
}