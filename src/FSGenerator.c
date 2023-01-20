#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probdata_binpacking.h"
#include "FSGenerator.h"




processingTimes generatePTs(int nbrJobs, int nbrMachines, int upper, int lower) {
    int i;
    int ii;
    processingTimes pt;

    for( i = 0; i < nbrMachines; ++i ) {
        for( ii = 0; ii < nbrJobs; ++ii ) {
            pt.machine[i].m[ii] = (rand() % (upper-lower+1)) + lower;
        }
    }
    
    return pt;
}

void writeInitSched(int nbrJobs, int nbrMachines, int upper, int lower) {
    int i;
    int ii;
    int iii;
    FILE* fpt;
    processingTimes pt = generatePTs(nbrJobs, nbrMachines, upper, lower);




    fpt = fopen("initSched.txt", "w+");

    fprintf(fpt,"%d %d \n",nbrJobs, nbrMachines);
    for (i=0; i < nbrMachines; i++) {
        for (ii=0; ii < nbrJobs; ii++) {            
            fprintf(fpt,"%f ", pt.machine[i].m[ii]); 
        }
        fprintf(fpt,"\n"); 
    }


    for (i=0; i < nbrMachines; i++) {
        for (ii=0; ii < nbrJobs; ii++) {
            double start = 0.0;
            for( iii = 0; iii < ii; ++iii ) {
                start += pt.machine[i].m[iii];
            }
            fprintf(fpt,"%d %d %f %f\n", i,ii,start,start + pt.machine[i].m[ii]); 
        }
    }
    fclose(fpt);
}