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

    pinMode(pinSW, INPUT);
    pinMode(pinDT, INPUT);
    if(pinClk >= 0)
        pinMode(pinClk, INPUT_PULLUP);
}

void VpcRotary::readInitialState()
{
    this->setValue(0);
    this->setMinValue(0);
    this->setMaxValue(0);
    this->setStep(0);
    this->Loop(false);
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
    if(curStateClk != oldStateClk && curStateClk == 1)
    {
        int curStateDT = digitalRead(pinDT);
        if(curStateDT != curStateClk)
        {
            //Moved in the clockwise direction
            value += step;
            if(value > maxValue)
            {
                if(loop)
                {
                    value = minValue;
                }
                else
                {
                    value = maxValue;
                }
            }
            movedClockwise = true;
        }
        else
        {
            value -= step;
            if(value < minValue)
            {
                if(loop)
                {
                    value = maxValue;
                }
                else
                {
                    value = minValue;
                }
            }
            //Moved counterclockwise
            movedCounterclock = true;
        }
        
        lastMove = currMilis;
        delay(1);
    }
    oldStateClk = curStateClk;

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
        }
        oldStateSW = curStateSW;
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

void VpcRotary::setValue(int value)
{
    this->value = value;
}

int VpcRotary::getValue(void)
{
    return this->value;
}

void VpcRotary::setStep(int step)
{
    this->step = step;
}

void VpcRotary::setMinValue(int minValue)
{
    this->minValue = minValue;
}

void VpcRotary::setMaxValue(int maxValue)
{
    this->maxValue = maxValue;
}

void VpcRotary::Loop(bool loop)
{
    this->loop = loop;
}
