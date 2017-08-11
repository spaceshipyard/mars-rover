#include <MovingPlatform.h>
#include <MotorShieldMovingPlatform.h>

#include <Arduino.h>
#include <AFMotor.h>

#define SIDE_MOTORS_SIZE 2
#define ALL_MOTORS_SIZE SIDE_MOTORS_SIZE * 2

AF_DCMotor side1_1(1);
AF_DCMotor side1_2(2);
AF_DCMotor side2_1(3);
AF_DCMotor side2_2(4);

AF_DCMotor motorGroupLeft[SIDE_MOTORS_SIZE] = {side1_1, side1_2};;
AF_DCMotor motorGroupRight[SIDE_MOTORS_SIZE] =  {side2_1, side2_2};
AF_DCMotor allMotors[ALL_MOTORS_SIZE] = {motorGroupLeft[0], motorGroupLeft[1], motorGroupRight[0], motorGroupRight[1]};

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

void pauseBeforeChangeDirection() {
  setRunForMotors(allMotors, ALL_MOTORS_SIZE, RELEASE);
  delay(100);
}

//motorGroupLeft = {side1_1, side1_2};
//motorGroupRight[SIDE_MOTORS_SIZE] = {side2_1, side2_2};
//allMotors[ALL_MOTORS_SIZE] = {motorGroupLeft[0], motorGroupLeft[1], motorGroupRight[0], motorGroupRight[1]};

MotorShieldMovingPlatform::MotorShieldMovingPlatform() {

}

void MotorShieldMovingPlatform::setup() {
  setMotorsSpeed(allMotors, ALL_MOTORS_SIZE, 255);
  setRunForMotors(allMotors, ALL_MOTORS_SIZE, RELEASE);
};

void MotorShieldMovingPlatform::setDirecton(int dir) {
    pauseBeforeChangeDirection();
    setRunForMotors(allMotors, ALL_MOTORS_SIZE, dir);
}

void MotorShieldMovingPlatform::setSpeed(byte speed) {
  setMotorsSpeed(allMotors, ALL_MOTORS_SIZE, speed);
}

void MotorShieldMovingPlatform::rotateToLeft() {
  pauseBeforeChangeDirection();
  setRunForMotors(motorGroupLeft, SIDE_MOTORS_SIZE, FORWARD);
  setRunForMotors(motorGroupRight, SIDE_MOTORS_SIZE, BACKWARD);
}

void MotorShieldMovingPlatform::rotateToRigth() {
  pauseBeforeChangeDirection();
  setRunForMotors(motorGroupLeft, SIDE_MOTORS_SIZE, BACKWARD);
  setRunForMotors(motorGroupRight, SIDE_MOTORS_SIZE, FORWARD);
}

void MotorShieldMovingPlatform::setLeftSpeed(byte speed) {
  setMotorsSpeed(motorGroupLeft, SIDE_MOTORS_SIZE, speed);
}

void MotorShieldMovingPlatform::setRightSpeed(byte speed) {
  setMotorsSpeed(motorGroupRight, SIDE_MOTORS_SIZE, speed);
}
