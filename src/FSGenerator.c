#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probdata_binpacking.h"
#include "FSGenerator.h"




processingTimes generatePTs(int nbrJobs, int nbrMachines, int upper, int lower, int seed) {
    int i;
    int ii;
    processingTimes pt;
    srand(seed);

    for( i = 0; i < nbrMachines; ++i ) {
        for( ii = 0; ii < nbrJobs; ++ii ) {
            pt.machine[i].m[ii] = (rand() % (upper-lower+1)) + lower;
        }
    }
    
    return pt;
}

void writeInitSched(char* filename, int nbrJobs, int nbrMachines, int upper, int lower, int seed) {
    int i;
    int ii;
    int iii;
    FILE* fpt;
    processingTimes pt = generatePTs(nbrJobs, nbrMachines, upper, lower, seed);

    fpt = fopen(filename, "w+");

    fprintf(fpt,"%d %d \n",nbrJobs, nbrMachines);
    for (i=0; i < nbrMachines; i++) {
        for (ii=0; ii < nbrJobs; ii++) {            
            fprintf(fpt,"%f ", pt.machine[i].m[ii]); 
        }
        fprintf(fpt,"\n"); 
    }

    int iterPat = 0; // we define only the first pattern per machine here
    for (i=0; i < nbrMachines; i++) {
        for (ii=0; ii < nbrJobs; ii++) {
            double start = 0.0;
            for( iii = 0; iii < ii; ++iii ) {
                start += pt.machine[i].m[iii];
            }
            fprintf(fpt,"%d %d %d %f %f\n", iterPat,i,ii,start,start + pt.machine[i].m[ii]); 
        }
    }
    fclose(fpt);
}

schedule readInitSched(SCIP* scip, char* filename) {
    int i;
    int ii;
    int iii;
    int nbrJobs, nbrMachines;
    processingTimes pt;
    schedule s2; // contains a list of patterns for each machine (mp1,...mpI)
    
    char str[500];
    FILE* fpt;
    fpt = fopen(filename, "r");

    fscanf(fpt,"%d %d \n",&nbrJobs, &nbrMachines);
    SCIPallocBlockMemoryArray(scip, &(s2.sched), nbrMachines*sizeof(struct mPats)) ;

    for (i=0; i < nbrMachines; i++) {
        mPats mp1;
        SCIPallocBlockMemoryArray(scip, &(mp1.mp), 100*sizeof(struct pat)) ;
        mp1.lastIdx = 0;
        s2.sched[i] = mp1;
        for (ii=0; ii < nbrJobs; ii++) {            
            fscanf(fpt,"%lf ", &pt.machine[i].m[ii]); 
        }
    }

    int iterPat = 0;
    double start;
    double end;
    while (fgets(str,500,fpt)) {
        pat p1;
        SCIPallocBlockMemoryArray(scip, &p1.job, nbrJobs*sizeof(struct sPat)) ;
        // now parse the pattern
        for (iii=0; iii < nbrJobs; iii++) {
            sscanf(str,"%d %d %d %lf %lf", &iterPat, &i, &ii, &start, &end);
            assert(iii == ii);
            p1.job[ii].start = start;
            p1.job[ii].end = end;
            if (iii != nbrJobs-1) {
                fgets(str,500,fpt);
            }
            

        }
        s2.sched[i].mp[iterPat] = p1;  
        if (iterPat > s2.sched[i].lastIdx) {
            s2.sched[i].lastIdx = iterPat; 
        }
         
    
    }
    s2.lastIdx = nbrMachines-1;        
    
    fclose(fpt);

    return s2;
      
}

processingTimes readInitPT(SCIP* scip, char* filename) {
    int i;
    int ii;
    int iii;
    int nbrJobs, nbrMachines;
    processingTimes pt;
    schedule s2; // contains a list of patterns for each machine (mp1,...mpI)
    
    char str[500];
    FILE* fpt;
    fpt = fopen(filename, "r");

    fscanf(fpt,"%d %d \n",&nbrJobs, &nbrMachines);
    SCIPallocBlockMemoryArray(scip, &(s2.sched), nbrMachines*sizeof(struct mPats)) ;

    for (i=0; i < nbrMachines; i++) {
        mPats mp1;
        SCIPallocBlockMemoryArray(scip, &(mp1.mp), 100*sizeof(struct pat)) ;
        s2.sched[i] = mp1;
        for (ii=0; ii < nbrJobs; ii++) {            
            fscanf(fpt,"%lf ", &pt.machine[i].m[ii]); 
        }
    }

    return pt;
      
}