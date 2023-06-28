#ifndef PIR_MANAGE_H
#define PIR_MANAGE_H

#include <Arduino.h>

class PirManage
{
    public:
        void setup(uint8_t PirPin);
        void checkMovement(bool Modality, bool &MoveDetected);
    private:
        uint8_t _pin;
};

#endif