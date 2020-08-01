#ifndef LCD_MANAGE_H
#define LCD_MANAGE_H

#include <NewLCDLib.h>
#include <LiquidCrystal_I2C.h> // Libreria LCD I2C

class LCD_MANAGE
{
    public:
        setup();
        setState(bool DisplayState);
        shoInfoPirMod(bool Modality);
        
};
#endif