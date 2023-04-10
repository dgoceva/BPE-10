#include "pet.h"

int main()
{
    TPet pets[100];
    unsigned len;

    len = readCsv(IN_TXT_NAME,pets);
    printPets(pets,len);
    writeBin(IN_BIN_NAME,pets,len);
    printf("Hello world!\n");
    return 0;
}
