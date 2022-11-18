#include "Grille.hpp"
#include "Bateau.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

//Grille
//constructeurs
Grille::Grille(int n) : grid(){
            for (int i=0; i<10; i++) {
                vector<int> ligne;
                for (int j = 0; j <10; j++) {
                    ligne.push_back(n);
                }
                grid.push_back(ligne);}
} //par defaut

Grille::Grille(const Grille &g):  grid() { //par copie
        for (int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                grid[i][j]=g.grid[i][j];}}
    }

//operateurs
std::ostream& operator<<(std::ostream& out, const Grille &g){ //getter et setter
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            out<<g.grid[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}

//methodes
pair<char, int> Grille::gametocoord(char col, int ligne){
        pair<int, int> res;
        res.first=int(col)%65;
        res.second=ligne-1;
        return res;} 



//Grille Depart




//GrilleJeu


void GrilleDepart::placer(Bateau bateau){
    //recuperation coordonnees
    int startx = bateau.x_start(); //getters de la classe Bateau
    int starty = bateau.y_start();
    int endx = bateau.x_end();
    int endy = bateau.y_end();

    //tests validite coordonnees
    assert(startx==endx || starty==endy);
    int longueur;
    if(startx==endx){longueur=abs(endy-starty)+1;}
    else{int longueur=abs(startx-starty)+1;}
    assert(longueur==bateau.size());

    for (int i=startx; i<=endx; i++){
        for(int j=starty; j<=endy; j++){
            grid[i][j]=1;
        }
    }
}



