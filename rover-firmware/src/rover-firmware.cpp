#include <Arduino.h>
#include <MotorShieldMovingPlatform.h>
#include <Controller.h>




MotorShieldMovingPlatform movingPlatform;
Controller ctrl(movingPlatform);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.setTimeout(2000);
  // turn on motor
  ctrl.setup();
}

void loop() {
  ctrl.onTick();
  delay(100);
}
