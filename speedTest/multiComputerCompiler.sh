#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <source file>"
    exit 1
fi

mpicc $1 -lm

scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI1:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI2:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI3:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI4:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI5:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI6:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI7:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI8:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI9:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI10:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI11:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI12:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI13:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI14:~/a.out
scp mpiuser21@dim-openMPI0:~/a.out mpiuser21@dim-openMPI15:~/a.out
