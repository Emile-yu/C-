OBJECTS =  Coordinate.o main.o
CC = g++
CFLAGS = -Wall -g

default:program

%o:%cpp
	$(CC) $(CFLAGS) -c $< -o $@
program:$(OBJECTS)
	$(CC) MyStack.h $(OBJECTS) -o $@
clean:
	rm -f program
	rm -f $(OBJECTS) 