#include "array.h"

// function definition
int compare(const void* a, const void* b)
{
//    int* a1 = (int*)a;
//    int *b1 = (int*)b;
//    return *a1 - *b1;

    return *(int*)b - *(int*)a;
}

void generateData(int data[])
{
//    srand(time(NULL));

    for(int i=0;i<SIZE;++i){
        data[i] = rand()%50-25;
    }
}

void printData(int data[])
{
    for(int i=0;i<SIZE;++i){
        printf("%d ",data[i]);
    }
    printf("\n");

}

void mySort(int data[])
{
    int temp;

    for(int j=9;j>=0;--j){
        for(int i=0;i<j;++i){
            if (data[i]>data[i+1]){
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
    }
}
