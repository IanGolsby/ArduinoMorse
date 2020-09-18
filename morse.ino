const int pin = 13; // This pin also corresponds to the builtin led on the board, so this can be run with no external circuitry.
const int unit = 100; // Time unit length in milliseconds. 100 is somewhat readable if you kinda know some morse but are untrained, and 60 is close to the standard as far as I can tell.
const int dotLength = unit;     // Lines 3-7 just define the timing standard for morse code.
const int bitDist = unit;
const int dashLength = 3*unit;
const int letterDist = 3*unit;
const int wordDist = 4*unit;
String strng = "Put whatever you want here, it'll handle basic punctuation, spacing, and is case-insensitive. Also, if there's something it doesn't know the code for, it ignores it.";
const int len = strng.length();

void dot(int pin) {       // This code turns the light on for a dot length then off for a bit length
  digitalWrite(pin,1);
  delay(dotLength);
  digitalWrite(pin,0);
  delay(bitDist);
}

void dash(int pin) {      // Ditto but with dash not dot
  digitalWrite(pin,1);
  delay(dashLength);
  digitalWrite(pin,0);
  delay(bitDist);
}

void morse(char c) { // Pass it a character and it will call the functions corresponding to the character in morse code
  if (c=='a') {
    dot(pin);
    dash(pin);
  } else if (c=='b') {
    dash(pin);
    dot(pin);
    dot(pin);
    dot(pin);
  } else if (c=='c') {
    dash(pin);
    dot(pin);
    dash(pin);
    dot(pin);
  } else if (c=='d') {
    dash(pin);
    dot(pin);
    dot(pin);
  } else if (c=='e') {
    dot(pin);
  } else if (c=='f') {
    dot(pin);
    dot(pin);
    dash(pin);
    dot(pin);
  } else if (c=='g') {
    dash(pin);
    dash(pin);
    dot(pin);
  } else if (c=='h') {
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin);
  } else if (c=='i') {
    dot(pin);
    dot(pin);
  } else if (c=='j') {
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin);
  } else if (c=='k') {
    dash(pin);
    dot(pin);
    dash(pin);
  } else if (c=='l') {
    dot(pin);
    dash(pin);
    dot(pin);
    dot(pin);
  } else if (c=='m') {
    dash(pin);
    dash(pin);
  } else if (c=='n') {
    dash(pin);
    dot(pin);
  } else if (c=='o') {
    dash(pin);
    dash(pin);
    dash(pin);
  } else if (c=='p') {
    dot(pin);
    dash(pin);
    dash(pin);
    dot(pin);
  } else if (c=='q') {
    dash(pin);
    dash(pin);
    dot(pin);
    dash(pin);
  } else if (c=='r') {
    dot(pin);
    dash(pin);
    dot(pin);
  } else if (c=='s') {
    dot(pin);
    dot(pin);
    dot(pin);
  } else if (c=='t') {
    dash(pin);
  } else if (c=='u') {
    dot(pin);
    dot(pin);
    dash(pin);
  } else if (c=='v') {
    dot(pin);
    dot(pin);
    dot(pin);
    dash(pin);
  } else if (c=='w') {
    dot(pin);
    dash(pin);
    dash(pin);
  } else if (c=='x') {
    dash(pin);
    dot(pin);
    dot(pin);
    dash(pin);
  } else if (c=='y') {
    dash(pin);
    dot(pin);
    dash(pin);
    dash(pin);
  } else if (c=='z') {
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin);
  } else if (c=='0') {
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
  } else if (c=='1') {
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
  } else if (c=='2') {
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin);
  } else if (c=='3') {
    dot(pin);
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin);
  } else if (c=='4') {
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin);
    dash(pin);
  } else if (c=='5') {
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin);
  } else if (c=='6') {
    dash(pin);
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin);
  } else if (c=='7') {
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin);
    dot(pin);
  } else if (c=='8') {
    dash(pin);
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin);
  } else if (c=='9') {
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dot(pin);
  } else if (c=='.') {
    dot(pin);
    dash(pin);
    dot(pin);
    dash(pin);
    dot(pin);
    dash(pin);
  } else if (c==',') {
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin);
  } else if (c=='?') {
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin);
  } else if (c==39) { // Special character '
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dot(pin);
  } else if (c==' ') { // Space means there's a new word, so we're gonna add appropriate time delay
    delay(wordDist);
  }
  delay(letterDist);
}       // Yes, I know that I could have done this as like some sort of external file using a single dict variable or whatever Arduino uses but I did this while half asleep and I've already typed all this once I'm not gonna do it again just for different formatting.

void setup() {
  pinMode(pin, OUTPUT); // Define output pin
  strng.toLowerCase();  // Removes capitalization for convenience
}                       // Haven't gotten around to testing it but I'm pretty sure this code will break if the string ends in a space when you pass it. Or maybe not, idk.

void loop() {
  for (int i = 0; i < len; i++) {   // Loop through every character in the string and call the morse function
    morse(strng.charAt(i));
  }
  delay(5000);                      // Take a 5 and do it again
}
