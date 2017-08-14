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

void resetVerticalView() {
  tapButton("RS_DOWN", 500);
  tapButton("RS_UP", 250);
}


void startHorde(boolean campaignScreen) {

  //Campaign unavailable
  if (campaignScreen) {
    tapButton("A", 60);
    delay(1000);
  }
   
  //Start horde game
  tapButton("A", 100);
  delay(1000);
  //Are you sure?
  tapButton("A", 100);

  //Wait for map selection screen to load
  delay(12000);
   
  //Select map
  tapButton("START", 60);
  delay(2000);
  //Start match
  tapButton("START", 60);   
   
  //Wait for match to be loaded
  delay(49000);
}


void returnToMainMenu() {
  tapButton("START", 60);
  delay(1000);
  tapButton("LS_UP", 60);
  delay(1000);
  tapButton("A", 60);
  delay(1000);
  tapButton("A", 60);
  delay(13000);
}


void roll(String dirBtn) {
  setButton(dirBtn, true);
  delay(100);
  tapButton("X", 60);
  setButton(dirBtn, false);
  delay(2000);
}


void setup() {
  pinMode(13, INPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  
  delay(15000);
  //returnToMainMenu();
  startHorde(false);
  //resetVerticalView();
}

void loop() {
  foundBaseOnAzura();
  returnToMainMenu();
  startHorde(true);
}


void foundBaseOnAzura() {
  tapButton("LS_DOWN", 1500);
  delay(250);
  roll("LS_LEFT");
  delay(250);
  roll("LS_LEFT");

  delay(250);  
  tapButton("LS_UP", 1000);
  delay(250);
  //Slide to pillar
  tapButton("A", 60);
  delay(1000);
  
  tapButton("LS_RIGHT", 500);
   
  setButton("LS_RIGHT", true);
  tapButton("A", 60);
  setButton("LS_RIGHT", false);
  delay(500);
  tapButton("RS_RIGHT", 150);
  tapButton("X", 2900);
  delay(100);
  tapButton("RSbtn", 60);
}

void tapButton(String btn, int holdTime) {
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
