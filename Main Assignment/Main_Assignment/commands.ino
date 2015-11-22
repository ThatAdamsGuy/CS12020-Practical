 void checkForCommand() {
  if (commandString == "$$^/$$=/^^/^$=") {
    PMIR();
  }
  else if (commandString == "^$=/=$^/^^/^$=") {
    RXIR();
  }
  else if (commandString == "==^/^$=/==^") {
    VRV(); 
  }
 }
 
 void LP(){
   Serial.println("LP COMMAND");
 }

 void PMIR() {
  Serial.println("PMIR COMMAND");
 }

 void RXIR() {
  Serial.println("RXIR COMMAND");
 }

 void VRV() {
  Serial.println("VRV COMMAND");
 }

