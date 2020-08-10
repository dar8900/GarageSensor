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
        bool drawDisplay;
        void setState(bool DisplayState);
        void shoInfoPirMod(bool Modality);
        void showInfoLogTime(uint32_t LogTime);
        void showInfoCountDownLightState(bool Modality, uint32_t CountTimer, bool LightStatus);
        void showTempSensorData(float Temp, float Humidity);
        String stringToStamp;
        NewLCDLib Lcd;
    public:
        void setup();
        void showLcdInfo(bool Modality,  bool LightStatus, uint32_t LogTime, uint32_t CountTimer, float Temp, float Humidity);

                
};
#endif