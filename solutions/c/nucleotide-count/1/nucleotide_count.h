#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *count(const char *dna_strand);
bool is_dna(const char *str);
int	digit_count(int nb);
char *itoa(int nb);

#endif
