#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

int main()
{
    Py_Initialize();
    PyRun_SimpleString("import matplotlib.pyplot as plt");
    PyRun_SimpleString("import numpy as np");
    PyRun_SimpleString("x=np.arange(0,4*np.pi,0.1)");
    PyRun_SimpleString("y=np.sin(x)");
    PyRun_SimpleString("plt.plot(x,y)");
    PyRun_SimpleString("plt.show()");
    Py_Exit(0);
    printf("Hello world!\n");
    return 0;
}
