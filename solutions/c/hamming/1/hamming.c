#include "hamming.h"
int compute(const char *lhs, const char *rhs)
{
    int h = 0;
    
    if (strlen(lhs) == 0 && strlen(rhs) == 0)
        return 0;
    if (strlen(lhs) == 0 || strlen(rhs) == 0 || strlen(lhs) != strlen(rhs))
        return -1;
    for (int i = 0; i < (int) strlen(lhs); i++)
    {
        if (*(lhs + i) != *(rhs + i))
            h++;
    }
    return h;
}