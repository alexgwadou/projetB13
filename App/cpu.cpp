#include <iostream>
#include <unistd.h>
#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>

#define NomFic "/proc/stat"
#define NomFic1 "/proc/meminfo"

using namespace std;

cpu::cpu()
{

}

/* fonction qui accede a l'interface et qui calcule le pourcentage */
double cpu::cpuPcent(void)
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
   /* on attend 1 sec */
   sleep(1);
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





