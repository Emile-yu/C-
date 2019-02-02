CC=mpicxx
CFLAGS=-Wall -g
OMPFLAGS=-fopenmp
RUN=mpirun

all:PI PI_HYBRID

PI:pi.cpp
	$(CC) $(CFLAGS) $^ -o $@

PI_HYBRID:pi_hybrid.cpp
	$(CC) $(OMPFLAGS) $(CFLAGS) $^ -o $@
clean:
	rm -f PI PI_HYBRID

bench:
	@echo "## PI ##"
	${RUN} -np 4 ./PI

	@echo "## PI_HYBRID ##"
	${RUN} -np 4 ./PI_HYBRID