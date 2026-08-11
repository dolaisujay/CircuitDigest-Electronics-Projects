// Arduino Obstacle Avoiding Robot
#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int in1 = 4, in2 = 5, in3 = 6, in4 = 7;

long getDistance() {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.0343 / 2;
}

void setup() {
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
}

void loop() {
  long dist = getDistance();
  if (dist < 20) { // Obstacle ahead
    digitalWrite(in1, LOW); digitalWrite(in2, HIGH); // Reverse & Turn
    digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
    delay(500);
  } else { // Move forward
    digitalWrite(in1, HIGH); digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH); digitalWrite(in4, LOW);
  }
}
