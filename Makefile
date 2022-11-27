all:
	$(MAKE) MrProper
	$(MAKE) PrimeNumberFinderSequential
	$(MAKE) PrimeNumberFinderParallel
	$(MAKE) TwinPrimeNumberFinderParallel
	$(MAKE) clean

PrimeNumberFinderSequential:
	gcc primeNumberFinderSeq/main.c -o buildMakeFile/primeNumberFinderSequential -std=c90 -Wall -O2

PrimeNumberFinderParallel:
	mpicc primeNumberFinderMPI/main.c -o buildMakeFile/primeNumberFinderMPI -std=c90 -Wall -O2 -lm

TwinPrimeNumberFinderParallel:
	mpicc twinPrimeNumberFinderMPI/main.c -o buildMakeFile/twinPrimeNumberFinderMPI -std=c90 -Wall -O2 -lm

MrProper : clean
	rm -f buildMakeFile/primeNumberFinderSequential
	rm -f buildMakeFile/primeNumberFinderMPI
	rm -f buildMakeFile/twinPrimeNumberFinderMPI
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
