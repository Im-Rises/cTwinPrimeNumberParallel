all:
	$(MAKE) MrProper
	$(MAKE) PrimeNumberFinderSequential
	$(MAKE) PrimeNumberFinderParallel
	$(MAKE) clean

PrimeNumberFinderSequential:
	gcc PrimeNumberFinderSeq/main.c -o buildMakeFile/PrimeNumberFinderSequential

PrimeNumberFinderParallel:
	mpicc primeNumberFinderMPI/main.c -o buildMakeFile/primeNumberFinderMPI

MrProper : clean
	rm -f buildMakeFile/primeNumberFinder
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
