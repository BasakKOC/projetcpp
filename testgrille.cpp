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

	GrilleDepart g;
	cout<<endl<<"Depart g = "<<endl<<g<<endl;
	vector<Bateau> bat1 = g.get_bat();
	cout<< "bat = ";
	for (Bateau boat: bat1){
    	cout << boat << ' ';}
	Bateau b(5, 3, 5, 7, 5); //(startx=3, starty=5); (endx=7, endy=5)
	cout<<endl<<"taille b = "<<b.size();

	//test placer

	g.placer(b);
	cout<<endl<<"New g = "<<endl<<g<<endl;
	bat1 = g.get_bat();
	cout<< "New bat = ";
	for (Bateau boat: bat1){
    	cout << boat << ' ';}

	//test get_allcoord
	vector<vector<int>> allcoord = b.get_allcoord();
	cout<<"Coord de b : ";
	for (vector<int> couple: allcoord){
		cout << " " << "("<<couple[0]<<", "<< couple[1]<<")";}

}