#include "BatailleNavale.hpp"
#include "Grille.hpp"
#include "Bateau.hpp"
#include "IA.hpp"

using std::cout;
using std::endl;
using std::vector;

int main(){
    // ---- TESTS GRILLE -----
    //Tests constructeurs et << pour les grilles
    Grille g(5);
    cout<<endl<<"Depart g = "<<endl<<g<<endl;

    GrilleDepart gd;
    cout<<endl<<"Depart gd = "<<endl<<gd<<endl;

    GrilleJeu gj;
    cout<<"gj="<<endl<<gj<<endl;

    //Test getter et << de l'attribut bat
    vector<Bateau> batgd = gd.get_bat();
    cout << endl << "batgd = " << endl;
    for (Bateau boat: batgd){
        cout << boat << ' ';}

    //Test constructeur, size et << Bateau
    //bateau vertical
    Bateau b0(5, 3, 5, 7, 5); //(startx=3, starty=5); (endx=7, endy=5)
    cout<<endl<<"taille b0 = "<<b0.size()<<endl;
    cout<<endl<<"b0 = "<<b0<<endl;
    //bateau horizontal
    Bateau b1(3,1,1,1,3); 

    //Test methode placer 
    gd.placer(b0);
    cout<<endl<<"gd + b0 = "<<endl<<gd<<endl;
    gd.placer(b1);
    cout<<endl<<"gd + b0 + b1 = "<<endl<<gd<<endl;
    //cas chevauchement bateaux
    Bateau b2(2, 3, 5, 3, 6); 
    //gd.placer(b2); // on a bien un assertion fail


    // Getter et << de l'attribut bat
    batgd = gd.get_bat();
    cout<<"batgd = "<<endl;
    for (Bateau boat: batgd){
        cout << boat << ' ';}

    // Test constructeur par copie Grille
    GrilleDepart gd_cpy(gd);
    cout<<endl<<"gd_cpy = "<<endl<<gd_cpy<<endl;

    vector<Bateau> batgd_cpy = gd_cpy.get_bat();
    cout<<"batgd_cpy = "<<endl;
    for (Bateau boat: batgd_cpy){
        cout << boat << ' ';}

    // Test constructeur par copie Bateau
    Bateau b0_cpy(b0);
    cout<<endl<<"b0_cpy = "<<b0_cpy<<endl;

    // Test getter coordonnees Bateau get_allcoord
    vector<vector<int>> allcoord_b0 = b0.get_allcoord();
    cout<<"Coord de b0 : ";
    for (vector<int> couple: allcoord_b0){
        cout << " " << "("<<couple[0]<<", "<< couple[1]<<")";}
    cout<<endl;

    // Test quel_bat de GrilleDepart
    cout << endl<< "(1,1) Case bateau ? : "<< gd.quel_bat(7, 5).second << endl;
    cout << endl<< "Indice bateau touche (1,1) : "<< gd.quel_bat(1, 1).first << endl;
    cout << endl<< "(0,0) Case bateau ? : "<< gd.quel_bat(0, 0).second << endl;
    cout << endl<< "Indice bateau touche (0,0) : "<< gd.quel_bat(0, 0).first << endl;


    // Test affichage GrilleJeu
    cout<<endl<<"Affichage grille joueur :"<<endl;
    gj.affiche();

    // Test recupere_bat (copie bat de GrilleDepart dans GrilleJeu)
    gj.recupere_bat(gd);
    vector<Bateau> batgj = gj.get_bat();
    cout<<endl<<"batgj = "<<endl;
    for (Bateau boat: batgj){
        cout << boat << ' ';}
    cout<<endl;

    // Test actualiser
    bool a=gj.actualiser(0,0,gd);
    cout<< "gj.actualiser(0,0,g) = "<<a;
    cout<<endl<<"Grille joueur :"<<endl;
    gj.affiche();

    bool z=gj.actualiser(1,1,gd);
	cout<<"gj.actualiser(1,1,g) = "<<z<<endl;
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    bool e=gj.actualiser(1,2,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    bool y=gj.actualiser(1,3,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    bool t=gj.actualiser(7,5,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    bool r=gj.actualiser(6,5,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

	//Test fin_bat
	cout<<"Les bateaux de gj pour l'instant sont :"<<endl;
    for (Bateau boat: gj.get_bat()){
        cout << boat;}
    cout<<endl<<"Fin bat ? : "<<gj.fin_bat()<<endl;

    bool u=gj.actualiser(4,5,gd);
	cout<<endl<<"Grille joueur :"<<endl;
	gj.affiche();

    bool o=gj.actualiser(5,5,gd);
	cout<<"Grille joueur :"<<endl;
	gj.affiche();

    bool p=gj.actualiser(3,5,gd);
    cout<<"Grille joueur :"<<endl;
	gj.affiche();

    cout<<"Les bateaux de gj pour l'instant sont :"<<endl;
    for (Bateau boat: gj.get_bat()){
        cout << boat;}
    cout<<endl<<"Fin bat ? : "<<gj.fin_bat()<<endl;



    // ---- TESTS BATAILLENAVALE -----
    BatailleNavale bataille;

    //Tests methodes privees
    test_BatailleNavale(bataille);

    // Test jouer
    bataille.jouer();

    return 0;
}