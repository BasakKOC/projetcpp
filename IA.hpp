#include "Grille.hpp"
#include "Bateau.hpp"
#include <vector>

using namespace std;
#ifndef BATAILLENAVALE_CPP_IA_HPP
#define BATAILLENAVALE_CPP_IA_HPP

class IA{

private:
    Bateau coord_bateau(int);  // trouve un bateau placer
public:
    //fonction utile pour la suite
    vector<pair<int,int>> ou_sont_les_uns(const GrilleJeu&) ;

    //preparer la grilleDepart
    GrilleDepart preparer_IA(); //renvoie une grille depart avec tous les bateau placer

    //renvoie les coord jouer par IA
    pair<int,int> level_random(const GrilleJeu&);
    pair<int,int> level_normal(const GrilleJeu&);
};

#endif //BATAILLENAVALE_CPP_IA_HPP
