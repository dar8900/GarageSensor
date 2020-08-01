#ifndef LOG_TIME_MANAGE_H
#define LOG_TIME_MANAGE_H

#include <Chrono.h>
#include <Arduino.h>

class LOG_TIME_MANAGE
{
    public:
        void setup(uint32_t &LogTimer);
        void checkLogTime(bool Modality, bool Movedetected, uint32_t CountDownTimer, uint32_t &LogTimer);
};

#endif