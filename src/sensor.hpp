#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

class Sensor {
public:
    Sensor();
    bool begin();
    float getAccelerationMagnitude();
    float getTemperature();

private:
    Adafruit_MPU6050 mpu;
};

#endif
