#include "sensor.hpp"
#include <Wire.h>
#include <math.h>

Sensor::Sensor() {}

bool Sensor::begin() {
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    return mpu.begin();
}

float Sensor::getAccelerationMagnitude() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return sqrt(a.acceleration.x * a.acceleration.x + 
                a.acceleration.y * a.acceleration.y + 
                a.acceleration.z * a.acceleration.z);
}

float Sensor::getTemperature() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    return temp.temperature;
}
