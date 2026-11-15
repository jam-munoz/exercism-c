#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int value)
{
    unsigned int eggs = 0;
    
    while (value > 0)
    {
        if (value & 0x1)
            eggs++;
        value >>= 1;
    }
    return eggs;
}