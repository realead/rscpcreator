#start sh run_prefetch.sh name_of_test
#
# name_of_test:
#          build
#          distr
#


set -e

TARGET=test_$1

cd tests
g++ $TARGET.cpp -O3 -std=c++11 -I../includes -o $TARGET 


if [ $TARGET = "test_build" ] ; then
        ./$TARGET
else
    ./$TARGET  > $TARGET.log
    python create_report.py $TARGET.log
fi

