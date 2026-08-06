#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H

#include <stdlib.h>

typedef enum { CLOVER = 0, GRASS = 1, RADISHES = 2, VIOLETS = 3 } plant_t;

typedef struct {
   plant_t plants[4];
} plants_t;

plants_t plants(const char *diagram, const char *student);
plant_t convert_plant(char c);

#endif
