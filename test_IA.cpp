#include "IA.hpp"
#include "Grille.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    IA ia;
    //test de coord_bat qui est mnt privee
    //Bateau b(ia.coord_bateau(3));

    //test ia.preparer
    GrilleDepart g(ia.preparer_IA());
    cout<<g<<endl;
    cout<<"bateau de g = "<<endl;
    for(const Bateau& boat: g.get_bat()){
        cout<<boat;
    }


//    //test levle_random
    GrilleJeu gj;
    gj.recupere_bat(g);
    cout<<"grille jeu = "<<endl<<gj<<endl;
//    cout<<"bateau de gj = "<<endl;
//    for(const Bateau& boat: gj.get_bat()){
//        cout<<boat;
//    }
//    for (int i=0; i<50 ;i++) {
//        cout<<"tour "<<i<<endl;
//        cout<<"les coord choisies sont :"<<endl;
//        pair<int, int> p(ia.level_random(gj));
//
//        gj.actualiser(p.first, p.second, g);
//        cout << "gj apres actualisation = " << endl;
//        gj.affiche();
//        cout << "bateau de gj = " << endl;
//        for (const Bateau &boat: gj.get_bat()) {
//            cout << boat;
//        }
//    }


    //test ou sont les un
    int x,y;
    cin>>x;
    cin>>y;
    gj.actualiser(x,y,g);

    cin>>x;
    cin>>y;
    gj.actualiser(x,y,g);

    cin>>x;
    cin>>y;
    gj.actualiser(x,y,g);

    vector<pair<int,int>> v=ia.ou_sont_les_uns(gj);
    for (pair<int,int> p :v){
        cout<<"p.first = "<<p.first<<" ; p.second = "<<p.second<<endl;
    }


}


