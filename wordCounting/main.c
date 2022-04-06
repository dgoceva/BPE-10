#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
    unsigned nl,nw,nc;

    counting(&nc,&nw,&nl);
    printf("%u\t%u\t%u\n",nl,nw,nc);

    return 0;

}
