#include "LightManage.h"

#define ON          true
#define OFF         false

#define AUTO_MODE   true
#define MANUAL_MODE false

void LIGHT_MANAGE::setup()
{
    pinMode(RELAY_PIN, OUTPUT);
}

void LIGHT_MANAGE::changeLightState(bool LightStatus)
{
    if(LightStatus == ON)
    {
        digitalWrite(RELAY_PIN, HIGH);
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW);
    }   
}