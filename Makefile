all:
	$(MAKE) MrProper
	$(MAKE) PrimeNumberFinderSequential
	$(MAKE) PrimeNumberFinderParallel
	$(MAKE) clean

PrimeNumberFinderSequential:
	gcc rimeNumberFinderSeq/main.c -o buildMakeFile/primeNumberFinderSequential -std=c90 -Wall -O2

PrimeNumberFinderParallel:
	mpicc primeNumberFinderMPI/main.c -o buildMakeFile/primeNumberFinderMPI -std=c90 -Wall -O2 -lm

MrProper : clean
	rm -f buildMakeFile/primeNumberFinder
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
