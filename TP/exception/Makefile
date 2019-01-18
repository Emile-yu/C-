OBJECTS = Exception.o IndexException.o main.o
CC = g++
CFLAGS = -Wall -g

default:program

%.o:%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

program:$(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(OBJECTS)
	rm -f program
