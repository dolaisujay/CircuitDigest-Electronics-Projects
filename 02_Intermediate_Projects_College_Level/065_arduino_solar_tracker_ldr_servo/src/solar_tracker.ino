// Arduino Dual LDR Solar Tracker
#include <Servo.h>

Servo trackerServo;
const int ldrLeft = A0;
const int ldrRight = A1;
int pos = 90;

void setup() {
  trackerServo.attach(9);
  trackerServo.write(pos);
}

void loop() {
  int leftVal = analogRead(ldrLeft);
  int rightVal = analogRead(ldrRight);
  
  if (leftVal - rightVal > 50 && pos > 0) {
    pos--;
    trackerServo.write(pos);
  } else if (rightVal - leftVal > 50 && pos < 180) {
    pos++;
    trackerServo.write(pos);
  }
  delay(30);
}
