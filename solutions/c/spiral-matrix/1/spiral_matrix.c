#include "spiral_matrix.h"

spiral_matrix_t *spiral_matrix_create(int size)
{
    int i = 1, x = 0, y = 0;

    spiral_matrix_t *spiral = malloc(sizeof(*spiral));
    if (spiral == NULL)
        return NULL;
    
    if (size < 1)
    {
        spiral->size = 0;
        spiral->matrix = NULL;
        return spiral;
    }
    
    spiral->size = size;
    spiral->matrix = malloc(size * sizeof(*spiral->matrix));
    if (spiral->matrix == NULL)
    {
        free(spiral);
        return NULL;
    }
    
    int *data = malloc(size * size * sizeof(*data));
    if (data == NULL)
    {
        free(spiral->matrix);
        free(spiral);
        return NULL;
    }
    
    for (int i = 0; i < size; i++)
        spiral->matrix[i] = data + i * size;
    
    for (int start = 0; start < size; start++, size--)
    {
        for (; x < size; i++, x++)
            spiral->matrix[y][x] = i;
        x--;
        y++;
        for (; y < size; i++, y++)
            spiral->matrix[y][x] = i;
        x--;
        y--;
        for (; x >= start; i++, x--)
            spiral->matrix[y][x] = i;
        x++;
        y--;
        for (; y > start; i++, y--)
            spiral->matrix[y][x] = i;
        x++;
        y++;
    }
    
    return spiral;
}

void spiral_matrix_destroy(spiral_matrix_t *actual)
{
    if (actual->matrix)
    {
        free(actual->matrix[0]);
        free(actual->matrix);
        free(actual);
    }
}