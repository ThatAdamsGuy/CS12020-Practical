void equalsLED() {
  digitalWrite(BLUELED, HIGH);
  delay (2 * timeUnit);
  digitalWrite(BLUELED, LOW);
}

void dollarLED() {
  digitalWrite(BLUELED, HIGH);
  delay(4 * timeUnit);
  digitalWrite(BLUELED, LOW);
}

void upLED() {
  digitalWrite(BLUELED, HIGH);
  delay(timeUnit);
  digitalWrite(BLUELED, LOW);
}

void spaceLED() {
  delay(5 * timeUnit);
}

void slashLED() {
  delay(3 * timeUnit);
}

void errorLED() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(REDLED, HIGH);
    delay(200);
    digitalWrite(REDLED, LOW);
    delay(200);
  }
}

