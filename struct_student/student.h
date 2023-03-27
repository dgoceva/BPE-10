#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//#include <locale>
#include <windows.h>

#define SIZE 5

struct TTStudent {
    unsigned fnom;
    char name[SIZE];
    float avmark;
};

typedef struct TTStudent TStudent;

TStudent input();
void output(TStudent student);

#endif // STUDENT_H_INCLUDED
