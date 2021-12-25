#ifndef PROCESSIMAGES_H
#define PROCESSIMAGES_H

#include "RTIMULib.h"
#include<QReadWriteLock>

class ReadData
{
private:
    bool bInitFlag = true;

    float fTemperature = 0.1f;
    float fAirPressur = 0.1f;
    float fHumidity = 0.1f;
    float fxMagnetometer = 0.1f;
    float fyMagnetometer = 0.1f;
    float fzMagnetometer = 0.1f;

    RTIMUSettings* pRTIMUSettings = nullptr;
    RTIMU* pRTIMU = nullptr;
    RTPressure* pRTPressure = nullptr;
    RTHumidity* pRTHumidity = nullptr;

    QReadWriteLock* ReadWriterLook = nullptr;

public:
    ProcessImages();
    ~ProcessImages();
    bool vReadProcessImage(void);

    //Getter Setter Methodes
    bool getInitFlag();
    float getTemperature();
    float getAirPressur();
    float getHumidity();
    float getMagnetometerX();
    float getMagnetometerY();
    float getMagnetometerZ();

    void setInitFlag(bool init);
    void setTemperature(float temp);
    void setAirPressur(float Air);
    void setHumidity(float humidity);
    void setMagnetometerX(float x);
    void setMagnetometerY(float y);
    void setMagnetometerZ(float z);
};

#endif // PROCESSIMAGES_H
