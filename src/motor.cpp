#include <Arduino.h>
// #include "config.h"
#include "motor.h"


Motor::Motor(int A_1, int A_2, int B_1, int B_2)
{
  _pin_A1 = A_1;
  _pin_A2 = A_2;
  _pin_B1 = B_1;
  _pin_B2 = B_2;
  _speedMax = 255;
  _speedSlow = 160;
}

Motor::~Motor(){}

void Motor::begin()
{
  ledcSetup(LED_CHANELL_1A, FREQ, RESOLUTION);
  ledcSetup(LED_CHANELL_2A, FREQ, RESOLUTION);
  ledcSetup(LED_CHANELL_1B, FREQ, RESOLUTION);
  ledcSetup(LED_CHANELL_2B, FREQ, RESOLUTION);
  ledcAttachPin(_pin_A1, LED_CHANELL_1A); 
  ledcAttachPin(_pin_A2, LED_CHANELL_2A);
  ledcAttachPin(_pin_B1, LED_CHANELL_1B); 
  ledcAttachPin(_pin_B2, LED_CHANELL_2B);
  ledcWrite(LED_CHANELL_1A, 0);
  ledcWrite(LED_CHANELL_2A, 0);
  ledcWrite(LED_CHANELL_1B, 0);
  ledcWrite(LED_CHANELL_2B, 0);
}

void Motor::go()
{
  foward(_speedMax, _speedMax);
}

void Motor::go_slow()
{
  foward(_speedSlow, _speedSlow);
}

void Motor::go_back()
{
  back(-_speedMax, -_speedMax);
}

void Motor::foward(int _speed_A, int _speed_B)
{
  move_A(_speed_A);
  move_B(_speed_B);
}

void Motor::back(int _speed_A, int _speed_B)
{
  move_A(_speed_A);
  move_B(_speed_B);
}

void Motor::left(int _speed_A, int _speed_B)
{
  move_A(_speed_A);
  move_B(_speed_B);
}

void Motor::right(int _speed_A, int _speed_B)
{
  move_A(_speed_A);
  move_B(_speed_B);
}

void Motor::stop()
{
  move_A(0);
  move_B(0);
}

void Motor::move_A(int _speed)
{
  if(_speed > 0)
  {
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1A, 0);
    ledcWrite(LED_CHANELL_2A, _speed);
  }
  else if(_speed < 0)
  {
    _speed = -_speed;
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1A, _speed);
    ledcWrite(LED_CHANELL_2A, 0);
  }
  else if(_speed == 0)
  {
    ledcWrite(LED_CHANELL_1A, 0);
    ledcWrite(LED_CHANELL_2A, 0);
  }
}

void Motor::move_B(int _speed)
{
  if(_speed > 0)
  {
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1B, 0);
    ledcWrite(LED_CHANELL_2B, _speed);
  }
  else if(_speed < 0)
  {
    _speed = -_speed;
    if(_speed > _speedMax)_speed = _speedMax;
    ledcWrite(LED_CHANELL_1B, _speed);
    ledcWrite(LED_CHANELL_2B, 0);
  }
  else if(_speed == 0)
  {
    ledcWrite(LED_CHANELL_1B, 0);
    ledcWrite(LED_CHANELL_2B, 0);
  }
}
