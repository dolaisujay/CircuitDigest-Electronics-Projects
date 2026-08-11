// Automatic Room Visitor Counter
const int irIn = 2;
const int irOut = 3;
int visitorCount = 0;

void setup() {
  pinMode(irIn, INPUT);
  pinMode(irOut, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(irIn) == LOW) {
    visitorCount++;
    Serial.print("Visitors in Room: "); Serial.println(visitorCount);
    delay(500);
  }
  if (digitalRead(irOut) == LOW && visitorCount > 0) {
    visitorCount--;
    Serial.print("Visitors in Room: "); Serial.println(visitorCount);
    delay(500);
  }
}
