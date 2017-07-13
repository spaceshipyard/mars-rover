// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

#define SIDE_MOTORS_SIZE 2
#define ALL_MOTORS_SIZE SIDE_MOTORS_SIZE * 2


AF_DCMotor side1_1(1);
AF_DCMotor side1_2(4);
AF_DCMotor side2_1(2);
AF_DCMotor side2_2(3);

AF_DCMotor motorGroupLeft[SIDE_MOTORS_SIZE] = {side1_1, side1_2};
AF_DCMotor motorGroupRight[SIDE_MOTORS_SIZE] = {side2_1, side2_2};

AF_DCMotor allMotors[ALL_MOTORS_SIZE] = {motorGroupLeft[0], motorGroupLeft[1], motorGroupRight[0], motorGroupRight[1]};

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.setTimeout(1000);
  // turn on motor
  for (int i = 0; i < sizeof(allMotors); i++) {
      AF_DCMotor motor = allMotors[i];
      motor.setSpeed(255);
      motor.run(RELEASE);
  }
}

void setRunForMotors(AF_DCMotor motors[], int size, int dir) {
    for (int i = 0; i < size; i++) {
      AF_DCMotor motor = motors[i];
      motor.run(dir);
    }
}

void setMotorsSpeed(AF_DCMotor motors[], int size, byte speed) {
    for (int i = 0; i < size; i++) {
      AF_DCMotor motor = motors[i];
      motor.setSpeed(speed);
    }  
}

int strToDirection(String str) {
  if (str == "FORWARD") {
    return (FORWARD);
  } else if (str == "BACKWARD") {
    return (BACKWARD);
  } else if (str == "RELEASE") {
    return (RELEASE);
  }
  
  return RELEASE;
}

void loop() {
  
  while (Serial.available() > 0) {
    String cmd = Serial.readStringUntil(':');
    Serial.println(cmd);
    if (cmd == "direction") {
      String dirStr = Serial.readStringUntil(';');
      int dir = strToDirection(dirStr);
      setRunForMotors(allMotors, ALL_MOTORS_SIZE, dir);  
    } else if (cmd == "speed")  {
      String speedStr = Serial.readStringUntil(';');
      Serial.println(speedStr);
      setMotorsSpeed(allMotors, ALL_MOTORS_SIZE, speedStr.toInt());
    } else if (cmd == "dir-left") {
      String dirStr = Serial.readStringUntil(';');
      int dir = strToDirection(dirStr);
      setRunForMotors(motorGroupLeft, SIDE_MOTORS_SIZE, dir);  
    } else if (cmd == "dir-right") {
      String dirStr = Serial.readStringUntil(';');
      int dir = strToDirection(dirStr);
      setRunForMotors(motorGroupRight, SIDE_MOTORS_SIZE, dir);  
    }
  }
  
  delay(100);
}
