#ifndef LIGHT_MANAGE_H
#define LIGHT_MANAGE_H

#include <Arduino.h>

#define RELAY_PIN   3

class LIGHT_MANAGE
{
    private:
        bool oldLightStatus;
    public:
        void setup();
        void changeLightState(bool LightStatus, uint32_t &PowerUpTimes);
};

#endif