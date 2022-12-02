#include "Grille.hpp"
#include "Bateau.hpp"


#ifndef BATAILLENAVALE_CPP_IA_HPP
#define BATAILLENAVALE_CPP_IA_HPP

class IA{
public:
    //ajouter constructeur

    Bateau coord_bateau(int);  // trouve un bateau placer
    GrilleDepart preparer_IA(); //renvoie une grille depart avec tous les bateau placer

    pair<int,int> level_random(const GrilleJeu&);
    //pair<int,int> level_normal(const GrilleJeu&);
//    pair<int,int> level_God();
};

#endif //BATAILLENAVALE_CPP_IA_HPP
