#include <Arduino.h>
#include "config.h"
#include "robot.h"
// #include "motor.h"

// Motor motor;

Robot::Robot()
{
    name = "mower";

}

Robot::~Robot()
{

}


void Robot::setup()
{
    // motor->begin();

}

void Robot::loop()
{
    readSensors();
}