# cTwinPrimeNumberParallel

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="cppLogo" style="height:60px;"/>
      <img src="https://user-images.githubusercontent.com/59691442/204111351-40876ca8-3bb8-49a6-96e2-6aa3bfcc21f4.png" alt="mpiLogo" style="height:60px;"/>
</p>

## Description

This is a simple program that calculates the number of prime and twin prime numbers in a given range.
It uses the parallel programming library MPI to parallelize the calculation.

The Prime algorithm is based on the Sieve of Eratosthenes. The original Algorithm is based on
Michael J. Quinn's book `Parallel Programming in C with MPI and OpenMP`.

The implemented algorithm are the following:

- [x] Sequential Sieve of Eratosthenes
- [x] Parallel Sieve of Eratosthenes
- [x] Parallel twin prime number finder using MPI_Send and MPI_Recv (V1)
- [x] Parallel twin prime number finder using MPI_Get with windows (V2)

## Dependencies

- C90
- CMake or Make
- C90 compiler (GCC, Clang, MSVC, ...)

## Table of Contents

- [Description](#description)
- [Dependencies](#Dependencies)
- [Table of Contents](#table-of-contents)
- [Quickstart](#Quick-start)
- [Algorithms](#Algorithms)
    - [Sequential Prime Number Algorithm](#Sequential-Prime-Number-Algorithm)
    - [Parallel Prime Number Algorithm](#Parallel-Prime-Number-Algorithm)
- [Results](#Results)
- [Speed test](#Speed-test)
- [Compilation](#Compilation)
    - [Makefile build](#Makefile-build)
    - [CMake build](#CMake-build)
- [How to use](#How-to-use)
- [Project Architecture](#Project-Architecture)
- [GitHub Actions](#GitHub-Actions)
- [Documentations](#Documentation)
- [Contributors](#Contributors)

## Quick Start

Depending on your operating system you will need to install some libs, they are installed differently depending on your
system, please follow the instructions in the Compilation section.

For an explanation on `How to use` go to the according section.

The different algorithms used are described below.

The finderSeq version is composed of the sequential prime number finder and the sequential twin prime number finder.

## Algorithms

The algorithm used to calculate the twin prime numbers is the Sieve of Eratosthenes. It is a simple, ancient algorithm
for finding all prime numbers up to any given limit. It does so by iteratively marking as composite (i.e., not prime)
the multiples of each prime, starting with the multiples of 2.

```algorithm
1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
2. Initially, let p equal 2, the first prime number.
3. Enumerate the multiples of p by counting in increments of p from 2p to n, and mark them in the list (these will be 2p, 3p, 4p, ...; the p itself should not be marked).
4. Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
```

The algorithm is implemented to count the number of prime numbers in a given range.

### Sequential Prime Number Algorithm

```algorithm
1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
2. Initially, let k equal 2, the first prime number.
3. Repeat
   a) Mark all multiples of k between k^2 and n as composite.
   b) Find the first number greater than k in the list that is not marked. If there was no such number, stop. Otherwise, let k now equal this new number (which is the next prime), and repeat from step 3.
4. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
5. Count the number of prime numbers in the list.
```

### Parallel Prime Number Algorithm

```algorithm
1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n). (Each process creates its share of list)
2. Initially, let p equal 2, the first prime number. (Each process does this)
3. Repeat
   a) Mark all multiples of k between k^2 and n as composite. (Each process marks its share of list)
   b) Find the first number greater than k in the list that is not marked. If there was no such number, stop. Otherwise, let k now equal this new number (which is the next prime), and repeat from step 3. (Process 0 only)
   c) Broadcast the new value of k to all processes. (Process 0 only)
4. Reduction of the list of primes.
5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
6. Count the number of prime numbers in the list.
```

## Details on the implementation

Each parallel version of the algoithm has been modified to work with small ranges.

The original algorithm from Michael Quinn's book `Parallel Programming in C with MPI and OpenMP` seems to have
an issue calculating the prime numbers in a range smaller than 10 with 4 processes, it returns 5 prime numbers instead
of 4.
The modified algorithm is the following:

```c
proc0_size = (n - 1) / p;

if ((2 + proc0_size) < (int)sqrt((double)n))
{
    if (!id)
    {
        printf("Too many processes\n");
    }
    MPI_Finalize();
    exit(1);
}
```

has been replaced by the following code:

```c
if (sqrt(n) >= (double)n / p)
{
    if (!id)
    {
        printf("Error : Too many processes\n");
    }
    MPI_Finalize();
    exit(1);
}
```

Preventing from having more processes than the square root of the range.

## Results

The results of the programs are shown in the following table:

| n (upper limit) | machines number | Time V1  | Time V2  | Twin prime numbers |
|-----------------|-----------------|----------|----------|--------------------|
| 100000000       | 1               | 2.808879 | 2.95147  | 440312             |
| 100000000       | 2               | 1.308096 | 1.412506 | 440312             |
| 100000000       | 3               | 0.946394 | 0.973774 | 440312             |
| 100000000       | 4               | 0.642441 | 0.695551 | 440312             |
| 100000000       | 5               | 0.529234 | 0.569689 | 440312             |
| 100000000       | 6               | 0.434324 | 0.429896 | 440312             |
| 100000000       | 7               | 0.399249 | 0.413432 | 440312             |
| 100000000       | 8               | 0.323008 | 0.347013 | 440312             |
| 100000000       | 9               | 0.302753 | 0.338876 | 440312             |
| 100000000       | 10              | 0.26638  | 0.290584 | 440312             |
| 100000000       | 11              | 0.237417 | 0.261102 | 440312             |
| 100000000       | 12              | 0.258154 | 0.26576  | 440312             |
| 100000000       | 13              | 0.230347 | 0.238771 | 440312             |
| 100000000       | 14              | 0.219647 | 0.234258 | 440312             |
| 100000000       | 15              | 0.216049 | 0.229017 | 440312             |
| 100000000       | 16              | 0.19889  | 0.213629 | 440312             |

<details>
<summary>Click to see detailed results</summary>

| n (upper limit) | machines number | Time V1  | Time V2  | Twin prime numbers |
|-----------------|-----------------|----------|----------|--------------------|
| 10              | 1               | 0.000053 | 0.000228 | 2                  |
| 10              | 2               | 0.000265 | 0.001174 | 2                  |
| 10              | 3               | 0.000323 | 0.002461 | 2                  |
| 10              | 4               |          |          | 2                  |
| 10              | 5               |          |          | 2                  |
| 10              | 6               |          |          | 2                  |
| 10              | 7               |          |          | 2                  |
| 10              | 8               |          |          | 2                  |
| 10              | 9               |          |          | 2                  |
| 10              | 10              |          |          | 2                  |
| 10              | 11              |          |          | 2                  |
| 10              | 12              |          |          | 2                  |
| 10              | 13              |          |          | 2                  |
| 10              | 14              |          |          | 2                  |
| 10              | 15              |          |          | 2                  |
| 10              | 16              |          |          | 2                  |
| 100             | 1               | 0.000043 | 0.000215 | 8                  |
| 100             | 2               | 0.000237 | 0.00134  | 8                  |
| 100             | 3               | 0.003479 | 0.001748 | 8                  |
| 100             | 4               | 0.001612 | 0.004303 | 8                  |
| 100             | 5               | 0.002697 | 0.007367 | 8                  |
| 100             | 6               | 0.002069 | 0.004391 | 8                  |
| 100             | 7               | 0.0012   | 0.004815 | 8                  |
| 100             | 8               | 0.001518 | 0.008082 | 8                  |
| 100             | 9               | 0.003855 | 0.007261 | 8                  |
| 100             | 10              |          |          | 8                  |
| 100             | 11              |          |          | 8                  |
| 100             | 12              |          |          | 8                  |
| 100             | 13              |          |          | 8                  |
| 100             | 14              |          |          | 8                  |
| 100             | 15              |          |          | 8                  |
| 100             | 16              |          |          | 8                  |
| 1000            | 1               | 0.000183 | 0.000252 | 35                 |
| 1000            | 2               | 0.000232 | 0.001436 | 35                 |
| 1000            | 3               | 0.00058  | 0.002049 | 35                 |
| 1000            | 4               | 0.001635 | 0.005213 | 35                 |
| 1000            | 5               | 0.000947 | 0.003938 | 35                 |
| 1000            | 6               | 0.0021   | 0.005677 | 35                 |
| 1000            | 7               | 0.001076 | 0.004761 | 35                 |
| 1000            | 8               | 0.002279 | 0.008067 | 35                 |
| 1000            | 9               | 0.001254 | 0.008475 | 35                 |
| 1000            | 10              | 0.00146  | 0.007181 | 35                 |
| 1000            | 11              | 0.002341 | 0.015144 | 35                 |
| 1000            | 12              | 0.002051 | 0.011632 | 35                 |
| 1000            | 13              | 0.001305 | 0.009518 | 35                 |
| 1000            | 14              | 0.002554 | 0.013066 | 35                 |
| 1000            | 15              | 0.001497 | 0.034798 | 35                 |
| 1000            | 16              | 0.0041   | 0.02542  | 35                 |
| 10000           | 1               | 0.000165 | 0.000321 | 205                |
| 10000           | 2               | 0.000599 | 0.00179  | 205                |
| 10000           | 3               | 0.000649 | 0.002224 | 205                |
| 10000           | 4               | 0.002252 | 0.004705 | 205                |
| 10000           | 5               | 0.001673 | 0.004671 | 205                |
| 10000           | 6               | 0.002435 | 0.004599 | 205                |
| 10000           | 7               | 0.002261 | 0.006064 | 205                |
| 10000           | 8               | 0.0022   | 0.008406 | 205                |
| 10000           | 9               | 0.001977 | 0.007317 | 205                |
| 10000           | 10              | 0.00192  | 0.008946 | 205                |
| 10000           | 11              | 0.001892 | 0.009959 | 205                |
| 10000           | 12              | 0.002271 | 0.009783 | 205                |
| 10000           | 13              | 0.002849 | 0.010273 | 205                |
| 10000           | 14              | 0.013783 | 0.013611 | 205                |
| 10000           | 15              | 0.002218 | 0.012203 | 205                |
| 10000           | 16              | 0.005288 | 0.013704 | 205                |
| 100000          | 1               | 0.001173 | 0.001788 | 1224               |
| 100000          | 2               | 0.001216 | 0.00298  | 1224               |
| 100000          | 3               | 0.005796 | 0.003283 | 1224               |
| 100000          | 4               | 0.005458 | 0.00733  | 1224               |
| 100000          | 5               | 0.002918 | 0.004663 | 1224               |
| 100000          | 6               | 0.005898 | 0.007053 | 1224               |
| 100000          | 7               | 0.00229  | 0.005705 | 1224               |
| 100000          | 8               | 0.004954 | 0.009955 | 1224               |
| 100000          | 9               | 0.003073 | 0.009845 | 1224               |
| 100000          | 10              | 0.004389 | 0.012207 | 1224               |
| 100000          | 11              | 0.004299 | 0.009352 | 1224               |
| 100000          | 12              | 0.002632 | 0.009647 | 1224               |
| 100000          | 13              | 0.003848 | 0.011904 | 1224               |
| 100000          | 14              | 0.005902 | 0.010826 | 1224               |
| 100000          | 15              | 0.005442 | 0.016598 | 1224               |
| 100000          | 16              | 0.006033 | 0.01509  | 1224               |
| 1000000         | 1               | 0.011429 | 0.014362 | 8169               |
| 1000000         | 2               | 0.00824  | 0.010348 | 8169               |
| 1000000         | 3               | 0.005953 | 0.015472 | 8169               |
| 1000000         | 4               | 0.006401 | 0.010918 | 8169               |
| 1000000         | 5               | 0.010776 | 0.013523 | 8169               |
| 1000000         | 6               | 0.007204 | 0.011878 | 8169               |
| 1000000         | 7               | 0.009542 | 0.019755 | 8169               |
| 1000000         | 8               | 0.006692 | 0.011999 | 8169               |
| 1000000         | 9               | 0.012837 | 0.02199  | 8169               |
| 1000000         | 10              | 0.010097 | 0.023918 | 8169               |
| 1000000         | 11              | 0.016681 | 0.013194 | 8169               |
| 1000000         | 12              | 0.008815 | 0.013648 | 8169               |
| 1000000         | 13              | 0.010978 | 0.039109 | 8169               |
| 1000000         | 14              | 0.009185 | 0.016248 | 8169               |
| 1000000         | 15              | 0.009272 | 0.018724 | 8169               |
| 1000000         | 16              | 0.011021 | 0.025345 | 8169               |
| 10000000        | 1               | 0.141508 | 0.160949 | 58980              |
| 10000000        | 2               | 0.071351 | 0.083553 | 58980              |
| 10000000        | 3               | 0.063278 | 0.073145 | 58980              |
| 10000000        | 4               | 0.049691 | 0.048778 | 58980              |
| 10000000        | 5               | 0.050554 | 0.054734 | 58980              |
| 10000000        | 6               | 0.046479 | 0.042268 | 58980              |
| 10000000        | 7               | 0.037244 | 0.045187 | 58980              |
| 10000000        | 8               | 0.040999 | 0.037032 | 58980              |
| 10000000        | 9               | 0.037903 | 0.041825 | 58980              |
| 10000000        | 10              | 0.038408 | 0.043571 | 58980              |
| 10000000        | 11              | 0.042799 | 0.046796 | 58980              |
| 10000000        | 12              | 0.035235 | 0.035868 | 58980              |
| 10000000        | 13              | 0.036882 | 0.037351 | 58980              |
| 10000000        | 14              | 0.038998 | 0.036742 | 58980              |
| 10000000        | 15              | 0.036792 | 0.040683 | 58980              |
| 10000000        | 16              | 0.03962  | 0.045223 | 58980              |
| 100000000       | 1               | 2.808879 | 2.95147  | 440312             |
| 100000000       | 2               | 1.308096 | 1.412506 | 440312             |
| 100000000       | 3               | 0.946394 | 0.973774 | 440312             |
| 100000000       | 4               | 0.642441 | 0.695551 | 440312             |
| 100000000       | 5               | 0.529234 | 0.569689 | 440312             |
| 100000000       | 6               | 0.434324 | 0.429896 | 440312             |
| 100000000       | 7               | 0.399249 | 0.413432 | 440312             |
| 100000000       | 8               | 0.323008 | 0.347013 | 440312             |
| 100000000       | 9               | 0.302753 | 0.338876 | 440312             |
| 100000000       | 10              | 0.26638  | 0.290584 | 440312             |
| 100000000       | 11              | 0.237417 | 0.261102 | 440312             |
| 100000000       | 12              | 0.258154 | 0.26576  | 440312             |
| 100000000       | 13              | 0.230347 | 0.238771 | 440312             |
| 100000000       | 14              | 0.219647 | 0.234258 | 440312             |
| 100000000       | 15              | 0.216049 | 0.229017 | 440312             |
| 100000000       | 16              | 0.19889  | 0.213629 | 440312             |

</details>

> *Note*  
> The results are indicative and may vary depending on the machine.

## Speed test

The project is set up with some bash scripts to test the speed of the different algorithms. You can start the test by
running the speedTest.sh script in the speedTest folder.

```bash
./speedTestMonoComputer.sh <base n value> <multiplier> <iteration number>
```

Example :

```bash
./speedTestMonoComputer.sh 10 10 6
```

The output will be printed in the console. You can use a pipe to redirect the output to a file.

```bash
./speedTestMonoComputer.sh 10 10 6 > output.txt
```

> *Warning*  
> You need to build the project before running the script (check the compilation section). You also need to be in
> the speedTest folder to run the script correctly.

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

## How to use

To use the program, you need to run the executable file and pass the following arguments:

```bash
mpirun -np <number of processes> ./build/cTwinPrimeNumberParallel <upper limit>
```

or

```bash
mpirun -c <number of processes> ./build/cTwinPrimeNumberParallel <upper limit>
```

The program will calculate the prime numbers in the range [3, upper limit].

The twin prime program will count the number of twin prime numbers in the range [3, upper limit].

> **Note**  
> I will not explain how to set up the MPI library for multiple processes from different machines.  
> You can find more information about it in the [MPI documentation](https://www.open-mpi.org/doc/current/).
> You can also find more information about the MPI library in the [MPI tutorial](https://mpitutorial.com/tutorials/).
> The program will only work on your local machine if you use the `mpirun` command with a number of core less than or
> equal to the number of cores of your machine.

## Project Architecture

~~~
cTwinPrimeNumberParallel
├── .github
│  ├── workflows
│  │   |── c-cpp.yml
│  │   |── cmake.yml
│  │   |── codeql.yml
│  │   |── cpp-linter.yml
│  │   |── dependency-review.yml
│  │   |── flawfinder.yml
│  │   |── greetings.yml
│  │   |── label.yml
│  │   |── stale.yml
|  ├── labels.yml
|  ├── release.yml
├── buildMakeFile
│   |── *
├── finderSeq
|  ├── CMakelists.txt
|  ├── main.c
├── PrimeNumberFinderParallel
|  ├── CMakelists.txt
|  ├── main.c
├── test
|  ├── CMakeLists.txt
|  ├── *.c
├── TwinPrimeNumberFinderMpiV1
|  ├── CMakelists.txt
|  ├── main.c
├── TwinPrimeNumberFinderMpiV2
|  ├── CMakelists.txt
|  ├── main.c
├── .clang-format
├── .clang-tidy
├── .editorconfig
├── .gitattributes
├── .gitignore
├── CMakelists.txt
├── CMakePresets.json
├── CMakeSettings.json
├── Makefile
├── README.md
~~~

## GitHub Actions

[![C/C++ CI](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/c-cpp.yml/badge.svg?branch=main)](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/c-cpp.yml)
[![CMake](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/codeql.yml/badge.svg)](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/codeql.yml)
[![cpp-linter](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/cpp-linter.yml/badge.svg?branch=main)](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/cpp-linter.yml)
[![flawfinder](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/flawfinder.yml/badge.svg?branch=main)](https://github.com/Im-Rises/cTwinPrimeNumberParallel/actions/workflows/flawfinder.yml)

This project uses GitHub Actions to build and test the program.

- C/C++ CI: This workflow will build the program using the makefile.
- CMake: This workflow will build the program using the CMake build system.
- CodeQL: This workflow will analyze the code to find security vulnerabilities.
- cpp-linter: This workflow will analyze the code to find bugs and potential vulnerabilities.
- flawfinder: This workflow will analyze the code to find bugs and potential vulnerabilities.

## Documentation

Parallel Programming in C with MPI and OpenMP, Michael J. Quinn, 2003

Code from marius92mc's repository:  
<https://github.com/marius92mc/sieve-of-eratosthenes-with-MPI>

Sieve of Eratosthenes:  
<https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes>

MPI Hello World:  
<https://mpitutorial.com/tutorials/mpi-hello-world/>

MPI website:  
<https://www.open-mpi.org/>

MPI CMake:  
<https://cliutils.gitlab.io/modern-cmake/chapters/packages/MPI.html>

hugin:  
<https://www.hugin.com.au/prime/twin.php>

## Contributors

Quentin MOREL:

- @Im-Rises
- <https://github.com/Im-Rises>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/cTwinPrimeNumberParallel)](https://github.com/Im-Rises/cTwinPrimeNumberParallel/graphs/contributors)
