// Arduino Capacitance Meter
const int analogPin = A0;
const float resistor = 10000.0; // 10k resistor
unsigned long startTime;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Charge capacitor and measure time constant tau = R*C
  delay(1000);
}
