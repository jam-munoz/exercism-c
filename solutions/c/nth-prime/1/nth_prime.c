#include "nth_prime.h"

uint32_t nth(uint32_t n)
{
    if (n == 0)
        return 0;
    
    uint32_t i = 2;
    uint32_t count = 0;

    for (; count < n; i++)
    {
        if (is_prime(i))
            count++;
    }
    i--;
    
    return i;
}

bool is_prime(uint32_t n)
{
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    uint32_t i = 5;
    
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}