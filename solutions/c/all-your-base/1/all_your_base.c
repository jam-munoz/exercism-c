#include "all_your_base.h"

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length)
{
    if (input_base < 2 || output_base < 2 || input_length < 1)
        return 0;
    if (input_base == output_base)
        return input_length;

    size_t i = 0, len;
    int j;
    long sum = 0;
    
    for (; !digits[i]; i++);
    for (; i < input_length; i++)
    {
        if (digits[i] < 0 || digits[i] >= input_base)
            return 0;
        sum = (sum * input_base) + digits[i];
        digits[i] = 0;
    }
    len = digit_count(sum, output_base);
    
    for (j = len - 1; j >= 0; j--)
    {
        digits[j] = sum % output_base;
        sum /= output_base;
    }
    return len;
}
    
size_t digit_count(long n, int16_t output_base)
{
    if (n == 0)
        return 1;
        
    if (output_base == 10)
    {
    	if (n < 10)
    		return (1);
    	if (n < 100)
    		return (2);
    	if (n < 1000)
    		return (3);
    	if (n < 10000)
    		return (4);
    	if (n < 100000)
    		return (5);
    	if (n < 1000000)
    		return (6);
    	if (n < 10000000)
    		return (7);
    	if (n < 100000000)
    		return (8);
    	if (n < 1000000000)
    		return (9);
    	return (10);
    }
    else
    {
        size_t digit_count = 0;
        
        while (n > 0)
        {
            n /= output_base;
            digit_count++;
        }
        return digit_count;
    }
}

