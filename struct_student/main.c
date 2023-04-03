#include "student.h"

int main()
{
    TStudent student;

//    system("chcp 65001  > nul");
//    student = input();
//    output(student);
//    writeToFile("students.csv",student);
    student = readFromFile("students.csv");
    output(student);
 //   printf("Hello world!\n");
    return 0;
}
