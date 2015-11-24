void checkForCommand() {
  int commandASCIILength = commandASCII.length();
  //Checks if the input starts LP
  if (commandASCII.charAt(0) == 'L' && commandASCII.charAt(1) == 'P' && commandASCIILength == 14) {
    Serial.println("Checking for the LP command");
    for (int i = 2; i < 12; i++) {  //For all the "digits" in the input
      int checkDigit = commandASCII.charAt(i);
      if (isdigit(checkDigit)) { //Checks that each digit is, in fact, a digit
        checkLPDigits = 1;  //If it's a digit, boolean is true.
#ifdef DEBUG
        Serial.println(checkLPDigits);
#endif
      }
      else {
        checkLPDigits = 0;  //If not a digit, break the loop.
#ifdef DEBUG
        Serial.println("Not a digit");
        Serial.println(checkLPDigits);
#endif
        break;
      }
    }
    if (checkLPDigits == 1) {
      Serial.println("All of these are digits!");
      LP();
    }
  }
  else if (commandString == "$$^/$$=/^^/^$=") {
    PMIR();
  }
  else if (commandString == "^$=/=$^/^^/^$=") {
    RXIR();
  }
  else if (commandString == "==^/^$=/==^") {
    VRV();
  }
}

void LP() {

#ifdef DEBUG
  Serial.println("LP COMMAND");
#endif


}

void PMIR() {
#ifdef DEBUG
  Serial.println("+-IR COMMAND");
#endif

  digitalWrite(IR_TRANSMIT, HIGH);
  delay(1000);
  digitalWrite(IR_TRANSMIT, LOW);
}

void RXIR() {
#ifdef DEBUG
  Serial.println("RXIR COMMAND");
#endif
  Serial.println("IR Receiver Value: ");
  Serial.println(analogRead(IR_RECEIVER));

}

void VRV() {
#ifdef DEBUG
  Serial.println("VRV COMMAND");
#endif

  int potReading = analogRead(POTENTIOMETER);
  Serial.println(potReading);
}

