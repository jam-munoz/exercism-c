#include "binary.h"
int convert(const char *input)
{
    int sum = 0;
    for (int i = strlen(input)-1, pwr = 1; i >= 0; i--, pwr *= 2)
    {
        if (input[i] != '0' && input[i] != '1')
            return INVALID;
        sum += (input[i] - 48) * pwr;
    }
    return sum;
}