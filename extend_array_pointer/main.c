#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void input(int *array, unsigned len)
{
    for(int i=0;i<len;++i){
        array[i] = rand()%60-30;
    }
}void output(int array[], unsigned len)
{
    for(int i=0;i<len;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void move(int *array, unsigned len,int start)
{
    for(int i=len;i>start;--i){
        array[i] = array[i-1];
    }
}
unsigned extend(int *array, unsigned len)
{
    for(int i=0;i<len;++i){
        if(array[i]%2==0){
            array = (int*)realloc(array, (len+1)*sizeof(int));
            if(array==NULL){
                perror("Realloc error: ");
                exit(EXIT_FAILURE);
            }
            move(array,len,i);
            array[i+1] = array[i]+1;
            len++;i++;
        }
    }
    return len;
}
int main()
{
    int *array;
    unsigned len;

    srand(time(NULL));

    array = (int*)malloc(SIZE*sizeof(int));
    if(array==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    input(array,SIZE);
    output(array,SIZE);
    len = extend(array,SIZE);
    output(array,len);

    free(array);
//    printf("Hello world!\n");
    return 0;
}
