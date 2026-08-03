#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define MAX_AMINO_ACIDS 10

typedef enum {
   Methionine,
   Phenylalanine,
   Leucine,
   Serine,
   Tyrosine,
   Cysteine,
   Tryptophan,
} amino_acid_t;

typedef struct {
   bool valid;
   size_t count;
   amino_acid_t amino_acids[MAX_AMINO_ACIDS];
} protein_t;

protein_t protein(const char *const rna);
int is_protein(const char *str);
bool is_methionine(const char *str);
bool is_phenylalanine(const char *str);
bool is_leucine(const char *str);
bool is_serine(const char *str);
bool is_tyrosine(const char *str);
bool is_cysteine(const char *str);
bool is_tryptophan(const char *str);
bool is_stop(const char *str);

#endif
