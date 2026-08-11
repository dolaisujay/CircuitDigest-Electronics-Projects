// Automatic Plant Watering System
const int sensorPin = A0;
const int relayPin = 7;
const int dryThreshold = 600;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Relay OFF (Active LOW)
  Serial.begin(9600);
}

void loop() {
  int moisture = analogRead(sensorPin);
  Serial.print("Soil Moisture: "); Serial.println(moisture);
  
  if (moisture > dryThreshold) {
    digitalWrite(relayPin, LOW);  // Turn ON pump
    delay(3000);                  // Water for 3 seconds
    digitalWrite(relayPin, HIGH); // Turn OFF pump
  }
  delay(5000);
}
