#include "Grille.hpp"
#include "Bateau.hpp"
#include "BatailleNavale.hpp"
#include "IA.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;


//constructeur
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
                cout << "A l'eau !" << endl;
                player1_rival.actualiser(x, y, player2_self);
                break;
        case 1: // nouvelle case bateau
                cout << "Touche !" << endl;
                player1_rival.actualiser(x, y, player2_self);
                break;
        default: // already touched (2) or sank (3)
            cout << "Case deja touchee !" << endl;
    }
    player1_rival.affiche();
}


// Turn of AI
void BatailleNavale::turn_2(int x, int y){ // nothing happens for: water (0), already touched (2) or sank (3) - note: AI should not repeat movements
    player2_rival.actualiser(x, y, player1_self);
}


void BatailleNavale::prepare_game(){ // 2 - IDEA: CREATE AUX METHOD FOR CHECKING CONDITIONS 
    int start_x, end_x, start_y, end_y;
    int sizes [7] = {5, 4, 3, 3, 3, 2, 2};
    string ships [7] = {"porte-avion", "croiseur", "first contre-torpilleur", "second contre-torpilleur", 
                        "third contre-torpilleur", "first torpilleur", "second torpilleur"};

    // Setting the ships of Player 1 
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {   
        while(true){
            cout << "Player 1! Please, type the " << ships[i] << " coordinates (size " << sizes[i] << ")." << endl;
            cout << "Respect this order: start_x, start_y, end_x, end_y." << endl;
            cin >> start_x;
            cin >> start_y; 
            cin >> end_x; 
            cin >> end_y;
            bool cond1 = (start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10);
            bool cond2 = start_x == end_x || start_y == end_y;
            int longueur;
            if(start_x == end_x){longueur = abs(end_y - start_y) +1;}
            else{longueur = abs(start_x - end_x) +1;}
            bool cond3 = longueur == sizes[i];
            bool cond4;
            for (int i=start_x; i<=end_x; i++){
                for(int j=start_y; j<=end_y; j++){ 
                    cond4 = player1_self(i, j) == 0;
                }
            }
            
            if(cond1 == true && cond2 == true && cond3 == true && cond4 == true){
                break;
            }
        }
        Bateau b1(sizes[i], start_x, start_y, end_x, end_y);
        player1_self.placer(b1);
        cout << player1_self;
        player2_rival.recupere_bat(player1_self);
    }

    // Setting the ships of IA
    IA ia;
    cout<<"Veuillez patientez, le joueur 2 place ses bateaux ..."<<endl;
    player2_self = ia.preparer_IA();
    player1_rival.recupere_bat(player2_self);
    cout<<"grille IA :"<<endl<<player2_self<<endl;
    
    // 1 - TEST this
    //player2_self = player1_self;
    
/*
    // Setting the ships of AI (random) -- NOT WORKING
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        while(true){
            srand (time(NULL));
            start_x = rand() % 9;
            start_y = rand() % 9;
            end_x = rand() % 9;
            end_y = rand() % 9;

            bool cond1 = (start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10);
            bool cond2 = start_x == end_x || start_y == end_y;
            int longueur;
            if(start_x == end_x){longueur = abs(end_y - start_y) +1;}
            else{longueur = abs(start_x - end_x) +1;}
            bool cond3 = longueur == sizes[i];
            
            if(cond1 == true && cond2 == true && cond3 == true){
                break;
            }
        }
        Bateau b2(sizes[i], start_x, start_y, end_x, end_y);
        player2_self.placer(b2);
        cout << player2_self;
    }*/
}


Grille BatailleNavale::jouer(){
    prepare_game();

    while(true){
         // Turn of player 1
        cout << "TURN OF PLAYER 1" << endl;
        //cout << player1_rival << endl;
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

