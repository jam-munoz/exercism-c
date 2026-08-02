#include "collatz_conjecture.h"
int steps(int start)
{
    int i = 0;
    if (start == 1)
        return 0;
    if (start < 1)
        return -1;
    while (start > 1)
    {
        if (start % 2 != 0)
        {
            start = (start * 3) + 1;
            i++;
        }
        else
        {
            start /= 2;
            i++;
        }
    }
    return i;
}