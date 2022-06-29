SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
//give the pins a name
#define lightSensor A5
#define LED D5
#define signal D4
//define variables to 0
int maxValue = 0;
int minValue = 0;
int timer = 0;

void setup() {
  //setting up pins
  pinMode(lightSensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(signal, OUTPUT);
}


void loop() {
  //reading the value from light sensor
  int value = analogRead(lightSensor);
  //finding greatest value from value
  maxValue = max(maxValue, value);
  //finding smallest value from value
  minValue = min(minValue, value);
  //turning the value into a range of 0-255
  int brightness = map(value, minValue, maxValue, 0, 255);
  //brighting up the LED
  analogWrite(LED, brightness);
  //setting up timer which lasts in total 5 seconds split in short amounts of time so the other code would acc run as well
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