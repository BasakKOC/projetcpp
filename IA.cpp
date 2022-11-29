#include "Grille.hpp"
#include "Bateau.hpp"



#include "IA.hpp"


Bateau IA::coord_bateau(int size) {
    int hor_or_ver=rand()%2;  //0 : hor et 1 : ver;
    int startx = rand() % 9;
    int starty = rand() % 9;
    int endx,endy;
    if (hor_or_ver==0){
        endx=startx;
        endy=starty+size;
    }
    else{
        endy=starty;
        endx=startx+size;
    }
    Bateau b(size,startx,starty,endx,endy);
    return b;
}

GrilleDepart IA::preparer_IA() {
    int size=3;
    Bateau b(coord_bateau(size));
    GrilleDepart g;
    g.placer(b);
    return g;
}

//void IA::tirer() {}