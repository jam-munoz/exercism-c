#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#define DIGITS_ARRAY_SIZE 64

#include <stddef.h>
#include <stdint.h>

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length);
size_t digit_count(long n, int16_t output_base);

#endif
