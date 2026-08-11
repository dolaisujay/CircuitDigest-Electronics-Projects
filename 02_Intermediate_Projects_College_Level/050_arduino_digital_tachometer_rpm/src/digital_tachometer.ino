// Arduino Digital Tachometer (RPM Counter)
const int irSensorPin = 2;
volatile unsigned int pulseCount = 0;
unsigned long lastMillis = 0;

void countPulse() {
  pulseCount++;
}

void setup() {
  Serial.begin(9600);
  pinMode(irSensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(irSensorPin), countPulse, RISING);
}

void loop() {
  if (millis() - lastMillis >= 1000) {
    detachInterrupt(digitalPinToInterrupt(irSensorPin));
    float rpm = (pulseCount * 60.0);
    Serial.print("Motor RPM: "); Serial.println(rpm);
    pulseCount = 0;
    lastMillis = millis();
    attachInterrupt(digitalPinToInterrupt(irSensorPin), countPulse, RISING);
  }
}
