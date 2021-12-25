#include "processimages.h"

ProcessImages::ProcessImages()
{
     pRTIMUSettings = new RTIMUSettings("RTIMULib");
     pRTIMU = RTIMU::createIMU(pRTIMUSettings);
     pRTPressure = RTPressure::createPressure(pRTIMUSettings);
     pRTHumidity = RTHumidity::createHumidity(pRTIMUSettings);

     ReadWriterLook = new QReadWriteLock();

     if ((pRTIMU != nullptr) && (pRTIMU->IMUType() != RTIMU_TYPE_NULL) &&
     (pRTPressure != nullptr) && (pRTHumidity != nullptr))
     {
        pRTIMU->IMUInit();
        pRTIMU->setCompassEnable(true);
        pRTPressure->pressureInit();
        pRTHumidity->humidityInit();
     }
     else
     {
        bInitFlag = false;
     }
}

ProcessImages::~ProcessImages()
{
    if(ReadWriterLook != nullptr)
        delete ReadWriterLook;
}

bool ProcessImages::vReadProcessImage(void)
{
    if (bInitFlag)
    {
        if (pRTIMU->IMURead())
        {
            ReadWriterLook->lockForWrite();
            RTIMU_DATA RTIMUData = pRTIMU->getIMUData();
            pRTPressure->pressureRead(RTIMUData);
            pRTHumidity->humidityRead(RTIMUData);

            if(RTIMUData.pressureValid)
            {
                fAirPressur = RTIMUData.pressure;
            }

            if(RTIMUData.temperatureValid)
            {
                fTemperature = RTIMUData.temperature;
            }

            if(RTIMUData.humidityValid)
            {
                fHumidity = RTIMUData.humidity;
            }

            RTIMUData.compass.normalize();

            if(RTIMUData.compassValid)
            {
                fxMagnetometer = RTIMUData.compass.x();
                fyMagnetometer = RTIMUData.compass.y();
                fzMagnetometer = RTIMUData.compass.z();
            }
            ReadWriterLook->unlock();
        }
    }
 return bInitFlag;
}

bool ProcessImages::getInitFlag(void)
{
    return bInitFlag;
}
void ProcessImages::setInitFlag(bool init)
{
    bInitFlag = init;
}

float ProcessImages::getTemperature(void)
{
    return fTemperature;
}
void ProcessImages::setTemperature(float temp)
{
    fTemperature = temp;
}

float ProcessImages::getAirPressur(void)
{
    return fAirPressur;
}
void ProcessImages::setAirPressur(float Air)
{
    fAirPressur = Air;
}

float ProcessImages::getHumidity(void)
{
    return fHumidity;
}
void ProcessImages::setHumidity(float Humidity)
{
    fHumidity = Humidity;
}

float ProcessImages::getMagnetometerX(void)
{
    return fxMagnetometer;
}
void ProcessImages::setMagnetometerX(float x)
{
    fxMagnetometer = x;
}

float ProcessImages::getMagnetometerY(void)
{
    return fyMagnetometer;
}
void ProcessImages::setMagnetometerY(float y)
{
    fyMagnetometer = y;
}

float ProcessImages::getMagnetometerZ(void)
{
    return fzMagnetometer;
}
void ProcessImages::setMagnetometerZ(float value)
{
    fzMagnetometer = value;
}
