#include "protein_translation.h"

protein_t protein(const char *const rna)
{
    protein_t protein;
    int i, j;
    protein.valid = true;
    protein.count = 0;

    for (i = 0, j = 0; rna[i] && j < MAX_AMINO_ACIDS; i += 3)
    {
        if (is_stop(&rna[i]))
            break;
        else if (is_protein(&rna[i]) != -1)
        {
            protein.count++;
            protein.amino_acids[j++] = is_protein(&rna[i]);
        }
        else
        {
            protein.valid = false;
            break;
        }
    }
    return protein;
}

int is_protein(const char *str)
{
    if (is_methionine(str))
        return Methionine;
    else if (is_phenylalanine(str))
        return Phenylalanine;
    else if (is_leucine(str))
        return Leucine;
    else if (is_serine(str))
        return Serine;
    else if (is_tyrosine(str))
        return Tyrosine;
    else if (is_cysteine(str))
        return Cysteine;
    else if (is_tryptophan(str))
        return Tryptophan;
    else
        return -1;
}

bool is_methionine(const char *str)
{
    if (strncmp(str, "AUG", 3) == 0)
        return true;
    else
        return false;
}

bool is_phenylalanine(const char *str)
{
    if (strncmp(str, "UUU", 3) == 0 || strncmp(str, "UUC", 3) == 0)
        return true;
    else
        return false;
}

bool is_leucine(const char *str)
{
    if (strncmp(str, "UUA", 3) == 0 || strncmp(str, "UUG", 3) == 0)
        return true;
    else
        return false;
}

bool is_serine(const char *str)
{
    if (strncmp(str, "UCU", 3) == 0 || strncmp(str, "UCC", 3) == 0 || strncmp(str, "UCA", 3) == 0 || strncmp(str, "UCG", 3) == 0)
        return true;
    else
        return false;
}

bool is_tyrosine(const char *str)
{
    if (strncmp(str, "UAU", 3) == 0 || strncmp(str, "UAC", 3) == 0)
        return true;
    else
        return false;
}

bool is_cysteine(const char *str)
{
    if (strncmp(str, "UGU", 3) == 0 || strncmp(str, "UGC", 3) == 0)
        return true;
    else
        return false;
}

bool is_tryptophan(const char *str)
{
    if (strncmp(str, "UGG", 3) == 0)
        return true;
    else
        return false;
}

bool is_stop(const char *str)
{
    if (strncmp(str, "UAA", 3) == 0 || strncmp(str, "UAG", 3) == 0 || strncmp(str, "UGA", 3) == 0)
        return true;
    else
        return false;
}