#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
    a.real = a.real + b.real;
    a.imag = a.imag + b.imag;
    return a;
}

complex_t c_sub(complex_t a, complex_t b)
{
    a.real = a.real - b.real;
    a.imag = a.imag - b.imag;
    return a;
}

complex_t c_mul(complex_t a, complex_t b)
{
    complex_t mul;
    mul.real = (a.real * b.real) - (a.imag * b.imag);
    mul.imag = (a.imag * b.real) + (a.real * b.imag);
    return mul;

}

complex_t c_div(complex_t a, complex_t b)
{
    complex_t div;
    double divisor = pow(b.real, 2) + pow(b.imag, 2);
    div.real = ((a.real * b.real) + (a.imag * b.imag)) / divisor;
    div.imag = ((a.imag * b.real) - (a.real * b.imag)) / divisor;
    return div;
}

double c_abs(complex_t x)
{
    double abs;
    abs = sqrt(pow(x.real, 2) + pow(x.imag, 2));
    return abs;
}

complex_t c_conjugate(complex_t x)
{
    x.imag = -x.imag;
    return x;
}

double c_real(complex_t x)
{
    return x.real;
}

double c_imag(complex_t x)
{
    return x.imag;
}

complex_t c_exp(complex_t x)
{
    complex_t ex;
    ex.real = exp(x.real) * cos(x.imag);
    ex.imag = exp(x.real) * sin(x.imag);
    return ex;
}
