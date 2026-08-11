// ESP8266 Smart Plug Relay Control
#include <ESP8266WiFi.h>

const int relayPin = 12; // GPIO12

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}

void loop() {
  digitalWrite(relayPin, HIGH); // Turn ON load
  delay(5000);
  digitalWrite(relayPin, LOW);  // Turn OFF load
  delay(5000);
}
