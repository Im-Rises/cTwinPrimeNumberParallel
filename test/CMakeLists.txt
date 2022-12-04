set(SRCS_TEST "finderSeqTest.c" "primeNumberParallelTest.c" "twinPrimeNumberSequentialTest.c" "twinPrimeNumberParallelTest.c")

set(COMMON_FUNCTIONS_HEADERS "../finderSeq/commonFunctions.h" "../finderSeq/commonFunctions.c")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${COMMON_FUNCTIONS_HEADERS})
    add_test(${testName} ${testName})
endforeach ()
