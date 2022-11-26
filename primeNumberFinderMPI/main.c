#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_LOW(id, p, n) ((id) * (n) / (p))
#define BLOCK_HIGH(id, p, n) (BLOCK_LOW((id) + 1, p, n) - 1)
#define BLOCK_SIZE(id, p, n) (BLOCK_LOW((id) + 1, p, n) - BLOCK_LOW(id, p, n))
#define BLOCK_OWNER(index, p, n) (((p)*(index)+1)-1)/(n))

int main(int argc, char** argv) {
    /*Init MPI*/
    MPI_Init(&argc, &argv);
    MPI_Barrier(MPI_COMM_WORLD);

    /*Init timer*/
    double elapsed_time = -MPI_Wtime();

    /*Get rank and size*/
    int id, p;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    if (argc != 2)
    {
        if (!id)
            printf("Command line: %s <m>\n", argv[0]);
        MPI_Finalize();
        exit(1);
    }

    /* Init variables */
    int n = atoi(argv[1]);
    int global_count = 0;
    int local_count = 0;
    int low_value = 2 + BLOCK_LOW(id, p, n - 1);
    int high_value = 0 + BLOCK_HIGH(id, p, n - 1);
    int size = BLOCK_SIZE(id, p, n - 1);


    /* Finalize MPI */
    MPI_Finalize();
}
