#ifndef _MOTOR_SHIELD_MOVING_PLATFORM_H_
#define _MOTOR_SHIELD_MOVING_PLATFORM_H_

#include <MovingPlatform.h>
#include <Arduino.h>


class MotorShieldMovingPlatform : public MovingPlatform {

private:


public:
  MotorShieldMovingPlatform();

  void setup() override;

  void setDirecton(int dir) override;

  void setSpeed(byte speed) override;

  void rotateToLeft() override;

  void rotateToRigth() override;

  void setLeftSpeed(byte speed) override;

  void setRightSpeed(byte speed) override;

};


#endif /* end of include guard: _MOTOR_SHIELD_MOVING_PLATFORM_H_ */
