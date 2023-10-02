#include <Arduino.h>
// #include "config.h"
#include "drive/motor/motor.h"

static boolean flipLeft = false;
static boolean flipRight = false;

MotorClass::MotorClass(int _A1, int _A2, int _B1, int _B2)
// Motor::Motor()
{
  _pin_A1 = _A1;
  _pin_A2 = _A2;
  _pin_B1 = _B1;
  _pin_B2 = _B2;
  _speedMax = 255;
  _speedSlow = 160;
  LED_CHANELL_1A = 0;
  LED_CHANELL_2A = 1;
  LED_CHANELL_1B = 2;
  LED_CHANELL_2B = 3;
  FREQ = 2000;
  RESOLUTION = 8;
}

MotorClass::~MotorClass()
{

}

void MotorClass::motorBegin()
{
  ledcSetup(LED_CHANELL_1A, FREQ, RESOLUTION);
  ledcSetup(LED_CHANELL_2A, FREQ, RESOLUTION);
  ledcSetup(LED_CHANELL_1B, FREQ, RESOLUTION);
  ledcSetup(LED_CHANELL_2B, FREQ, RESOLUTION);
  ledcAttachPin(_pin_A1, LED_CHANELL_1A); 
  ledcAttachPin(_pin_A2, LED_CHANELL_2A);
  ledcAttachPin(_pin_B1, LED_CHANELL_1B); 
  ledcAttachPin(_pin_B2, LED_CHANELL_2B);
  stop();
}

// enable/disable flipping of left motor
void MotorClass::flipLeftMotor(boolean flip)
{
  flipLeft = flip;
}

// enable/disable flipping of right motor
void MotorClass::flipRightMotor(boolean flip)
{
  flipRight = flip;
}

// set speed for left motor; speed is a number between -255 and 255
void MotorClass::setLeftMotor(int _speed)
{
  if(flipLeft)_speed = -_speed;
  if(_speed > 0)
  {
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1A, 0);
    ledcWrite(LED_CHANELL_2A, _speed);
  }
  else if(_speed <= 0)
  {
    _speed = -_speed;
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1A, _speed);
    ledcWrite(LED_CHANELL_2A, 0);
  }
}

// set speed for right motor; speed is a number between -255 and 255
void MotorClass::setRightMotor(int _speed)
{
  if(flipRight)_speed = -_speed;
  if(_speed > 0)
  {
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1B, 0);
    ledcWrite(LED_CHANELL_2B, _speed);
  }
  else if(_speed <= 0)
  {
    _speed = -_speed;
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1B, _speed);
    ledcWrite(LED_CHANELL_2B, 0);
  }
}

// set speed for both motors
void MotorClass::go(int _speed_A, int _speed_B)
{
  setLeftMotor(_speed_A);
  setRightMotor(_speed_B);
}

// set stop for both motors
void MotorClass::stop()
{
  ledcWrite(LED_CHANELL_1A, 0);
  ledcWrite(LED_CHANELL_2A, 0);
  ledcWrite(LED_CHANELL_1B, 0);
  ledcWrite(LED_CHANELL_2B, 0);
}

