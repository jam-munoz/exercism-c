#include "pangram.h"
#include <ctype.h>
#include <string.h>
bool is_pangram(const char *sentence)
{
    if (sentence == NULL)
        return false;
    int i, j, len = strlen(sentence);
    if (len < 26)
        return false;
    bool repeat[26] = { false };
    char string[len];
    for (j = 0, i = 0; i < len; i++)
    {
        if (isalpha(sentence[i]))
        {
            if (!repeat[toupper(sentence[i])-'A'])
            {
              repeat[toupper(sentence[i])-'A'] = true;
              string[j] = toupper(sentence[i]);
              j++;
            }
        }
    }
    string[j] = '\0';
    int pangram = strlen(string);
    return (pangram == 26);
}