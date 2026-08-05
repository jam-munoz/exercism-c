#include "sum_of_multiples.h"

bool is_modulus(const unsigned int *factors, const size_t number_of_factors, const unsigned int i)
{
    for (size_t k = 0; k < number_of_factors; k++)
    {
        if (factors[k] == 0)
            return false;
        if (i % factors[k] == 0)
            return true;
    }
    return false;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
    unsigned int sum = 0, i;
    for (i = 0; i < limit; i++)
    {
        if (is_modulus(factors, number_of_factors, i))
            sum += i;
    }
    return sum;
}