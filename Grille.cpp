#include "Grille.hpp"
#include <iostream>
#include <cassert>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

//constructeur
Grille::Grille() : grid(){ //par defaut
            for (int i=0; i<10; i++) {
                vector<int> ligne;
                for (int j = 0; j <10; j++) {
                    ligne.push_back(0);
                }
                grid.push_back(ligne);}
    }

Grille::Grille(const Grille &g):  grid() { //par copie
        for (int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                grid[i][j]=g.grid[i][j];}}
    }

std::ostream& operator<<(std::ostream& out, const Grille &g){
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            out<<g.grid[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}