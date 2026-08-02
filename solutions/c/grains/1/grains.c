#include "grains.h"
uint64_t square(uint8_t index)
{
    if (index > 0 && index <= 64)
    {
        unsigned long n = 1;
        for (int i = 1; i < index; i++)
        {
            n *= 2;
        }
    return n;
    }
    else return 0;
}
uint64_t total(void)
{
    int n = (square(64));
    int i = 64;
    while (i > 0)
        n = n + square(i--);
    return n;
}