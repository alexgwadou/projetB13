#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Memory.h"



int main(int N, char * P[])
{
    double v, m;
    Memory memory;
    //v = memory.cpuPcent();
    m = memory.memoryRequest();
    //printf("Le Pcentage CPU instantanne est %g\n", v);
    printf("La memoire (cat /proc/meminfo : %f\n", m);
    return 0;
}
