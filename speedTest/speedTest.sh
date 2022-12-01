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
#nValues=()
#for (( i=0; i<$iteration; i++ )); do
#    nValues+=($nInitValue)
#    nInitValue=$(($nInitValue*$multiplier))
#done

# Generate threads number list
processesNumberList=(1 2 4 8 16 24 48 64)

# Run the executables
for arraySize in "${arraySizeList[@]}"; do
    for processNumber in "${processesNumberList[@]}"; do
        echo "Running twin primes finder with $processNumber processes with a value n = $arraySize"
        for mergeSortExeName in "${twinPrimeFinderExeNames[@]}"; do
#            echo "Running $mergeSortExeName with $processNumber processes on array of size $arraySize"
#            eval "./${buildPath}${mergeSortExeName} < ${speedTestArraysPath}array_${arraySize}.txt > ./${outputsPath}${mergeSortExeName}_${arraySize}_${processNumber}.txt $processNumber"
        done
    done
done

echo "Done: outputs written in $outputsPath"
