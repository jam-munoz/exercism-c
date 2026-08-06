#include "sublist.h"

comparison_result_t check_lists(int *list_a, int *list_b, size_t a_size, size_t b_size)
{
    if(!list_a && !list_b)
        return EQUAL;
    if(!list_a)
        return SUBLIST;
    if(!list_b)
        return SUPERLIST;

    size_t i = 0, j = 0, start = 0;
    
    while (list_a[i] != list_b[start] && start < b_size)
        start++;
    
    while (j < b_size)    
    {
        i = 0;
        j = start;
        start++;
        while (list_a[i] == list_b[j] && i < a_size && j < b_size)
        {
            i++;
            j++;
            if (i == a_size)
            {    
                if (a_size == b_size)
                    return EQUAL;
                 else
                     return SUBLIST;
            }
        }
    }

    start = 0;
    while (list_a[start] != list_b[j] && start < a_size)
        start++;
    
    while (i < a_size)    
    {
        j = 0;
        i = start;
        start++;
        
        while (list_a[i] == list_b[j] && i < a_size && j < b_size)
        {
            i++;
            j++;
            if (j == b_size)
                return SUPERLIST;
        }
    }
    
    return UNEQUAL;
}
