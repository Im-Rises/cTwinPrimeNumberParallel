CC=gcc
MPI_CC=mpicc
CFLAGS=-std=c90 -W -Wall -ansi -pedantic -O2
LDFLAGS=-lm
OUTPUT_DIR=./buildMakeFile

all:
	$(MAKE) mrproper
	$(MAKE) FinderSequential
	$(MAKE) PrimeNumberFinderParallel
	$(MAKE) TwinPrimeNumberFinderParallelV1
	$(MAKE) TwinPrimeNumberFinderParallelV2
	$(MAKE) clean

FinderSequential:
	$(CC) ./finderSeq/main.c -o $(OUTPUT_DIR)/main.o -c $(CFLAGS) $(LDFLAGS)
	$(CC) ./finderSeq/commonFunctions.c -o $(OUTPUT_DIR)/commonFunctions.o -c  $(CFLAGS) $(LDFLAGS)
	$(CC) -o $(OUTPUT_DIR)/finderSequential $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/commonFunctions.o $(CFLAGS) $(LDFLAGS)

PrimeNumberFinderParallel:
	$(MPI_CC) primeNumberFinderMpi/main.c -o $(OUTPUT_DIR)/primeNumberFinderMpi $(CFLAGS) $(LDFLAGS)

TwinPrimeNumberFinderParallelV1:
	$(MPI_CC) twinPrimeNumberFinderMpiV1/main.c -o $(OUTPUT_DIR)/twinPrimeNumberFinderMpiV1 $(CFLAGS) $(LDFLAGS)

TwinPrimeNumberFinderParallelV2:
	$(MPI_CC) twinPrimeNumberFinderMpiV2/main.c -o $(OUTPUT_DIR)/twinPrimeNumberFinderMpiV2 $(CFLAGS) $(LDFLAGS)

.PHONY: clean mrproper all

mrproper : clean
	rm -f $(OUTPUT_DIR)/finderSequential
	rm -f $(OUTPUT_DIR)/primeNumberFinderMpi
	rm -f $(OUTPUT_DIR)/twinPrimeNumberFinderMpiV1
	rm -f $(OUTPUT_DIR)/twinPrimeNumberFinderMpiV2
	$(MAKE) clean

clean :
	rm -rf $(OUTPUT_DIR)/*.o
