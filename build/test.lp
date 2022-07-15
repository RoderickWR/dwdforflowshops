\ SCIP STATISTICS
\   Problem name     : flowshop1
\   Variables        : 7 (2 binary, 0 integer, 0 implicit integer, 5 continuous)
\   Constraints      : 4
Minimize
 Obj: +1 lamb0 +1 lamb1 +1 makespan
Subject to
 conv: +1 lamb0 +1 lamb1 = +1
 startTimeConstr: +7 lamb1 -1 start0 = +0
 startTimeConstr: +7 lamb1 -1 start1 = +0
