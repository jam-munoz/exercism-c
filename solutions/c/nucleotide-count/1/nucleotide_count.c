#include "nucleotide_count.h"

char *count(const char *dna_strand)
{
    char *str;
    char *tmp;
    int count[4] = { 0 };
    int len = sizeof("A: C: G: T:");
    int i;
    
    if (!is_dna(dna_strand))
    {
        str = malloc(sizeof(char));
        str[0] = '\0';
        return str;
    }

    for (i = 0; dna_strand[i]; i++)
    {
        switch(dna_strand[i])
        {
            case 'A': count[0] = count[0] + 1;
                break;
            case 'C': count[1] = count[1] + 1;
                break;
            case 'G': count[2] = count[2] + 1;
                break;
            case 'T': count[3] = count[3] + 1;
                break;
            default:
                break;
        }
    }
    for (i = 0; i < 4; i++)
        len = len + digit_count(count[i]);
    
    str = malloc(len * sizeof(char));
    strcpy(str, "A:");
    tmp = itoa(count[0]);
    strcat(str, tmp);
    free(tmp);
    strcat(str, " C:");
    tmp = itoa(count[1]);
    strcat(str, tmp);
    free(tmp);
    strcat(str, " G:");
    tmp = itoa(count[2]);
    strcat(str, tmp);
    free(tmp);
    strcat(str, " T:");
    tmp = itoa(count[3]);
    strcat(str, tmp);
    free(tmp);
    str[len - 1] = '\0';
    
    return str;
}

bool is_dna(const char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != 'A' && str[i] != 'C' && str[i] != 'G' && str[i] != 'T')
            return false;
    }
    return true;
}

int	digit_count(int nb)
{
	long n;

	n = nb;
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	return (10);
}

char *itoa(int nb)
{
	long n;
	int digits;
	char *out;
	int i;
	int start;

	n = nb;
	digits = digit_count(nb);
	out = malloc(digits + 1);
	i = 0;
	start = 0;
	if (n < 0)
	{
		n *= -1;
		out[i++] = '-';
		start = 1;
	}
	out[digits--] = '\0';
	while (digits >= start)
	{
		out[digits--] = (n % 10) + '0';
		n /= 10;
	}
	return out;
}