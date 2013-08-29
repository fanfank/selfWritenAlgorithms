OBJS = *.o

makeandclean: sort

sort: main.h main.cpp quicksort.cpp mergesort.cpp selectionsort.cpp heapsort.cpp insertionsort.cpp bubblesort.cpp
	g++ -o $@ main.cpp

cleanall:
	-rm sort
