#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "probdata_binpacking.h"
#include "FSGenerator.h"




processingTimes* generatePTs(int nbrJobs, int nbrMachines, int upper, int lower, int seed) {
    int i;
    int ii;
    processingTimes* ppt = (processingTimes*) malloc(sizeof(processingTimes));
    ppt->machine = malloc(nbrMachines*sizeof(processingTimesOneMachine));
    srand(seed);

    for( i = 0; i < nbrMachines; ++i ) {
        processingTimesOneMachine* pptom = (processingTimesOneMachine*) malloc(sizeof(processingTimesOneMachine));;
        pptom->m = malloc(nbrJobs*sizeof(double));

        for( ii = 0; ii < nbrJobs; ++ii ) {
            pptom->m[ii] = (rand() % (upper-lower+1)) + lower;
        }
        ppt->machine[i] = *pptom;
    }
    
    return ppt;
}

void writeInitSched(char* filename, int nbrJobs, int nbrMachines, int mPats_initSize, int upper, int lower, int seed) {
    int i;
    int ii;
    int iii;
    FILE* fpt;
    processingTimes* ppt = generatePTs(nbrJobs, nbrMachines, upper, lower, seed);

    

    fpt = fopen(filename, "w+");

    fprintf(fpt,"%d %d \n",nbrJobs, nbrMachines);
    for (i=0; i < nbrMachines; i++) {
        for (ii=0; ii < nbrJobs; ii++) {            
            fprintf(fpt,"%f ", ppt->machine[i].m[ii]); 
        }
        fprintf(fpt,"\n"); 
    }

    int iterPat = 0; // we define only the first pattern per machine here
    for (iterPat=0; iterPat < mPats_initSize; iterPat++) {
        for (i=0; i < nbrMachines; i++) {
            for (ii=0; ii < nbrJobs; ii++) {
                double start = 0.0;
                for( iii = 0; iii < ii; ++iii ) {
                    start += ppt->machine[i].m[iii];
                }
                fprintf(fpt,"%d %d %d %f %f\n", iterPat,i,ii,start + iterPat,start + ppt->machine[i].m[ii] + iterPat); 
            }
        }
    }
    // free processing Times array again
    for( i = 0; i < nbrMachines; ++i ) {       
        free(ppt->machine[i].m);
        //free(&(ppt->machine[i]));        
    }
    fclose(fpt);
}

schedule readInitSched(SCIP* scip, char* filename, int mPats_initSize, int* mPats_sizes) {
    int i;
    int ii;
    int iii;
    int nbrJobs, nbrMachines;
    schedule s2; // contains a list of patterns for each machine (mp1,...mpI)
        
    char str[500];
    FILE* fpt;
    fpt = fopen(filename, "r");

    fscanf(fpt,"%d %d",&nbrJobs, &nbrMachines);
    SCIPallocBlockMemoryArray(scip, &(s2.sched), nbrMachines*sizeof(struct mPats)) ;

    double dummy; // just needed to skip lines in the file

    for (i=0; i < nbrMachines; i++) {
        mPats mp1;
        SCIPallocBlockMemoryArray(scip, &(mp1.mp), mPats_initSize*sizeof(struct pat)) ;
        mp1.lastIdx = 0;
        mp1.size = mPats_initSize;
        s2.sched[i] = mp1;
        // to skip the processing time lines in the file
        for (ii=0; ii < nbrJobs; ii++) {            
            fscanf(fpt,"%lf ", &dummy); 
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
        if (s2.sched[i].size <= iterPat) {
            int newsize = s2.sched[i].size * 2;
            SCIPreallocBlockMemoryArray(scip, &(s2.sched[i].mp), s2.sched[i].size, newsize);
            s2.sched[i].size = newsize;
        }
        s2.sched[i].mp[iterPat] = p1;  
        if (iterPat > s2.sched[i].lastIdx) {
            s2.sched[i].lastIdx = iterPat; 
            mPats_sizes[i] = iterPat;
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
    
    char str[500];
    FILE* fpt;
    fpt = fopen(filename, "r");
    // first we need nbr Jobs and Machines
    fscanf(fpt,"%d %d \n",&nbrJobs, &nbrMachines);
    // we allocate processing times array
    SCIPallocBlockMemoryArray(scip, &(pt.machine), nbrMachines*sizeof(struct processingTimesOneMachine)) ;
        for (i=0; i < nbrMachines; i++) {
        processingTimesOneMachine pptom;
        SCIPallocBlockMemoryArray(scip, &(pptom.m), nbrJobs*sizeof(double)) ;
        for (ii=0; ii < nbrJobs; ii++) {            
            fscanf(fpt,"%lf ", &pptom.m[ii]); 
        }
        pt.machine[i] = pptom;
    }

    return pt;
      
}