#define DEBUG

#define IR_Receiver 2
#define Switch_S1 3
#define REDLED 5
#define ORANGELED 6
#define YELLOWLED 9
#define GREENLED 10
#define BLUELED 11
#define POTENTIOMETER A0
#define IR_Transmit A1
#define Mono_Jack A2

//Code started - 09/11/2015
//Code by Harry Adams (haa14@aber.ac.uk) for CS12020 Assignment

// ^ : 1 time unit
// = : 2 time units
// $ : 4 time units

//Delay between signals forming the same letter : 1 time unit
//Delay between characters forming the same word : 3 time units
//Delay between two words: 5 time units.

//Separator between characters forming same letter: NONE
//Separator between characters forming the same word: /
//Separator between two words: One space character

//MACE LETTERS                    //TIME CODES (21 = 2 time units, 1 time unit break, 1 time unit)
char mace_a[] = "=";              //2
char mace_b[] = "^^=";            //112
char mace_c[] = "^=$";            //124
char mace_d[] = "=^";             //21
char mace_e[] = "^";              //1
char mace_f[] = "^=^";            //121
char mace_g[] = "==";             //22
char mace_h[] = "^==";            //122
char mace_i[] = "^^";             //11
char mace_j[] = "=^^";            //211
char mace_k[] = "^$";             //14
char mace_l[] = "^^$";            //114
char mace_m[] = "^=";             //12
char mace_n[] = "=$";             //24
char mace_o[] = "$=";             //42
char mace_p[] = "$^";             //41
char mace_q[] = "=^$";            //214
char mace_r[] = "^$=";            //142
char mace_s[] = "^$^";            //141
char mace_t[] = "$";              //4
char mace_u[] = "$$";             //44
char mace_v[] = "==^";            //221
char mace_w[] = "==$";            //224
char mace_x[] = "=$^";            //241
char mace_y[] = "^$$";            //144
char mace_z[] = "===";            //222
//MACE NUMBERS
char mace_1[] = "$^^=";           //4112
char mace_2[] = "$^^$";           //4114
char mace_3[] = "$^=^";           //4121
char mace_4[] = "$^==";           //4122
char mace_5[] = "$^=$";           //4124
char mace_6[] = "$^$^";           //4141
char mace_7[] = "$^$=";           //4142
char mace_8[] = "$^$$";           //4144
char mace_9[] = "$=^^";           //4211
char mace_0[] = "$^^^";           //4111
//MACE PUNCTUATION
char mace_fullstop[] = "$^^";     //411
char mace_comma[] = "$^=";        //412
char mace_apostraphe[] = "$=^";   //421
char mace_question[] = "$==";     //422
char mace_exclamation[] = "$=$";  //424
char mace_plus[] = "$$^";         //441
char mace_minus[] = "$$=";        //442
char mace_multiply[] = "$$$";     //444
char mace_divide[] = "$^$";       //414
char mace_equals[] = "$==$";      //4224
char mace_space[] = " ";
char mace_error[] = "Untranslateable Character";

//Other
String inputString;               //The string to be translated
char inputChar;                   //The char being worked on at any given time in the stringToMace loop
char nextChar;
int inputStringLength;            //Length of input string (used for loops)
int maceStringLength;             //Length of MACE characters string
String maceChar;                  //The mace char in the stringToMace loop
String nextMaceChar;
String maceString;                //The final output as its own string
String asciiString;
int timeUnit;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //Resets the inputs at the new iteration of the loop
  inputString = "";
  maceChar = "";
  nextMaceChar = "";
  maceString = "";
  asciiString = "";


  getInputString();
  if (inputString.charAt(0) == '$' || inputString.charAt(0) == '^' || inputString.charAt(0) == '=') {
    inputStringToAscii();
  }
  else {
    inputStringToMace();
    Serial.println();
    Serial.println();
  }

  timeUnit = 10 + analogRead(POTENTIOMETER);
  flashMaceString();
}


String getStringInput() {
  while (!Serial.available()) {
    ;
  }
  return Serial.readString();
}

void getInputString() {
  Serial.print("What is your input string?: ");
  inputString = getStringInput();
  Serial.println(inputString);
  inputStringLength = inputString.length();
#ifdef DEBUG
  Serial.print("String length: ");
  Serial.println(inputStringLength);
#endif
}

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
    else {
      maceString = maceString + maceChar + "/";
    }
  }
  Serial.println(maceString);
}



void inputStringToAscii() {
  maceTree();
  Serial.println(asciiString);
  Serial.println();
}

void flashMaceString() {
  maceStringLength = maceString.length();
  for (int i = 0; i < maceStringLength; i++) {
    if (maceString.charAt(i) == '=') {
      equalsLED();
      if (maceString.charAt(i+1) != ' ' ||maceString.charAt(i+1) != '/'){
        delay(timeUnit);
      }
    }
    else if (maceString.charAt(i) == '$') {
      dollarLED();
      if (maceString.charAt(i+1) != ' ' ||maceString.charAt(i+1) != '/'){
        delay(timeUnit);
      }
    }
    else if (maceString.charAt(i) == '^') {
      upLED();
      if (maceString.charAt(i+1) != ' ' ||maceString.charAt(i+1) != '/'){
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
      errorLED();
    }
#ifdef DEBUG
    Serial.print(maceString.charAt(i));    
#endif
  }
  Serial.println();
}

