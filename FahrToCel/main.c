#include <stdio.h>
#include <stdlib.h>

#define LOWER 0
#define UPPER 30
#define STEP 20

int main()
{
    float cel;
//    for (;;)
    printf("Fahr\t\tCel\n");
    for (int fahr=LOWER;fahr<=UPPER;fahr+=STEP)
    {
        cel = (fahr-32)*5/9.;
        printf("%d\t\t%g\n",fahr,cel);
    }
//    printf("Hello world!\n");
/*    return EXIT_FAILURE;
*/
    return EXIT_SUCCESS;
}
