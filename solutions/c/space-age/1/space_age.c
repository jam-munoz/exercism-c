#include "space_age.h"

float age(planet_t planet, int64_t seconds)
{
    float year = seconds / 31557600;
    switch (planet)
    {
        case EARTH: return year; break;    
        case MERCURY: return year / 0.2408467; break;
        case VENUS: return year / 0.61519726; break;
        case MARS: return year / 1.8808158; break;
        case JUPITER: return year / 11.862615; break;
        case SATURN: return year / 29.447498; break;
        case URANUS: return year / 84.016846; break;
        case NEPTUNE: return year / 164.79132; break;
        default: return -1; break;
    }
}