#include "student.h"

int main()
{
 //   TStudent student;
    TStudent *group;
    unsigned len,real_len;

//    system("chcp 65001  > nul");
//    student = input();
//    output(student);
//    writeToFile("students.csv",student);
//    student = readFromFile("students.csv");
//    output(student);
 //   printf("%u\n",countStudents("students.csv"));

    len = countStudents("students.csv");
    if (!len){
        puts("Empty file...\n");
        return EXIT_SUCCESS;
    }
    if((group=(TStudent*)malloc(len*sizeof(TStudent)))==NULL){
        perror("memory error: ");
        exit(EXIT_FAILURE);
    }
    real_len = readGroup("students.csv",group,len);
    outputGroup(group,real_len);
    printf("Average Mark: %.3g\n",averageGroupMark(group,real_len));
    output(minGroupMark(group,real_len));

    free(group);
 //   printf("Hello world!\n");
    return 0;
}
