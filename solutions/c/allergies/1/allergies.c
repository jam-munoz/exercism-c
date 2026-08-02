#include "allergies.h"


bool is_allergic_to(allergen_t allergen, int score)
{
    allergen_list_t list = get_allergens(score);
    
    return list.allergens[allergen];
}

allergen_list_t get_allergens(int score)
{
    allergen_list_t list = { 0 };
    
    while (score >= 256)
    {
        score -= 256;
    }
    if (score >= 128)
    {
        list.allergens[ALLERGEN_CATS] = true;
        list.count++;
        score -= 128;
    }
    if (score >= 64)
    {
        list.allergens[ALLERGEN_POLLEN] = true;
        list.count++;
        score -= 64;
    }
    if (score >= 32)
    {
        list.allergens[ALLERGEN_CHOCOLATE] = true;
        list.count++;
        score -= 32;
    }
    if (score >= 16)
    {
        list.allergens[ALLERGEN_TOMATOES] = true;
        list.count++;
        score -= 16;
    }
    if (score >= 8)
    {
        list.allergens[ALLERGEN_STRAWBERRIES] = true;
        list.count++;
        score -= 8;
    }
    if (score >= 4)
    {
        list.allergens[ALLERGEN_SHELLFISH] = true;
        list.count++;
        score -= 4;
    }
    if (score >= 2)
    {
        list.allergens[ALLERGEN_PEANUTS] = true;
        list.count++;
        score -= 2;
    }
    if (score >= 1)
    {
        list.allergens[ALLERGEN_EGGS] = true;
        list.count++;
        score -= 1;
    }

    return list;
}
