#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void input(int *data,unsigned len);
void print(int *data,unsigned len);
void move(int data[],unsigned len);
unsigned extend(int data[],unsigned len);

int main()
{
    int array[SIZE*2];
    unsigned len;

    srand(time(NULL));
    input(array,SIZE);
    print(array,SIZE);
//    print(array,SIZE*2);
    move(array,SIZE);
 //   print(array,SIZE*2);
    len = extend(array,SIZE);
 //   print(array,SIZE*2);
    print(array,len);
 //   printf("Hello world!\n");
    return 0;
}

void input(int data[],unsigned len)
{
    for(int i=0;i<len;++i)
        data[i] = rand()%50 - 25;
}

void print(int data[],unsigned len)
{
    for(int i=0;i<len;++i)
        printf("%d ",data[i]);
    putchar('\n');
}

void move(int *data,unsigned len)
{
    for(int i=0;i<len;++i)
        data[i+len] = data[i];
}

unsigned extend(int data[],unsigned len)
{
        unsigned i,index;

        for(i=index=0;i<len;++i,++index)
        {
            data[index] = data[i+len];
            if (data[index]%2==0)
            {
                    data[++index] = data[i+len]+1;
            }
        }
        return index;
}
