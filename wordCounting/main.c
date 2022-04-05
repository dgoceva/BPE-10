#include <stdio.h>
#include <stdlib.h>

#define BOOLEAN int
#define FALSE 0

int main()
{
    char c;
    unsigned nc,nw,nl;
    BOOLEAN isInside=FALSE;

    nc=nw=nl=0;

    while((c=getchar())!=EOF) {  // ^Z===EOF
        nc++;
        if (c=='\n'){
            ++nl;
        }
        if (c=='\n' || c==' ' || c=='\t'){
            isInside = FALSE;
        }else if (!isInside){
            isInside = !FALSE;
            nw++;
        }
    }

    printf("Chars: %u, Words: %u, Lines: %u\n",nc,nw,nl);

    return 0;
}
