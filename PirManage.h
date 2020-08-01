#ifndef PIR_MANAGE_H
#define PIR_MANAGE_H

#include <Arduino.h>

#define PIR_PIN     2

class PIR_MANAGE
{
    public:
        void setup();
        void checkMovement(bool Modality, bool &MoveDetected);
};

#endif