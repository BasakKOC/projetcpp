#include "IA.hpp"
#include "Grille.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    IA ia;
    //Bateau b(ia.coord_bateau(3)); a ete tester , fonction privee
    GrilleDepart g(ia.preparer_IA());
    cout<<g<<endl;
    cout<<"bateau de g = "<<endl;
    for(const Bateau& boat: g.get_bat()){
        cout<<boat;
    }



    GrilleJeu gj;
    gj.recupere_bat(g);
    cout<<gj<<endl;
    cout<<"bateau de gj = "<<endl;
    for(const Bateau& boat: gj.get_bat()){
        cout<<boat;
    }
    for (int i=0; i<50 ;i++) {
        cout<<"tour "<<i<<endl;
        cout<<"les coord choisies sont :"<<endl;
        pair<int, int> p(ia.level_random(gj));

        gj.actualiser(p.first, p.second, g);
        cout << "gj apres actualisation = " << endl;
        gj.affiche();
        cout << "bateau de gj = " << endl;
        for (const Bateau &boat: gj.get_bat()) {
            cout << boat;
        }
    }
}


