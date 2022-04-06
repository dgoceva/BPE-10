#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(float* data, unsigned len)
{
    srand(time(NULL));

    for(int i=0;i<len;++i){
        data[i] = rand()%50/5.;
    }
}

void printArray(float* data, unsigned len)
{
    for (int i=0;i<len;++i)
        printf("%g\t",data[i]);
    printf("\n");
}

void mainArray()
{
    float *data;

    data=(float*) malloc(5*sizeof(float));
    if (data==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    generateArray(data,5);
    printArray(data,5);

    free(data);
    data=NULL;
}
void generateMatrix(float*data[], unsigned rows)
{
    for (int i=0;i<rows;++i){
        for (int j=0;j<=i;++j){
            data[i][j]=rand()%50/5.;
        }
    }
}
void printMatrix(float**data, unsigned rows)
{
    for (int i=0;i<rows;++i){
        for (int j=0;j<=i;++j){
            printf("%g\t",data[i][j]);
        }
        printf("\n");
    }
}
void freeMatrix(float**data, unsigned rows)
{
    for(int j=0;j<rows;++j){
        free(data[j]);
        data[j]=NULL;
    }
    free(data);
    data=NULL;
}
void mainMatrix()
{
    float **data;

    if ((data=(float**)malloc(5*sizeof(float*)))==NULL){
        perror("malloc row error:");
        exit(EXIT_FAILURE);
    }

    for (int i=0;i<5;++i){
        if ((data[i]=(float*)calloc(i+1,sizeof(float)))==NULL){
/*
            for(int j=0;j<i;++j){
                free(data[j]);
                data[j]=NULL;
            }
            free(data);
            data=NULL;
*/
            freeMatrix(data,i);
            perror("calloc col error");
            exit(-1);
        }
    }
    generateMatrix(data,5);
    printMatrix(data,5);

    /*
    for(int j=0;j<5;++j){
        free(data[j]);
        data[j]=NULL;
    }
    free(data);
    data=NULL;
*/
    freeMatrix(data,5);
}
int main()
{
//    mainArray();
    mainMatrix();
    return 0;
}
