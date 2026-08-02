#ifndef LUHN_H
#define LUHN_H

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

bool luhn(const char *num);
int num_count(const char *num);

#endif
