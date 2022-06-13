# CMake generated Testfile for 
# Source directory: /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check
# Build directory: /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/check
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(examples-binpacking-build "/usr/bin/cmake" "--build" "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build" "--config" "Debug" "--target" "binpacking")
set_tests_properties(examples-binpacking-build PROPERTIES  RESOURCE_LOCK "libscip" _BACKTRACE_TRIPLES "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;16;add_test;/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;0;")
add_test(examples-binpacking-u20_00 "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/binpacking" "-f" "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/../data/u20_00.bpa" "-o" "9" "9")
set_tests_properties(examples-binpacking-u20_00 PROPERTIES  DEPENDS "examples-binpacking-build" PASS_REGULAR_EXPRESSION "Validation         : Success" RESOURCE_LOCK "libscip" _BACKTRACE_TRIPLES "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;37;add_test;/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;0;")
add_test(examples-binpacking-u40_00 "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/binpacking" "-f" "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/../data/u40_00.bpa" "-o" "17" "17")
set_tests_properties(examples-binpacking-u40_00 PROPERTIES  DEPENDS "examples-binpacking-build" PASS_REGULAR_EXPRESSION "Validation         : Success" RESOURCE_LOCK "libscip" _BACKTRACE_TRIPLES "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;37;add_test;/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;0;")
add_test(examples-binpacking-u60_00 "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/binpacking" "-f" "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/../data/u60_00.bpa" "-o" "27" "27")
set_tests_properties(examples-binpacking-u60_00 PROPERTIES  DEPENDS "examples-binpacking-build" PASS_REGULAR_EXPRESSION "Validation         : Success" RESOURCE_LOCK "libscip" _BACKTRACE_TRIPLES "/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;37;add_test;/home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check/CMakeLists.txt;0;")
