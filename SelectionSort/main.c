#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {3,0,1,8,7,2,5,4,9,6};
    int idx,temp;

    for(int i=0;i<9;++i)
    {
        idx=i;
        for(int j=i+1;j<10;++j)
        {
            if(a[idx]>a[j])
                idx = j;
        }
        temp = a[idx];
        a[idx] = a[i];
        a[i] = temp;
    }
    for(int i=0;i<10;++i)
        printf("%d\t",a[i]);
    putchar('\n');

//    printf("Hello world!\n");
    return 0;
}
