CC=g++
CFLAGS=-Wall -g
default: program

Points2D.o:Points2D.cpp
	$(CC) -c $(CFLAGS) $< -o $@
	
program:Points2D.o main.o
	$(CC) -o $@ main.o Points2D.o 
	
clean:
	rm -rf Points2D.o
	rm -rf program
