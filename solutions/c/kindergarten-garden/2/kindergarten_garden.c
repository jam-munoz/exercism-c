#include "kindergarten_garden.h"

plants_t plants(const char *diagram, const char *student)
{
    plants_t p;
    int start, i;
    static const plant_t table[256] = {
        ['C'] = CLOVER,
        ['G'] = GRASS,
        ['R'] = RADISHES,
        ['V'] = VIOLETS,
    };
    
    start = (student[0] - 'A') * 2;
    i = start;
    
    p.plants[0] = table[(unsigned char)diagram[i++]];
    p.plants[1] = table[(unsigned char)diagram[i]];
    
    for (; diagram[i] && diagram[i] != '\n'; i++) ;
    if (diagram[i] == '\n')
        i += start + 1;
    else
        return p;
    
    p.plants[2] = table[(unsigned char)diagram[i++]];
    p.plants[3] = table[(unsigned char)diagram[i]];
    
    return p;
}
