#include "Arduino.h"
#include "VpcRotary.h"

/*
 * Constructor for "simple" version
 * (without Switch button)
 * Just check for rotation states
 * Params:
 * pinDT = wired port for Detection pin
 * pinClk = wired port for Clokwise direction
 */
VpcRotary::VpcRotary(int pinDT, int pinClk)
{
    this->pinDT = pinDT;
    this->pinClk = pinSW;
    this->pinSW = -1;
    this->setPinMode();
    this->readInitialState();
}

/*
 * Constructor for full version
 * (with Switch button)
 * Check for rotation states and Switch (click)
 * Params:
 * pinDT = wired port for Detection pin
 * pinClk = wired port for Clokwise direction
 * pinSW = wired port for Switch pin
 */
VpcRotary::VpcRotary(int pinDT, int pinClk, int pinSW)
{
    this->pinSW = pinSW;
    this->pinDT = pinDT;
    this->pinClk = pinClk;
    this->setPinMode();
    this->readInitialState();
}

void VpcRotary::setPinMode()
{
    movedClockwise = false;
    movedCounterclock = false;

    pinMode(pinSW, INPUT_PULLUP);
    pinMode(pinDT, INPUT_PULLUP);
    if(pinClk >= 0)
        pinMode(pinClk, INPUT_PULLUP);
}

void VpcRotary::readInitialState()
{
    lastMove = millis();
    oldStateSW = digitalRead(pinSW);
    oldStateDT = digitalRead(pinDT);
    if(pinClk >= 0)
        oldStateClk = digitalRead(pinClk);
}

void VpcRotary::check()
{
    long unsigned currMilis = millis();
    int curStateClk = digitalRead(pinClk);

    movedClockwise = false;
    movedCounterclock = false;
    if(curStateClk != oldStateClk)
    {
        int curStateDT = digitalRead(pinDT);
        if(curStateDT != curStateClk && currMilis - lastMove > 500)
        {
            //Moved in the clockwise direction
            movedClockwise = true;
        }
        else
        {
            //Moved counterclockwise
            movedCounterclock = true;
        }
        oldStateClk = curStateClk;
        lastMove = currMilis;
        delay(200);
    }

    if(pinSW >= 0)
    {
        int curStateSW = digitalRead(pinSW);
        if(curStateSW != oldStateSW)
        {
            if(oldStateSW)
            {
                //Pressed
                pushDown = true;
                pushUp = false;
            }
            else
            {
                //Released
                pushUp = true;
                pushDown = false;
            }
            oldStateSW = curStateSW;
        }
    }
}

bool VpcRotary::isClockwise()
{
    return movedClockwise;
}

bool VpcRotary::isCounterclock()
{
    return movedCounterclock;
}

bool VpcRotary::buttonUp()
{
    bool isPushUp = pushUp;
    pushUp = false;
    return isPushUp;
}

bool VpcRotary::buttonDown()
{
    bool isPushDown = pushDown;
    pushDown = false;
    return isPushDown;
}
