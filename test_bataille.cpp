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
    //bataille.prepare_game();

    // Test turn
    /* for(int j=0; j<=20;j++){
        cout<<"ligne ?"<<endl;
        cin>>i;
        cout<<"colonne ?"<<endl;
        cin>>j;
        bataille.turn(i, j, bataille.player2_self, bataille.player1_rival);
    } */
 
    // Test jouer
    bataille.jouer();
    return 0;
}