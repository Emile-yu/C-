OBJECTS = main.o
CC = g++
CFLAGS = -Wall -g

default:program

%o:%cpp
	$(CC) -c $(CFLAGS) $< -O $@
program:$(OBJECTS)
	$(CC) MyQueue.h $(OBJECTS) -o $@
clean:
	rm -f program
	rm -f $(OBJECTS)