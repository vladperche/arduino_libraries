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

        void setValue(int value);
        int getValue(void);
        
        void setStep(int step);
        void setMinValue(int minValue);
        void setMaxValue(int maxValue);
        void Loop(bool loop);
        
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

        int value;
        int step;
        int minValue;
        int maxValue;
        bool loop;
};

#endif
