## (https://cliutils.gitlab.io/modern-cmake/chapters/packages/MPI.html)

set(SRCS_TEST "finderSeqTest.c" "primeNumberParallelTest.c" "twinPrimeNumberSequentialTest.c" "twinPrimeNumberParallelTest.c")

set(COMMON_FUNCTIONS_HEADERS "../finderSeq/commonFunctions.h" "../finderSeq/commonFunctions.c")

enable_testing()

find_package(MPI REQUIRED)

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${COMMON_FUNCTIONS_HEADERS})
    if (UNIX AND NOT APPLE)
        message(STATUS "Run: ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${MPIEXEC_MAX_NUMPROCS} ${MPIEXEC_PREFLAGS} EXECUTABLE ${MPIEXEC_POSTFLAGS} ARGS")
        target_link_libraries(${testName} PUBLIC MPI::MPI_C)
        target_link_libraries(${testName} PUBLIC -lm)
    endif ()
    add_test(${testName} ${testName})
endforeach ()
