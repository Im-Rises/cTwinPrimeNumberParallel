# cTwinPrimeNumberParallel

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="cppLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/204111351-40876ca8-3bb8-49a6-96e2-6aa3bfcc21f4.png" alt="mpiLogo" style="height:60px;"/>
</p>

## Description

This is a simple program that calculates the twin prime numbers in a given range. It uses the parallel programming
library MPI to parallelize the calculation.

## Compilation

To compile the program, you can use the makefile or the CMakelists.txt file.
The makefile is for the GNU compiler collection (GCC) and the CMakelists.txt file is for the CMake build system.

### Makefile build

To compile the program using the makefile, first you need to install the GNU compiler collection (GCC) and the MPI
library.
Then you can compile the program using the following command:

```bash
sudo apt-get install gcc
```

```bash
sudo apt-get install make
```

```bash
sudo apt-get install openmpi-bin openmpi-doc libopenmpi-dev
```

Once you have installed the required libraries, you can compile the program using the following command:

```bash
make
```

The executable file will be located in the `buildMakeFile` folder.

### CMake build

To compile the program using the CMake build system, first you need to install the CMake build system and the MPI
library.
Then you can compile the program using the following command:

```bash
sudo apt-get install cmake
```

```bash
cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=g++
```

Once you have installed the required libraries, you can compile the program using the following command:

```bash
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
```

```bash
cmake --build ./build --config Release
```

The executable file will be located in the `build` folder.

## Documentation

Sieve of Eratosthenes:  
<https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes>

MPI Hello World:
<https://mpitutorial.com/tutorials/mpi-hello-world/>

## Contributors

Quentin MOREL:

- @Im-Rises
- <https://github.com/Im-Rises>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/cTwinPrimeNumberParallel)](https://github.com/Im-Rises/cTwinPrimeNumberParallel/graphs/contributors)
