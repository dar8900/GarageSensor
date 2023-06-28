#include "PirManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

void PirManage::setup(uint8_t PirPin)
{
    _pin = PirPin;
    pinMode(_pin, INPUT);
}

void PirManage::checkMovement(bool Modality, bool &MoveDetected)
{
    if(Modality == AUTO_MODE)
    {
        if(digitalRead(_pin))
        {
            MoveDetected = true;
        }
    }
    else
    {
        MoveDetected = false;
    }
    
}