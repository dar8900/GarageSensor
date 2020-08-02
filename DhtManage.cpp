#include "DhtManage.h"

DHT TempSensor(DHT_PIN, DHTTYPE);
Chrono ReadSensorTimer(Chrono::SECONDS);

void DHT_MANAGE::setup()
{
    TempSensor.begin();
}

void DHT_MANAGE::readData(float &Temp, float &Humidity)
{
    if(ReadSensorTimer.hasPassed(5, true))
    {
        Temp = TempSensor.readTemperature();
        Humidity = TempSensor.readHumidity();
    }
}