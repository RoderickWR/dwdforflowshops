\ SCIP STATISTICS
\   Problem name     : flowshop1
\   Variables        : 7 (2 binary, 0 integer, 0 implicit integer, 5 continuous)
\   Constraints      : 5
Minimize
 Obj: +1 lamb0 +1 lamb1 +1 makespan
Subject to
 conv: +1 lamb0 +1 lamb1 = +1
 startTimeConstrJ0: +7 lamb1 -1 start0 = +0
 startTimeConstrJ1: +7 lamb1 -1 start1 = +0
 endTimeConstrJ0: +7 lamb0 +8 lamb1 -1 end0 = +0
 endTimeConstrJ1: +7 lamb0 +8 lamb1 -1 end1 = +0
Bounds
 0 <= lamb0 <= 1
 0 <= lamb1 <= 1
 0 <= start0 <= 50
 0 <= end0 <= 50
 0 <= start1 <= 50
 0 <= end1 <= 50
 0 <= makespan <= 50
Binaries
 lamb0 lamb1
End
