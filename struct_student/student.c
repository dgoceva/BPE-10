#include "student.h"

/*
TStudent input()
{
    TStudent student;

    printf("Faculty Number: ");
    scanf("%u",&student.fnom);
    printf("Name: ");
    scanf("%4s",student.name);
    fflush(stdin);
    printf("Average Mark: ");
    scanf("%f",&student.avmark);

    return student;
}
*/
TStudent input()
{
    TStudent student;

    printf("Факултетен Number: ");
    scanf("%u",&student.fnom);
    fflush(stdin);
    printf("Name: ");
    fgets(student.name,SIZE,stdin);
    fflush(stdin);
    printf("Average Mark: ");
    scanf("%f",&student.avmark);

    return student;
}
void output(TStudent student)
{
    printf("(%u, %s, %g)\n",student.fnom,student.name,student.avmark);
}

void writeToFile(char *fname,TStudent student)
{
    FILE *f;

    if((f=fopen(fname,"a"))==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    fprintf(f,"%u,%s,%g\n",student.fnom,student.name,student.avmark);

    fclose(f);
}
TStudent readFromFile(char *fname)
{
     FILE *f;
     char buff[MAX_SIZE];

    if((f=fopen(fname,"r"))==NULL){
        perror("open file error: ");
        exit(EXIT_FAILURE);
    }

    if(fgets(buff,MAX_SIZE,f)==NULL){
        perror("reading error: ");
        fclose(f);
        exit(EXIT_FAILURE);
    }
    fclose(f);
    puts(buff);
    return parseStudent(buff);
}

TStudent parseStudent(char *buff)
{
    TStudent student;
    char *token;

    if((token=strtok(buff,DELIM))==NULL){
        perror("token error: ");
        exit(EXIT_FAILURE);
    }
    student.fnom = atoi(token);

    if((token=strtok(NULL,DELIM))==NULL){
        perror("token error2: ");
        exit(EXIT_FAILURE);
    }
    strcpy(student.name,token);

    if((token=strtok(NULL,DELIM))==NULL){
        perror("token error3: ");
        exit(EXIT_FAILURE);
    }
    student.avmark = atof(token);

    return student;
}
unsigned countStudents(char *fname)
{
     FILE *f;
     char buff[MAX_SIZE];
     unsigned count=0;

    if((f=fopen(fname,"r"))==NULL){
        perror("open file error: ");
        exit(EXIT_FAILURE);
    }

    while(true){
        if(fgets(buff,MAX_SIZE,f)==NULL){
            if(!feof(f)){
                perror("reading error: ");
                fclose(f);
                exit(EXIT_FAILURE);
            }
            else {
                fclose(f);
                return count;
            }
        }
        count++;
    }
}
unsigned readGroup(char *fname,TStudent *group,unsigned len)
{
     FILE *f;
     unsigned count;

    if((f=fopen(fname,"r"))==NULL){
        perror("open file error: ");
        return 0;
    }

    for(count=0;count<len && readStudent(f,group+count);++count)
        ;

    fclose(f);
    return count;
}
bool readStudent(FILE *f, TStudent *student)
{
    char buff[MAX_SIZE];

    if(fgets(buff,MAX_SIZE,f)==NULL){
        perror("reading error: ");
        return false;
    }
    *student = parseStudent(buff);
    return true;
}
void outputGroup(TStudent *group, unsigned len)
{
    for(int i=0;i<len;++i)
        output(group[i]);
}
