#include <iostream>
#include "class.hpp"
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
private:
    vector<vector<int>> grid;

public:
    //constructeurs
    Grille(const Grille &g); //par copie

    //getter
    int elem(int i, int j) const {assert(i>=0 && i<10 && j>=0 && j<10); return grid[i][j];}

    //operateurs
    int operator() (int i,int j) const { //retourne grid[i][j]
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];}

    friend std::ostream& operator<<(std::ostream& out, const Grille &g);

    /* int& operator()(char colonne, int ligne) { //version (lettre, int entre 1 et 10)
        int i=int(colonne)%65; //on convertit la lettre en coord entre 0 et 10
        int j=ligne-1;
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];} */

    int& operator()(int i, int j) { //version (int entre 0 et 9, int entre 0 et 9)
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];}

    pair<char, int> gametocoord(char col, int ligne); //transforme une coordonnee lettre en int compris entre 0 et 10

    void placer(Bateau bateau, int startx, int starty, int endx, int endy); //prend un bateau, coord case debut, coord case fin bateau et le place sur la grille
    
    // 0 : case eau, 1: case bateau intact, 2: case bateau touché
    // 3: coulé, 4 : inconnu (pour le joueur)

    void actualiser(); //actualise une grille
};

class GrilleDepart : public Grille{
    public :
    GrilleDepart ();


};

class GrilleJeu : public Grille{
    GrilleJeu ();


};

#endif