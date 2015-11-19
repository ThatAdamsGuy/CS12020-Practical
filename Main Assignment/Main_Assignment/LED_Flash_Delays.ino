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

void charactersInWordLED() {
  delay(3 * timeUnit);
}

void sameCharacterDelayLED() {
  delay(timeUnit);
}
