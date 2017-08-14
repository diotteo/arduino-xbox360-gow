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

void setup() {
  
  //Pull RT high (so it doesn't fire)
  digitalWrite(FIRE_PIN, HIGH);
  pinMode(FIRE_PIN, OUTPUT);
  
  //Pull mantle low (don't roll)
  digitalWrite(MANTLE_PIN, LOW);
  pinMode(MANTLE_PIN, OUTPUT);
  
  //The onboard LED will mimic the mantle/roll pin
  digitalWrite(13, LOW);
  pinMode(13, OUTPUT);

  
  //Pull RB low (don't reload)
  digitalWrite(RELOAD_PIN, LOW);
  pinMode(RELOAD_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(START_PIN)) {
    mantle();
  } else {
    delay(50);
  }
}

void mantle() {
  digitalWrite(MANTLE_PIN, HIGH);
  digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(MANTLE_PIN, LOW);
  digitalWrite(13, LOW);
  delay(MANTLE_DELAY);
}
