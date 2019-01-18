OBJECTS = Node.o List.o main.o Person.o
CC = g++
CFLAGS = -Wall -g

default:program

$o:$cpp
	$(CC) -c $(CFLAGS) $< -o $@
program:$(OBJECTS)
	$(CC) $(OBJECTS) -o $@
clean:
	rm -f program
	rm -f $(OBJECTS)