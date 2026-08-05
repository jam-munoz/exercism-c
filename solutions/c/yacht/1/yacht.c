#include "yacht.h"

int score(dice_t dice, category_t category)
{
    switch (category)
    {
        case YACHT: return(yacht_score(dice));
        case CHOICE: return(choice_score(dice));
        case BIG_STRAIGHT: return(straight(dice, 2));
        case LITTLE_STRAIGHT: return(straight(dice, 1));
        case FOUR_OF_A_KIND: return(four_of_a_kind(dice));
        case FULL_HOUSE: return(full_house(dice));
        case SIXES: case FIVES: case FOURS: case THREES: case TWOS: case ONES:
            return(number_score(dice, category + 1));
        default: break;
    }
    return 0;
}

int yacht_score(dice_t dice)
{
    if (dice.faces[0] == dice.faces[1] && dice.faces[1] == dice.faces[2] && dice.faces[2] == dice.faces[3] && dice.faces[3] == dice.faces[4])
        return 50;
    else
        return 0;
}

int choice_score(dice_t dice)
{
    int sum = 0;
    
    for (int i = 0; i < DICE; i++)
        sum += dice.faces[i];
    
    return sum;
}

int straight(dice_t dice, int search)
{
	int i, j, sum = 0;

	for (j = 0; j < DICE; j++)
	{
		for (i = 0; i < DICE; i++)
		{
			if (dice.faces[i] == search)
			{
				search++;
                sum++;
				break;
			}
		}
	}
    
	if (sum == DICE)
		return 30;
	return 0;
}

int full_house(dice_t dice)
{
    qsort(dice.faces, DICE, sizeof(int), comp);
    
    int sum = 0;

    if (dice.faces[0] == dice.faces[1] && (dice.faces[1] == dice.faces[2] || dice.faces[2] == dice.faces[3]) && dice.faces[3] == dice.faces[4])
    {
        for (int i = 0; i < DICE; i++)
            sum += dice.faces[i];
    }
    
    if (sum == dice.faces[0] * DICE)
        return 0;
    return sum;
}

int four_of_a_kind(dice_t dice)
{
    qsort(dice.faces, DICE, sizeof(int), comp);
    
    int sum = 0;
    int n = dice.faces[2];

    for (int i = 0; i < DICE; i++)
	{
		if (dice.faces[i] == n)
			sum++;
	}

    if (sum >= 4)
        return (n * 4);
    return 0;
}

int number_score(dice_t dice, int n)
{
	int sum = 0;

	for (int i = 0; i < DICE; i++)
	{
		if (dice.faces[i] == n)
			sum += n;
	}
    
	return sum;
}

int comp(const void *a, const void *b) 
{
    return (*(int *)b - *(int *)a);
}
