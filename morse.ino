const int pin = 13;
const int unit = 100; // Time unit length in milliseconds. 100 is somewhat readable if you kinda know some morse but are untrained, and 60 is close to the standard as far as I can tell.
const int dotLength = unit;
const int bitDist = unit;
const int dashLength = 3*unit;
const int letterDist = 3*unit;
const int wordDist = 4*unit;
String strng = "Put whatever you want here, it'll handle basic punctuation, spacing, and is case-insensitive. Also, if there's something it doesn't know the code for, it ignores it.";

void dot(int pin, boolean final=false) {
  digitalWrite(pin,1);
  delay(dotLength);
  digitalWrite(pin,0);
  if (final) {
    delay(letterDist);
  } else {
    delay(bitDist);
  }
}

void dash(int pin, boolean final=false) {
  digitalWrite(pin,1);
  delay(dashLength);
  digitalWrite(pin,0);
  if (final) {
    delay(letterDist);
  } else {
    delay(bitDist);
  }
}

void morse(char c) {
  if (c=='a') {
    dot(pin);
    dash(pin,true);
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
}

void setup() {
  pinMode(pin, OUTPUT);
  strng.toLowerCase();
  strng += ' ';
}

void parseSpaces(String str) {
  if (str.indexOf(' ') != -1) {
    for (int i = 0; i < str.indexOf(' '); i++) {
      morse(str[i]);
    }
    delay(wordDist);
    str.remove(0,str.indexOf(' ')+1);
    if (str != ' ' && str) {
      parseSpaces(str);
    }
  }
}

void loop() {
  parseSpaces(strng);
  delay(5000);
}
