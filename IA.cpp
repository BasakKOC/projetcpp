#include "Grille.hpp"
#include "Bateau.hpp"
#include<iostream>
#include "IA.hpp"
#include <vector>
#include <algorithm>
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
    cout<<"x = "<<x<<"; y = "<<y<<endl;
    return p;
}

/* pair<int, int> IA::level_normal(const GrilleJeu & g) {
    int x,y;
    vector<pair<int,int>> vec(ou_sont_les_uns(g));
    if (vec.empty()){
        return level_random(g);
    }
    if (vec.size()==1) {
        int i = vec[0].first;
        int j = vec[0].second;
        for (int t = 0; t < 4 ; t++) {
            if ((i + 1) >= 0 && (i + 1) < 10) {
                if(g(i+1,j)==4){
                    pair<int,int> p(i+1,j);
                    return p;
                }

            }
            if ((i - 1) >= 0 && (i - 1) < 10) {
                if(g(i-1,j)==4){
                    pair<int,int> p(i-1,j);
                    return p;
                }

            }
            if ((j + 1) >= 0 && (j + 1) < 10) {
                if(g(i,j+1)==4){
                    pair<int,int> p(i,j+1);
                    return p;
                }

            }
            if ((j - 1) >= 0 && (j - 1) < 10) {
                if(g(i,j-1)==4){
                    pair<int,int> p(i,j-1);
                    return p;
                }

            }
        }
    }
    else{
        if (vec[0].first==vec[1].second){  //cas ou le bateau est en ligne
            int i = vec[0].first;
            int j = vec[0].second+vec.size();
            if (j >= 0 && j < 10) {
                if(g(i,j-1)==4){
                    pair<int,int> p(i,j);
                    return p;
                }
            }
            else {
                pair<int,int> p(i,vec[0].second-1);
                return p;
            }
        }
        else{  //cas ou le bateau est en colonne
//            pair<int,int> p(???,vec[0].second);
//            return p;
            int i = vec[0].first+vec.size();
            int j = vec[0].second;
            if (i >= 0 && i< 10) {
                if(g(i,j-1)==4){
                    pair<int,int> p(i,j);
                    return p;
                }
            }
            else {
                pair<int,int> p(vec[0].first-1,j);
                return p;
            }
        }
    }
    cout<<"x = "<<x<<" ;y = "<<y<<endl;
    pair<int,int> p(x,y);
    return p;
} */

vector<pair<int, int>> IA::ou_sont_les_uns(const GrilleJeu & g) { //il y a toujours au moins un bateau pas coule
    vector<Bateau> bat(g.get_bat());
    vector<pair<int, int>> vec;        //on mettra ici les coord si y il y a plusieurs uns daffiler
    vector<pair<int, int>> vec_isole;  //on met le premier un 'isole' si vec est vide cest lui quon renvoie
    for(Bateau boat : bat){            //on va verifier chaque bateau de la grille jeu
        if (boat.couler()) {           // si le bateau est couler ca sert a rien de le considerer
            continue;
        }
        vector<vector<int>> coord=boat.get_allcoord();
        for (int i = 0 ; i<boat.size();i++){
            if (boat.state(i)==1){
                if (i==boat.size()-1){  // cest le dernier point de boat, si on est arrivee jusque la cest que y avait pas dautre un avant, cest un 1 'isole' on le met dans vec_isole
                    if (vec_isole.empty()){
                        pair<int,int> p(coord[i][0],coord[i][1]);
                        vec_isole.push_back(p);
                    }
                }
                else {
                    if (boat.state(i + 1) == 0 && vec_isole.empty()) {
                        pair<int, int> p(coord[i][0], coord[i][1]);
                        vec_isole.push_back(p);
                    } else {
//                    pair<int,int> p(coord[i][0],coord[i][1]);
//                    vec.push_back(p);
                        int j = i;
                        while (j < boat.size()) {//rajouter un -1 ?
                            if (boat.state(j) == 1) {
                                pair<int, int> p(coord[j][0], coord[j][1]);
                                vec.push_back(p);
                            }
                            j += 1;
                        }
                        sort(vec.begin(),vec.end());
                        return vec;
                    }
                }
            }
        }
    }
    return vec_isole;
}
