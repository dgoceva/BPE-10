#include "year.h"

unsigned input()
{
    unsigned year;

    do {
        printf("year=");
        scanf("%u",&year);

        assert(year>=1000);

        if (year<1000)
            printf("Year must be greater or equal to 1000\n");
    } while(year<1000);

    return year;
}
/*
static void zerofill(unsigned digits[])
{
    for(int i=0;i<10;++i)
        digits[i] = 0;
}
*/

static void print(unsigned digits[], unsigned len)
{
    for(int i=0;i<len;++i)
        printf("%u\t",digits[i]);
    NL;
}
int is_found(unsigned year)
{
    unsigned digits[10]={0};

//    print(digits,10);

    while(year){
        int x = year%10;
        digits[x]++;
        if (digits[x]>1)
            return 0;
        year /= 10;
    }
    return 1;
}
