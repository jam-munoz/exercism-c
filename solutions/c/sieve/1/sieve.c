#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    if (max_primes < 1 || limit < 2)
        return 0;
    
    uint32_t i, k, j = 0, count = 0;
    bool *marked = calloc(limit + 1, sizeof(bool));
    
    for (i = 2; i <= limit && count < max_primes; i++)
    {
        if (!marked[i])
        {
            primes[j++] = i;
            count++;
            k = i << 1;
            while (k <= limit)
            {
                if (!marked[k])
                    marked[k] = true;
                k += i;
            }
        }
    }
    free(marked);
    return count;
}