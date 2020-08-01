#ifndef BUTTON_MANAGE_H
#define BUTTON_MANAGE_H
#include <Arduino.h>

#define BUTTON_PIN  5

class BUTTON_MANAGE
{
    private:
        typedef enum
        {
            PRESSED = 0,
            SWITCH_PIR_MODE,
            NO_PRESS,
            MAX_BUTTON_STATUS
        }BUTTON_STATUS;

    public:
        void setup();
        void buttonRead();
        void changeModality(bool &Modality);
        void changeLightStatus(bool &LightState);
};

#endif
