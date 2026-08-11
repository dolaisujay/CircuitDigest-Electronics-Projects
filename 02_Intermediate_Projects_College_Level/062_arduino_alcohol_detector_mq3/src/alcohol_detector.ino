// Arduino MQ-3 Alcohol Detector Alarm
const int mq3Pin = A0;
const int buzzerPin = 8;
const int threshold = 400;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(mq3Pin);
  Serial.print("Alcohol Level: "); Serial.println(sensorVal);
  if (sensorVal > threshold) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(300);
}
