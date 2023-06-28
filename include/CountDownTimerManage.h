#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

#include <Chrono.h>
#include <Arduino.h>

#define AUTO_ON_LIGHT_TIME  60

class COUNTDOWN_TIMER
{
    public:
        void setup(uint32_t &CountDownTimer);
        void checkCountDown(bool Modality, bool &MoveDetected, uint32_t &CountDownTimer, bool &LightState);
};

#endif
