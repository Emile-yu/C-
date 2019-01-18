OBJECTS = Time.o Match.o main.o Match1.o
CC = g++
CFLAGS = -Wall -g

default:program

%o:%cpp
	$(CC) -c $(CFLAGS) $< -o $@

program:$(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(OBJECTS)
	rm -f program