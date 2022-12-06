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
        
    public:
        GrilleDepart player1_self, player2_self;
        GrilleJeu player1_rival, player2_rival;
        /* void turn_1(int x, int y);

        void turn_2(int x, int y); */

        bool turn(int x, int y, const GrilleDepart&, GrilleJeu&);

        void prepare_game_auto(GrilleDepart& gd,GrilleJeu& gj);

        void prepare_game();

        BatailleNavale();

        void jouer();

        bool test_coord_prepare (const GrilleDepart &player_self, int startx, int starty, int endx, int endy, int size_boat) const; //a utiliser dans prepare

        bool test_coord_tir (const GrilleJeu& player_rival, int x, int y) const; //a utiliser avant actualiser

};
