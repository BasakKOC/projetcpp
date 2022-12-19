#include "Grille.hpp"
#include "Bateau.hpp"
#include <vector>

using namespace std;

#ifndef BATAILLENAVALE_CPP_IA_HPP
#define BATAILLENAVALE_CPP_IA_HPP

class IA{

private:
    Bateau coord_bateau(int) const;  //trouve un bateau placer
    vector<pair<int,int>> ou_sont_les_uns(const GrilleJeu&)const ; //vecteur qui indique a level_normal ou sont les cases toucher
    pair<int,int> level_random(const GrilleJeu&)const; //ia qui ne reflechie pas

public:
    //preparer la grilleDepart
    GrilleDepart preparer_IA()const; //renvoie une grille depart avec tous les bateau placer

    //renvoie les coord jouer par IA
    pair<int,int> level_normal(const GrilleJeu&)const;

    //methode test
    void test_coord_bateau() const;
    void test_ou_sont_les_uns()const;
    void test_level_random(GrilleJeu&,const GrilleDepart&)const;
};

#endif //BATAILLENAVALE_CPP_IA_HPP
