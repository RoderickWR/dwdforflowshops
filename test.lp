\ SCIP STATISTICS
\   Problem name     : flowshop1
\   Variables        : 7 (2 binary, 0 integer, 0 implicit integer, 5 continuous)
\   Constraints      : 5
Minimize
 Obj: +1 lamb0 +1 lamb1 +1 makespan
Subject to
 conv: +1 lamb0 +1 lamb1 = +1
 conv: +1 lamb0 +1 lamb1 = +1
 conv: -1 start0 +7 lamb1 -1 start1 = +1
 conv: -1 start0 +7 lamb1 -1 start1 = +1
 conv: -1 start0 +7 lamb1 -1 start1 = +1
Bounds
 0 <= lamb0 <= 1
 0 <= lamb1 <= 1
 0 <= start0 <= 50
 0 <= finish0 <= 50
 0 <= start1 <= 50
 0 <= finish1 <= 50
 0 <= makespan <= 50
Binaries
 lamb0 lamb1
End
