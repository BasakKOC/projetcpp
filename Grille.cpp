#include "Grille.hpp"
#include "Bateau.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <string>

using std::pair;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

//Grille
//constructeurs
Grille::Grille(int n) : grid(),bat() {
            for (int i=0; i<10; i++) {
                vector<int> ligne;
                for (int j = 0; j <10; j++) {
                    ligne.push_back(n);
                }
                grid.push_back(ligne);}
} //par defaut

//operateurs
std::ostream& operator<<(std::ostream& out, const Grille &g){ //getter et setter
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            out<<g.grid[i][j]<<" ";
        }
        out<<endl;
    }
    out<<endl;
    return out;
}



//Grille Depart

// Methodes
pair<int,bool> GrilleDepart::quel_bat (int x,int y) const{
    int pos=0; //position du bateau
    for (Bateau boat: bat){
        vector<vector<int>> coord = boat.get_allcoord(); //recuperation des coord des bateaux
        for (vector<int> couple: coord){
            if(couple[0]==x){
                if(couple[1]==y){
                    pair<int,bool> p{pos,true};
                    return p;
                }
            } 
        }
        pos+=1;
    }
    pair<int,bool> p0{-1,false};
    return p0;
    //assert(pos>=9); //si on arrive la c qu'il y a un pb et que les coord sont dans l'eau
}

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
    assert(startx==endx || starty==endy);
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

void GrilleDepart::affiche_depart() const {
    cout<<"  0 1 2 3 4 5 6 7 8 9"<<endl;
    for (int i = 0; i<grid.size();i++){
        cout<<i<<" ";
        for (int j = 0;j<grid.size();j++){
            if (grid[i][j]==0){
                cout<<"~"<<" ";
            }
            if (grid[i][j]==1){
                cout<<"x"<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl <<endl;
}



//GrilleJeu

void GrilleJeu::recupere_bat(const GrilleDepart& gr) {
    bat=gr.get_bat();
}

bool GrilleJeu::actualiser(int x, int y, const GrilleDepart& gr) { //par du principe que les coord sont valides 
//(dans la grille et pas deja touché (donc la case est un 4) : Tester dans bataille Navale)
    pair<int, bool> p = gr.quel_bat(x,y);
    int place=p.first;
    bool j=p.second;
    if (not j) {
        grid[x][y]=0;
    }
    else {
        grid[x][y] = 2;
        //cout<<"bat[place]="<<bat[place]<<endl;
        /* for (Bateau  boat : bat){
            cout <<boat;
        } */
        bat[place].toucher(x,y);
        if (bat[place].couler()) {
            vector<vector<int>> coord_bat = bat[place].get_allcoord();
            for (int i = 0; i < bat[place].size(); i++) {
                int x_ = coord_bat[i][0];
                int y_= coord_bat[i][1];
                grid[x_][y_] = 3;
            }
            cout<<endl<<"Coule !"<<endl;
        }
    }
    return j;
}

bool GrilleJeu::fin_bat() const {
    bool fin=true;
    for (int i=0; i<bat.size(); i++) {
        if (not bat[i].couler()) {fin = false;}
    }
    return fin;
}


void GrilleJeu::affiche() const {
    cout<<"  0 1 2 3 4 5 6 7 8 9"<<endl;
    for (int i = 0; i<grid.size();i++){
        cout<<i<<" ";
        for (int j = 0;j<grid.size();j++){
            if (grid[i][j]==4){
                cout<<"?"<<" ";
            }
            if (grid[i][j]==2){
                cout<<"o"<<" ";
            }
            if (grid[i][j]==3){
                cout<<"X"<<" ";
            }
            if (grid[i][j]==0){
                cout<<"~"<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl <<endl;
}