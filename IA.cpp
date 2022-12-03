#include "Grille.hpp"
#include "Bateau.hpp"
#include<iostream>
#include "IA.hpp"
#include <vector>
using namespace std;

Bateau IA::coord_bateau(int size) {
    srand (time(NULL));
    int hor_or_ver=rand()%2;  //0 : hor et 1 : ver;
    int startx,starty,endx,endy;
    if (hor_or_ver==0){
        starty = rand() % (10-size+1);
        startx = rand()%10;
        endx=startx;
        endy=starty+size-1;
    }
    else{
        starty = rand()%10;
        startx = rand() % (10-size+1);
        endy=starty;
        endx=startx+size-1;
    }
    Bateau b(size,startx,starty,endx,endy);
    return b;
}

GrilleDepart IA::preparer_IA() {
    int sizes [7] = {5, 4, 3, 3, 3, 2, 2};
    GrilleDepart g;
    Bateau b(0,0,0,0,0);
    for (int size : sizes){
        bool tous_egaux_a_zero; //on va verifier si un bateau existe deja la ou on veur mettre le notre
        while (true) {
            b = coord_bateau(size);
            int startx=b.get_x_start();
            int endx=b.get_x_end();
            int starty=b.get_y_start();
            int endy=b.get_y_end();

            tous_egaux_a_zero=true;
            for (int i=startx; i<=endx; i++){
                for(int j=starty; j<=endy; j++){
                    if (g(i,j)!=0) {
                        tous_egaux_a_zero=false;
                    }
                }
            }
            if (tous_egaux_a_zero){break;}
        }
        g.placer(b);
    }
    return g;
}

pair<int, int> IA::level_random(const GrilleJeu& g) {
    srand (time(NULL));
    int x,y;
    while (true) {
        x = rand()%10;
        y = rand()%10;
        if (g(x,y)==4){
            break;
        }
    }
    pair<int,int> p(x,y);
    cout<<"x = "<<x<<" ;y = "<<y<<endl;
    return p;
}

pair<int, int> IA::level_normal(const GrilleJeu & g) {
    srand (time(NULL));
    int x,y;
    //cas bateau touche : au moins deux1 daffile et bateau en question non coule


    //cas il y a un bateau touche : 1 isole
    vector<pair<int,int>> fonction(appeler la fonction qui fera ca!);
    if (il y a un bateau avec un 1 isole){ //un bool + plus la position du 1
        //cas ou le point est un coin

        //cas ou cest sur le bord

        //cas ou cest pas un bord
    }


    //cas il n y a pas de bateau touche pour linstant ou il sont couler
    //mettre dans une boucle if
    return level_random(g);


    pair<int,int> p(x,y);
    cout<<"x = "<<x<<" ;y = "<<y<<endl;
    return p;
}

vector<pair<int, int>> IA::ou_sont_les_uns(const GrilleDepart & g) {
    vector<Bateau> bat(g.get_bat());
    for(Bateau boat : bat){
        vector<vector<int>> coord=boat.get_allcoord();
        for (int i = 0 ; i<boat.size();i++){
            if (boat.state(i)==1){
                //verifie a droite et a gauche
                //si y a que des zeros on fait un push_back et on renvoie!
                //sinon on mets de cote et on continue de chercher
                //verifier que cest pas un bateau coule aussi !
            }
        }
    }

}
