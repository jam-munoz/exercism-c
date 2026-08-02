#include "triangle.h"

bool is_equilateral(triangle_t sides)
{
    if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0)
        return false;
    if (sides.a + sides.b >= sides.c && sides.b + sides.c >= sides.a && sides.a + sides.c >= sides.b)
        return (sides.a == sides.b && sides.b == sides.c && sides.a == sides.c);
    else return false;
}
bool is_isosceles(triangle_t sides)
{
    if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0)
        return false;
    if (sides.a + sides.b >= sides.c && sides.b + sides.c >= sides.a && sides.a + sides.c >= sides.b)
        return (sides.a == sides.b || sides.a == sides.c || sides.c == sides.b);
    else return false;
}
bool is_scalene(triangle_t sides)
{
    if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0)
        return false;
    if (sides.a + sides.b >= sides.c && sides.b + sides.c >= sides.a && sides.a + sides.c >= sides.b)
        return !(sides.a == sides.b || sides.b == sides.c || sides.a == sides.c);
    else return false;
}