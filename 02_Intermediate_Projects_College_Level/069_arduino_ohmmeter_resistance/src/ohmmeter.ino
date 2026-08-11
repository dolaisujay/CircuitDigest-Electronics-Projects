// Arduino Digital Ohmmeter
const int analogPin = A0;
const float knownResistor = 1000.0; // 1k Known Resistor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(analogPin);
  if (raw) {
    float buffer = raw * 5.0 / 1023.0;
    float rx = knownResistor * ((5.0 / buffer) - 1.0);
    Serial.print("Rx: "); Serial.print(rx); Serial.println(" Ohms");
  }
  delay(1000);
}
