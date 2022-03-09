#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 10

// function declaration
int compare(const void* a, const void* b);
void generateData(int data[]);
void printData(int data[]);
void mySort(int data[]);

void itob(unsigned number, char *output, unsigned base);
void escape(char *dest, const char *src);

#endif // ARRAY_H_INCLUDED
