#include "kindergarten_garden.h"

plants_t plants(const char *diagram, const char *student)
{
    plants_t p = { 0 };
    int start, i;
    
    switch(student[0])
    {
        case 'A': start = 0;
            break;
        case 'B': start = 2;
            break;
        case 'C': start = 4;
            break;
        case 'D': start = 6;
            break;
        case 'E': start = 8;
            break;
        case 'F': start = 10;
            break;
        case 'G': start = 12;
            break;
        case 'H': start = 14;
            break;
        case 'I': start = 16;
            break;
        case 'J': start = 18;
            break;
        case 'K': start = 20;
            break;
        case 'L': start = 22;
            break;
        default: return p;
    }
    
    i = start;
    p.plants[0] = convert_plant(diagram[i++]);
    p.plants[1] = convert_plant(diagram[i]);
    
    for (; diagram[i] && diagram[i] != '\n'; i++) ;
    if (diagram[i] == '\n')
        i += start + 1;
    else
        return p;
    
    p.plants[2] = convert_plant(diagram[i++]);
    p.plants[3] = convert_plant(diagram[i]);
    
    return p;
}

plant_t convert_plant(char c)
{
    switch(c)
    {
        case 'G': return GRASS;
        case 'C': return CLOVER;
        case 'R': return RADISHES;
        case 'V': return VIOLETS;
        default: return -1;
    }
}


        