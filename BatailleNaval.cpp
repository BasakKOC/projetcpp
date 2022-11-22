#include "Grille.hpp"
#include "Bateau.hpp"
#include "BatailleNaval.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;



	//questions a poser : que represente x et y
		void BatailleNaval::turn(Grille player, int x, int y){
			// case eau
			if(player == player2_self && player2_self(x, y) == 0){
				// player 1, nothing
			}
			if(player == player1_self && player2_self(x, y) == 0){
				// player 2, nothing
			}
			
			// case on touche
			if(player == player2_self && player2_self(x, y) == 1){
				player2_rival(x, y) = 2;
				player1_self(x, y) = 2;
			}
			if(player == player2_self && player2_self(x, y) == 1){
				player1_rival(x, y) = 2;
				player2_self(x, y) = 2;
			}	
		}
// dans prepare game je crois que la verification des coordonnees est faite dans placer bateau et bateau ?? a verifier  !!!!!!!!
		void BatailleNaval::prepare_game(){
			// Setting the ships of Player 1
			int start_x, end_x, start_y, end_y;
			cout << "Player 1! Please, type the porte-avion coordinates (size 5)." << endl;
			cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
			cin >> start_x; 
			cin >> end_x; 
			cin >> start_y; 
			cin >> end_y;
			assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
			player1_self.placer(new Bateau (5, start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);
			
			cout << "Player 1! Please, type the croiseur coordinates (size 4)." << endl;
			cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
			cin >> start_x; 
			cin >> end_x; 
			cin >> start_y; 
			cin >> end_y;
			assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
			player1_self.placer(new Bateau (4, start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);

			cout << "Player 1! Please, type the first contre-torpilleur coordinates (size 3)." << endl;
			cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
			cin >> start_x; 
			cin >> end_x; 
			cin >> start_y; 
			cin >> end_y;
			assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
			player1_self.placer(new Bateau (3, start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);

			cout << "Player 1! Please, type the second contre-torpilleur coordinates (size 3)." << endl;
			cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
			cin >> start_x; 
			cin >> end_x; 
			cin >> start_y; 
			cin >> end_y;
			assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
			player1_self.placer(new Bateau (3, start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);

			cout << "Player 1! Please, type the third contre-torpilleur coordinates (size 3)." << endl;
			cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
			cin >> start_x; 
			cin >> end_x; 
			cin >> start_y; 
			cin >> end_y;
			assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
			player1_self.placer(new Bateau (3, start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);

			cout << "Player 1! Please, type the first torpilleur coordinates (size 2)." << endl;
			cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
			cin >> start_x; 
			cin >> end_x; 
			cin >> start_y; 
			cin >> end_y;
			assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
			player1_self.placer(new Bateau (2, start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);

			cout << "Player 1! Please, type the second torpilleur coordinates (size 2)." << endl;
			cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
			cin >> start_x; 
			cin >> end_x; 
			cin >> start_y; 
			cin >> end_y;
			assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
			player1_self.placer(new Bateau (2, start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);

			// Setting the ships of Player 2 (default or random)
			...
		}
//reflechir sur les constructeurs : juste par defaut ca devrait suffir
//celui avec les grilles : ??
		BatailleNaval::BatailleNaval();

		BatailleNaval::BatailleNaval(Grille play1_s, Grille play1_r, Grille play2_s, Grille play2_r){
			player1_self = play1_s; // Grille of player 1
			player1_rival = play1_r; // Grille of player 2 from player 1 perspective
			player2_self = play2_s; // Grille of player 2
			player2_rival = play2_r; // Grille of player 1 from player 2 perspective
		}

		Grille BatailleNaval::jouer(){
			prepare_game();

			while(true){
				int movement1_row, movement1_column;
				cout << "Player 1! Please, type the row." << endl;
				cin >> movement1_row; 
				cout << "Player 1! Please, type the column." << endl;
				cin >> movement1_column;
				assert((movement1_row > -1 && movement1_row < 10) && (movement1_column > -1 && movement1_column < 10)); //idem ca doit surement etre verifie ailleurs a verifier
				turn(player2_self, movement1_row, movement1_column); // turn of player 1

				if(player 2 has no ships){
					break;
				}
				
				srand (time(NULL));
				int movement2_row = rand() % 9; //demander cest quoi le %9
				int movement2_column = rand() % 9;
				turn(player1_self, movement2_row, movement2_column); // turn of player 2

				if (player 1 has no ships){
					break; 
				}
			}
		}


// NOTES
// each player object has grid[i][j]. ex: player1_self(i, j)
// test file: create un object BatailleNaval and call jouer()
