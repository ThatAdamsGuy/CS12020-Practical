void checkForCommand() {
  //Checks if the input starts LP
  if (commandString.charAt(0) == 76 && commandString.charAt(1) == 80) {
    for (int i = 2; i < 12; i++) {  //For all the "digits" in the input
      if (isdigit(commandString.charAt(i))) { //Checks that each digit is, in fact, a digit
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

}

void VRV() {
#ifdef DEBUG
  Serial.println("VRV COMMAND");
#endif

  int potReading = analogRead(POTENTIOMETER);
  Serial.println(potReading);
}

