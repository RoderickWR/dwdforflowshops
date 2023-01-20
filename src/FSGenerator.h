#include <stdio.h>
#include "probdata_binpacking.h"



processingTimes generatePTs(int nbrJobs, int nbrMachines, int upper, int lower); 

void writeInitSched(int nbrJobs, int nbrMachines, int upper, int lower);