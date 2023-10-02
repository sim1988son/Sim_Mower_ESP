#include <Arduino.h>
// #include "config.h"
#include "mower.h"
// #include "NewPing.h"

// MowerClass robot;

// MowerClass::Mower()
// {
//     name = "Sim_mower_ESP";
// }
MowerClass *MowerClass::_mower = nullptr;
// MowerClass::~Mower()
// {
// }

// NewPing NewSonarLeft(pinSonarLeftTrigger, pinSonarLeftEcho, 80);
// NewPing NewSonarRight(pinSonarRightTrigger, pinSonarRightEcho, 80);
// NewPing NewSonarCenter(pinSonarCenterTrigger, pinSonarCenterEcho, 80);

// void MowerClass::setup()
// {
    
//     Robot::setup(); 
// }

// int MowerClass::readSensor(char type){
//     switch (type) {
//         // sonar---------------------------------------------------------------------------------------------------
//         case SEN_SONAR_CENTER: return(NewSonarCenter.ping_cm()); break;
//         case SEN_SONAR_LEFT: return(NewSonarLeft.ping_cm()); break;
//         case SEN_SONAR_RIGHT: return(NewSonarRight.ping_cm()); break; 
//     }
//     return 0;   
// }