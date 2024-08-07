#include <Arduino.h>

#define POWER_BUTTON 5
#define INCREASE_BUTTON 4
#define DECREASE_BUTTON 3
#define FAN 2

int inputPins[] = {POWER_BUTTON, INCREASE_BUTTON, DECREASE_BUTTON};

bool on = false;
int fanSpeed = 1;

// put function declarations here:
void turnOn();
void turnOff();

void setup() {
  // put your setup code here, to run once:
  int size = sizeof(inputPins) / sizeof(int);
  for (int i = 0; i < size; i++){
    pinMode(inputPins[i], INPUT);
  }
  pinMode(FAN, OUTPUT);
}

void loop() {
  // Turns on/off fan
  if (digitalRead(POWER_BUTTON) == HIGH) (on) ? turnOff() : turnOn();
  // Controls fan speed
  if (digitalRead(INCREASE_BUTTON) == HIGH) if (fanSpeed < 4)  fanSpeed++;
  if (digitalRead(DECREASE_BUTTON) == HIGH) if (fanSpeed > 1)  fanSpeed--;
  // Controls motor depending fan speed
  if (on){
    switch (fanSpeed){
      case 1:
        analogWrite(FAN, 128);
        break;
      case 2:
        analogWrite(FAN, 192);
        break;
      case 3:
        analogWrite(FAN, 255);
        break;
      default:
        break;
    }
  }
  
  delay(500);
}

// Turns on fan
void turnOn(){
  digitalWrite(FAN, HIGH);
  on = true;
}

// Turns off fan
void turnOff(){
  digitalWrite(FAN, LOW);
  on = false;
}