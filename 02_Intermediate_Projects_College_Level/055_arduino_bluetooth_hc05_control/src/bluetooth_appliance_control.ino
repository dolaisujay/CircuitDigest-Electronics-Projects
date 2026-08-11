// Arduino HC-05 Bluetooth Appliance Controller
#include <SoftwareSerial.h>

SoftwareSerial btSerial(10, 11); // RX, TX
const int relay1 = 4;

void setup() {
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, LOW);
  btSerial.begin(9600);
}

void loop() {
  if (btSerial.available()) {
    char cmd = btSerial.read();
    if (cmd == '1') digitalWrite(relay1, HIGH);
    else if (cmd == '0') digitalWrite(relay1, LOW);
  }
}
