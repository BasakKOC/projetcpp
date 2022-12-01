#include "Grille.hpp"
#include "Bateau.hpp"


#ifndef BATAILLENAVALE_CPP_IA_HPP
#define BATAILLENAVALE_CPP_IA_HPP

class IA{
public:
    //ajouter constructeur

    Bateau coord_bateau(int); // il reste a faire la fonction placer avec ce bateau
    GrilleDepart preparer_IA(); // ok mais pas tres smart

//    pair<int,int> level_random();
//    pair<int,int> level_normal();
//    pair<int,int> level_God();
};

#endif //BATAILLENAVALE_CPP_IA_HPP
