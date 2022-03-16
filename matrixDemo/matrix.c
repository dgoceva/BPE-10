#include "matrix.h"

void generateMatrix(int matrix[][N], unsigned size)
{
//    srand(time(NULL));
    for (int i=0;i<size;++i){
        for (int j=0;j<size;++j){
            matrix[i][j] = rand()%50-25;
        }
    }
}
void inputMatrix(int matrix[][N], unsigned size)
{
    for (int i=0;i<size;++i){
        for (int j=0;j<size;++j){
            printf("(%d,%d)=",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
}
void printMatrix(int matrix[N][N], unsigned size)
{
    for (int i=0;i<size;++i){
        for (int j=0;j<size;++j){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void printArray(int array[], unsigned size)
{
     for (int j=0;j<size;++j){
        printf("%d ",array[j]);
    }
    printf("\n");
}
long product(int matrix[][N], unsigned size)
{
    long prod = 1;

    for(int k=0;k<size;++k) {
        prod *= matrix[k][k];
    }
    return prod;
}
long sum(int matrix[][N], unsigned size)
{
    long sum = 0;

    for (int i=0;i<size-1;++i){
        for (int j=i+1;j<size;++j){
            sum += matrix[i][j];
        }
    }
    return sum;
}
int min(int matrix[][N], unsigned size)
{
    int minel = matrix[1][0];

    for (int i=1;i<size;++i){
        for (int j=0;j<i;++j){
            if (matrix[i][j]<minel){
                minel = matrix[i][j];
            }
        }
    }
    return minel;
}

void multiply(int m1[N][N],int m2[N][N],long result[N][N], unsigned size)
{
    for (int i=0;i<size;++i){
        for (int j=0;j<size;++j){
            result[i][j]=0;
            for (int k=0;k<size;++k){
                result[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
}

void maxByRow(int matrix[][N],int result[],unsigned size)
{
    for (int i=0;i<size;++i){
        result[i]=matrix[i][0];
        for (int j=0;j<size;++j){
            if (result[i]<matrix[i][j]){
                result[i]=matrix[i][j];
            }
        }
    }
}
