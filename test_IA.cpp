#include "IA.hpp"
#include "Grille.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    IA ia;
    //Bateau b(ia.coord_bateau(3));
    GrilleDepart g(ia.preparer_IA());
    cout<<g<<endl;
//    cout<<"bateau de g = "<<endl;
//    for(Bateau boat: g.get_bat()){
//        cout<<boat<<endl;
//    }
}