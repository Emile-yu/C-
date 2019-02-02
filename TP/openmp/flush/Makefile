CC=g++
OMPFLAGS=-fopenmp

all:FLUSH

FLUSH:flush.cpp
	$(CC) $(OMPFLAGS) $^ -o $@
clean:
	rm -f FLUSH
	