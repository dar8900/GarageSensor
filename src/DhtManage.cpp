#include "DhtManage.h"

DHT TempSensor(DHT_PIN, DHTTYPE);
Chrono ReadSensorTimer(Chrono::SECONDS);

void DhtManage::setup()
{
    TempSensor.begin();
}

void DhtManage::readData(float &Temp, float &Humidity)
{
    if(ReadSensorTimer.hasPassed(5, true))
    {
        Temp = TempSensor.readTemperature();
        Humidity = TempSensor.readHumidity();
    }
}