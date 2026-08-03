#include "square_root.h"

uint16_t square_root(uint16_t nb)
{
	long	x;
	long	y;

	if (nb < 1)
		return (0);
	x = nb;
	y = (x + 1) / 2;
	while (y < x)
	{
		x = y;
		y = (x + nb / x) / 2;
	}
	return ((uint16_t) x);
}