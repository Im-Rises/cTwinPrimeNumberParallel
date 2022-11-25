cmake_minimum_required(VERSION 3.9)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project("primeNumberFinderSequential")
add_subdirectory(${PROJECT_NAME})

project("primeNumberFinderParallel")
add_subdirectory(${PROJECT_NAME})

enable_testing()
add_subdirectory("test")

