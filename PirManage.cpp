#include "PirManage.cpp"

#define AUTO_MODE   true
#define MANUAL_MODE false

void PIR_MANAGE::setup()
{
    pinMode(PIR_PIN, INPUT);
}

void PIR_MANAGE::checkMovement(bool Modality, bool &MoveDetected)
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