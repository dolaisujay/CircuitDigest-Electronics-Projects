// ESP32 BLE Beacon Transmitter
#include <BLEDevice.h>
#include <BLEUtils.h>

void setup() {
  BLEDevice::init("ESP32_BLE_Beacon");
  BLEServer *pServer = BLEDevice::createServer();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

void loop() {
  delay(2000);
}
