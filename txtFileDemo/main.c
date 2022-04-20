#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef enum {False,True} TBoolean;

void copyFile(char *src, char *dest)
{
    //1
    FILE *in, *out;
    char c;

    //2
    in = fopen(src,"r");
    if (in==NULL){
        perror(NULL);
        exit(errno);
    }
    if ((out=fopen(dest,"w"))==NULL){
        perror("Open file error");
        exit(EXIT_FAILURE);
    }

    //3
    while((c=fgetc(in))!=EOF){
        fputc(c,out);
    }

    //4
    fclose(in);
    fclose(out);
}

void catFile(char *src, char *dest)
{
    FILE *in, *out;
    char buf[BUFSIZ];

    if ((in=fopen(src,"r"))==NULL){
        perror("Open input file error");
        exit(EXIT_FAILURE);
    }
   if ((out=fopen(dest,"a"))==NULL){
        perror("Open file error");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf,BUFSIZ,in)!=NULL){
        fputs(buf,out);
        puts(buf);
    }
    fclose(in);
    fclose(out);
}
int inputTemperatures(double *temp, char *fname)
{
    FILE *in;
    int len=0;

    if ((in=fopen(fname,"r"))==NULL){
        perror("Open input file error");
        exit(EXIT_FAILURE);
    }

    while(True){
        if (fscanf(in,"%lf",&temp[len])!=1){
            if (feof(in)){
                fclose(in);
                return len;
            }else {
                perror(NULL);
                fclose(in);
                exit(EXIT_FAILURE);
            }
        }
        len = (len+1)%N;
    }
}
void print(double *temp, int size)
{
    for (int i=0;i<size;++i){
        printf("%g\t",temp[i]);
    }
    printf("\n");
}
int main()
{
    double tempData[N];
    int len;
//    copyFile("lipsum.txt","lipsum.out.txt");
//    catFile("lipsum.txt","lipsum.dat.txt");

    len = inputTemperatures(tempData,"temp.txt");
    print(tempData,len);

    return 0;
}
