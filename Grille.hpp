#include <iostream>
#include "class.hpp"
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#ifndef GRILLEHEADERDEF
#define GRILLEHEADERDEF

class Grille{
private:
    vector<vector<int>> grid;

public:
    //constructeurs
    Grille ();
    
    Grille(const Grille &g);

    //getter
    int elem(int i, int j) const {assert(i>=0 && i<10 && j>=0 && j<10); return grid[i][j];}

    //operateurs
    int operator() (int i,int j) const { //retourne grid[i][j]
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];}

    friend std::ostream& operator<<(std::ostream& out, const Grille &g);

    int& operator()(int i, int j) { //version grille non constante
        assert(i>=0 && i<=10 && j>=0 && j<=10);
        return grid[i][j];}

    Grille placer(Bateau bateau);
    // 0 : case eau, 1: case bateau intact, 2: case bateau touché
    // 3: coulé, 4 : inconnu (pour le joueur)

    void actualiser(); //actualise une grille



};

#endif