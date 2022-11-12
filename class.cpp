#include "class.hpp"

bool Bateau::couler() const {
	for (int i=0;i<taille;i++){
		if  (vec[i]==0) {
			return false;
		}
	}
	return true;
}


std::ostream& operator<< (std::ostream& o, const Bateau& b){
	for (int i=0;i<b.size();i++){
		o<<b.state(i) <<" ";
	}
	o<<std::endl;
	return o;
}
