#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int compare(const void* a, const void* b)
{
//    int* a1 = (int*)a;
//    int *b1 = (int*)b;
//    return *a1 - *b1;

    return *(int*)b - *(int*)a;
}

int main()
{
    int a[SIZE];
    int temp;

    for(int i=0;i<SIZE;++i){
        a[i] = rand()%50-25;
    }

    for(int i=0;i<SIZE;++i){
        printf("%d ",a[i]);
    }
    printf("\n");

    for(int j=9;j>=0;--j){
        for(int i=0;i<j;++i){
            if (a[i]>a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }

    for(int i=0;i<SIZE;++i){
        printf("%d ",a[i]);
    }
    printf("\n");

    qsort(a,SIZE,sizeof(int),compare);

    for(int i=0;i<SIZE;++i){
        printf("%d ",a[i]);
    }
    printf("\n");

   return 0;
}
