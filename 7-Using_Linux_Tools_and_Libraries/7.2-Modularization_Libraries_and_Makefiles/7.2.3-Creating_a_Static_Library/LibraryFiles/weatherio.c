#include <stdio.h>

void printTemps(double *listTemps, int numOfTemps){
    int i;
    for (i=0; i<numOfTemps; i++){
        printf("Day %d: %.2lf\n", i+1, listTemps[i]);
    }
}
