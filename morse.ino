const int pin = 13; // This pin also corresponds to the builtin led on the board, so this can be run with no external circuitry.
const int unit = 100; // Time unit length in milliseconds. 100 is somewhat readable if you kinda know some morse but are untrained, and 60 is close to the standard as far as I can tell.
const int dotLength = unit;     // Lines 3-7 just define the timing standard for morse code.
const int bitDist = unit;
const int dashLength = 3*unit;
const int letterDist = 3*unit;
const int wordDist = 4*unit;
String strng = "Put whatever you want here, it'll handle basic punctuation, spacing, and is case-insensitive. Also, if there's something it doesn't know the code for, it ignores it.";

void dot(int pin, boolean final=false) { // This code activates the LED for the length of time required for a dot, then turns it off for the length of time in between signals. If the final variable is true, it's the last signal in the letter and will have a larger downtime gap.
  digitalWrite(pin,1);
  delay(dotLength);
  digitalWrite(pin,0);
  if (final) {
    delay(letterDist);
  } else {
    delay(bitDist);
  }
}

void dash(int pin, boolean final=false) { // It's the dot function but the light is on longer
  digitalWrite(pin,1);
  delay(dashLength);
  digitalWrite(pin,0);
  if (final) {
    delay(letterDist);
  } else {
    delay(bitDist);
  }
}

void morse(char c) { // Pass it a character and it will call the functions corresponding to the character in morse code
  if (c=='a') {
    dot(pin);
    dash(pin,true); // Note that the last call for each character always activates the 'final' variable
  } else if (c=='b') {
    dash(pin);
    dot(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='c') {
    dash(pin);
    dot(pin);
    dash(pin);
    dot(pin,true);
  } else if (c=='d') {
    dash(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='e') {
    dot(pin,true);
  } else if (c=='f') {
    dot(pin);
    dot(pin);
    dash(pin);
    dot(pin,true);
  } else if (c=='g') {
    dash(pin);
    dash(pin);
    dot(pin,true);
  } else if (c=='h') {
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='i') {
    dot(pin);
    dot(pin,true);
  } else if (c=='j') {
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='k') {
    dash(pin);
    dot(pin);
    dash(pin,true);
  } else if (c=='l') {
    dot(pin);
    dash(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='m') {
    dash(pin);
    dash(pin,true);
  } else if (c=='n') {
    dash(pin);
    dot(pin,true);
  } else if (c=='o') {
    dash(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='p') {
    dot(pin);
    dash(pin);
    dash(pin,true);
    dot(pin);
  } else if (c=='q') {
    dash(pin);
    dash(pin);
    dot(pin);
    dash(pin,true);
  } else if (c=='r') {
    dot(pin);
    dash(pin);
    dot(pin,true);
  } else if (c=='s') {
    dot(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='t') {
    dash(pin,true);
  } else if (c=='u') {
    dot(pin);
    dot(pin);
    dash(pin,true);
  } else if (c=='v') {
    dot(pin);
    dot(pin);
    dot(pin);
    dash(pin,true);
  } else if (c=='w') {
    dot(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='x') {
    dash(pin);
    dot(pin);
    dot(pin);
    dash(pin,true);
  } else if (c=='y') {
    dash(pin);
    dot(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='z') {
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='0') {
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='1') {
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='2') {
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='3') {
    dot(pin);
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='4') {
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin);
    dash(pin,true);
  } else if (c=='5') {
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='6') {
    dash(pin);
    dot(pin);
    dot(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='7') {
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='8') {
    dash(pin);
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin,true);
  } else if (c=='9') {
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dot(pin,true);
  } else if (c=='.') {
    dot(pin);
    dash(pin);
    dot(pin);
    dash(pin);
    dot(pin);
    dash(pin,true);
  } else if (c==',') {
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin,true);
  } else if (c=='?') {
    dot(pin);
    dot(pin);
    dash(pin);
    dash(pin);
    dot(pin);
    dot(pin,true);
  } else if (c==39) { // Special character '
    dot(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dash(pin);
    dot(pin,true);
  }
}       // Yes, I know that I could have done this as like some sort of external file using a single dict variable or whatever Arduino uses but I did this while half asleep and I've already typed all this once I'm not gonna do it again just for different formatting.

void setup() {
  pinMode(pin, OUTPUT); // Define output pin
  strng.toLowerCase();  // Removes capitalization for convenience
  strng += ' ';         // Adds a space at the end. This is what allows parseSpaces to run the final word. Otherwise, it stops at the last space and doesn't output every given word.
}                       // Haven't gotten around to testing it but I'm pretty sure this code will break if the string ends in a space when you pass it. Or maybe not, idk.

void parseSpaces(String str) {                      // Located in a weird space because I was testing with Serial, which was breaking when I tried to use it before calling .begin() even though it wasn't being executed
  if (str.indexOf(' ') != -1) {                     // indexOf returns -1 if it doesn't find the passed character. This is breaking the string up into different words.
    for (int i = 0; i < str.indexOf(' '); i++) {    // For every letter up to the first space, flash the morse code.
      morse(str[i]);
    }
    delay(wordDist);                                // Wait before doing the next word
    str.remove(0,str.indexOf(' ')+1);               // Cut the word we just did out of the original string.
    parseSpaces(str);                               // That's right, it's a recursive function. We're just doing it all again without the first word.
  }
}

void loop() {           // Just gonna do the thing then wait 5 seconds before doing it again.
  parseSpaces(strng);
  delay(5000);
}
