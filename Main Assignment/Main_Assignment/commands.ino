//This page focuses on Part 3 of the assignment - responding to inputs

void checkForCommand() {
  int commandASCIILength = commandASCII.length();
  //Checks if the input starts LP                                       //Checks that the command is exactly 14 characters (LP + 12 digits - prevents incorrect commands entered)
  if (commandASCII.charAt(0) == 'L' && commandASCII.charAt(1) == 'P' && commandASCIILength == 14) {
#ifdef DEBUG
    Serial.println("Checking for the LP command");
#endif
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
#ifdef DEBUG
      Serial.println("All of these are digits!");
#endif
      LP();
    }
  }
  else if (commandString == "$$^/$$=/^^/^$=") { //Runs the specified command if this string is matched exactly
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
  int redPWM = 0, orangePWM = 0, yellowPWM = 0, greenPWM = 0;
#ifdef DEBUG
  Serial.println("LP COMMAND");
#endif

  redPWM = ((commandASCII.charAt(2) - '0') * 100) + ((commandASCII.charAt(3) - '0') * 10) + (commandASCII.charAt(4) - '0');
  orangePWM = ((commandASCII.charAt(5) - '0') * 100) + ((commandASCII.charAt(6) - '0') * 10) + (commandASCII.charAt(7) - '0');
  yellowPWM = ((commandASCII.charAt(8) - '0') * 100) + ((commandASCII.charAt(9) - '0') * 10) + (commandASCII.charAt(10) - '0');
  greenPWM = ((commandASCII.charAt(11) - '0') * 100) + ((commandASCII.charAt(12) - '0') * 10) + (commandASCII.charAt(13) - '0');

#ifdef DEBUG
  Serial.println(redPWM);
  Serial.println(orangePWM);
  Serial.println(yellowPWM);
  Serial.println(greenPWM);
#endif

  if (redPWM > 255) {
    Serial.println("Red value is invalid!");
    Serial.println("Setting value to 255");
    redPWM = 255;
  }
  else if (orangePWM > 255) {
    Serial.println("Orange value is invalid!");
    Serial.println("Setting value to 255");
    orangePWM = 255;
  }
  else if (yellowPWM > 255) {
    Serial.println("Yellow value is invalid!");
    Serial.println("Setting value to 255");
    yellowPWM = 255;
  }
  else if (greenPWM > 255) {
    Serial.println("Green value is invalid!");
    Serial.println("Setting value to 255");
    yellowPWM = 255;
  }

  analogWrite(REDLED, redPWM);
  analogWrite(ORANGELED, orangePWM);
  analogWrite(YELLOWLED, yellowPWM);
  analogWrite(GREENLED, greenPWM);

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

