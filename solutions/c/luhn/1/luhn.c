#include "luhn.h"

int num_count(const char *num)
{
    int count = 0;
    for (int i = 0; num[i]; i++)
    {
        if (isdigit(num[i]))
            count++;
    }
    return count;
}

bool luhn(const char *num)
{
    int i, k, sum = 0;
    
    for (i = 0; num[i]; i++)
    {
        if (!(isdigit(num[i]) || isspace(num[i])))
            return false;
    }
    int count = num_count(num);
    if (count < 2)
        return false;
    
    int *str = malloc(count * sizeof(int));
    for (i = 0, k = 0; num[i]; i++)
    {
        if (isdigit(num[i]))
        {
            str[k] = num[i] - '0';
            k++;
        }
    }
    for (i = count - 2; i >= 0; i = i - 2)
    {
        str[i] *= 2;
        if (str[i] > 9)
            str[i] -= 9;
    }
    for (i = 0; i < count; i++)
    {
          sum += str[i];
    }
    free(str);
    if (sum % 10 == 0)
            return true;
    else
            return false;
}