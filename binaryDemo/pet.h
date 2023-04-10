#ifndef PET_H_INCLUDED
#define PET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEN 31
#define CH_LEN 8
#define IN_TXT_NAME "animals.txt"
#define IN_BIN_NAME "animals.bin"
#define MAX_SIZE 1001

typedef struct {
    char name[LEN];
    char chip[CH_LEN];
    float price;
} TPet;

unsigned readCsv(char* fname,TPet *pets);
bool parsePet(char *buff, TPet *pet);
void printPets(TPet *pets, unsigned len);
void writeBin(char *fname, TPet *pets, unsigned len);

#endif // PET_H_INCLUDED
