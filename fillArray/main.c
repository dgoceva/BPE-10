#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(unsigned array[], unsigned len)
{
    srand(time(NULL));

    for (int i=0;i<len;++i){
        array[i] = rand();
    }
}

void printArray(unsigned array[], unsigned len)
{
    for (int i=0;i<len;++i){
        printf("%u ",array[i]);
    }
    printf("\n");
}

unsigned lastDigit(unsigned number)
{
    return number%10;
}

unsigned firstDigit(unsigned number)
{
    while (number>=10){
        number /= 10;
    }
    return number;
}

// 123: 123%10 = 3
// 123: 123/10 = 12%10 = 2
// 1234: 1234/10 = 123%10 = 3
unsigned fillArray(unsigned *dest, unsigned src[], unsigned len)
{
    unsigned j=0;

    for (int i=0;i<len;++i){
        if (lastDigit(src[i]) == src[i]/10%10){
            dest[j++] = src[i];
        }
    }
    return j;
}

unsigned fillArray1(unsigned dest[], unsigned *src, unsigned len)
{
    unsigned j=0;

    for (int i=0;i<len;++i){
        if (lastDigit(src[i]) == firstDigit(src[i])){
            dest[j++] = src[i];
        }
    }
    return j;
}

int main()
{
    const unsigned LEN=10;
    unsigned data[LEN];
    unsigned result[LEN];
    unsigned size;

    generateArray(data, LEN);
    printArray(data, LEN);

    size=fillArray(result,data,LEN);
    if (size){
        printArray(result,size);
    }else {
        printf("No such data...\n");
    }

    size=fillArray1(result,data,LEN);
    if (size){
        printArray(result,size);
    }else {
        printf("No such data...\n");
    }

    return 0;
}
