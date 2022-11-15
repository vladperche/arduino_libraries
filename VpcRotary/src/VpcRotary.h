/*
 *
 */

#ifndef VPC_ROTARY
#define VPC_ROTARY

#include "Arduino.h"

class VpcRotary
{
    public:
        VpcRotary(int pinDT, int pinClk);
        VpcRotary(int pinDT, int pinClk, int pinSW);
        void check();
        bool isClockwise();
        bool isCounterclock();
        bool buttonUp();
        bool buttonDown();
        
    private:
        void setPinMode();
        void readInitialState();
        int pinSW;
        int pinDT;
        int pinClk;
        int oldStateSW;
        int oldStateDT;
        int oldStateClk;
        long unsigned lastMove;
        bool movedClockwise;
        bool movedCounterclock;
        bool pushUp;
        bool pushDown;
};

#endif
