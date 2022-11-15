#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;

class BatailleNaval{
	private:
		Grille player1_self, player1_rival, player2_self, player2_rival;
		
		void turn(Grille player, int x, int y);

		void prepare_game();
	public:
		BatailleNaval();

		BatailleNaval(Grille play1_s, Grille play1_r, Grille play2_s, Grille play2_r);

		Grille jouer();
		
}
