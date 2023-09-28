#ifndef _MOTOR_H
#define _MOTOR_H

#include <Arduino.h>
#include "config.h"

class Motor
{
  int _pin_A1;
  int _pin_A2;
  int _pin_B1;
  int _pin_B2;
  int _speedMax;
  int _speedSlow;

  void move_A(int);
  void move_B(int);

public:
  Motor(int, int, int, int);
  ~Motor();
  void begin();
  void go();
  void go_slow();
  void go_back();
  void foward(int, int);
  void back(int, int);
  void left(int, int);
  void right(int, int);
  void stop();

};



#endif
