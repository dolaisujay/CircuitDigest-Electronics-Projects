// MPPT Solar Charge Controller (Perturb & Observe)
float vPv, iPv, pPv, pLast = 0;
int dutyCycle = 50;

void loop() {
  // Read V & I from Solar Panel
  pPv = vPv * iPv;
  if (pPv > pLast) dutyCycle++;
  else dutyCycle--;
  pLast = pPv;
  delay(100);
}
