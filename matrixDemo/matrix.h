#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void generateMatrix(int matrix[][N], unsigned size);
void printMatrix(int matrix[][N], unsigned size);
long product(int matrix[][N], unsigned size);
long sum(int matrix[][N], unsigned size);
int min(int matrix[][N], unsigned size);
void multiply(int m1[N][N],int m2[N][N],long result[N][N], unsigned size);
void inputMatrix(int matrix[][N], unsigned size);
void maxByRow(int matrix[][N],int result[],unsigned size);
void printArray(int array[], unsigned size);

#endif // MATRIX_H_INCLUDED
