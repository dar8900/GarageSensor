#ifndef LCD_MANAGE_H
#define LCD_MANAGE_H

#include <Arduino.h>
#include <NewLCDLib.h>
#include <LiquidCrystal_I2C.h> // Libreria LCD I2C

class LCD_MANAGE
{
    private:
        NewLCDLib Lcd;
    public:
        void setup();
        void setState(bool DisplayState);
        void shoInfoPirMod(bool Modality);
        void showInfoLogTime(uint32_t LogTime);
        void showInfoCountDown(uint32_t CountTimer);
        void showTempSensorData(float Temp, float Humidity);
                
};
#endif