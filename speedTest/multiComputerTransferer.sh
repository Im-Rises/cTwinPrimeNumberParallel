#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <executable>"
    exit 1
fi

#mpicc $1 -lm

scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI1:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI2:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI3:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI4:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI5:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI6:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI7:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI8:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI9:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI10:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI11:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI12:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI13:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI14:~/$1
scp mpiuser21@dim-openMPI0:~/$1 mpiuser21@dim-openMPI15:~/$1
