// Arduino Digital Frequency Meter
const int pulsePin = 2;
volatile unsigned long count = 0;

void counter() { count++; }

void setup() {
  Serial.begin(9600);
  pinMode(pulsePin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pulsePin), counter, RISING);
}

void loop() {
  count = 0;
  delay(1000);
  Serial.print("Frequency: "); Serial.print(count); Serial.println(" Hz");
}
