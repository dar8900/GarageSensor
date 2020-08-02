#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

#include <Chrono.h>
#include <Arduino.h>

class COUNTDOWN_TIMER
{
    public:
        void setup(uint32_t &CountDownTimer);
        void checkCountDown(bool Modality, bool &MoveDetected, uint32_t &CountDownTimer, bool &LightState);
};

#endif
