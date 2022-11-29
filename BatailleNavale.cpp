#include "Grille.hpp"
#include "Bateau.hpp"
#include "BatailleNavale.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <string>

using std::string;
using std::cout;
using std::endl;


BatailleNavale::BatailleNavale(){
    player1_self = GrilleDepart();      // Grille of player 
    player1_rival = GrilleJeu();        // Grille of AI from player's perspective
    player2_self = GrilleDepart();      // Grille of AI
    player2_rival = GrilleJeu();        // Grille of player from AI's perspective
}


// Turn of player 1
void BatailleNavale::turn_1(int x, int y){
    switch(player2_self(x, y)){
        case 0: // water
                cout << "Oh, no! Nothing there. Good luck the next time." << endl;
                break;
        case 1: // untouched
            player1_rival.actualiser(x, y, player2_self);
            // *update1 for player2_self and player1_rival: touch the ship (2)*
            // *update2 for player2_self and player1_rival: if necessary, sink the ship (3)*
                break;
        default: // already touched (2) or sank (3)
            cout << "Cmon! Do not repeat movements." << endl;
    }
}


// Turn of AI
void BatailleNavale::turn_2(int x, int y){ // nothing happens for: water (0), already touched (2) or sank (3) - note: AI should not repeat movements
    if(player1_self(x, y) == 1) { // untouched
            player2_rival.actualiser(x, y, player1_self);
            // *update1 for player1_self and player2_rival: touch the ship (2)*
            // *update2 for player1_self and player2_rival: if necessary, sink the ship (3)*
    }
}


void BatailleNavale::prepare_game(){
    int start_x, end_x, start_y, end_y;
    int sizes [7] = {5, 4, 3, 3, 3, 2, 2};
    string ships [7] = {"porte-avion", "croiseur", "first contre-torpilleur", "second contre-torpilleur", 
                        "third contre-torpilleur", "first torpilleur", "second torpilleur"};

    // Setting the ships of Player 1
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        cout << "Player 1! Please, type the " << ships[i] << " coordinates (size " << sizes[i] << ")." << endl;
        cout << "Respect this order: start_x, end_x, start_y, end_y." << endl;
        cin >> start_x; 
        cin >> end_x; 
        cin >> start_y; 
        cin >> end_y;
        assert((start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10));
        player1_self.placer(new Bateau (sizes[i], start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);
    }

    // Setting the ships of AI (random)
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        srand (time(NULL));
        start_x = rand() % 9;
        end_x = rand() % 9;
        start_y = rand() % 9;
        end_y = rand() % 9;
        player2_self.placer(new Bateau (sizes[i], start_x, start_y, end_x, end_y), start_x, start_y, end_x, end_y);
    }
}

	
Grille BatailleNavale::jouer(){
    prepare_game();

    while(true){
         // Turn of player 1
        cout << "TURN OF PLAYER 1" << endl;
        cout << player1_rival << endl;
        int movement1_row, movement1_column;
        cout << "Player 1! Please, type the row." << endl;
        cin >> movement1_row; 
        cout << "Player 1! Please, type the column." << endl;
        cin >> movement1_column;
        assert((movement1_row > -1 && movement1_row < 10) && (movement1_column > -1 && movement1_column < 10));
        turn_1(movement1_row, movement1_column); 
        cout << player1_rival << endl;
		
        if(player2_rival.fin_bat()){ 
            cout << "YOU WIN!" << endl;
            break;
        }
				
        // Turn of AI
        cout << "TURN OF PLAYER 2" << endl;
        cout << player2_rival << endl;
        srand (time(NULL));
        int movement2_row = rand() % 9;
        int movement2_column = rand() % 9;
        turn_2(movement2_row, movement2_column); 
        cout << player2_rival << endl;
		
        if (player1_rival.fin_bat()){ 
            cout << "YOU LOSE!" << endl;
            break; 
        }
    }
}



// NOTES
// each player object has grid[i][j]. ex: player1_self(i, j)
// test file: create un object BatailleNaval and call jouer()
