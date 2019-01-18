OBJECTS = Artiste.o Chanson.o Langues.o Concert.o
CC=g++
CFLAGS=-Wall -g

default: program
%.o:%.cpp
	$(CC) -c $(CFLAGS) $< -o $@
	
program:$(OBJECTS) main.o
	$(CC) $(OBJECTS) main.o -o $@

clean:
	rm -f $(OBJECTS)
	rm -f program
