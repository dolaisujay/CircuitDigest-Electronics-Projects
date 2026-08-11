// Arduino L298N DC Motor Control
const int in1 = 4;
const int in2 = 5;
const int ena = 3;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
}

void loop() {
  // Forward @ 75% speed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 190);
  delay(2000);
  
  // Reverse @ 50% speed
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 128);
  delay(2000);
}
