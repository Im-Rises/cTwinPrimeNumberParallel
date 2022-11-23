all:
	$(MAKE) LinuxVer

LinuxVer:
	$(MAKE) MrProper
	$(MAKE) OpenMpVerLinux
	$(MAKE) clean

OpenMpVerLinux:
	gcc ./mergeSortOpenMp/main.c -o buildMakeFile/main.o -c -std=c90 -Wall -O2
	gcc ./mergeSortOpenMp/mergeSortParallelOpenMp.c -o buildMakeFile/mergeSortParallelOpenMp.o -fopenmp -c -std=c90 -Wall -O2
	gcc ./mergeSortSequential/mergeSortSequential.c -o buildMakeFile/mergeSortSequential.o -c -std=c90 -Wall -O2
	gcc ./commonFunctions/commonFunctions.c -o buildMakeFile/commonFunctions.o -c -std=c90 -Wall -O2
	gcc -o ./buildMakeFile/mergeSortOpenMp buildMakeFile/main.o buildMakeFile/mergeSortParallelOpenMp.o buildMakeFile/commonFunctions.o buildMakeFile/mergeSortSequential.o -fopenmp -std=c90 -Wall -O2

MrProper : clean
	rm -f buildMakeFile/fileGenerator
	rm -f buildMakeFile/mergeSortOpenMp
	rm -f buildMakeFile/mergeSortPThread
	rm -f buildMakeFile/mergeSortSequential
	$(MAKE) clean

clean :
	rm -rf buildMakeFile/*.o
