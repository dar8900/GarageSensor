#include "ButtonManage.h"

#define AUTO_MODE   true
#define MANUAL_MODE false

#define ON          true
#define OFF         false

void BUTTON_MANAGE::setup()
{
    pinMode(BUTTON_PIN, INPUT);
}

void BUTTON_MANAGE::buttonRead(bool &Modality, bool &LightState, uint32_t &PowerUpTimes)
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
				wasLongPressed = true;
				break;
			}
		}
		if(ButtonPress != SWITCH_PIR_MODE)
		{
			if(!wasLongPressed)
				ButtonPress = PRESSED;
			else
			{
				wasLongPressed = false;
			}
				
		}
	}
	delay(25);
    if(ButtonPress == SWITCH_PIR_MODE)
    {
        Modality = !Modality;
		if(Modality == AUTO_MODE)
		{
			PowerUpTimes = 0;
			LightState = OFF;
		}
    }
    else if(ButtonPress == PRESSED)
    {
        if(Modality == MANUAL_MODE)
        {
            LightState = !LightState;
        }
    }
    
}