//Declare variables and constants
byte PINS[18] = {
  A0, A1, A2, A3, A4, A5, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
byte SND   = 0;
byte RSx   = 1;
byte RSy   = 2;
byte RT    = 3;
byte RSbtn = 4;
int RB     = 5;
int A      = 6;
int B      = 7;
int X      = 8;
int Y      = 9;
int START  = 10;
int XBOX   = 11;
int BACK   = 12;
int LB     = 13;
int LSy    = 14;
int LSx    = 15;
int LT     = 16;
int LSbtn  = 17;

//int MANTLE_DELAY=2000;

unsigned long sTime;

void resetVerticalView() {
  pressButton("RS_DOWN", 500);
  pressButton("RS_UP", 250);
}

void roll(String dirBtn) {
  setButton(dirBtn, true);
  delay(100);
  pressButton("X", 60);
  delay(200);
  setButton(dirBtn, false);
  delay(1800);
}

void setup() {
  pinMode(13, INPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  
  //resetVerticalView();

  delay(9000);

  sTime = millis();
}

void loop() {
  pressButton("A", 60);
  delay(10500);
  pressButton("BACK", 100);
  pressButton("LSbtn", 50);
  delay(3000);
  pressButton("A", 60);
  delay(1000);
  pressButton("RS_LEFT", 60);
  setButton("LS_UP", true);
  
  unsigned long time1 = millis();
  unsigned long fireTime = 0;
  unsigned long curTime;
  boolean b_viewReset = false;
  boolean b_continue = true;
  boolean b_turnRight1 = true;
  boolean b_turnRight2 = true;
  boolean b_shootAtFeet = false;
  boolean b_stopWalking = false;


  while (b_continue) {
    curTime = millis();
    if (curTime - time1 >= 45000) {
      b_continue = false;  
    } else if (b_turnRight1 && curTime - time1 >= 13000) {
      b_turnRight1 = false;
      pressButton("RS_LEFT", 100);
    } else if (b_turnRight2 && curTime - time1 >= 27000) {
      b_turnRight2 = false;
      b_shootAtFeet = true;
      pressButton("RS_LEFT", 220);
    } else if (!b_stopWalking && curTime - time1 >= 30000) {
      b_stopWalking = true;
      setButton("LS_UP", false);
    } else if ( (!b_viewReset) && (curTime - fireTime > 5000)) {
      b_viewReset = true;
      pressButton("RS_UP", 500);
      if (!b_shootAtFeet) {
        pressButton("RS_DOWN", 350);
      }
    } else if (curTime - fireTime >= 6000) {
      fireTime = millis();
      b_viewReset = false;
      pressButton("Y", 50);
    }
  }
  
  delay(4000);
}


void pressButton(String btn, int holdTime) {
  setButton(btn, true);
  delay(holdTime);
  setButton(btn, false);
}


//btn is button (A, B, X, Y, START, LS_UP, RS_LEFT, XBOX, etc.)
//b_set is true to set (press) the button, false to reset (depress)
void setButton(String btn, boolean b_set) {
  byte pin = 255;
  boolean value = HIGH;
  boolean isStick = false;
  boolean isTrigger = false;

  if (btn == "RT") {
    pin = RT;
    value = LOW;
    isTrigger = true;
  } else if (btn == "LT") {
    pin = LT;
    value = LOW;
    isTrigger = true;
  } else if (btn == "A") {
    pin = A;
  } else if (btn == "B") {
    pin = B;
  } else if (btn == "X") {
    pin = X;
  } else if (btn == "Y") {
    pin = Y;
  } else if (btn == "START") {
    pin = START;
  } else if (btn == "XBOX") {
    pin = XBOX;
  } else if (btn == "BACK") {
    pin = BACK;
  } else if (btn == "LB") {
    pin = LB;
  } else if (btn == "RB") {
    pin = RB;    
  } else if (btn == "LSbtn") {
    pin = LSbtn;
  } else if (btn == "RSbtn") {
    pin = RSbtn;
  } else if (btn == "RS_UP") {
    pin = RSy;
    value = HIGH;
    isStick = true;
  } else if (btn == "RS_DOWN") {
    pin = RSy;
    value = LOW;
    isStick = true;
  } else if (btn == "RS_LEFT") {
    pin = RSx;
    value = HIGH;
    isStick = true;    
  } else if (btn == "RS_RIGHT") {
    pin = RSx;
    value = LOW;
    isStick = true;    
  } else if (btn == "LS_UP") {
    pin = LSy;
    value = HIGH;
    isStick = true;    
  } else if (btn == "LS_DOWN") {
    pin = LSy;
    value = LOW;
    isStick = true;    
  } else if (btn == "LS_LEFT") {
    pin = LSx;
    value = HIGH;
    isStick = true;    
  } else if (btn == "LS_RIGHT") {
    pin = LSx;
    value = LOW;
    isStick = true;    
  }

  //Joysticks
  if (isStick) {
    if (b_set) {
      pinMode(PINS[pin], OUTPUT);
      digitalWrite(PINS[pin], value);
    } else {
      digitalWrite(PINS[pin], LOW);
      pinMode(PINS[pin], INPUT);
    }
  } else if (isTrigger) {
    if (b_set) {
      digitalWrite(PINS[pin], LOW);
      pinMode(PINS[pin], OUTPUT);
    } else {
      pinMode(PINS[pin], INPUT);
    }
  } else if (PINS[pin] < 255) {
    pinMode(PINS[pin], OUTPUT);
    if (b_set) {
      digitalWrite(PINS[pin], HIGH);
    } else {
      digitalWrite(PINS[pin], LOW);
    }
  }
}
