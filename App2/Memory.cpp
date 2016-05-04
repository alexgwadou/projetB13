//
// Created by yaren on 5/4/16.
//
#include <iostream>
#include <unistd.h>
#include "Memory.h"
#include <stdlib.h>
#include <stdio.h>


#define NomFic "/proc/stat"
#define NomFic1 "/proc/meminfo"
using namespace std;



double Memory::cpuPcent(void)
{
    FILE * fp;
    char nom [10];
    long v1, v2, v3, v4;
    long vp1, vp2, vp3, vp4;
    long d1, d2, d3, d4;
    double res=0.;
    if ((fp = fopen(NomFic, "r")) == NULL) return (double)-1;
    fscanf(fp,"%s %ld %ld %ld %ld", nom, &v1, &v2, &v3, &v4);
    printf("%s %ld %ld %ld %ld\n",nom,v1,v2,v3,v4);
    /* on attend 10 sec */

    sleep(10);
    rewind(fp);
    if ((fp = fopen(NomFic, "r")) == NULL) return (double)-1;
    fscanf(fp,"%s %ld %ld %ld %ld", nom, &vp1, &vp2, &vp3, &vp4);
    printf("%s %ld %ld %ld %ld\n",nom,vp1,vp2,vp3,vp4);
    d1 = vp1 - v1;
    d2 = vp2 - v2;
    d3 = vp3 - v3;
    d4 = vp4 - v4;
    res = (double)((d1+d2+d3) * 100L) / (double)(d1+d2+d3+d4);
    return res;
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

