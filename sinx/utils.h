#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define DEG_TO_RAD(x) x/180*M_PI
#define EPS 1e-6
#define DELTA 0.01

double sinx0(double x);
double sinx(double x);
double sinx_ae(double x);
double sinx_re(double x);

#endif // UTILS_H_INCLUDED
