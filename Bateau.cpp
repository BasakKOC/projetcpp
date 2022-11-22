#include "Bateau.hpp"
#include <cassert>
#include <iostream>

//cobstructeur
Bateau::Bateau(int n,int startx_, int starty_,int endx_,int endy_) : 
	vec(n,0), startx(startx_), starty(starty_), endx(endx_), endy(endy_){
	//assert(n ...)// a faire 
	taille=n;
}


bool Bateau::couler() const {
	for (int i=0;i<taille;i++){
		if  (vec[i]==0) {
			return false;
		}
	}
	return true;
}


bool Bateau::toucher(int x, int y){
	if ( (x>=startx && x<= endx) && (y>= starty && y<= endy) ){
		if (startx==endx){
			state(y-starty)+=1;
		}
		if (starty==endy){
			state(x-startx)+=1;
		}
		return true;
	}
	return false;
}

std::ostream& operator<< (std::ostream& o, const Bateau& b){
	for (int i=0;i<b.size();i++){
		o<<b.state(i) <<" ";
	}
	o<<std::endl;
	return o;
}
