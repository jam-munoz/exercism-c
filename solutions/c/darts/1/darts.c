#include <math.h>
#include "darts.h"
uint8_t score(coordinate_t landing_position)
{
    float radius = hypot(landing_position.x, landing_position.y);
    if (radius <= 1)
        return 10;
    if (radius <= 5)
        return 5;
    if (radius <= 10)
        return 1;
    return 0;
}