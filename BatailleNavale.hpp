#include "Grille.hpp"
#include "Bateau.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

class BatailleNavale{
    private:
        GrilleDepart player1_self, player2_self;
        GrilleJeu player1_rival, player2_rival;

        void turn_1(int x, int y);

        void turn_2(int x, int y);

        void prepare_game();
    public:
        BatailleNavale();

        Grille jouer();
		
};
