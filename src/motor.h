#ifndef _MOTOR_H
#define _MOTOR_H

#include <Arduino.h>

class Motor
{
private:
int _pin_A1;
int _pin_A2;
int _pin_B1;
int _pin_B2;
public:
  motor(int pin_A1, int pin_A2, int pin_B1, int pin_B2){
    _pin_A1 = pin_A1;
    _pin_A2 = pin_A2;
    _pin_B1 = pin_B1;
    _pin_B2 = pin_B2;
  }
  ~motor();
  void begin(){
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

}



#endif
