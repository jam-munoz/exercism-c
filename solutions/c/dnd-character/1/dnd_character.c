#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);

int ability(void)
{
    srand((unsigned) time(NULL));
    int roll1, roll2, roll3, roll4, lowest;
    int *p = &roll1;
    roll1 = roll_dice();
    lowest = roll1;
    roll2 = roll_dice();
    if (roll2 < lowest)
    {
        p = &roll2;
        lowest = roll2;
    }
    roll3 = roll_dice();
    if (roll3 < lowest)
    {
        p = &roll3;
        lowest = roll3;
    }
    roll4 = roll_dice();
    if (roll4 < lowest)
    {
        p = &roll4;
    }
    *p = 0;
    return roll1 + roll2 + roll3 + roll4;
}
int modifier(int score)
{
   return (int) floor((float) (score - 10) / 2);
}
    
dnd_character_t make_dnd_character(void)
{
    dnd_character_t character = 
    {
        .strength = ability(),
        .dexterity = ability(),
        .constitution = ability(),
        .intelligence = ability(),
        .wisdom = ability(),
        .charisma = ability(),
    };
    character.hitpoints = 10 + modifier(character.constitution);
    return character;
}

int roll_dice(void)
{
    return (rand() % 6) + 1;
}