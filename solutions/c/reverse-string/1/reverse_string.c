#include "reverse_string.h"

char *reverse(const char *value)
{
    int len = strlen(value) - 1;
    char *str = strdup(value);
    
    for (int i = 0; i < len; i++, len--)
        swap(&str[i], &str[len]);
    
    return str;
}

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
