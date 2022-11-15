#include "Grille.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include "class.hpp"

using std::cout;
using std::endl;
using std::vector;

int main(){
	
	Grille g;
	cout<<"g="<<endl<<g<<endl;
    cout<<"g="<<g.elem(1,1)<<endl;
	cout<<"g(1,1)="<<g(1,1)<<endl;
	Bateau b(2);
	cout<<b;
}