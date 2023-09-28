#include <Arduino.h>
#include "config.h"
#include "motor.h"

Motor motor(MA1, MA2, MB1, MB2);

void setup(){
motor.begin();

}

void loop(){

}
