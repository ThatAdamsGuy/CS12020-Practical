//#define DEBUG

#define IR_RECEIVER 2
#define Switch_S1 3
#define REDLED 5
#define ORANGELED 6
#define YELLOWLED 9
#define GREENLED 10
#define BLUELED 11
#define POTENTIOMETER A0
#define IR_TRANSMIT A1
#define MONO_JACK A2

//Code started - 09/11/2015
//Code by Harry Adams (haa14@aber.ac.uk) for CS12020 Assignment
//Help gotten from the Arduino forums. Specific posts:
//Integer substrings: https://forum.arduino.cc/index.php?topic=361541.0
//Detecting input as int: http://forum.arduino.cc/index.php?topic=361232.msg2490774
//Altering potentiometer minmax values: http://forum.arduino.cc/index.php?topic=360717.msg2487297

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
char space = ' ';

//Other
String inputString;               //The string to be translated
char inputChar;                   //The char being worked on at any given time in the stringToMace loop
char nextChar;                    //Used purely for debug
int inputStringLength;            //Length of input string (used for loops)
int maceStringLength;             //Length of MACE characters string
String maceChar;                  //The mace char in the stringToMace loop
String nextMaceChar;              //Looks at the next MACE Char (used to detect spaces or end of line)
String maceString;                //The final output as its own string
String asciiString;
String commandString;             //Puts the MACE part of the loop into this string to be used in the Commands checking section.
String commandASCII;              //The string, also in ASCII, for commands (used for LP command)
bool checkLPDigits;               //Boolean used in the LP command loop
int timeUnit;                     //Reads the value from the potentiometer and uses this as the delay (in ms) ranging from 20-500.


void setup() {
  //Set baud rate
  Serial.begin(9600);

  //Sets the LED to Output (otherwise has brightnedd issues)
  pinMode(REDLED, OUTPUT);
  pinMode(ORANGELED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(IR_RECEIVER, OUTPUT);

  //run the startupFlash function (small light show to show program has started new)
  startupFlash();
}

void loop() {
  //Resets the inputs at the new iteration of the loop
  inputString = "";
  maceChar = "";
  nextMaceChar = "";
  maceString = "";
  asciiString = "";

  getInputString(); //Get the user's input

  //Detects leading spaces and removes them.
  while (inputString.charAt(0) == ' ') {
    String subInput;
    subInput = inputString.substring(1, inputStringLength);
    inputString = subInput;
    inputStringLength = inputString.length();
  }

  //Detects if the input is ASCII or MACE
  if (inputString.charAt(0) == '$' || inputString.charAt(0) == '^' || inputString.charAt(0) == '=') {
    //If MACE, run functions to translate MACE to ASCII, and then flash the BLUE LED
    inputStringToAscii();
    flashInputtedMaceString();
  }
  else {
    //If ASCII, run functions to translate ASCII to MACE, and then flash the RED LED
    inputStringToMace();
    flashTranslatedMaceString();
  }


  checkForCommand();    //Checks if the input was a command, and if so, run the command.

}


String getStringInput() {       //Get a string input
  while (!Serial.available()) { //Do nothing while Serial port is available
    ;
  }
  return Serial.readString();   //When not available (because input made) return the input
}

void getInputString() {
#ifdef DEBUG
  Serial.println("What is your input string?: "); //Ask user for input
#endif
  inputString = getStringInput(); //Run the getStringInput function to get serial input
#ifdef DEBYG
  Serial.println(inputString);    //Print what the user just inputted
#endif
  inputStringLength = inputString.length(); //Get the length of characters for this input (used for loops)

#ifdef DEBUG
  Serial.print("String length: ");
  Serial.println(inputStringLength);
#endif

}






