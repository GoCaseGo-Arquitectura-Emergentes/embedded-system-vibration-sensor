#include <Wire.h>
#include "Arduino.h"
#include "wifi_utils.hpp"
#include "sensor.hpp"
#include "display.hpp"
#include "http_utils.hpp"

#define DELAY 600

// Umbral de aceleración para detectar un choque
const float shockThreshold = 3.5; // Ajusta este valor según necesites

Sensor sensor;
Display display(0x27, 16, 2);
bool possibleCrash = false;
bool previousCrashState = false;

const char* authToken ; // Reemplaza con tu token de autenticación

void setup() {
    Serial.begin(115200);

    // Iniciar WiFi
    setupWiFi();
    Serial.println("WiFi configurado");

    // Inicializando sensor y display
    Serial.println("Initializing the sensor and display");
    display.init();
    Serial.println("LCD initialized");

    // Inicializa el sensor MPU6050
    if (!sensor.begin()) {
        Serial.println("Failed to initialize MPU6050 sensor");
        display.showShockAlert(-1);  // Usar una temperatura ficticia para indicar error
        while (1) {
            delay(500);
        }
    } else {
        Serial.println("MPU6050 sensor initialized");
    }
    delay(DELAY);
}

void loop() {
    float accMagnitude = sensor.getAccelerationMagnitude();
    float temperature = sensor.getTemperature();

    Serial.print("Magnitud Acel.: ");
    Serial.println(accMagnitude);
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" C");

    possibleCrash = (accMagnitude >= shockThreshold);

    if (possibleCrash != previousCrashState) {
        updateWarning(authToken, possibleCrash);
        previousCrashState = possibleCrash;
    }

    if (possibleCrash) {
        display.showShockAlert(temperature);
    } else {
        display.showNoAlert(temperature);
    }

    delay(100);  // Retardo para la estabilidad de la lectura
}
