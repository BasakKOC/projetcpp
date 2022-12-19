#include "Grille.hpp"
#include "Bateau.hpp"
#include<iostream>
#include "IA.hpp"
#include <vector>
#include <algorithm>  //sort dans ou sont les uns

using namespace std;

Bateau IA::coord_bateau(int size) const {
    srand (time(NULL));
    int hor_or_ver=rand()%2;  //0 : hor et 1 : ver;
    int startx,starty,endx,endy;
    if (hor_or_ver==0){    //cas ou le bateau est plavcer a lhorizontale
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

GrilleDepart IA::preparer_IA() const{
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

pair<int, int> IA::level_random(const GrilleJeu& g) const{
    srand (time(NULL));
    int x,y;
    while (true) {
        x = rand()%10;
        y = rand()%10;
        if (g(x,y)==4){  //verifie que la case na pas deja ete touche
            break;
        }
    }
    pair<int,int> p(x,y);
    cout<<"x = "<<x<<"; y = "<<y<<endl;
    return p;
}

pair<int, int> IA::level_normal(const GrilleJeu & g) const{
    vector<pair<int,int>> vec(ou_sont_les_uns(g));

    if (vec.empty()){
        return level_random(g);
    }
    if (vec.size()==1) {  //cas ou on ne connait pas la direction du bateau (hor ou vertical), on essaye de toucher autour
        int i = vec[0].first;
        int j = vec[0].second;
        //on fait les quatre cas en verifiant les conditions a chaque fois, on sarrete des quon a trouve une case jouable
        if ((i + 1) >= 0 && (i + 1) < 10) {
            if(g(i+1,j)==4){
                pair<int,int> p(i+1,j);
                cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                return p;
            }
        }
        if ((i - 1) >= 0 && (i - 1) < 10) {
            if(g(i-1,j)==4){
                pair<int,int> p(i-1,j);
                cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                return p;
            }
        }
        if ((j + 1) >= 0 && (j + 1) < 10) {
            if(g(i,j+1)==4){
                pair<int,int> p(i,j+1);
                cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                return p;
            }
        }
        if ((j - 1) >= 0 && (j - 1) < 10) {
            if(g(i,j-1)==4){
                pair<int,int> p(i,j-1);
                cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                return p;
            }
        }
    }
    else{ //cas ou on connait lorientation du bateau, on essaye donc de toucher dans la continuiter du bateau
        if (vec[0].first==vec[1].first){  //cas ou le bateau est en ligne
            int i = vec[0].first;
            int j = vec[0].second+vec.size();
            if (j >= 0 && j < 10) {  //on touche a la droite des points deja touche
                if(g(i,j)==4){
                    pair<int,int> p(i,j);
                    cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                    return p;
                }
                else { //si la case est deja joue on joue a la gauche
                    pair<int,int> p(i,vec[0].second-1);
                    cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                    return p;}
            }
            else {  //si la case a droite nest pas dans la grille on joue a gauche
                pair<int,int> p(i,vec[0].second-1);
                cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                return p;
            }
        }
        else{  //cas ou le bateau est en colonne
            int i = vec[0].first+vec.size();
            int j = vec[0].second;
            if (i >= 0 && i< 10) {
                if(g(i,j)==4){
                    pair<int,int> p(i,j);
                    cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                    return p;
                }
                else{
                    pair<int,int> p(vec[0].first-1,j);
                    cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                    return p;
                }
            }
            else {
                pair<int,int> p(vec[0].first-1,j);
                cout<<"x = "<<p.first<<" ;y = "<<p.second<<endl;
                return p;
            }
        }
    }

    pair<int,int> p(-1,-1);  //le code ne doit pas arrive jusque la
    cout<<"x = "<<-1<<" ;y = "<<-1<<endl;
    return p;
}

vector<pair<int, int>> IA::ou_sont_les_uns(const GrilleJeu & g)const { //il y a toujours au moins un bateau pas coule
    vector<Bateau> bat(g.get_bat());
    vector<pair<int, int>> vec;        //on mettra ici les coord si y il y a plusieurs case toucher daffiler
    vector<pair<int, int>> vec_isole;  //on met le premier un 'isole' si vec est vide cest lui quon renvoie
    for(Bateau boat : bat){    //on va verifier chaque bateau de la grille jeu
        if (boat.couler()) {   // si le bateau est couler ca sert a rien de le considerer
            continue;
        }
        vector<vector<int>> coord=boat.get_allcoord();
        for (int i = 0 ; i<boat.size();i++){
            if (boat.state(i)==1){
                if (i==boat.size()-1){  //la case touche est le dernier point de boat, si on est arrivee jusque la cest que y avait pas dautre case touche sur ce bateau avant, cest un 1 'isole' on le met dans vec_isole
                    if (vec_isole.empty()){
                        pair<int,int> p(coord[i][0],coord[i][1]);
                        vec_isole.push_back(p);
                    }
                }
                else {  //on va verifier si la case touche trouve est 'entoure' dautres case touche ou non
                    if (boat.state(i + 1) == 0 && vec_isole.empty()) {
                        pair<int, int> p(coord[i][0], coord[i][1]);
                        vec_isole.push_back(p);
                    }
                    else {
                        int j = i;
                        while (j < boat.size()) {
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


void IA::test_coord_bateau() const{
    cout<<endl<<"test coord bateau"<<endl;
    Bateau b(coord_bateau(3));
    cout<<"taille du bateau "<<b.size()<<endl;
    cout<<"debut x de b vaut : "<<b.get_x_start()<<endl;
    cout<<"debut y de b vaut : "<<b.get_y_start()<<endl;
    cout<<"fin x de b vaut : "<<b.get_x_end()<<endl;
    cout<<"fin y de b vaut : "<<b.get_y_end()<<endl;
}

void IA::test_level_random(GrilleJeu& gj,const GrilleDepart& g)const{
    cout<<"test level random"<<endl;
    cout<<"grille jeu = "<<endl<<gj<<endl;
    cout<<"bateau de gj = "<<endl;
    for(const Bateau& boat: gj.get_bat()){
        cout<<boat;
    }
    for (int i=0; i<5 ;i++) {
        cout<<"tour "<<i+1<<endl;
        cout<<"les coord choisies sont :"<<endl;
        pair<int, int> p(level_random(gj));

        gj.actualiser(p.first, p.second, g);
        cout << "gj apres actualisation = " << endl;
        gj.affiche();
        cout << "bateau de gj = " << endl;
        for (const Bateau &boat: gj.get_bat()) {
            cout << boat;
        }
    }
}
void IA::test_ou_sont_les_uns()const{
    cout<<endl<<"test ou sont les uns "<<endl;
    //preparation
    GrilleDepart gd;
    Bateau b0(5, 3, 5, 7, 5);
    Bateau b1(3,1,1,1,3);
    gd.placer(b0);
    gd.placer(b1);
    GrilleJeu gj;
    gj.recupere_bat(gd);

    cout<<"le vecteur ici vaut"<<endl;
    vector<pair<int,int>> v=ou_sont_les_uns(gj);
    for (pair<int,int> p :v){
        cout<<"p.first = "<<p.first<<" ; p.second = "<<p.second<<endl;
    }

    gj.actualiser(1,1,gd);
    cout<<"Grille joueur :"<<endl;
    gj.affiche();

    cout<<"le vecteur ici vaut"<<endl;
    v=ou_sont_les_uns(gj);
    for (pair<int,int> p :v){
        cout<<"p.first = "<<p.first<<" ; p.second = "<<p.second<<endl;
    }

    gj.actualiser(1,2,gd);
    cout<<"Grille joueur :"<<endl;
    gj.affiche();

    cout<<"le vecteur ici vaut"<<endl;
    v=ou_sont_les_uns(gj);
    for (pair<int,int> p :v){
        cout<<"p.first = "<<p.first<<" ; p.second = "<<p.second<<endl;
    }

    gj.actualiser(1,3,gd);
    cout<<"Grille joueur :"<<endl;
    gj.affiche();

    gj.actualiser(7,5,gd);
    cout<<"Grille joueur :"<<endl;
    gj.affiche();

    cout<<"le vecteur ici vaut"<<endl;
    v=ou_sont_les_uns(gj);
    for (pair<int,int> p :v){
        cout<<"p.first = "<<p.first<<" ; p.second = "<<p.second<<endl;
    }
}