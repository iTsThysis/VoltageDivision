/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/darwinwang/Documents/IoT/VoltageDivision/src/VoltageDivision.ino"
void setup();
void loop();
#line 1 "/Users/darwinwang/Documents/IoT/VoltageDivision/src/VoltageDivision.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#define lightSensor A5
#define LED D5
#define signal D4
int maxValue = 0;
int minValue = 0;
int timer = 0;

void setup() {
  pinMode(lightSensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(signal, OUTPUT);
  Serial.begin(9600);
  Serial.println(timer);
}


void loop() {
  
  int value = analogRead(lightSensor);
  maxValue = max(maxValue, value);
  minValue = min(minValue, value);
  
  int brightness = map(value, minValue, maxValue, 0, 255);
  
  analogWrite(LED, brightness);

  if (timer == 25) {
    maxValue = 0;
    minValue = 0;
    timer = 0;
    digitalWrite(signal, HIGH);
    delay(200);
  } else {
    timer = timer + 1;
    digitalWrite(signal, LOW);
    delay(192);
  }
  
}