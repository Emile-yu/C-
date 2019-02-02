CC=g++
OMPFLAGS=-fopenmp
FLAGS=-Wall -g

all:PI

PI:pi.cpp
	$(CC) $(FLAGS) $(OMPFLAGS) $^ -o $@
clean:
	rm -f PI
