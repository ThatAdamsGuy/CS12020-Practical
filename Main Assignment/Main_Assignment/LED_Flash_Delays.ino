//This set of functions controls the LED Flashing for various characters
//This will have different functions based on whether it's flashing RED or BLUE
//RED for translated MACE code, BLUE for manually inputted MACE code

void flashTranslatedMaceString() {  //TRANSLATED MACE ONLY - Flashes RED LED
  maceStringLength = maceString.length(); //Gets length of the Mace String
  timeUnit = map(analogRead(POTENTIOMETER), 0, 1023, 20, 500);

#ifdef DEBUG
  Serial.print("Time unit: ");
  Serial.println(timeUnit);
#endif

  for (int i = 0; i < maceStringLength; i++) {  //A loop for the number of characters in the string
    if (maceString.charAt(i) == '=') {  //Checks the current character in the MACE string
      equalsREDLED(); //Runs the LED Function for that character
      if (maceString.charAt(i + 1) != ' ' || maceString.charAt(i + 1) != '/') { //Checks if the next character is part if the same letter
        delay(timeUnit);  //If so, add the appropriate delay
      }
    }
    else if (maceString.charAt(i) == '$') {
      dollarREDLED();
      if (maceString.charAt(i + 1) != ' ' || maceString.charAt(i + 1) != '/') {
        delay(timeUnit);
      }
    }
    else if (maceString.charAt(i) == '^') {
      upREDLED();
      if (maceString.charAt(i + 1) != ' ' || maceString.charAt(i + 1) != '/') {
        delay(timeUnit);
      }
    }
    else if (maceString.charAt(i) == ' ') {
      spaceLED();
    }
    else if (maceString.charAt(i) == '/') {
      slashLED();
    }
    else {
      errorREDLED();
    }
#ifdef DEBUG
    Serial.print(maceString.charAt(i));
#endif
  }
  Serial.println();
}



void flashInputtedMaceString() {
  timeUnit = map(analogRead(POTENTIOMETER), 0, 1023, 20, 500);

#ifdef DEBUG
  Serial.print("Time unit: ");
  Serial.println(timeUnit);
#endif

  for (int i = 0; i < inputStringLength; i++) {  //A loop for the number of characters in the string
    if (inputString.charAt(i) == '=') {  //Checks the current character in the INPUT string
      equalsBLUELED(); //Runs the LED Function for that character
      if (inputString.charAt(i + 1) != ' ' || inputString.charAt(i + 1) != '/') { //Checks if the next character is part if the same letter
        delay(timeUnit);  //If so, add the appropriate delay
      }
    }
    else if (inputString.charAt(i) == '$') {
      dollarBLUELED();
      if (inputString.charAt(i + 1) != ' ' || inputString.charAt(i + 1) != '/') {
        delay(timeUnit);
      }
    }
    else if (inputString.charAt(i) == '^') {
      upBLUELED();
      if (inputString.charAt(i + 1) != ' ' || inputString.charAt(i + 1) != '/') {
        delay(timeUnit);
      }
    }
    else if (inputString.charAt(i) == ' ') {
      spaceLED();
    }
    else if (inputString.charAt(i) == '/') {
      slashLED();
    }
    else {
      errorBLUELED();
    }

#ifdef DEBUG
    Serial.print(inputString.charAt(i));
#endif

  }
}







void equalsREDLED() {
  digitalWrite(REDLED, HIGH);
  delay (2 * timeUnit);
  digitalWrite(REDLED, LOW);
}

void dollarREDLED() {
  digitalWrite(REDLED, HIGH);
  delay(4 * timeUnit);
  digitalWrite(REDLED, LOW);
}

void upREDLED() {
  digitalWrite(REDLED, HIGH);
  delay(timeUnit);
  digitalWrite(REDLED, LOW);
}

void errorREDLED() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(REDLED, HIGH);
    delay(100);
    digitalWrite(REDLED, LOW);
    delay(100);
  }
}



void equalsBLUELED() {
  digitalWrite(BLUELED, HIGH);
  delay (2 * timeUnit);
  digitalWrite(BLUELED, LOW);
}

void dollarBLUELED() {
  digitalWrite(BLUELED, HIGH);
  delay(4 * timeUnit);
  digitalWrite(BLUELED, LOW);
}

void upBLUELED() {
  digitalWrite(BLUELED, HIGH);
  delay(timeUnit);
  digitalWrite(BLUELED, LOW);
}

void errorBLUELED() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(BLUELED, HIGH);
    delay(100);
    digitalWrite(BLUELED, LOW);
    delay(100);
  }
}


void spaceLED() {
  delay(5 * timeUnit);
}

void slashLED() {
  delay(3 * timeUnit);
}



