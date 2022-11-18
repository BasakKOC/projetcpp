#include <iostream>
#include "Bateau.hpp"
#include <cassert>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

#ifndef GRILLEHEADERDEF
#define GRILLEHEADERDEF

class Grille{
protected:
    vector<vector<int>> grid;

public:
    //constructeurs
    Grille(int);
    Grille(const Grille &g); //par copie

    //getter
    int elem(int i, int j) const {assert(i>=0 && i<10 && j>=0 && j<10); return grid[i][j];}

    //operateurs
    int operator() (int i,int j) const { //getter
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];}

    int& operator()(int i, int j) { //setter
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];}

    friend std::ostream& operator<<(std::ostream& out, const Grille &g); //affichage

    /* int& operator()(char colonne, int ligne) { //version (lettre, int entre 1 et 10)
        int i=int(colonne)%65; //on convertit la lettre en coord entre 0 et 10
        int j=ligne-1;
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];} */

    pair<char, int> gametocoord(char col, int ligne); //transforme une coordonnee lettre en int compris entre 0 et 10
    
    // 0 : case eau, 1: case bateau intact, 2: case bateau touché
    // 3: coulé, 4 : inconnu (pour le joueur)
};

class GrilleDepart : public Grille{
    public :
    GrilleDepart(): Grille(0){};
    void placer(Bateau bateau); //prend un bateau, coord case debut, coord case fin bateau et le place sur la grille
};

class GrilleJeu : public Grille{
    public:
    GrilleJeu(): Grille(4){};
    void actualiser(); //actualise une grille
};  

#endif
