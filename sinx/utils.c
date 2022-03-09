#include "utils.h"

// 3! = 1.2.3 = 1!.2.3
// 5! = 1.2.3.4.5 = 3!.4.5
double sinx0(double x)
{
        double sum=0;
        double nom=x;
        double denom=1;
        unsigned fact=3;

        for (int i=1;i<1000;++i,fact+=2){
            sum += nom/denom;
            nom *= -x*x;
            denom *= (fact-1)*fact;
        }
        return sum;
}

double sinx(double x)
{
        double sum=0;
        double member=x;
       unsigned fact=3;

        for (int i=1;i<1000;++i,fact+=2){
            sum += member;
            member *= -x*x/((fact-1)*fact);
        }
        return sum;
}

// | memberN-memberN-1 | <eps
double sinx_ae(double x)
{
        double sum=0;
        double member=x;
        double member1=0;
        unsigned fact=3;

        while (fabs(member-member1)>=EPS){
            sum += member;
            member1 = member;
            member *= -x*x/((fact-1)*fact);
            fact +=2;
        }
        return sum;
}

// | (memberN-memberN-1)/memberN-1 | <delta
double sinx_re(double x)
{
        double sum=0;
        double member=x;
        double member1=0;
        unsigned fact=3;

        while (fabs((member-member1)/member)>=DELTA){
            sum += member;
            member1 = member;
            member *= -x*x/((fact-1)*fact);
            fact +=2;
        }
        return sum;
}
