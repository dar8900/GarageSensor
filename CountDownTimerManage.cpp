#include "CountDownTimerManage.h"

#define AUTO_ON_LIGHT_TIME  60
#define AUTO_MODE   true
#define MANUAL_MODE false
#define ON          true
#define OFF         false

Chrono CountTimer(Chrono::SECONDS);

void COUNTDOWN_TIMER::setup(uint32_t &CountDownTimer)
{
    CountDownTimer = 0;
}

void COUNTDOWN_TIMER::checkCountDown(bool Modality, bool &MoveDetected, uint32_t &CountDownTimer, bool &LightState)
{
    if(Modality == AUTO_MODE)
    {
        if(MoveDetected)
        {
            if(CountTimer.hasPassed(1, true) && CountDownTimer > 0)
            {
                CountDownTimer--;
                LightState = ON;
            }
            else if(CountDownTimer == 0)
            {
                LightState = OFF;
                MoveDetected = false;
            }
        }
        else
        {
            CountDownTimer = AUTO_ON_LIGHT_TIME;
            CountTimer.restart();
        }
        
    }
    else
    {
        CountDownTimer = AUTO_ON_LIGHT_TIME;
        CountTimer.restart();
    }
    
}