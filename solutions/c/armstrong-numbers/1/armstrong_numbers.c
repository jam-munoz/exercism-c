#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate)
{
    if (candidate < 0)
        return false;
    int digit_number = 0, temp = candidate, i, armstrong = 0;
    while (temp > 0)
    {
        temp /= 10;
        digit_number++;
    }
    temp = candidate;
    int digits[digit_number];
    for (i = 0; i < digit_number; i++)
    {
        digits[i] = temp % 10;
        temp /= 10;
    }
    for (i = 0; i < digit_number; i++)
    {
        armstrong += pow(digits[i], digit_number);
    }
    if (armstrong == candidate)
        return true;
    else return false;
}