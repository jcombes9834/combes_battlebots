// Basic sketch for trying out the Adafruit DRV8871 Breakout
#include <Arduino.h>

const int RIGHT_IN1 = 3;
const int RIGHT_IN2 = 5;

const int LEFT_IN1 = 6;
const int LEFT_IN2 = 9;

void setup() 
{
  pinMode(RIGHT_IN1, OUTPUT);
  pinMode(RIGHT_IN2, OUTPUT);
  pinMode(LEFT_IN1, OUTPUT);
  pinMode(LEFT_IN2, OUTPUT);
  delay(500);
}

void loop() {

  // ramp up forward
  digitalWrite(LEFT_IN1, LOW);
  digitalWrite(RIGHT_IN1, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(LEFT_IN2, i);
    analogWrite(RIGHT_IN2, i);
    delay(10);
  }

  // forward full speed for one second
  delay(1000);

  // ramp down forward
  for (int i=255; i>=0; i--) {
    analogWrite(LEFT_IN2, i);
    analogWrite(RIGHT_IN2, i);
    delay(10);
  }
  delay(2000);
/*
  // ramp up backward
  digitalWrite(MOTOR_IN2, LOW);
  for (int i=0; i<255; i++) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }

  // backward full speed for one second
  delay(1000);

  // ramp down backward
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR_IN1, i);
    delay(10);
  }
  */
}