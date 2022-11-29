#include "IA.hpp"
#include "Grille.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    IA ia;
    GrilleDepart g(ia.preparer_IA());
    cout<<g<<endl;

}