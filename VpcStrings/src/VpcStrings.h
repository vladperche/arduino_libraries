/*
 *
 */

#ifndef VPC_STRINGS
#define VPC_STRINGS

#include "Arduino.h"

class VpcStrings
{
private:
public:
    VpcStrings();
    static String PadL(String source, char filler, int size);
    static String PadR(String source, char filler, int size);
    static String DateToDDMMYYYY(int year, int month, int day);
    static String DateToDDMMYY(int year, int month, int day);
    static String TimeToHHMMSS(int hour, int minutes, int seconds);
};

#endif
