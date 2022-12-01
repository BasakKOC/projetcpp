#include "Bateau.hpp"
#include <iostream>

using namespace std;

int main(){

	int n=4;

	Bateau b(n,1,1,4,1);
	//~ cout<<b.size()<<std::endl;
	//~ cout<<b.state(0)<<std::endl;
	//~ cout<<b.state(0)<<std::endl;
	//~ cout<<b;
	//~ cout<<b.couler()<<std::endl;
	//~ b.state(1)+=1;
	//~ b.state(2)+=1;
	//~ cout << b.couler()<<std::endl;
	//cout<<b.toucher(1,1)<<std::endl;
	
	cout<<b<<std::endl;
    b.state(0)+=1;
    Bateau b1(b);
    b1.state(0)+=1;
    cout<<std::endl<<b<<std::endl;
	return 0;
}
