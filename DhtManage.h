#ifndef DHT_MANAGE_H
#define DHT_MANAGE_H

#include <Arduino.h>
#include <DHT.h>
#include <Chrono.h>

#define DHTTYPE DHT11
#define DHT_PIN     4

class DHT_MANAGE
{
    public:
        void setup();
        void readData(float &Temp, float &Humidity);
};

#endif