#include <stdio.h>
//#include <stdlib.h>

int main()
{
    unsigned year;
    /* static */ unsigned digits[10];
    int found;

    do {
        printf("year=");
        scanf("%u",&year);
        if (year<1000)
            printf("Year must be greater or equal to 1000");
    } while(year<1000);

    do {
        found = 1;
        unsigned n = ++year;

        for(int i=0;i<10;++i)
            digits[i] = 0;

        while(n){
            int x = n%10;
            digits[x]++;
            if (digits[x]>1) {
                found = 0;
                break;
            }
            n /= 10;
        }
    } while(!found);
//    printf("Hello world!\n");
    printf("%u",year);
    return 0;
}
