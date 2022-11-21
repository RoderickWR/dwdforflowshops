#include <stdio.h>
#include <string.h>
#include "probdata_binpacking.h"

void printOutPattern(pat p, int nbrJobs) {
    int i = 0;
    
    for (i=0 ; i < nbrJobs; i++) {
        printf("job%d_start%f_end%f", i,p.job[i].start,p.job[i].end);
        fflush(stdout);
    }


}