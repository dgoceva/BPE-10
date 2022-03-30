#include <stdio.h>
#include <stdlib.h>

#define PR(format, value) printf(""#value" = %"#format"\t",(value))
#define NL printf("\n")

int a[]={0,1,2,3,4};

void pointer()
{
    int x=1,z[]={0,1,2,3,4,5,6,7,8,9};
    int *ip;

    printf("%p, %d\n",ip,*ip);

    ip = &x;
    printf("%p, %d\n",ip,*ip);

    ip = z;
    printf("%p, %d\n",ip,*ip);
    ip = ip+2;
    printf("%p, %d\n",ip,*ip);
    *ip += 3;
    printf("%p, %d\n",ip,*ip);
    ++*ip;
    printf("%p, %d\n",ip,*ip);
    *++ip;
    printf("%p, %d\n",ip,*ip);
    *ip++;
    printf("%p, %d\n",ip,*ip);
    (*ip)++;
    printf("%p, %d\n",ip,*ip);

    for (int i=0;i<10;++i)
        printf("%d ",z[i]);
    NL;
    for (ip=z;ip-z<10;++ip)
        printf("%d ",*ip);
    NL;
 }

 void pointer2()
 {
        int i,*p;
        for (i=0; i<=4; i++) PR(d,a[i]);
        NL;
        for (p=&a[0]; p<=&a[4]; p++)
           PR(d,*p);
        NL; NL;
        for (p=&a[0],i=1; i<=5; i++)
           PR(d,p[i]);
        NL;
        for (p=a,i=0; p+i<=a+4; p++,i++)
           PR(d,*(p+i));
        NL; NL;
        for (p=a+4; p>=a; p--) PR(d,*p);
        NL;
        for (p=a+4,i=0; i<=4; i++) PR(d,p[-i]);
        NL;
        for (p=a+4; p>=a; p--) PR(d,a[p-a]);
        NL;
 }
 void no_swap(int x, int y)
 {
     int temp = x;
     x = y;
     y = temp;
     PR(d,x);
     PR(d,y);
     NL;
 }
void swap(int *x, int *y)
 {
     int temp = *x;
     *x = *y;
     *y = temp;
     PR(d,*x);
     PR(d,*y);
     NL;
 }
int main(int argc,char *argv[])
{
    for (int i=0;i<argc;++i)
        printf("%s\n",argv[i]);
//    pointer();
 //   pointer2();
    int x=3,y=2;

    no_swap(x,y);
    PR(d,x);
    PR(d,y);
    NL;
    swap(&x,&y);
    PR(d,x);
    PR(d,y);
 /*
    int x=1,z[]={0,1,2,3,4,5,6,7,8,9};
    int *ip;

    printf("%p\n",ip);
    printf("%p, %d\n",ip,*ip);
*/
    return EXIT_SUCCESS;
}
