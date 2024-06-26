#include "http_utils.hpp"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#define SENSOR_ID 1
const char* authServerAddress = "https://equipatour.osc-fr1.scalingo.io/api/iot/logger/token";
const char* serverUpdate = "https://equipatour.osc-fr1.scalingo.io/api/v1/vibration-sensors/update-vibration-sensor/";

void checkResponseCode(int httpResponseCode) {
  if (httpResponseCode == 200) {
    Serial.println("Successfully updated on the server.");
  } else {
    Serial.print("Request error. HTTP response code:");
    Serial.println(httpResponseCode);
  }
}

void updateWarning(const char* authToken, bool possibleCrash, int resourceId = SENSOR_ID) {
  HTTPClient http;
  http.begin(serverUpdate + String(resourceId));
  http.addHeader("Content-Type", "application/json");
  String authHeader = "Bearer " + String(authToken);
  http.addHeader("Authorization", authHeader);

  String requestBody = "{\"hasPossibleCrashWarning\": " + String(possibleCrash) + "}";
  int httpResponseCode = http.PUT(requestBody);

  if (httpResponseCode == 200) {
    String response = http.getString();
    Serial.println("Successful request");
  } else {
    Serial.print("Error on HTTP request. Response code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}
