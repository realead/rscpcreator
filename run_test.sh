#start sh run_prefetch.sh name_of_test
#
# name_of_test:
#          build
#


set -e

TARGET=test_$1

cd tests
g++ $TARGET.cpp -O3 -std=c++11 -I../includes -o $TARGET 
./$TARGET 


