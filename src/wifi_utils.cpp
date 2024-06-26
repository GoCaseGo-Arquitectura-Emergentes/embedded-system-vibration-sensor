#include <WiFi.h>
#include "wifi_utils.hpp"

// Credenciales WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setupWiFi() {
    Serial.println("Starting WiFi setup...");
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" Connected to WiFi");
}
