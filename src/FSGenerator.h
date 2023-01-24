#include <stdio.h>
#include "probdata_binpacking.h"



processingTimes generatePTs(int nbrJobs, int nbrMachines, int upper, int lower, int seed); 

void writeInitSched(char* filename, int nbrJobs,int mPats_initSize, int nbrMachines, int upper, int lower, int seed);

schedule readInitSched(SCIP* scip, char* filename, int mPats_initSize, int* mPats_sizes);

processingTimes readInitPT(SCIP* scip, char* filename);