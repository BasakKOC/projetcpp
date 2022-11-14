#include "Grille.hpp"
#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){
	
	Grille g;
	cout<<"g="<<endl<<g<<endl;
    cout<<"g="<<g.elem(1,1)<<endl;
	g(1,1)=1;
	cout<<"g="<<g(1,1)<<endl;
}