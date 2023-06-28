#include "PirManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

void PirManage::setup()
{
    pinMode(PIR_PIN, INPUT);
}

void PirManage::checkMovement(bool Modality, bool &MoveDetected)
{
    if(Modality == AUTO_MODE)
    {
        if(digitalRead(PIR_PIN))
        {
            MoveDetected = true;
        }
    }
    else
    {
        MoveDetected = false;
    }
    
}