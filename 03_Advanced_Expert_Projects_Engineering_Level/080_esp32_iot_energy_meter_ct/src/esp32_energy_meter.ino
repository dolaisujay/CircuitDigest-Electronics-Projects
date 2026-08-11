// ESP32 Energy Meter SCT-013 CT Sensor
#include "EmonLib.h"
EnergyMonitor emon1;

void setup() {
  Serial.begin(115200);
  emon1.current(34, 60.6); // ADC Pin 34, calibration factor
}

void loop() {
  double Irms = emon1.calcIrms(1480);
  double Power = Irms * 230.0;
  Serial.print("Power: "); Serial.print(Power); Serial.println(" W");
  delay(2000);
}
