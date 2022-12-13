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
};

class GrilleDepart : public Grille{
    public :
    //constructeur
    GrilleDepart(): Grille(0){};

    //methodes
    void placer(Bateau bateau); //prend un bateau, coord case debut, coord case fin bateau et le place sur la grille
    pair<int,bool> quel_bat(int x, int y) const;
    void affiche_depart() const;
};

class GrilleJeu : public Grille{
    public:
    //constructeur
    GrilleJeu(): Grille(4){};
    void recupere_bat(const GrilleDepart&);

    //methodes
    bool actualiser(int, int, const GrilleDepart&); //actualise une grille
    bool fin_bat() const;
    void affiche() const;
}; 

#endif
