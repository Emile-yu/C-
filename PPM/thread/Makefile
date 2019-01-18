OBJECTS = ex1.o
CC = g++ 
CFLAGS =  -Wall -g

default:program

%o:%cpp
	$(CC) -std=c++11 $(CFLAGS) -c $< -o $@
program:$(OBJECTS)
	$(CC) -std=c++11 $(CFLAGS) $< -o $@ -lpthread
	
clean:
	rm -f $(OBJECTS)
	rm -f program
