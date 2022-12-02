PROGS: test_bateau testgrille test_bataille test_IA

all: $(PROGS)

test_bateau: test_bateau.o Bateau.o
	g++ -o $@ $^ 

testgrille: testgrille.o Bateau.o Grille.o
	g++ -o $@ $^ 

test_bataille: test_bataille.o Bateau.o Grille.o BatailleNavale.o IA.o
	g++ -o $@ $^ 

test_IA: test_IA.o Bateau.o Grille.o IA.o
	g++ -o $@ $^ 

test_bataille.o: test_bataille.cpp Bateau.hpp Grille.hpp BatailleNavale.hpp IA.hpp
	g++ -c $<

IA.o: IA.cpp Bateau.hpp Grille.hpp IA.hpp
	g++ -c 	IA.cpp

BatailleNavale.o: BatailleNavale.cpp Bateau.hpp Grille.hpp BatailleNavale.hpp IA.hpp
	g++ -c BatailleNavale.cpp

test_bateau.o: test_bateau.cpp  Bateau.hpp
	g++ -c $< 

test_IA.o: test_IA.cpp  Bateau.hpp Grille.hpp
	g++ -c $<

Bateau.o: Bateau.cpp Bateau.hpp
	g++ -c Bateau.cpp

testgrille.o: testgrille.cpp Bateau.hpp Grille.hpp
	g++ -c $< 

Grille.o: Grille.cpp  Bateau.hpp Grille.hpp
	g++ -c Grille.cpp

clean:
	-rm -f *.o *~ $ (PROGS)
