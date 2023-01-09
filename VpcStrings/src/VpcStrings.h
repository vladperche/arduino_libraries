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
        /* Converte um número [0-7] para a sigla do dia da semana (DOM, SEG, TER, etc...) */
        static String CDoW_smallest(int dow);
        /* Converte um número [0-7] para o nome do dia da semana abreviado (domingo, segunda, terça, etc...) */
        static String CDoW_short(int dow);
        /* Converte um número [0-7] para o nome do dia da semana completo (domingo, segunda-feira, terça-feira, etc...) */
        static String CDoW_long(int dow);
};

#endif
