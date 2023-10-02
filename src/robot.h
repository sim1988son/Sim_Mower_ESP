#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
// #include "config.h"
#include "drive/motor/motor.h"

// sensors
enum {
    SEN_MOTOR_LEFT,        // 0..MAX_MOTOR_CURRENT
    SEN_MOTOR_RIGHT,       // 0..MAX_MOTOR_CURRENT
    SEN_MOTOR_MOW,         // 0..MAX_MOW_CURRENT   
    SEN_SONAR_CENTER,      // 0..SONAR_TRIGGER_DISTANCE
    SEN_SONAR_LEFT,        // 0..SONAR_TRIGGER_DISTANCE
    SEN_SONAR_RIGHT,       // 0..SONAR_TRIGGER_DISTANCE
};

// finate state machine states
enum { 
    STATE_OFF,          // off
    STATE_ROS,          // Linux ROS control
    STATE_REMOTE,       // model remote control (R/C)
    STATE_FORWARD,      // drive forward
    STATE_ROLL,         // drive roll right/left  
    STATE_REVERSE,      // drive reverse
    STATE_CIRCLE,       // drive circle  
    STATE_ERROR,        // error
    STATE_PERI_FIND,    // perimeter find 
    STATE_PERI_TRACK,   // perimeter track
    STATE_PERI_ROLL,    // perimeter roll
    STATE_PERI_REV,     // perimeter reverse
    STATE_STATION,       // in station
    STATE_STATION_CHARGING,       // in station charging
    STATE_STATION_CHECK, //checks if station is present
    STATE_STATION_REV,   // charge reverse
    STATE_STATION_ROLL,  // charge roll
    STATE_STATION_FORW,  // charge forward
    STATE_MANUAL,       // manual navigation  
    STATE_ROLL_WAIT,    // drive roll right/left
    STATE_PERI_OUT_FORW, // outside perimeter forward driving without checkPerimeterBoundary()
    STATE_PERI_OUT_REV,   // outside perimeter reverse driving without checkPerimeterBoundary()
    STATE_PERI_OUT_ROLL,   // outside perimeter rolling driving without checkPerimeterBoundary()
    STATE_TILT_STOP,    // tilt sensor activated, stop motors, wait for un-tilt
    STATE_BUMPER_REVERSE,      // drive reverse
    STATE_BUMPER_FORWARD,      // drive forward	
};


class Robot
{
public:
    String name;
    // --------- state machine --------------------------
    byte stateCurr;



    Robot();
    ~Robot();
    virtual void setup();
    virtual void loop();

private:
    
    /* data */
protected:
    // read sensors
    virtual void readSensors();
};



#endif