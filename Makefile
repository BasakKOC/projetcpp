PROGS: tests Jeu

all: $(PROGS)

tests: tests.o Bateau.o Grille.o BatailleNavale.o IA.o
	g++ -o $@ $^ 

Jeu: Jeu.o BatailleNavale.o Bateau.o Grille.o IA.o
	g++ -o $@ $^

tests.o: tests.cpp Bateau.hpp Grille.hpp BatailleNavale.hpp IA.hpp
	g++ -c $<

IA.o: IA.cpp Bateau.hpp Grille.hpp IA.hpp
	g++ -c 	IA.cpp

BatailleNavale.o: BatailleNavale.cpp Bateau.hpp Grille.hpp BatailleNavale.hpp IA.hpp
	g++ -c BatailleNavale.cpp

Bateau.o: Bateau.cpp Bateau.hpp
	g++ -c Bateau.cpp

Grille.o: Grille.cpp  Bateau.hpp Grille.hpp
	g++ -c Grille.cpp

Jeu.o: Jeu.cpp BatailleNavale.cpp Bateau.hpp Grille.hpp IA.hpp
	g++ -c $< 

clean:
	-rm -f *.o *~ $ (PROGS)