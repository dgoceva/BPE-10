#include "matrix.h"

int main()
{
    int A[N][N],M[N];
//    int B[N][N];
//    long C[N][N];

    generateMatrix(A,5);
    printMatrix(A,5);

    printf("Product: %ld\n",product(A,5));
    printf("Sum: %ld\n",sum(A,5));
    printf("Minimum: %d\n",min(A,5));

    maxByRow(A,M,5);
    printArray(M,5);

/*
    inputMatrix(A,3);
    inputMatrix(B,3);
    multiply(A,B,C,3);
    printMatrix(C,3);
*/
    return 0;
}
