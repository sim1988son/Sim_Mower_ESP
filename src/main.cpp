// !!!!BOARD !!!
#define MOWER_ESP


#include <Arduino.h>
#include "mower.h"


MowerClass *mower = MowerClass::getMower();

void setup(){
    mower->begin();
    mower->motor->go(255,255);
    
}

void loop(){
    // robot.loop();
}
