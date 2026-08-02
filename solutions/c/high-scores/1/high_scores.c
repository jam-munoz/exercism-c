#include "high_scores.h"
#include <stdlib.h>
#include <string.h>
int comp(const void *a, const void *b);

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{
    return scores[scores_len-1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    int pb = 0;
    for(int i = 0; i < (int)scores_len; i++)
    {
        if (scores[i] > pb)
            pb = scores[i];
    }
    return pb;
}
/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
    int i, temp[scores_len];
    memcpy(temp, scores, scores_len*sizeof(temp[0]));
    qsort(temp, scores_len, sizeof(temp[0]), comp);
    for(i = 0; i < (int)scores_len && i < 3; i++)
    {
      output[i] = temp[i];
    }
    return i;
}
int comp(const void *a, const void *b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;
    return 0;
}