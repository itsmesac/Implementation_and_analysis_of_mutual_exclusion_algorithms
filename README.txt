********************************************************************************************************
Filter Algorithm

- Lock_Filter is provided as a class with a header file named filter.h
- testFilter.cpp is used to test the validity of Lock_Filter and for performance analysis.
- Compile the source files using the following command :
	-> g++470 -std=c++11 -c filter.o filter.cpp
	-> g++470 -std=c++11 -c testFilter.o testFilter.cpp
- Link the object files with the required libraries to generate the executable.
	->g++470 -std=c++11 -o testFilter testFilter.o filter.o -lpthread
- Run the executable

Explanation of Output:
- The test program prints all the numbers upto a specified number in sequential order.
- The output is redirected to out.txt.
- The lock algorithm can be verified by the sequential printing of the numbers in the output file


********************************************************************************************************
Compare and Swap

- Compile the source files using the following command :
	-> g++470 -std=c++11 -c compare_and_swap.o compare_and_swap.cpp
- Link the object files with the required libraries to generate the executable.
	->g++470 -std=c++11 -o compare_and_swap compare_and_swap.o -lpthread	
- Run the executable	

Explanation of Output:
- The test program prints all the numbers upto a specified number in sequential order.
- The output is redirected to out.txt.
- The lock algorithm can be verified by the sequential printing of the numbers in the output file


********************************************************************************************************
Test and Set

- Compile the source files using the following command :
	-> g++470 -std=c++11 -c test_and_set.o test_and_set.cpp
- Link the object files with the required libraries to generate the executable.
	->g++470 -std=c++11 -o test_and_set test_and_set.o -lpthread	
- Run the executable	

Explanation of Output:
- The test program prints all the numbers upto a specified number in sequential order.
- The output is redirected to out.txt.
- The lock algorithm can be verified by the sequential printing of the numbers in the output file


********************************************************************************************************
Performance Analysis

- The time required with varying number of lock acquires/releases with a constant number of threads(=25) has been plotted
  in 'PerformanceAnalysis.xlsx' for FilterLock and TestAndSet.
  
  
********************************************************************************************************
List of Atomic Instructions

- List of Atomic Instructions available on cs1/cs2 machines can be found in 'ListOfAtomicInstructions.txt'


********************************************************************************************************
SOURCES

- Intel® 64 and IA-32 Architectures
	Software Developer’s Manual
	Combined Volumes:
	1, 2A, 2B, 2C, 3A, 3B and 3C : List of atomic instructions supported for Intel Xeon architecture
	
- The Art of Multiprocessor Programming for Filter algorithm.

- www.cplusplus.com for instructions on how to use thread, atomic libraries.

- Lecture slides of Dr.Neeraj Mittal for general references.


********************************************************************************************************