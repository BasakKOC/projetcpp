#include <vector>
#include <cassert>
#include <iostream>

#ifndef CLASSBATAILLENAVALE_BATEAU
#define CLASSBATAILLENAVALE_BATEAU

using std::vector;

class Bateau{
    private:
    int taille;
    std::vector<int> vec;  //garde en memoire l'etat du bateau
    int startx, starty, endx, endy;

    public:
    //constructeur
    Bateau(int n, int startx_, int starty_,int endx_,int endy_);
    Bateau(const Bateau&);

    //accesseurs et mutateurs
    int size() const {return taille;}
    int state(int i) const {assert (i<taille && i>-1); return vec[i];}
    int& state(int i) {assert(i<taille && i>-1);return vec[i];}

    int get_x_start() const {return startx;}
    int get_y_start() const {return starty;}
    int get_x_end() const {return endx;}
    int get_y_end() const {return endy;}

    vector<vector<int>> get_allcoord() const; //retourne toutes les coords d'une bateau

    //autres methodes
    bool couler() const ;
    void toucher(int x,int y);

    //affichage temporaire
    friend std::ostream& operator << (std::ostream &, const Bateau&);
};	
#endif
