#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input(int data[], unsigned len)
{
    for(int i=0;i<len;++i) {
        data[i] = rand()%100 -50;
    }
}
void print(int data[], unsigned len)
{
    for(int i=0;i<len;++i){
        printf("%d ",data[i]);
    }
    putchar('\n');
}

int compare_asc(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int compare_desc(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
    const unsigned LEN=10;
    int array[LEN];

    srand(time(NULL));
    input(array,LEN);
    print(array,LEN);
    qsort(array,LEN,sizeof(int),compare_asc);
    print(array,LEN);
    qsort(array,LEN,sizeof(int),compare_desc);
    print(array,LEN);
//    printf("Hello world!\n");
    return 0;
}
