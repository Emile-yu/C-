CC=g++
OMPFLAGS=-fopenmp

all:SCHEDULE

SCHEDULE:schedule.cpp
	$(CC) $(OMPFLAGS) $^ -o $@
clean:
	rm -f SCHEDULE
	