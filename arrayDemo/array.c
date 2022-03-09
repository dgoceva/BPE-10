#include "array.h"

// function definition
int compare(const void* a, const void* b)
{
//    int* a1 = (int*)a;
//    int *b1 = (int*)b;
//    return *a1 - *b1;

    return *(int*)b - *(int*)a;
}

void generateData(int data[])
{
//    srand(time(NULL));

    for(int i=0;i<SIZE;++i){
        data[i] = rand()%50-25;
    }
}

void printData(int data[])
{
    for(int i=0;i<SIZE;++i){
        printf("%d ",data[i]);
    }
    printf("\n");

}

void mySort(int data[])
{
    int temp;

    for(int j=9;j>=0;--j){
        for(int i=0;i<j;++i){
            if (data[i]>data[i+1]){
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
            }
        }
    }
}

void itob(unsigned number, char *output, unsigned base)
{
    int i = SIZE-1;

    memset(output,' ',SIZE);

    while(number!=0){
        if (number%base<=9){
          output[i--] = number%base+'0';
        } else {
         output[i--] = number%base+'7';
        }
        number /= base;
    }
 }

 // '\n' => "\n"
 // '\t' => "\t"
 void escape(char *dest, const char *src)
 {
     int j=0;

     for (int i=0; i<strlen(src);++i){
        switch(src[i]){
        case '\n':
            dest[j++] = '\\';
            dest[j++] = 'n';
            break;
        case '\t':
           dest[j++] = '\\';
            dest[j++] = 't';
            break;
        default:
            dest[j++] = src[i];
        }
     }
     dest[j] = '\0';
 }
