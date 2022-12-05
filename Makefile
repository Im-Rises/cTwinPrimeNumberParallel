all:
	$(MAKE) MrProper
	$(MAKE) FinderSequential
	$(MAKE) PrimeNumberFinderParallel
	$(MAKE) TwinPrimeNumberFinderParallelV1
	$(MAKE) TwinPrimeNumberFinderParallelV2
	$(MAKE) clean

FinderSequential:
	gcc ./finderSeq/main.c -o buildMakeFile/main.o -c -lm -std=c90 -Wall -O2
	gcc ./finderSeq/commonFunctions.c -o buildMakeFile/commonFunctions.o -c -lm -std=c90 -Wall -O2
	gcc -o buildMakeFile/finderSequential buildMakeFile/main.o buildMakeFile/commonFunctions.o -lm -std=c90 -Wall -O2

PrimeNumberFinderParallel:
	mpicc primeNumberFinderMpi/main.c -o buildMakeFile/primeNumberFinderMpi -std=c90 -Wall -O2 -lm

TwinPrimeNumberFinderParallelV1:
	mpicc twinPrimeNumberFinderMpiV1/main.c -o buildMakeFile/twinPrimeNumberFinderMpiV1 -std=c90 -Wall -O2 -lm

TwinPrimeNumberFinderParallelV2:
	mpicc twinPrimeNumberFinderMpiV2/main.c -o buildMakeFile/twinPrimeNumberFinderMpiV2 -std=c90 -Wall -O2 -lm

MrProper : clean
	rm -f buildMakeFile/finderSequential
	rm -f buildMakeFile/primeNumberFinderMpi
	rm -f buildMakeFile/twinPrimeNumberFinderMpiV1
	rm -f buildMakeFile/twinPrimeNumberFinderMpiV2
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
