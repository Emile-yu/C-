OBJECTS = a.o b.o c.o
CC=gcc
CFLAGS=-Wall -g
default: program

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
program: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean:
	rm -f $(OBJECTS)
	rm -f program

