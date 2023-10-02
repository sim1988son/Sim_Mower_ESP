#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
// #include "config.h"

class MotorClass
{
public:
  MotorClass(int , int , int , int);
  ~MotorClass();
  void motorBegin();
  void flipLeftMotor(boolean);
  void flipRightMotor(boolean);
  void setLeftMotor(int);
  void setRightMotor(int);
  void go(int, int);
  void stop();

private:
  int _pin_A1;
  int _pin_A2;
  int _pin_B1;
  int _pin_B2;
  int _speedMax;
  int _speedSlow;
  int LED_CHANELL_1A;
  int LED_CHANELL_2A;
  int LED_CHANELL_1B;
  int LED_CHANELL_2B;
  int FREQ;
  int RESOLUTION;

};


#endif
