//#define DEBUG

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
String maceChar;                  //The mace char in the stringToMace loop
String nextMaceChar;
String maceString;                //The final output as its own string

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  getInputString();
  if (inputString.charAt(0) == '$' ||inputString.charAt(0) == '^' ||inputString.charAt(0) == '=') {
    inputStringToAscii();
  }
  else {
    inputStringToMace();
    Serial.println();
    Serial.println();
  }
}


String getStringInput() {
  while (!Serial.available()) {
    ;
  }
  return Serial.readString();
}

char* getMaceChar(char inputChar) {
  switch (inputChar) {
    case 'a': return mace_a;
    case 'b': return mace_b;
    case 'c': return mace_c;
    case 'd': return mace_d;
    case 'e': return mace_e;
    case 'f': return mace_f;
    case 'g': return mace_g;
    case 'h': return mace_h;
    case 'i': return mace_i;
    case 'j': return mace_j;
    case 'k': return mace_k;
    case 'l': return mace_l;
    case 'm': return mace_m;
    case 'n': return mace_n;
    case 'o': return mace_o;
    case 'p': return mace_p;
    case 'q': return mace_q;
    case 'r': return mace_r;
    case 's': return mace_s;
    case 't': return mace_t;
    case 'u': return mace_u;
    case 'v': return mace_v;
    case 'w': return mace_w;
    case 'x': return mace_x;
    case 'y': return mace_y;
    case 'z': return mace_z;
    case '1': return mace_1;
    case '2': return mace_2;
    case '3': return mace_3;
    case '4': return mace_4;
    case '5': return mace_5;
    case '6': return mace_6;
    case '7': return mace_7;
    case '8': return mace_8;
    case '9': return mace_9;
    case '0': return mace_0;
    case ' ': return mace_space;
    case '.': return mace_fullstop;
    case ',': return mace_comma;
    case 39 : return mace_apostraphe;    //ASCII code for Apostrophe
    case '?': return mace_question;
    case '!': return mace_exclamation;
    case '+': return mace_plus;
    case '-': return mace_minus;
    case '/': return mace_divide;
    case '*': return mace_multiply;
    case '=': return mace_equals;
    default: return mace_error;
  }
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
  Serial.println("This is a MACE string. This functionality is not yet supported. Please input an ASCII string");
}

