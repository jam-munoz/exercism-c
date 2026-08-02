#include "perfect_numbers.h"
kind classify_number(int number)
{
    if (number <= 0)
        return ERROR;
    int i, aliquot = 0;
    for(i = 1; i <= (number / 2); i++)
    {
        if (number % i == 0)
            aliquot += i;
    }
    if (number == aliquot)
        return PERFECT_NUMBER;
    if (number < aliquot)
        return ABUNDANT_NUMBER;
    if (number > aliquot)
        return DEFICIENT_NUMBER;
    return ERROR;
}