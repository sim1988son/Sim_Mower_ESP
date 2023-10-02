#pragma once

#include <Arduino.h>
// !!!!BOARD !!!
#define MOWER_ESP


// => Options
#if defined(MOWER_ESP)
#include "board/MOWER_ESP.h"
#define MOWER_ESP_MOTOR
#endif


#include "drive/motor/motor.h"

#include "drive/i2c/i2c_bus.h"

class MowerClass 
{
public:
    static MowerClass *getMower()
    {
        if (_mower == nullptr) {
            _mower = new MowerClass();
            // _tpEvent = xEventGroupCreate();
        }
        return _mower;
    }

    void begin( uint8_t disable = 0 )
    {
        i2c = new I2CBus();

    #if defined(MOWER_ESP_MOTOR)
        motor = new MotorClass(pinMotorLeft1A, pinMotorLeft1B, pinMotorRight2A, pinMotorRight2B); 
    #endif /*MOWER_ESP_MOTOR*/

        initHardware();

    }


    I2CBus *i2c = nullptr;
    static MowerClass *_mower;

    MotorClass *motor = nullptr;



    /******************************************
     *              Wire1
     * ***************************************/

    I2CBus *wire;

    //Use the second set of I2C interfaces
    void beginWire(uint8_t sda = 25, uint8_t scl = 26)
    {
        wire = new I2CBus(Wire1, sda, scl);
    }

    TwoWire &getWire()
    {
        return (*wire->getHandler());
    }

/*TWI1*/

// bool initMotor()
// {
//     if (motor == nullptr) {
//         log_e("TFT Handler is NULL!!!");
//         return;
//     }
//     motor->motorBegin();
// }

private:
    MowerClass()
    {
    };

    ~MowerClass()
    {
    };

    void initHardware(void)
    {

        motor->motorBegin(); /*MOWER_ESP_MOTOR*/
    }
};

// extern MowerClass robot;

