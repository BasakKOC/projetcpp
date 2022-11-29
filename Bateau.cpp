#include "Bateau.hpp"
#include <cassert>
#include <iostream>
#include <vector>

//constructeur
Bateau::Bateau(int n,int startx_, int starty_,int endx_,int endy_) : 
	vec(n,0), startx(startx_), starty(starty_), endx(endx_), endy(endy_){
	//assert(n ...)// a faire 
	taille=n;
}

Bateau::Bateau(const Bateau& b){
	taille=b.taille;
	startx=b.startx;
	starty=b.starty;
	endx=b.endx;
	endy=b.endy;
}

//getter
vector<vector<int>> Bateau::get_allcoord() const{
	vector<vector<int>> res; //resulat
	if(startx==endx){
		for (int i=starty; i<=endy; i++){
			vector<int> couple;
			for(int j=startx; j<=endx; j++){
				couple.push_back(j);
				couple.push_back(i);
			}
			res.push_back(couple);}
		return res;
	}

	for (int i=startx; i<=endx; i++){
		vector<int> couple;
        for(int j=starty; j<=endy; j++){
			couple.push_back(i);
			couple.push_back(j);
		}
		res.push_back(couple);
	}
	return res;
}

bool Bateau::couler() const {
	for (int i=0;i<taille;i++){
		if  (vec[i]==0) {
			return false;
		}
	}
	return true;
}

void Bateau::toucher(int x, int y){
	if ( (x>=startx && x<= endx) && (y>= starty && y<= endy) ){
		if (startx==endx){
			state(y-starty)+=1;
		}
		if (starty==endy){
			state(x-startx)+=1;
		}
	}
}

std::ostream& operator<< (std::ostream& o, const Bateau& b){
	for (int i=0;i<b.size();i++){
		o<<b.state(i) <<" ";
	}
	o<<std::endl;
	return o;
}
