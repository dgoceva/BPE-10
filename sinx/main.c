#include "utils.h"

int main()
{
    double x,xrad;

    printf("x=");
    scanf("%lf",&x);

    xrad = DEG_TO_RAD(x);
//    xrad = x/180*3.14;

    printf("sin0(%g)=%lf\n",x,sinx0(xrad));
    printf("sin(%g)=%lf\n",x,sinx(xrad));
    printf("sinEPS(%g)=%lf\n",x,sinx_ae(xrad));
    printf("sinDELTA(%g)=%lf\n",x,sinx_re(xrad));
    printf("from math=%lf\n",sin(xrad));

    return 0;
}
