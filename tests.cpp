#include "BatailleNavale.hpp"
#include "Grille.hpp"
#include "Bateau.hpp"
#include "IA.hpp"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){

    // ---- TESTS BATEAU -----
    cout<<"---- TESTS BATEAU -----"<<endl;
    //test constructeur avec arguments
    int n=4;
    Bateau b(n,1,1,4,1);
    Bateau bcpy(b);

    //tst operateur de sortie <<
    cout<<"test operateur de sortie <<"<<endl;
    cout<<"le bateau b est "<<b; //doit renvoye 0 0 0 0
    cout<<"le bateau bcpy est "<<bcpy<<endl;  //idem

    //test methodes size
    cout<<"test size"<<endl;
    cout<<"la taille de b est " <<b.size()<<std::endl; //doit renvoyer 4
    cout<<"la taille de bcpy est "<<bcpy.size()<<std::endl; //idem


    //test getter et setter:
    cout<<endl<<"test getter et setter"<<endl;
    cout<<"l'element 0 du bteau b est "<<b.state(0)<<std::endl; //renvoie 0
    b.state(0)=1;
    cout<<"b apres changmt "<<b; //renvoie 1 0 0 0
    cout<<"bcoy vaut "<<bcpy; //on verifie que bcpy ne change pas en meme temps que b : renvoie 0 0 0 0
    //b.state(44); //compile mais ne sexecute pas
    //b.state(-1); //compile mais ne sexecute pas

    cout<<"debut x de b vaut : "<<b.get_x_start()<<endl; //renvoie 1
    cout<<"debut y de b vaut : "<<b.get_y_start()<<endl;//renvoie 1
    cout<<"fin x de b vaut : "<<b.get_x_end()<<endl;  //renvoie 4
    cout<<"fin y de b vaut : "<<b.get_y_end()<<endl;  //renvoie 1

    //test couler et touche
    cout<<"test couler et touche"<<endl;
    bcpy.toucher(0,0);
    cout<<"bcpy apres avoir touche la case 0,0 : "<<bcpy<<endl; //0 0 0 0

    bcpy.toucher(1,1);
    cout<<"bcpy apres avoir touche la case 1,1 : "<<bcpy<<endl; //1 0 0 0

    cout<<"bcpy couler ? "<<bcpy.couler()<<endl; //renvoie 0

    bcpy.toucher(2,1);
    bcpy.toucher(3,1);
    bcpy.toucher(4,1);
    cout<<"bcpy vaut mnt : "<<bcpy<<endl;//renvoie 1 1 1 1
    cout<<"bcpy couler apres tois tours? "<<bcpy.couler()<<endl; //renvoie 1

    //test allcoord
    cout<<"test all coord"<<endl;
    vector<vector<int>> vec(b.get_allcoord());
    for (vector<int> v: vec){
        cout << " " << "("<<v[0]<<", "<< v[1]<<")";
    }
    //doit renvoyer  (1, 1) (2, 1) (3, 1) (4, 1)




    // ---- TESTS GRILLE -----
    cout<<endl<<"---- TESTS GRILLE -----"<<endl;
    //Tests constructeurs et << pour les grilles
    cout<<"test constructeur et << grilles"<<endl;
    Grille g(5);
    cout<<endl<<"Depart g = "<<endl<<g<<endl; //renvoie une grille de taille 10*10 remplie de 5

    GrilleDepart gd;
    cout<<endl<<"Depart gd = "<<endl<<gd<<endl; //grille remplie de 0

    GrilleJeu gj;                               //grille remplie de 4
    cout<<"gj="<<endl<<gj<<endl;

    //Test getter de l'attribut bat
    cout<<"Test getter de l'attribut bat"<<endl;
    vector<Bateau> batgd = gd.get_bat();
    cout << endl << "batgd = " << endl;
    for (Bateau boat: batgd){
        cout << boat << ' ';}  // ne renvoie rien car vide

    //Test methode placer
    cout <<endl<<"test methode placer"<<endl;
    //bateau vertical
    Bateau b0(5, 3, 5, 7, 5); //(startx=3, starty=5); (endx=7, endy=5)
    //bateau horizontal
    Bateau b1(3,1,1,1,3); 


    gd.placer(b0);
    cout<<endl<<"gd + b0 = "<<endl<<gd<<endl;
    gd.placer(b1);
    cout<<endl<<"gd + b0 + b1 = "<<endl<<gd<<endl;
    //cas chevauchement bateaux
    Bateau b2(2, 3, 5, 3, 6); 
    //gd.placer(b2); // on a bien un assertion fail

    // Test constructeur par copie Grille
    cout<<"test constructeur par copie des grille"<<endl;
    GrilleDepart gd_cpy(gd);
    cout<<endl<<"gd_cpy = "<<endl<<gd_cpy<<endl;

    vector<Bateau> batgd_cpy = gd_cpy.get_bat();
    cout<<"batgd_cpy = "<<endl;
    for (Bateau boat: batgd_cpy){
        cout << boat << ' ';} //renvoie 0 0 0 0 0 et 0 0 0

    // Test quel_bat de GrilleDepart
    cout <<"test quell_bat de GrilleDepart"<<endl;
    cout << endl<< "(1,1) Case bateau ? : "<< gd.quel_bat(7, 5).second << endl; //1
    cout << endl<< "Indice bateau touche (1,1) : "<< gd.quel_bat(1, 1).first << endl; //1
    cout << endl<< "(0,0) Case bateau ? : "<< gd.quel_bat(0, 0).second << endl; //0
    cout << endl<< "Indice bateau touche (0,0) : "<< gd.quel_bat(0, 0).first << endl;  //-1


    // Test affichage GrilleJeu
    cout<<endl<<"Affichage grille joueur :"<<endl;
    gj.affiche();

    // Test recupere_bat (copie bat de GrilleDepart dans GrilleJeu)
    cout<<"est recupere_bat (copie bat de GrilleDepart dans GrilleJeu)"<<endl;
    gj.recupere_bat(gd);
    vector<Bateau> batgj = gj.get_bat();
    cout<<endl<<"batgj = "<<endl;
    for (Bateau boat: batgj){
        cout << boat << ' ';}
    cout<<endl;  //0 0 0 0 0 et 0 0 0

    // Test actualiser
    cout <<"test actualiser"<<endl;
    bool a=gj.actualiser(0,0,gd);
    cout<< "gj.actualiser(0,0,g) = "<<a;  //0
    cout<<endl<<"Grille joueur :"<<endl;
    gj.affiche();

    bool z=gj.actualiser(1,1,gd);
	cout<<"gj.actualiser(1,1,g) = "<<z<<endl;  //1
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    gj.actualiser(1,2,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    gj.actualiser(1,3,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    gj.actualiser(7,5,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    gj.actualiser(6,5,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

	//Test fin_bat
    cout<<"test fin-bat"<<endl;
	cout<<"Les bateaux de gj pour l'instant sont :"<<endl;
    for (Bateau boat: gj.get_bat()){
        cout << boat;}  //0 0 0 1 1 et 1 1 1
    cout<<endl<<"Fin bat ? : "<<gj.fin_bat()<<endl; //0

    gj.actualiser(4,5,gd);
	cout<<endl<<"Grille joueur :"<<endl;
	gj.affiche();

    gj.actualiser(5,5,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    gj.actualiser(3,5,gd);
    cout<<"Grille joueur :"<<endl;
	gj.affiche();

    cout<<"Les bateaux de gj pour l'instant sont :"<<endl;
    for (Bateau boat: gj.get_bat()){
        cout << boat;} //1 1 1 1 1 et 1 1 1
    cout<<endl<<"Fin bat ? : "<<gj.fin_bat()<<endl;//1

    // ---- TESTS IA -----
    cout<<" ---- TESTS IA -----"<<endl;
    IA ia;

    //test ia.preparer
    cout<<endl<<"test praparation de la grille par l IA"<<endl;
    GrilleDepart g1(ia.preparer_IA());
    g1.affiche_depart(); //grille remplie e bateau
    cout<<"bateau de g1 = "<<endl;
    for(const Bateau& boat: g1.get_bat()){
        cout<<boat;
    }// doit renvoyer tous les bateau donc 0 0 0 0 0 et 0 0 0 0 et 0 0 0 etc

    GrilleJeu gj;
    gj.recupere_bat(g1);

    ia.test_coord_bateau();//taille = 3, verifier que les coordonnes font sens
    cout<<endl;
    ia.test_level_random(gj,g1); //verifier que les coordonnes rendus sont jouables
    //fait 5 tours

    ia.test_ou_sont_les_uns();
    //le vecteur doit etre vide
    //doit renvoyer 1,1
    //doit renvoyer 1,1 puis 1,2
    //doit renvoyer 7,5

    //test level_normal:
    cout<<endl<<"test level_normal"<<endl;
    cout<<"le grille est "<<endl;
    g1.affiche_depart();
    cout<<endl;
    cout<<"la grille jeu vaut "<<endl;
    gj.affiche();
    cout<<endl;
    int x,y;
    cout<<"toucher un bateau (ligne entree puis colonne entree)"<<endl;
    cin>>x;
    cin>>y;
    gj.actualiser(x,y,g1);
    gj.affiche();
    cout<<"encore une fois(tester differents cas)"<<endl;
    cin>>x;
    cin>>y;
    gj.actualiser(x,y,g1);
    gj.affiche();
    for (int i = 0; i<2 ; i++){
        cout<<"level normal donne :"<<endl;
        pair<int, int> p(ia.level_normal(gj));

        gj.actualiser(p.first, p.second, g1);
        cout << "gj apres actualisation = " << endl;
        gj.affiche();
        cout << "bateau de gj = " << endl;
        for (const Bateau &boat: gj.get_bat()) {
            cout << boat;
        }
    }

    // ---- TESTS BATAILLENAVALE -----
    BatailleNavale bataille;

    //Tests methodes privees
    test_BatailleNavale(bataille);

    // Test jouer
    //bataille.jouer();

    return 0;
}