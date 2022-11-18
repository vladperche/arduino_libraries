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
};

#endif