OBJECTS = main.o GElement.o InfoSommetCarte.o InfoAreteCarte.o OutilsCarteRecuitSimule.o Vecteur2D.o
CC = g++
CFLAGS = -Wall -g
DEFAULT : program

%o:%cpp
	$(CC) $(CFLAGS)-c $< -o $@
program:$(OBJECTS)
	$(CC) $(OBJECTS) PElement.h Sommet.h Arete.h Graphe.h AlgebreLineaire.h -o $@

clean:
	rm -f program
	rm -f $(OBJECTS)