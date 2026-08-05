#include "beer_song.h"

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    uint8_t n = start_bottles;

    for (uint8_t i = 0; i < take_down; i++)
    {
        switch(n)
        {
            case 0: sprintf(*song, "No more bottles of beer on the wall, no more bottles of beer.");
                song++;
                sprintf(*song, "Go to the store and buy some more, 99 bottles of beer on the wall.");
                song += 2;
                n = 100;
                break;
            case 1: sprintf(*song, "1 bottle of beer on the wall, 1 bottle of beer.");
                song++;
                sprintf(*song, "Take it down and pass it around, no more bottles of beer on the wall.");
                song += 2;
                break;
            case 2: sprintf(*song, "2 bottles of beer on the wall, 2 bottles of beer.");
                song++;
                sprintf(*song, "Take one down and pass it around, 1 bottle of beer on the wall.");
                song += 2;
                break;
            default: sprintf(*song, "%d bottles of beer on the wall, %d bottles of beer.", n, n);
                song++;
                sprintf(*song, "Take one down and pass it around, %d bottles of beer on the wall.", n - 1);
                song +=2;
                break;
        }
        n--;
    }
}