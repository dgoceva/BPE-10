#include <stdio.h>
#include <stdlib.h>

/*
#define LOWER 0
#define UPPER 30
#define STEP 20
*/

int main()
{
    float cel;
    int lower;
    int upper, step;

 //   scanf("%d%d%d",&lower,&upper,&step);
    printf("Lower=");
    scanf("%d",&lower);
    printf("Upper=");
    scanf("%d",&upper);
    printf("Step=");
    scanf("%d",&step);

//    for (;;)
    printf("Fahr\t\tCel\n");
/*
    for (int fahr=lower;fahr<=upper;fahr+=step)
    {
        cel = (fahr-32)*5/9.;
        printf("%d\t\t%g\n",fahr,cel);
    }
*/
    int fahr=lower;
    // while(1)
/*    while (fahr<=upper)
    {
        cel = 5/9.*(fahr-32);
        printf("%d\t\t%g\n",fahr,cel);
        fahr += step;
    }
    */
    do {
        cel = 5/9.*(fahr-32);
        printf("%d\t\t%g\n",fahr,cel);
        fahr += step;
    } while (fahr<=upper);
//    printf("Hello world!\n");
/*    return EXIT_FAILURE;
*/
    return EXIT_SUCCESS;
}
