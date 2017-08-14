//Declare variables and constants
int RB_PIN=2;
int LB_PIN=3;
int Y_PIN=4;
int B_PIN=5;
int A_PIN=6;
int X_PIN=7;
int RT_PIN=8;
int LT_PIN=9;

int CONTROLLER_POWER_PIN=A0;
int START_PIN=12;

int MANTLE_DELAY=2000;

boolean b_waitForDepress=false;
boolean b_firstPress=true;

void setup() {
  //Flash the LED twice to indicate ready state
  digitalWrite(13, LOW);
  pinMode(13, OUTPUT);
  delay(1000);
  digitalWrite(13, HIGH);
  pinMode(13, OUTPUT);
  delay(1000);
  digitalWrite(13, LOW);
  pinMode(13, OUTPUT);
  delay(1000);
  digitalWrite(13, HIGH);
  pinMode(13, OUTPUT);
  
  boolean b_waitForDepress=false;
  boolean b_firstPress=true;
}

void loop() {
  if (digitalRead(START_PIN)) {
    if (b_firstPress) {
      b_firstPress=false;
      pressButton("A");
      delay(500);
    } else {
      pressButton("Y");
      delay(2000);
    }
  } else {
    delay(50);
  }
}


void pressButton(String btn) {
  
  if (btn == "A") {
    pinMode(A_PIN, OUTPUT);
    digitalWrite(A_PIN, HIGH);
    delay(50);
    digitalWrite(A_PIN, LOW);
  } else if (btn == "B") {
    pinMode(B_PIN, OUTPUT);
    digitalWrite(B_PIN, HIGH);
    delay(50);
    digitalWrite(B_PIN, LOW);
  } else if (btn == "X") {
    pinMode(X_PIN, OUTPUT);
    digitalWrite(X_PIN, HIGH);
    delay(50);
    digitalWrite(X_PIN, LOW);
  } else if (btn == "Y") {
    pinMode(Y_PIN, OUTPUT);
    digitalWrite(Y_PIN, HIGH);
    delay(50);
    digitalWrite(Y_PIN, LOW);
  } else if (btn == "LB") {
    pinMode(LB_PIN, OUTPUT);
    digitalWrite(LB_PIN, HIGH);
    delay(50);
    digitalWrite(LB_PIN, LOW);
  } else if (btn == "RB") {
    pinMode(RB_PIN, OUTPUT);
    digitalWrite(RB_PIN, HIGH);
    delay(50);
    digitalWrite(RB_PIN, LOW);
  } else if (btn == "LT") {
    digitalWrite(LT_PIN, LOW);
    pinMode(LT_PIN, OUTPUT);
    delay(50);
    pinMode(LT_PIN, INPUT);
  } else if (btn == "RT") {
    digitalWrite(RT_PIN, LOW);
    pinMode(RT_PIN, OUTPUT);
    delay(50);
    pinMode(RT_PIN, INPUT);
  } else {
    //Nothing to do until further notice
  }
}
