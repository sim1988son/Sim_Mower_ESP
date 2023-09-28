#include <Arduino.h>

Motor(int A1, int A2, int B1, int B2){
    _pin_A1 = A1;
    _pin_A2 = A2;
    _pin_B1 = B1;
    _pin_B2 = B2;
  }

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
