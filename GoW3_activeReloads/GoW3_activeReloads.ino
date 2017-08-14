//Declare variables and constants
int RELOAD_PIN=8;
int FIRE_PIN=7;

int CONTROLLER_POWER_PIN=A0;
int START_PIN=12;
int FIRE_DELAY=50;
int RELOAD_DELAY=780;
int RELOAD_TO_FIRE_DELAY=700;

void setup() {
  
  //Pull RT high (so it doesn't fire)
  digitalWrite(FIRE_PIN, HIGH);
  pinMode(FIRE_PIN, OUTPUT);
  
  //The onboard LED will mimic the fire pin
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  
  //Put RB in high-Z (input mode)
  //Not necessary, input mode is the default
  digitalWrite(RELOAD_PIN, LOW);
  pinMode(RELOAD_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(START_PIN)) {
    fire();
    reload();
    delay(RELOAD_TO_FIRE_DELAY);
  } else {
    delay(50);
  }
}

/*
*swaps between weapons
*argument should be one of
*GRENADE, LEFT, RIGHT or PISTOL
*/
void swapWeapon(int weapon) {
}

//Fires 1 bullet from current weapon
void fire() {
  digitalWrite(FIRE_PIN, LOW);
  digitalWrite(13, LOW);
  delay(FIRE_DELAY);
  digitalWrite(FIRE_PIN, HIGH);
  digitalWrite(13, HIGH);
  delay(50);
}

//Does an active reload
void reload() {
  digitalWrite(RELOAD_PIN, HIGH);
  delay(50);
  digitalWrite(RELOAD_PIN, LOW);
  delay(RELOAD_DELAY);
  digitalWrite(RELOAD_PIN, HIGH);
  delay(50);
  digitalWrite(RELOAD_PIN, LOW);
  delay(50);
}
