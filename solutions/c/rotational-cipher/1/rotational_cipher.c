#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
    int i, n;
    int len = strlen(text);
    char *str = malloc((len + 1) * sizeof(char));
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (!str)
    {
        free(str);
        return NULL;
    }

    shift_key = shift_key % 26;
    for (i = 0; text[i]; i++)
    {
        if (isupper(text[i]))
        {
            n = (text[i] - 'A' + shift_key) % 26;
            str[i] = upper[n];
        }
        else if (islower(text[i]))
        {
            n = (text[i] - 'a' + shift_key) % 26;
            str[i] = lower[n];
        }
        else
            str[i] = text[i];
    }
    str[i] = '\0';
    return str;
}