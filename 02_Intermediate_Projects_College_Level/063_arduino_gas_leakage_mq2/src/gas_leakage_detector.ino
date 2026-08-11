// Arduino MQ-2 Gas Leakage Alarm
const int mq2Pin = A0;
const int alarmPin = 7;

void setup() {
  pinMode(alarmPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(mq2Pin);
  if (val > 350) digitalWrite(alarmPin, HIGH);
  else digitalWrite(alarmPin, LOW);
  delay(500);
}
