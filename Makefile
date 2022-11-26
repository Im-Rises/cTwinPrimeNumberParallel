all:
	$(MAKE) MrProper
	$(MAKE) PrimeNumberFinderAll
	$(MAKE) clean

PrimeNumberFinderAll:
	gcc -fopenmp primeNumberFinder/main.c -o buildMakeFile/primeNumberFinder
#	gcc ./mergeSortOpenMp/main.c -o buildMakeFile/main.o -c -std=c90 -Wall -O2
#	gcc ./mergeSortOpenMp/mergeSortParallelOpenMp.c -o buildMakeFile/mergeSortParallelOpenMp.o -fopenmp -c -std=c90 -Wall -O2
#	gcc ./mergeSortSequential/mergeSortSequential.c -o buildMakeFile/mergeSortSequential.o -c -std=c90 -Wall -O2
#	gcc ./commonFunctions/commonFunctions.c -o buildMakeFile/commonFunctions.o -c -std=c90 -Wall -O2
#	gcc -o ./buildMakeFile/mergeSortOpenMp buildMakeFile/main.o buildMakeFile/mergeSortParallelOpenMp.o buildMakeFile/commonFunctions.o buildMakeFile/mergeSortSequential.o -fopenmp -std=c90 -Wall -O2

MrProper : clean
	rm -f buildMakeFile/primeNumberFinder
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
