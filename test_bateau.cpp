#include "class.hpp"
#include <iostream>

using namespace std;

int main(){
	
	int n=3;
	
	Bateau b(n);
	cout<<b;
	cout<<b.size()<<std::endl;
	cout<<b.state(0)<<std::endl;
	b.state(0)+=1;
	cout<<b.state(0)<<std::endl;
	cout<<b;
	cout<<b.couler()<<std::endl;
	b.state(1)+=1;
	b.state(2)+=1;
	cout << b.couler()<<std::endl;
	return 0;
}
