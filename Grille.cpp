#include "Grille.hpp"
#include "Bateau.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <string>
using std::string;
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
    int startx = bateau.get_x_start(); //getters de la classe Bateau
    int starty = bateau.get_y_start();
    int endx = bateau.get_x_end();
    int endy = bateau.get_y_end();

    //tests validite coordonnees
    //test coordonnees de grille valides
    assert(startx>=0 && starty>=0 && endx<=9 && endy<=9);
    //test coordonnees de bateau valides
    assert(startx==endx || starty==endy); //il faut aussi verifier si cest bien dans la grille !! (cf dans bataille_navale mais mieux vaut avoir tout les tests au mm endroit )
    int longueur;
    if(startx==endx){longueur=abs(endy-starty)+1;}
    else{longueur=abs(startx-endx)+1;}
    assert(longueur==bateau.size());
    
    //placement du bateau
    for (int i=startx; i<=endx; i++){
        for(int j=starty; j<=endy; j++){
            assert(grid[i][j]==0); //test si y'a pas déjà de bateau
            grid[i][j]=1; //utiliser (i,j) le setter codée juste au dessus
        }
    }

    //ajout du bateau à bat
    bat.push_back(bateau);

}


void GrilleJeu::actualiser(int x, int y, GrilleDepart gr) { //par du principe que les coord sont valide (dans la grille et pas deja touché (donc la case est un 4))
    bat=gr.bat();// faire la methode
    string sortie = "a l'eau";
    int i=quel_bat(x,y);
    if (bat[i].toucher(int x, int y)){
        grid[x][y]=2;
        sortie="touché";
    }
    if (bat[i].couler()){
        vector<vector<int>> coord_bat = bat[i].get_allcoord();
        for(int i=0; i<bat[i].size()){
            int x = coord_bat[i][0];
            int y = coord_bat[i][1];
            grid[x][y]=3;
        }
        sortie="coulé";
    }
    cout<<sortie<<endl;
}


int GrilleJeu::quel_bat(int x,int y) {
    for (int i=0; i<bat.size(); i++){
        // a faire
    }
}


bool GrilleJeu::fin_bat() {
    bool fin=true;
    for (int i=0; i<bat.size(); i++) {
        if not(bat[i].couler()){fin = false;}
    }
    return fin;
}
