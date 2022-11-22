#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;

class BatailleNavale{
	private:
		Grille player1_self, player1_rival, player2_self, player2_rival;
		
		void turn_1(int x, int y);
		
		void turn_2(int x, int y);

		void prepare_game();
	public:
		BatailleNaval();

		Grille jouer();
		
}
