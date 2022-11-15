PROGS: test_bateau testgrille

all: $(PROGS)

test_bateau: test_bateau.o Bateau.o
	g++ -o $@ $^ 

testgrille: test_bateau.o Bateau.o Grille.o
	g++ -o $@ $^ 

test_bateau.o: test_bateau.cpp  Bateau.hpp
	g++ -c $< 

Bateau.o: Bateau.cpp Bateau.hpp
	g++ -c Bateau.cpp

testgrille.o: test_bateau.cpp Bateau.hpp Grille.hpp
	g++ -c $< 

Grille.o: Grille.cpp  Bateau.hpp Grille.hpp
	g++ -c Grille.cpp

clean:
	-rm -f *.o *~ $ (PROGS )
