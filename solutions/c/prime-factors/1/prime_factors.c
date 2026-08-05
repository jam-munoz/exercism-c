#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    size_t len = 0;
    uint64_t i = 2;
    int j = 0;
    
    while (n >= i && j < MAXFACTORS)
    {
        if (n % i == 0)
        {
            len++;
            factors[j++] = i;
            n /= i;
        }
        else
            i++;
    }
    return len;
}
