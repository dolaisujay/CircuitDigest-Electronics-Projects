// Arduino Pulse / Heart Rate Monitor
const int pulsePin = A0;
int threshold = 550;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(pulsePin);
  if (val > threshold) {
    Serial.println("HEARTBEAT!");
  }
  delay(20);
}
