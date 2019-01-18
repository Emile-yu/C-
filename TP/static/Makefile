OBJECTS = Tank.o main.o
CC = g++
CFLAGS = -Wall -g

default:program 

%o:%cpp
	$(CC) -c $(CFLAGS) $< $@
program:$(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(OBJECTS)
	rm -f program