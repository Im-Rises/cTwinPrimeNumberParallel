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
    - [Twin Prime Number Algorithm using computer threads](#Twin-Prime-Number-Algorithm-using-computer-threads)
    - [Twin Prime Number Algorithm using multiple computers](#Twin-Prime-Number-Algorithm-using-multiple-computers)
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

### Twin Prime Number Algorithm using computer threads

| Number of processes | Sieve of Eratosthenes V1  | Sieve of Eratosthenes V2 | Time (s) |
|---------------------|---------------------------|--------------------------|----------|
| 1                   |                           |                          | 0.000    |
| 2                   |                           |                          | 0.000    |
| 3                   |                           |                          | 0.000    |
| 4                   |                           |                          | 0.000    |
| 5                   |                           |                          | 0.000    |
| 6                   |                           |                          | 0.000    |

<details>
<summary>Click to see the detailed results</summary>

| Number of processes | Sieve of Eratosthenes V1  | Sieve of Eratosthenes V2 | Time (s) |
|---------------------|---------------------------|--------------------------|----------|
| 1                   |                           |                          | 0.000    |
| 2                   |                           |                          | 0.000    |
| 3                   |                           |                          | 0.000    |
| 4                   |                           |                          | 0.000    |
| 5                   |                           |                          | 0.000    |
| 6                   |                           |                          | 0.000    |

</details>

### Twin Prime Number Algorithm using multiple computers

| Number of computers | Sieve of Eratosthenes V1  | Sieve of Eratosthenes V2 | Time (s) |
|---------------------|---------------------------|--------------------------|----------|
| 1                   |                           |                          | 0.000    |
| 2                   |                           |                          | 0.000    |
| 3                   |                           |                          | 0.000    |
| 4                   |                           |                          | 0.000    |
| 5                   |                           |                          | 0.000    |
| 6                   |                           |                          | 0.000    |
| 7                   |                           |                          | 0.000    |
| 9                   |                           |                          | 0.000    |
| 10                  |                           |                          | 0.000    |
| 11                  |                           |                          | 0.000    |
| 12                  |                           |                          | 0.000    |
| 13                  |                           |                          | 0.000    |
| 14                  |                           |                          | 0.000    |
| 15                  |                           |                          | 0.000    |
| 16                  |                           |                          | 0.000    |

<details>
<summary>Click to see the detailed results</summary>

| Number of computers | Sieve of Eratosthenes V1  | Sieve of Eratosthenes V2 | Time (s) |
|---------------------|---------------------------|--------------------------|----------|
| 1                   |                           |                          | 0.000    |
| 2                   |                           |                          | 0.000    |
| 3                   |                           |                          | 0.000    |
| 4                   |                           |                          | 0.000    |
| 5                   |                           |                          | 0.000    |
| 6                   |                           |                          | 0.000    |
| 7                   |                           |                          | 0.000    |
| 9                   |                           |                          | 0.000    |
| 10                  |                           |                          | 0.000    |
| 11                  |                           |                          | 0.000    |
| 12                  |                           |                          | 0.000    |
| 13                  |                           |                          | 0.000    |
| 14                  |                           |                          | 0.000    |
| 15                  |                           |                          | 0.000    |
| 16                  |                           |                          | 0.000    |

</details>

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

C/C++ CI : This workflow will build the program using the makefile.  
CMake : This workflow will build the program using the CMake build system.  
CodeQL : This workflow will analyze the code to find security vulnerabilities.  
cpp-linter : This workflow will analyze the code to find bugs and potential vulnerabilities.  
flawfinder : This workflow will analyze the code to find bugs and potential vulnerabilities.

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
