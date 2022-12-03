#!/bin/bash

if [ $# -ne 4 ]; then
    echo "Usage: $0 <executable> <n init value> <multiplier> <iteration number>"
    exit 1
fi

exeFileName=$1
nInitValue=$2
nMultiplier=$3
nIteration=$4

nValues=()
for (( i=0; i<$iteration; i++ )); do
    nValues+=($nInitValue)
    nInitValue=$(($nInitValue*$nMultiplier))
done

machineNumberList=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16)

for nValue in "${nValues[@]}"; do
    for machineNumber in "${machineNumberList[@]}"; do
        mpirun -np "$machineNumber" -host dim-openMPI0,dim-openMPI1,dim-openMPI2,dim-openMPI3,dim-openMPI4,dim-openMPI5,dim-openMPI6,dim-openMPI7,dim-openMPI8,dim-openMPI9,dim-openMPI10,dim-openMPI11,dim-openMPI12,dim-openMPI13,dim-openMPI14,dim-openMPI15 "$exeFileName" "$nValue"
    done
done
