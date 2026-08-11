// Arduino Servo Motor Control
#include <Servo.h>

Servo myServo;
const int potPin = A0;

void setup() {
  myServo.attach(9);
}

void loop() {
  int potVal = analogRead(potPin);
  int angle = map(potVal, 0, 1023, 0, 180);
  myServo.write(angle);
  delay(15);
}
