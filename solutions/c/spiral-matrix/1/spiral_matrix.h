#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H

#include <stdlib.h>

typedef struct {
   int size;
   int **matrix;
} spiral_matrix_t;

spiral_matrix_t *spiral_matrix_create(int len);
void spiral_matrix_destroy(spiral_matrix_t *actual);

#endif
