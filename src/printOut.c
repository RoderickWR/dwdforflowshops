#include <stdio.h>
#include <string.h>
#include "probdata_binpacking.h"
#include "branch_ryanfoster.h"

void printOutPattern(pat p, int nbrJobs) {
    int i = 0;
    printf("pattern: \n");
    for (i=0 ; i < nbrJobs; i++) {
        printf("job%d_start%f_end%f \n", i,p.job[i].start,p.job[i].end);
    }
    fflush(stdout);

}

void printOutBrachingList(branchingList bl1) {
    int i = 0;
    printf("Branching List: \n");
    for (i=0 ; i < bl1.lastIdx; i++) {
        printf("%d:(%d, %d)\n", i,bl1.bl[i].id1,bl1.bl[i].id2);
    }
    fflush(stdout);

}