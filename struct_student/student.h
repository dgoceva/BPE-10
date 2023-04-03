#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define SIZE            5
#define MAX_SIZE    1000
#define DELIM         ","

struct TTStudent {
    unsigned fnom;
    char name[SIZE];
    float avmark;
};

typedef struct TTStudent TStudent;

TStudent input();
void output(TStudent student);
void writeToFile(char *fname,TStudent student);
TStudent readFromFile(char *fname);
TStudent parseStudent(char *buff);
unsigned countStudents(char *fname);
unsigned readGroup(char *fname,TStudent *group,unsigned len);
bool readStudent(FILE *f, TStudent *student);
void outputGroup(TStudent *group, unsigned len);
float averageGroupMark(TStudent *group, unsigned len);
TStudent minGroupMark(TStudent *group, unsigned len);

#endif // STUDENT_H_INCLUDED
