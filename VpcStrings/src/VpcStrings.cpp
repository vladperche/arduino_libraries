#include "Arduino.h"
#include "VpcStrings.h"

VpcStrings::VpcStrings()
{
}

String VpcStrings::PadL(String source, char filler, int size)
{
    String output = source;
    while (output.length() < size)
    {
        String empty = "";
        empty.concat(filler);
        empty.concat(output);
        output = empty;
    }
    return output;
}

String VpcStrings::PadR(String source, char filler, int size)
{
    String output = source;
    while (output.length() < size)
    {
        output.concat(filler);
    }
    return output;
}
