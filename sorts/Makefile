CC = g++
CPPS = $(wildcard *.cpp)
OBJS = main.o quicksort.o mergesort.o selectionsort.o heapsort.o insertionsort.o bubblesort.o selectionsortV2.o mergesortV2.o quicksortV2.o
CFLAGS = -g

sort: $(CPPS)
	$(CC) -o $@ main.cpp

main.cpp: main.h


debug: $(OBJS) main.h
	$(CC) $(CFLAGS) -o sort_debug $^

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm $(OBJS)

cleanall:
	-rm sort* $(OBJS)

