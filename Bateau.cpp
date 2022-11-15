#include "class.hpp"
#include <cassert>
bool Bateau::couler() const {
	for (int i=0;i<taille;i++){
		if  (vec[i]==0) {
			return false;
		}
	}
	return true;
}


void Bateau::toucher(int x, int y){
	assert( (x>=startx && x<= endx) && (y>= starty && y<= endy) );
	if startx-endx==0 {
		state(y-starty)+=1;
	}
	if starty-endy==0{
		state(x-startx)=+=1;
	}
}

std::ostream& operator<< (std::ostream& o, const Bateau& b){
	for (int i=0;i<b.size();i++){
		o<<b.state(i) <<" ";
	}
	o<<std::endl;
	return o;
}
