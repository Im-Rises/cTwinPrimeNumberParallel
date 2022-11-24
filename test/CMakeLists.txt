set(SRCS_TEST "primeNumberSequentialTest.c" "primeNumberParallelTest.c")

set(COMMON_FUNCTIONS_HEADERS)
set(COMMON_FUNCTIONS_SOURCES)

#set(HEADERS "../mergeSortSequential/mergeSortSequential.h" "../mergeSortOpenMp/mergeSortParallelOpenMp.h")
#set(SRCS "../mergeSortSequential/mergeSortSequential.c" "../mergeSortOpenMp/mergeSortParallelOpenMp.c")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${HEADERS} ${SRCS} ${COMMON_FUNCTIONS_HEADERS} ${COMMON_FUNCTIONS_SRCS})
    add_test(${testName} ${testName})
endforeach ()

