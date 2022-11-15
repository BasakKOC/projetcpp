#include <vector>
#include <cassert>
#include <iostream>

#ifndef CLASSBATAILLENAVALE_BATEAU
#define CLASSBATAILLENAVALE_BATEAU

class Bateau{
	private:
	int taille;
	std::vector<int> vec;  //garde en memoire letat du bateau
	
	public:
	//constructeur
	Bateau(int n) : taille(n), vec(n,0) {}
	
	//accesseurs et mutateurs
	int size() const {return taille;}
	int state(int i) const {assert (i<taille); return vec[i];}  // ou le faire avec loperateur [] si vous preferer
	int& state(int i) {assert(i<taille);return vec[i];}
	
	//autres methodes
	bool couler() const ;
	// ajouter une methode qui fait +1 a la case correspondante lorsque la ieme case du bateau est touché ? 
	
	//affichage temporaire
	friend std::ostream& operator << (std::ostream &, const Bateau&);
};


//~ class Porte_avion : public Bateau{
	//~ private:
	//~ int taille = 5;
	//~ public:
	//~ Porte_avion();
//~ };

//~ class Croiseur : public Bateau{
	//~ private: 
	//~ int taille = 4;
	//~ public:
	//~ Croiseur();
//~ };

//~ class Contre_torpilleur : public Bateau{
	//~ private:
	//~ int taille = 3;
	//~ public:
	//~ Contre_torpilleur
//~ };

//~ class Torpilleur : public Bateau {
	//~ private:
	//~ int taille = 2;
//~ };
/* rajouter 4 classes filles pour chaque type de bateau :
	1 Porte-avions (5 cases) ;
    1 Croiseur (4 cases) ;
    2 Contre-torpilleurs (3 cases) ;
    1 Torpilleur (2 cases). */ 

	/* rajourter qqpart une methode nb_coule qui renvoie 
	le nb de bateaux coules pour arreter le jeu */
	
#endif
