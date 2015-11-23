//Gives an indication that the program has started
//Also a little bit of fun with time left at the end.
//Plus voidSetup was looking kinda dull...

void startupFlash() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(BLUELED, HIGH);
    delay (100);
    digitalWrite(BLUELED, LOW);
    digitalWrite(GREENLED, HIGH);
    delay (100);
    digitalWrite(GREENLED, LOW);
    digitalWrite(YELLOWLED, HIGH);
    delay (100);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(ORANGELED, HIGH);
    delay (100);
    digitalWrite(ORANGELED, LOW);
    digitalWrite(REDLED, HIGH);
    delay (100);
    digitalWrite(REDLED, LOW);
  }
  for (int k = 0; k < 2; k++) {
    digitalWrite(BLUELED, HIGH);
    digitalWrite(GREENLED, HIGH);
    digitalWrite(YELLOWLED, HIGH);
    digitalWrite(ORANGELED, HIGH);
    digitalWrite(REDLED, HIGH);
    delay(500);
    digitalWrite(BLUELED, LOW);
    digitalWrite(GREENLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(ORANGELED, LOW);
    digitalWrite(REDLED, LOW);    delay(500);
  }
}
