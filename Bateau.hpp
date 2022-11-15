#include <vector>
#include <cassert>
#include <iostream>

#ifndef CLASSBATAILLENAVALE_BATEAU
#define CLASSBATAILLENAVALE_BATEAU

class Bateau{
	private:
	int taille;
	std::vector<int> vec;  //garde en memoire letat du bateau
	int startx, starty,endx,endy;
	
	//mutateur
	int& set_x_start() {return startx;}
	int& set_y_start() {return starty;}
	int& set_x_end() {return endx;}
	int& set_y_end() {return endy;}
	public:
	//constructeur
	Bateau(int n,int startx_, int starty_,int endx_,int endy_) : taille(n), vec(n,0) ,startx(startx_), starty(starty_),endx(endx_),endy(endy_){}
	
	//accesseurs et mutateurs
	int size() const {return taille;}
	int state(int i) const {assert (i<taille); return vec[i];}  // ou le faire avec loperateur [] si vous preferer
	int& state(int i) {assert(i<taille);return vec[i];}
	
	int get_x_start() const {return startx;}
	int get_y_start() const {return starty;}
	int get_x_end() const {return endx;}
	int get_y_end() const {return endy;}
	
	//autres methodes
	bool couler() const ;
	void toucher(int x,int y);
	
	//affichage temporaire
	friend std::ostream& operator << (std::ostream &, const Bateau&);
};	
#endif
