#include "rna_transcription.h"
#include <stdlib.h>

char *to_rna(const char *dna)
{
    int lenght = strlen(dna);
    char *rna = malloc(lenght+1);
    for (int i = 0; i < lenght; i++)
    {
        switch(dna[i])
        {
            case 'G': rna[i] = 'C'; break;
            case 'C': rna[i] = 'G'; break;
            case 'T': rna[i] = 'A'; break;
            case 'A': rna[i] = 'U'; break;
            default: break;
        }
    }
    rna[lenght] = '\0';
    return rna;
}