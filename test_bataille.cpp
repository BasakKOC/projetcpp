#include "Grille.hpp"
#include "Bateau.hpp"
#include "BatailleNavale.hpp"
#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){
    BatailleNavale bataille;
    int i,j;
    bataille.prepare_game();
    for(int j=0; j<=100;j++){
        cout<<"ligne ?"<<endl;
        cin>>i;
        cout<<"colonne ?"<<endl;
        cin>>j;
        bataille.turn_1(i,j);
    }
    
    //bataille.jouer();

    return 0;
}