#include <stdio.h>
#include <stdlib.h>

void swap_err(int x, int y)
{
    int temp;

    temp=x;
    x=y;
    y=temp;

    printf("x=%d,y=%d\n",x,y);
}

void swap(int *x, int *y)
{
    int temp;

    temp = x[0];
    *x = *y;
    *y = temp;
}
int main()
{
    int a=3,b=4;

    swap_err(a,b);
    printf("a=%d,b=%d\n",a,b);
    swap(&a,&b);
    printf("a=%d,b=%d\n",a,b);
//    printf("Hello world!\n");
    return 0;
}
