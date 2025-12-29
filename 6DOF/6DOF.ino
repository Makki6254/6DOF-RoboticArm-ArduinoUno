#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 

float servoPos[6] = {90.0, 90.0, 90.0, 90.0, 90.0, 90.0}; 
const int pins[4] = {A0, A1, A2, A3}; 
const int swPin = 2; 

int centers[4];
int deadzone = 150; 
bool currentMode = false;

// --- ADDED SPEED VARIABLE ---
float moveSpeed = 0.5; 

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  pinMode(swPin, INPUT_PULLUP);

  delay(1000);
  for(int i = 0; i < 4; i++) centers[i] = analogRead(pins[i]);
}

void loop() {
  if (digitalRead(swPin) == LOW) {
    currentMode = !currentMode;
    Serial.println(currentMode ? "Mode: WRIST" : "Mode: BASE");
    delay(500); 
  }

  if (!currentMode) {
    updateAxis(0, 1, 0, 1); 
    updateAxis(2, 3, 2, 3); 
  } else {
    updateAxis(0, 1, 4, 5); 
  }

  for (int i = 0; i < 6; i++) {
    servoPos[i] = constrain(servoPos[i], 0, 180);
    // Cast to int for mapping to PCA9685 pulse
    pwm.setPWM(i, 0, map((int)servoPos[i], 0, 180, SERVOMIN, SERVOMAX));
  }
  
  // A small delay helps regulate the speed/loop timing
  delay(10); 
}

void updateAxis(int ax, int ay, int sx, int sy) {
  int x = analogRead(pins[ax]);
  int y = analogRead(pins[ay]);
  
  if (abs(x - centers[ax]) > abs(y - centers[ay]) && abs(x - centers[ax]) > deadzone) {
    // --- UPDATED TO USE moveSpeed ---
    if (x > centers[ax]) servoPos[sx] += moveSpeed;
    else servoPos[sx] -= moveSpeed;
  } 
  else if (abs(y - centers[ay]) > abs(x - centers[ax]) && abs(y - centers[ay]) > deadzone) {
    // --- UPDATED TO USE moveSpeed ---
    if (y > centers[ay]) servoPos[sy] += moveSpeed;
    else servoPos[sy] -= moveSpeed;
  }
}