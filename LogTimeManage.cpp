#include "LogTimeManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

Chrono LogTime(Chrono::SECONDS);

void LOG_TIME_MANAGE::setup(uint32_t &LogTimer)
{
    LogTimer = 0;
}


void LOG_TIME_MANAGE::checkLogTime(bool Modality, bool Movedetected, uint32_t CountDownTimer, uint32_t &LogTimer)
{
    if(Modality == AUTO_MODE)
    {
        if(!Movedetected && CountDownTimer == 0)
        {
            if(LogTime.hasPassed(1))
            {
                LogTimer++;
            }
        }
        else
        {
            if(CountDownTimer == 0)
            {
                LogTimer = 0;
            }
        }
    }
    else
    {
        LogTimer = 0;
        LogTime.restart();
    }
    
}