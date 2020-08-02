#include "ButtonManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

#define ON          true
#define OFF         false

void BUTTON_MANAGE::setup()
{
    pinMode(BUTTON_PIN, INPUT);
}

void BUTTON_MANAGE::buttonRead(bool &Modality, bool &LightState)
{
    uint32_t PressDelay = 0;
	uint8_t ButtonPress = NO_PRESS;
	if(digitalRead(BUTTON_PIN))
	{
		PressDelay = millis();
		while(digitalRead(BUTTON_PIN))
		{
			if(millis() - PressDelay >= 1000)
			{
				ButtonPress = SWITCH_PIR_MODE;
				break;
			}
		}
		if(ButtonPress != SWITCH_PIR_MODE)
		{
			ButtonPress = PRESSED;
		}
	}
	delay(25);
    if(ButtonPress == SWITCH_PIR_MODE)
    {
        Modality = !Modality;
    }
    else if(ButtonPress == PRESSED)
    {
        if(Modality == MANUAL_MODE)
        {
            LightState = !LightState;
        }
    }
    
}