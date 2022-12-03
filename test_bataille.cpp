#include "Grille.hpp"
#include "Bateau.hpp"
#include "BatailleNavale.hpp"
#include "IA.hpp"
#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){
    BatailleNavale bataille;
    int i,j;

    // Test prepare_game
    /* bataille.prepare_game(); */

    // Test turn_1
    /* for(int j=0; j<=100;j++){
        cout<<"ligne ?"<<endl;
        cin>>i;
        cout<<"colonne ?"<<endl;
        cin>>j;
        bataille.turn_1(i,j);
    } */

    // Test turn_2
    /* IA ia;
    
    GrilleDepart gd_ia = ia.preparer_IA();
    GrilleJeu gj_ia;
    gj_ia.recupere_bat(gd_ia);
    cout<<"gj_ia ="<<endl<<gj_ia<<endl;
    pair<int, int> p = ia.level_random(gj_ia);
    bataille.turn_2(p.first, p.second);
    gj_ia.actualiser(x, y, gj); */

    bataille.prepare_game();
    //bataille.jouer();



    return 0;
}