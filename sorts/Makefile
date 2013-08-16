OBJS = *.o

makeandclean: sort
	-rm ${OBJS}

sort: main.cpp quicksort.cpp mergesort.cpp selectionsort.cpp
	g++ -o $@ main.cpp

cleanall:
	-rm ${OBJS} sort
