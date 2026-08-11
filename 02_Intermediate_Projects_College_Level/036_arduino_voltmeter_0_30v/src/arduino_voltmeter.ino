// Arduino Digital Voltmeter (0-30V DC)
const int analogPin = A0;
const float R1 = 30000.0; // 30k Ohm
const float R2 = 7500.0;  // 7.5k Ohm

void setup() {
  Serial.begin(9600);
}

void loop() {
  int rawADC = analogRead(analogPin);
  float vOut = (rawADC * 5.0) / 1023.0;
  float vIn = vOut * ((R1 + R2) / R2);
  
  Serial.print("Measured Voltage: ");
  Serial.print(vIn, 2);
  Serial.println(" V");
  delay(500);
}
