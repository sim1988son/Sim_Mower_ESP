#ifndef _MOTOR_H
#define _MOTOR_H

#include <Arduino.h>

class Motor
{
  int _pin_A1;
  int _pin_A2;
  int _pin_B1;
  int _pin_B2;
public:
  Motor(int, int, int, int);
  ~Motor();
  void begin();

}



#endif
