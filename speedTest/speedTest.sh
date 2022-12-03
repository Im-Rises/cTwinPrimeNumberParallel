#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Usage: $0 <base n value> <multiplier> <iteration number>"
    exit 1
fi

# Input parameters
nInitValue=$1
multiplier=$2
iteration=$3

# Twin Prime Number executables
buildPath="../buildMakeFile/"
twinPrimeFinderExeNames=("twinPrimeNumberFinderMpiV1" "twinPrimeNumberFinderMpiV2")

# Generate the list of n values
nValues=()
for (( i=0; i<$iteration; i++ )); do
    nValues+=($nInitValue)
    nInitValue=$(($nInitValue*$multiplier))
done

# Generate threads number list
#processesNumberList=(1 2 4 8 16 24 48 64)
processesNumberList=(1 2 4 6)

# Run the executables
for nValue in "${nValues[@]}"; do
    for processNumber in "${processesNumberList[@]}"; do
        for twinPrimeExeName in "${twinPrimeFinderExeNames[@]}"; do
            echo "Running $twinPrimeExeName with $processNumber processes with a value n = $nValue"
            eval "mpirun -c $processNumber ./${buildPath}${twinPrimeExeName} $nValue"
        done
    done
done

echo "Done"
