#include <iostream>
#include "Bateau.hpp"
#include <cassert>
#include <vector>
#include <utility>

using std::pair;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

#ifndef GRILLEHEADERDEF
#define GRILLEHEADERDEF

class Grille{
protected:
    vector<vector<int>> grid;
    vector<Bateau> bat; // vecteur contenant les bateaux , remplacer par etats des bateau ou autre chose ???
                        // a modifier avec placer_bateau (les positions ) actualiser (l'etat du bateau)
public:
    //constructeurs
    Grille(int);
    Grille(const Grille &g); //par copie

    //getter bat
    vector<Bateau> get_bat() const {return bat;}

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
    pair<int,bool> quel_bat(int x, int y) const;
};

class GrilleJeu : public Grille{
    public:
    GrilleJeu(): Grille(4){};
    void recupere_bat(const GrilleDepart&);
    bool actualiser(int, int, const GrilleDepart&); //actualise une grille
    bool fin_bat();
    void affiche() const;
}; 

#endif
