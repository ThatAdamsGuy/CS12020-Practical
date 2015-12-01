void inputStringToMace() {
  for (int i = 0; i < inputStringLength; i++) {
    inputChar = inputString.charAt(i);
    inputChar = tolower(inputChar);
    nextChar = inputString.charAt(i + 1);
    nextChar = tolower(nextChar);
    maceChar = getMaceChar(inputChar);
    nextMaceChar = getMaceChar(nextChar);
    
#ifdef DEBUG
    Serial.println(inputChar);
    Serial.println(nextChar);
#endif

    if (nextMaceChar == " ") {
      maceString = maceString + maceChar;
    }
    else if (maceChar == " ") {
      maceString = maceString + maceChar;
    }
    else if (i == (inputStringLength - 1)) {
      maceString = maceString + maceChar;
    }
    else {
      maceString = maceString + maceChar + "/";
    }
  }
  Serial.println(maceString);
  commandString = maceString;
  commandASCII = inputString;
}



void inputStringToAscii() {
  maceTree();
  int asciiStringLength = asciiString.length();

  //This loop checks for an ending space for the MACE string, and removes it
  //Created as I kept copy-pasting previous translations with a space
  if (asciiString.charAt(asciiStringLength - 1) == ' ') {
    String tempSub;
    tempSub = asciiString.substring(0, (asciiStringLength - 1));
    #ifdef DEBUG
    Serial.println("Substring: ");
    Serial.println(tempSub);
    #endif
    asciiString = tempSub;
  }


  
  Serial.println(asciiString);
  Serial.println();
  commandString = inputString;
  commandASCII = asciiString;
}





//This is a very very nested series of 'if' statements to translate characters from MACE to ASCII
//"pointer" points at the current character of MACE being looked at.
//Based on the tree diagram in the writeup, it can determine if it has reached the end of the tree (due to the 'next' character being a slash)
void maceTree() {
  int pointer = 0;
  while (pointer < inputStringLength) {
    if (inputString.charAt(pointer) == '=') {
      pointer++;
      if (inputString.charAt(pointer) == '=') {
        pointer++;
        if (inputString.charAt(pointer) == '=') {
          pointer++;
          asciiString = asciiString + 'Z';
        }
        else if (inputString.charAt(pointer) == '$') {
          pointer++;
          asciiString = asciiString + 'W';
        }
        else if (inputString.charAt(pointer) == '^') {
          pointer++;
          asciiString = asciiString + 'V';
        }
        else {
          asciiString = asciiString + 'G';
        }
      }
      else if (inputString.charAt(pointer) == '$') {
        pointer++;
        if (inputString.charAt(pointer) == '^') {
          pointer++;
          asciiString = asciiString + 'X';
        }
        else {
          asciiString = asciiString + 'N';
        }
      }
      else if (inputString.charAt(pointer) == '^') {
        pointer++;
        if (inputString.charAt(pointer) == '$') {
          pointer++;
          asciiString = asciiString + 'Q';
        }
        else if (inputString.charAt(pointer) == '^') {
          pointer++;
          asciiString = asciiString + 'J';
        }
        else {
          asciiString = asciiString + 'D';
        }
      }
      else {
        asciiString = asciiString + 'A';
      }
    }


    else if (inputString.charAt(pointer) == '$') {
      pointer++;
      if (inputString.charAt(pointer) == '=') {
        pointer++;
        if (inputString.charAt(pointer) == '=') {
          pointer++;
          if (inputString.charAt(pointer) == '$') {
            pointer++;
            asciiString = asciiString + '=';
          }
          else {
            pointer++;
            asciiString = asciiString + '?';
          }
        }
        else if (inputString.charAt(pointer) == '$') {
          pointer++;
          asciiString = asciiString + '!';
        }
        else if (inputString.charAt(pointer) == '^') {
          pointer++;
          if (inputString.charAt(pointer) == '^') {
            pointer++;
            asciiString = asciiString + '9';
          }
          else {
            pointer++;
            asciiString = asciiString + "'";
          }
        }
        else {
          asciiString = asciiString + 'O';
        }
      }
      else if (inputString.charAt(pointer) == '$') {
        pointer++;
        if (inputString.charAt(pointer) == '=') {
          pointer++;
          asciiString = asciiString + '-';
        }
        else if (inputString.charAt(pointer) == '$') {
          pointer++;
          asciiString = asciiString + '*';
        }
        else if (inputString.charAt(pointer) == '^') {
          pointer++;
          asciiString = asciiString + '+';
        }
        else {
          asciiString = asciiString + 'U';
        }
      }
      else if (inputString.charAt(pointer) == '^') {
        pointer++;
        if (inputString.charAt(pointer) == '=') {
          pointer++;
          if (inputString.charAt(pointer) == '=') {
            pointer++;
            asciiString = asciiString + '4';
          }
          else if (inputString.charAt(pointer) == '$') {
            pointer++;
            asciiString = asciiString + '5';
          }
          else if (inputString.charAt(pointer) == '^') {
            pointer++;
            asciiString = asciiString + '3';
          }
          else {
            pointer++;
            asciiString = asciiString + ',';
          }
        }
        else if (inputString.charAt(pointer) == '$') {
          pointer++;
          if (inputString.charAt(pointer) == '=') {
            pointer++;
            asciiString = asciiString + '7';
          }
          else if (inputString.charAt(pointer) == '$') {
            pointer++;
            asciiString = asciiString + '8';
          }
          else if (inputString.charAt(pointer) == '^') {
            pointer++;
            asciiString = asciiString + '6';
          }
          else {
            pointer++;
            asciiString = asciiString + '/';
          }
        }
        else if (inputString.charAt(pointer) == '^') {
          pointer++;
          if (inputString.charAt(pointer) == '=') {
            pointer++;
            asciiString = asciiString + '1';
          }
          else if (inputString.charAt(pointer) == '$') {
            pointer++;
            asciiString = asciiString + '2';
          }
          else if (inputString.charAt(pointer) == '^') {
            pointer++;
            asciiString = asciiString + '0';
          }
          else {
            pointer++;
            asciiString = asciiString + '.';
          }
        }
        else {
          asciiString = asciiString + 'P';
        }
      }
      else {
        asciiString = asciiString + 'T';
      }
    }



    else if (inputString.charAt(pointer) == '^') {
      pointer++;
      if (inputString.charAt(pointer) == '=') {
        pointer++;
        if (inputString.charAt(pointer) == '=') {
          pointer++;
          asciiString = asciiString + 'H';
        }
        else if (inputString.charAt(pointer) == '$') {
          pointer++;
          asciiString = asciiString + 'C';
        }
        else if (inputString.charAt(pointer) == '^') {
          pointer++;
          asciiString = asciiString + 'F';
        }
        else {
          asciiString = asciiString + 'M';
        }
      }
      else if (inputString.charAt(pointer) == '$') {
        pointer++;
        if (inputString.charAt(pointer) == '=') {
          pointer++;
          asciiString = asciiString + 'R';
        }
        else if (inputString.charAt(pointer) == '$') {
          pointer++;
          asciiString = asciiString + 'Y';
        }
        else if (inputString.charAt(pointer) == '^') {
          pointer++;
          asciiString = asciiString + 'S';
        }
        else {
          asciiString = asciiString + 'K';
        }

      }
      else if (inputString.charAt(pointer) == '^') {
        pointer++;
        if (inputString.charAt(pointer) == '=') {
          pointer++;
          asciiString = asciiString + 'B';
        }
        else if (inputString.charAt(pointer) == '$') {
          pointer++;
          asciiString = asciiString + 'L';
        }
        else {
          asciiString = asciiString + 'I';
        }
      }
      else {
        asciiString = asciiString + 'E';
      }
    }



    else if (inputString.charAt(pointer) == '/') {
      pointer++;            //If char is a slash, not going to be start of a char, so +1 and go again.
    }
    else if (inputString.charAt(pointer) == ' ') {
      pointer++;            //Simply a space character
      asciiString = asciiString + ' ';
    }
    else {
      pointer++;            //ERROR DETECTION - If not a =$^/ or space, write invalid character.
      Serial.println("!!INVALID CHARACTER!!");
    }
  }
}
