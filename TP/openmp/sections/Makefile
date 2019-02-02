CC=g++
OMPFLAGS=-fopenmp

all:SECTIONS
SECTIONS:sections.cpp
	$(CC) $(OMPFLAGS) $^ -o $@
clean:
	rm -f SECTIONS