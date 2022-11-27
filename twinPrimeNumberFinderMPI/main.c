#include <math.h>
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
    int high_value = 2 + BLOCK_HIGH(id, p, n - 1);
    int size = BLOCK_SIZE(id, p, n - 1);
    int proc0_size = (n - 1) / p;
    if ((2 + proc0_size) < (int)sqrt((double)n))
    {
        if (!id)
            printf("Too many processes\n");
        MPI_Finalize();
        exit(1);
    }

    /* Allocate memory for sieve */
    char* marked = (char*)malloc(size);
    if (marked == NULL)
    {
        printf("Cannot allocate enough memory\n");
        MPI_Finalize();
        exit(1);
    }

    /* Sieve of Eratosthenes Algorithm */
    int index = 0;
    int prime = 0;
    int first = 0;
    int count = 0;
    int i;
    for (i = 0; i < size; i++)
        marked[i] = 0;
    if (!id)
        index = 0;
    prime = 2;
    do
    {
        if (prime * prime > low_value)
            first = prime * prime - low_value;
        else
        {
            if (!(low_value % prime))
                first = 0;
            else
                first = prime - (low_value % prime);
        }
        for (i = first; i < size; i += prime)
            marked[i] = 1;
        if (!id)
        {
            while (marked[++index])
                ;
            prime = index + 2;
        }
        MPI_Bcast(&prime, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } while (prime * prime <= n);

    /* Count twin primes */
    for (i = 0; i < size; i++)
    {
        if (marked[i] == 0)
        {
            if (i + 2 < size && marked[i + 2] == 0)
                local_count++;
        }
    }

    /* Sum local counts */
    MPI_Reduce(&local_count, &global_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    /* Stop timer */
    elapsed_time += MPI_Wtime();

    /* Print results */
    if (!id)
    {
        printf("There are %d twin primes less than or equal to %d\n", global_count, n);
        printf("Total elapsed time: %10.6f\n", elapsed_time);
    }

    /* Finalize MPI */
    MPI_Finalize();

    return 0;
}
