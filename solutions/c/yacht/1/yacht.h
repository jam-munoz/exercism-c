#ifndef YACHT_H
#define YACHT_H

#define DICE 5
#include <stdlib.h>

typedef enum {
   ONES,
   TWOS,
   THREES,
   FOURS,
   FIVES,
   SIXES,
   FULL_HOUSE,
   FOUR_OF_A_KIND,
   LITTLE_STRAIGHT,
   BIG_STRAIGHT,
   CHOICE,
   YACHT
} category_t;

typedef struct {
   int faces[5];
} dice_t;

int score(dice_t dice, category_t category);
int yacht_score(dice_t dice);
int choice_score(dice_t dice);
int straight(dice_t dice, int search);
int four_of_a_kind(dice_t dice);
int full_house(dice_t dice);
int number_score(dice_t dice, int n);
int comp(const void *a, const void *b); 

#endif
