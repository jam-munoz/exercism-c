#include "raindrops.h"
void convert(char result[], int drops)
{
    if (drops % 3 == 0)
        strcat(result, "Pling");
    if (drops % 5 == 0)
        strcat(result, "Plang");    
    if (drops % 7 == 0)
        strcat(result, "Plong");
    if (drops % 3 != 0 && drops % 5 != 0 && drops % 7 != 0)
    {//itoa
        int digits = 0;
        for (int temp = drops; temp > 0; digits++) //count digits
        {
            temp /= 10;
        }
        char str[digits+1];
        for (int i = 1; i <= digits; i++)
        {
        str[digits - i] = (drops % 10) + '0';
        drops /= 10;
        }
        str[digits] = '\0';   
        strcpy(result, str);
    }
}