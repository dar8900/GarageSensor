#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

#include <Chrono.h>
#include <Arduino.h>

class COUNTDOWN_TIMER
{
    public:
        void setup();
        void checkCountDown(bool Modality, uint32_t &CountDownTimer);
};

#endif
