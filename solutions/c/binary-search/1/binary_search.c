#include "binary_search.h"
const int *binary_search(int value, const int *arr, size_t length)
{
    if (length == 0 || value > arr[length-1] || value < arr[0])
        return NULL;
    int search = length / 2;
    if (value == arr[search])
        return &arr[search];
    int new_search;
    int left = 0;
    int right = length;
    while (value != arr[search])
    {
        if (value > arr[search])
        {
            left = search;
            new_search = (search + right) / 2;
            if (new_search == search)
                return NULL;
            else search = new_search;
        }
        else if (value < arr[search])
        {
            right = search;
            new_search = (search + left) / 2;
            if (new_search == search)
                return NULL;
            else search = new_search;
        }
    }
    return &arr[search];
}