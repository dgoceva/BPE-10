#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOLEAN int
#define FALSE 0

void counting(unsigned *nc, unsigned *nw, unsigned *nl)
{
    char c;
    BOOLEAN isInside=FALSE;

    *nc=*nw=*nl=0;

    while((c=getchar())!=EOF) {  // ^Z===EOF
        (*nc)++;
        if (c=='\n'){
            ++*nl;
        }
        if (c=='\n' || c==' ' || c=='\t'){
            isInside = FALSE;
        }else if (!isInside){
            isInside = !FALSE;
            (*nw)++;
        }
    }
}

void decode_options(int argc, char *argv[],BOOLEAN *l,BOOLEAN *m, BOOLEAN *c)
{
    for (int i=1;i<argc;++i){
        if (!strcmp(argv[i],"-c") || !strcmp(argv[i],"--bytes"))
            *c = !FALSE;
        if (!strcmp(argv[i],"-m") || !strcmp(argv[i],"--chars"))
            *m = !*m;
        if (!strcmp(argv[i],"-l") || !strcmp(argv[i],"--lines"))
            *l = !FALSE;
    }
}
int main(int argc, char *argv[])
{
    unsigned nl,nw,nc;
    BOOLEAN print_L=FALSE,print_c=FALSE,print_m=FALSE;

    counting(&nc,&nw,&nl);
    decode_options(argc,argv,&print_L,&print_m,&print_c);

    if (print_L)
        printf("%u\t",nl);
    if (print_m)
        printf("%u\t",nc);
    if (print_c)
        printf("%u\t",nc);
    if (!print_c && !print_L && !print_m)
        printf("%u\t%u\t%u\n",nl,nw,nc);
    else
        printf("\n");

    return 0;

}
