#include "eliuds_eggs.h"
unsigned int convert2unary(int decimal);

unsigned int egg_count(unsigned int value)
{
    unsigned int unary;
    //pasar de decimal a unario
    unary = convert2unary(value);
    return unary;
}

unsigned int convert2unary(int decimal)
{
  unsigned int binary = 0;

  for (unsigned long e10 = 1; decimal >= 1; e10 *= 10)
  {
    if (decimal % 2 != 0)
      binary++;
    decimal /= 2;
  }
  return binary;
}