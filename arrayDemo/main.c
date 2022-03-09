#include "array.h"

int main()
{
    int a[SIZE];
    char s[SIZE+1];
    unsigned n,b;
    char src[500] = "Hello\n\nC\t\tProgram!";
    char dest[1000];

    // function call
    generateData(a);
    printData(a);

    mySort(a);
    printData(a);

    qsort(a,SIZE,sizeof(int),compare);
    printData(a);

    printf("Input number: ");
    scanf("%u",&n);
    printf("Input base: ");
    scanf("%u",&b);
    itob(n,s,b);
    puts(s);

    escape(dest,src);
    puts(src);
    puts(dest);

   return 0;
}
