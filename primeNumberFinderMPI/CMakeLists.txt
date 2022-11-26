## (https://cliutils.gitlab.io/modern-cmake/chapters/packages/MPI.html)

if (UNIX)
    find_package(MPI REQUIRED)
    add_executable(${PROJECT_NAME} main.c)
    message(STATUS "Run: ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} ${MPIEXEC_MAX_NUMPROCS} ${MPIEXEC_PREFLAGS} EXECUTABLE ${MPIEXEC_POSTFLAGS} ARGS")
    target_link_libraries(${PROJECT_NAME} PUBLIC MPI::MPI_C)
endif()
