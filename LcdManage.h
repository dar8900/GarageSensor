#ifndef LCD_MANAGE_H
#define LCD_MANAGE_H

#include <Arduino.h>
#include <NewLCDLib.h>
#include <LiquidCrystal_I2C.h> // Libreria LCD I2C

class LCD_MANAGE
{
    private:
        bool oldModality;
        bool oldLightStatus;
		bool oldLcdState;
        bool drawDisplay;
        bool showLogTime = true;
        void setState(bool DisplayState);
        void shoInfoPirMod(bool Modality);
        void showInfoLogTime(uint32_t LogTime, bool Modality, uint32_t PowerOnTimes);
        void showInfoCountDownLightState(bool Modality, uint32_t CountTimer, bool LightStatus);
        void showTempSensorData(float Temp, float Humidity);
        String stringToStamp;
        NewLCDLib Lcd;
    public:
        void setup();
        void showLcdInfo(bool Modality,  bool LightStatus, bool &LcdState, uint32_t LogTime, uint32_t CountTimer, float Temp, float Humidity, uint32_t PowerUpTimes);

                
};
#endif