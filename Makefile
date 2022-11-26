all:
	$(MAKE) MrProper
	$(MAKE) PrimeNumberFinderSequential
	$(MAKE) PrimeNumberFinderParallel
	$(MAKE) clean

PrimeNumberFinderSequential:
	gcc PrimeNumberFinderSeq/main.c -o buildMakeFile/PrimeNumberFinderSequential -std=c90 -Wall -O2

PrimeNumberFinderParallel:
	mpicc primeNumberFinderMPI/main.c -o buildMakeFile/primeNumberFinderMPI -std=c90 -Wall -O2

MrProper : clean
	rm -f buildMakeFile/primeNumberFinder
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
