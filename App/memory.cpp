#include <iostream>
#include <unistd.h>
#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

#define NomFic "/proc/stat"
#define NomFic1 "/proc/meminfo"

using namespace std;

Memory::Memory()
{

}


double Memory::memoryRequest() {
    FILE * fp;
    char nom [10];
    char valeur[10];
    long v1, v2, v3, v4;
    double MemTot;

    if ((fp = fopen(NomFic1, "r")) == NULL) return (double)-1;

    /*Memoire Total*/
    fscanf(fp,"%s %ld %s", nom, &v1, valeur);
    printf("%s %ld %s\n",nom, v1, valeur);

    /*Memoire Free*/
    for(int i = 0; i<1; ++i){
        fscanf(fp,"%s %ld %s", nom, &v2, valeur);
        printf("%s %ld %s\n",nom, v2, valeur);
    }

    /*Buffer*/
    for(int i = 0; i<=4; ++i){
        fscanf(fp,"%s %ld %s", nom, &v3, valeur);

    }
    printf("%s %ld %s\n",nom, v3, valeur);

    /*Cache*/
    for(int i = 0; i<1; ++i){
        fscanf(fp,"%s %ld %s", nom, &v4, valeur);
    }
    printf("%s %ld %s\n",nom, v4, valeur);

    MemTot = v1 - (v2+v3+v4);
    return MemTot;

}


