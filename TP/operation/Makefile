OBJECTS = Contacts.o Telephones.o main.o
CC = g++
CFLAGS = -Wall -g

default:program
%o:%cpp
	$(CC) -c $(CFLAGS) $< -o $@

program:$(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -f program
	rm -f $(OBJECTS)