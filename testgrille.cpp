#include "Grille.hpp"
#include "Bateau.hpp"
#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){
	/* Grille g;
	cout<<"g="<<endl<<g<<endl;

	GrilleJeu gjeu;
	cout<<"gjeu="<<endl<<gjeu<<endl;
	
	GrilleDepart gdepart;
	cout<<"gdepart="<<endl<<gdepart<<endl; */

	//test constructeur Grille
	//GrilleDepart g;
	//cout<<endl<<"Depart g = "<<endl<<g<<endl;

	

	//vector<Bateau> bat1 = g.get_bat();
	/* cout<< "bat = ";
	for (Bateau boat: bat1){
		cout << boat << ' ';}
 */
	//test constructeur Bateau
	//Bateau b(5, 3, 5, 7, 5); //(startx=3, starty=5); (endx=7, endy=5)
	//cout<<endl<<"taille b = "<<b.size()<<endl;

	//test constructeur bateau par copie
	//Bateau bcpy(b);
	//cout<<endl<<"taille bcpy = "<<bcpy.size()<<endl;
	//test get_allcoord
	/* vector<vector<int>> allcoordbcpy = bcpy.get_allcoord();
	cout<<"Coord de bcpy : ";
	for (vector<int> couple: allcoordbcpy){
		cout << " " << "("<<couple[0]<<", "<< couple[1]<<")";}

	cout <<endl<<b<<endl;
	cout <<endl<<bcpy <<endl; */
	

	//test placer
	//g.placer(b);
	//cout<<endl<<"New g = "<<endl<<g<<endl;
	//bat1 = g.get_bat();

	//test constructeur par copie Grille
	//GrilleDepart g4(g);

	//cas chevauchement bateaux
	//Bateau b3(2, 3, 5, 3, 6);
	//g.placer(b3);




	//cout<< "New bat = ";
	//for (Bateau boat: bat1){
    //	cout << boat << ' ';}

	//test get_allcoord
	//vector<vector<int>> allcoord = b.get_allcoord();
	//cout<<"Coord de b : ";
	//for (vector<int> couple: allcoord){
	//	cout << " " << "("<<couple[0]<<", "<< couple[1]<<")";}

	//cout << endl<< "Indice bateau touche : "<< g.quel_bat(4, 5).first << endl;

	//test quel_bat
	//Bateau b2(3,1,1,1,3);
	//g.placer(b2);
	//cout<<endl<<"New g = "<<endl<<g<<endl;

	//vector<vector<int>> allcoord2 = b2.get_allcoord();
	//cout<<"Coord de b2 : ";
	//for (vector<int> couple: allcoord2){
	//	cout << " " << "("<<couple[0]<<", "<< couple[1]<<")";}

	//cout << endl<< "Indice bateau touche (1,1) : "<< g.quel_bat(1, 1).first << endl;
	//cout << endl<< "Indice bateau touche (7,5) : "<< g.quel_bat(7, 5).first << endl;

	// test actualiser

/* 	GrilleJeu gj;
	//cout<<"gj = "<<endl<<gj<<endl;
    gj.affiche();
    gj.recupere_bat(g);
    vector<Bateau> batj=gj.get_bat();
//    cout<<"les bateaux de gj pour linstant sont:"<<endl;
//    for (Bateau boat: batj){
//        cout << boat;}
	auto a=gj.actualiser(0,0,g);
    auto z=gj.actualiser(1,1,g);
    auto e=gj.actualiser(1,2,g);
    auto y=gj.actualiser(1,3,g);
    auto t=gj.actualiser(7,5,g);
    auto r=gj.actualiser(6,5,g);
    auto u=gj.actualiser(4,5,g);
    auto o=gj.actualiser(5,5,g);
    auto p=gj.actualiser(3,5,g);
    //bool n1=gj.actualiser(0,0,g);
	cout<< "gj.actualiser(1,1,g) = "<<z<<endl;
    //cout<< "gj.actualiser(0,0,g) = "<<n<<endl;
    cout<<" new gj = "<<endl<<gj<<endl;
    gj.affiche();
    cout<<"les bateaux de gj pour linstant sont:"<<endl;
    for (Bateau boat: gj.get_bat()){
        cout << boat;}
    cout<<"fin bat ? "<<gj.fin_bat()<<endl; */

	//vector<Bateau> vb;
	//vb.push_back(b);
	//vb.push_back(b3);
	/* for(Bateau boat: vb){
		cout<<"batjojhgfdsq:"<<boat<<endl;
	} */

	GrilleDepart g0;
	cout<<"g0="<<endl<<g0<<endl;
	for(Bateau boat: g0.get_bat()){
		cout<<"bat ="<<endl;
		cout<<boat<<endl;
	}
	Bateau b2(3,1,1,1,3);
	g0.placer(b2);
	for(Bateau boat: g0.get_bat()){
		cout<<"batg0 ="<<endl;
		cout<<boat<<endl;
	}

	GrilleDepart g0copy(g0);
	/* for(Bateau boat: g0copy.get_bat()){
		cout<<"batg0copy ="<<endl;
		cout<<boat<<endl;
	} */
}