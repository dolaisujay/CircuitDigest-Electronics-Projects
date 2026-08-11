// ESP8266 Telegram Alert Notifier
#include <ESP8266WiFi.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void loop() {
  // Read sensor and send HTTP request to Telegram Bot API
  delay(10000);
}
