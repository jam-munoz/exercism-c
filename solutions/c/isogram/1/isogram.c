#include "isogram.h"
#include <string.h>
#include <ctype.h>
bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
        return false;
    bool repeat_word[26] = { false };
    int len = strlen(phrase);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(phrase[i]))
        {
            if (repeat_word[tolower(phrase[i])-'a'])
                return false;
            else
                repeat_word[tolower(phrase[i])-'a'] = true;
        }
    }
    return true;
}
