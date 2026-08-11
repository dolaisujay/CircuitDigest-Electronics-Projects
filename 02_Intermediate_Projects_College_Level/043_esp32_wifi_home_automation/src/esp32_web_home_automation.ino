// ESP32 Wi-Fi Home Automation Web Server
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);
const int relayPin = 26;

void handleRoot() {
  String html = "<html><body><h1>ESP32 Home Automation</h1>";
  html += "<p><a href='/on'><button>Turn ON</button></a></p>";
  html += "<p><a href='/off'><button>Turn OFF</button></a></p></body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  
  server.on("/", handleRoot);
  server.on("/on", []() { digitalWrite(relayPin, HIGH); server.send(200, "text/html", "Relay ON"); });
  server.on("/off", []() { digitalWrite(relayPin, LOW); server.send(200, "text/html", "Relay OFF"); });
  server.begin();
}

void loop() {
  server.handleClient();
}
