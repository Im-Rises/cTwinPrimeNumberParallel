all:
	$(MAKE) MrProper
	#$(MAKE) PrimeNumberFinderSequential
	#$(MAKE) PrimeNumberFinderParallel
	$(MAKE) TwinPrimeNumberFinderSequential
	$(MAKE) TwinPrimeNumberFinderParallel
	$(MAKE) clean

#PrimeNumberFinderSequential:
#	gcc primeNumberFinderSeq/main.c -o buildMakeFile/primeNumberFinderSequential -std=c90 -Wall -O2

#PrimeNumberFinderParallel:
#	mpicc primeNumberFinderMPI/main.c -o buildMakeFile/primeNumberFinderMPI -std=c90 -Wall -O2 -lm

TwinPrimeNumberFinderSequential:
	gcc twinPrimeNumberFinderSeq/main.c -o buildMakeFile/twinPrimeNumberFinderSequential -std=c90 -Wall -O2

TwinPrimeNumberFinderParallel:
	mpicc twinPrimeNumberFinderMPI/main.c -o buildMakeFile/twinPrimeNumberFinderMPI -std=c90 -Wall -O2 -lm

MrProper : clean
	rm -f buildMakeFile/primeNumberFinderSequential
	rm -f buildMakeFile/primeNumberFinderMPI
	rm -f buildMakeFile/twinPrimeNumberFinderMPI
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
