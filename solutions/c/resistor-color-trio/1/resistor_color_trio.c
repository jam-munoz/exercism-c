#include "resistor_color_trio.h"
#include <math.h>
resistor_value_t color_code(resistor_band_t colors[])
{
    resistor_value_t resistor = { 0, 0 };
    long long temp_value;
    temp_value = ((colors[0]*10) + colors[1]) * pow(10, colors[2]);
    resistor.unit = OHMS;
    while (temp_value % 1000 == 0 && temp_value > 0)
    {
        temp_value /= 1000;
        resistor.unit++;
    }
    resistor.value = temp_value;
    return resistor;
}