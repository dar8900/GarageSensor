#include "LogTimeManage.h"
#include "CountDownTimerManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

Chrono LogTime(Chrono::SECONDS);

void LogTimeManage::setup(uint32_t &LogTimer, bool Modality)
{
	oldModality = Modality;
    LogTimer = 0;
}


void LogTimeManage::checkLogTime(bool Modality, bool Movedetected, uint32_t CountDownTimer, uint32_t &LogTimer)
{
    if(Modality == AUTO_MODE)
    {
        if(oldModality != Modality)
        {
            LogTimer = 0;
            oldModality = Modality;
        }
        if(!Movedetected && CountDownTimer == AUTO_ON_LIGHT_TIME)
        {
            if(LogTime.hasPassed(1, true))
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
		if(oldModality != Modality)
        {
            LogTimer = 0;
            oldModality = Modality;
        }
        if(LogTime.hasPassed(1, true))
        {
            LogTimer++;
        }
    }
    
}