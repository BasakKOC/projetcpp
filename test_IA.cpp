#include "IA.hpp"
#include "Grille.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(){

    IA ia;

    //test ia.preparer
    cout<<endl<<"test praparation de la grille par l IA"<<endl;
    GrilleDepart g(ia.preparer_IA());
    g.affiche_depart(); //grille remplie e bateau
    cout<<"bateau de g = "<<endl;
    for(const Bateau& boat: g.get_bat()){
        cout<<boat;
    }// doit renvoyer tous les bateau donc 0 0 0 0 0 et 0 0 0 0 et 0 0 0 etc

    GrilleJeu gj;
    gj.recupere_bat(g);

    ia.test_coord_bateau();//taille = 3, verifier que les coordonnes font sens
    cout<<endl;
    ia.test_level_random(gj,g); //verifier que les coordonnes rendus sont jouables
    //fait 5 tours

    ia.test_ou_sont_les_uns();
    //le vecteur doit etre vide
    //doit renvoyer 1,1
    //doit renvoyer 1,1 puis 1,2
    //doit renvoyer 7,5

    //test level_normal:
    cout<<endl<<"test level_normal"<<endl;
    cout<<"le grille est "<<endl;
    g.affiche_depart();
    cout<<endl;
    cout<<"la grille jeu vaut "<<endl;
    gj.affiche();
    cout<<endl;
    int x,y;
    cout<<"toucher un bateau (ligne entree puis colonne entree)"<<endl;
    cin>>x;
    cin>>y;
    gj.actualiser(x,y,g);
    gj.affiche();
    cout<<"encore une fois(tester differents cas)"<<endl;
    cin>>x;
    cin>>y;
    gj.actualiser(x,y,g);
    gj.affiche();
    for (int i = 0; i<2 ; i++){
        cout<<"level normal donne :"<<endl;
        pair<int, int> p(ia.level_normal(gj));

        gj.actualiser(p.first, p.second, g);
        cout << "gj apres actualisation = " << endl;
        gj.affiche();
        cout << "bateau de gj = " << endl;
        for (const Bateau &boat: gj.get_bat()) {
            cout << boat;
        }
    }
}


