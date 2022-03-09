#include "array.h"

int main()
{
    int a[SIZE];

    // function call
    generateData(a);
    printData(a);

    mySort(a);
    printData(a);

    qsort(a,SIZE,sizeof(int),compare);
    printData(a);

   return 0;
}
