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

String VpcStrings::DateToDDMMYYYY(int year, int month, int day)
{
    String value = VpcStrings->PadL(day, '0', 2);
    value += "/";
    value += VpcStrings->PadL(month, '0', 2);
    value += "/";
    value += VpcStrings->PadL(year, '0', 4);
    return value;
}

String VpcStrings::DateToDDMMYY(int year, int month, int day)
{
    String value = VpcStrings->PadL(day, '0', 2);
    value += "/";
    value += VpcStrings->PadL(month, '0', 2);
    value += "/";
    value += VpcStrings->PadL(year % 100, '0', 2);
    return value;
}

String VpcStrings::TimeToHHMMSS(int hour, int minutes, int seconds)
{
    String value = VpcStrings->PadL(hour, '0', 2);
    value += ":";
    value += VpcStrings->PadL(minutes, '0', 2);
    value += ":";
    value += VpcStrings->PadL(seconds, '0', 4);
    return value;
}

String VpcStrings::CDoW_smallest(int dow)
{
    String daysOfTheWeek[7] = {
        "DOM",
        "SEG",
        "TER",
        "QUA",
        "QUI",
        "SEX",
        "SAB"
    };
    return daysOfTheWeek[dow];
}

String VpcStrings::CDoW_short(int dow)
{
    String daysOfTheWeek[7] = {
        "Domingo",
        "Segunda",
        "Terca",
        "Quarta",
        "Quinta",
        "Sexta",
        "Sabado"
    };
    return daysOfTheWeek[dow];
}

String VpcStrings::CDoW_long(int dow)
{
    String daysOfTheWeek[7] = {
        "Domingo",
        "Segunda-feira",
        "Terca-feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sabado"
    };
    return daysOfTheWeek[dow];
}
