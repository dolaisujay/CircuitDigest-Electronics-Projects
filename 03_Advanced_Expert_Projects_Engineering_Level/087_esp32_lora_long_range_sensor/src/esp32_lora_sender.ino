// ESP32 LoRa Long-Range Sender
#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(115200);
  if (!LoRa.begin(915E6)) {
    Serial.println("LoRa Init Failed!");
    while (1);
  }
}

void loop() {
  LoRa.beginPacket();
  LoRa.print("Telemetry Packet");
  LoRa.endPacket();
  delay(5000);
}
