#include "student.h"

void mainStruct()
{
    TStudent st1, *st2, group[3];

    st1 = input();
    print(st1);

    if ((st2 = (TStudent*)malloc(sizeof(TStudent)))==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    *st2 = input();
    print(*st2);
    free(st2);

    inputGroup(group,3);
    printGroup(group,3);
    printf("Average Group Mark is %g\n",averageGroupMark(group,3));
}

int main()
{
    mainStruct();
    exStruct1();
    exStruct2();
    return 0;
}
