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


//methodes
bool BatailleNavale::test_coord_tir (const GrilleJeu& player_rival, int x, int y) const{
    //tests sur les coordonnees :
    //condgrid : teste coord dans la grille
    bool condgrid = (x > -1 && x < 10) && (y > -1 && y < 10);

    //conduntouched : teste si c'est une case non touchee
    bool conduntouched = false;
    if (condgrid){
        conduntouched = (player_rival(x, y) == 4);
    }
    return condgrid && conduntouched;
}

bool BatailleNavale::test_coord_prepare(const GrilleDepart &player_self, int start_x, int start_y, int end_x, int end_y, int size_boat) const{
    //tests sur les coordonnees :
    //condgrid : teste coord dans la grille
    bool condgrid = (start_x > -1 && start_x < 10) && (end_x > -1 && end_x < 10) && (start_y > -1 && start_y < 10) && (end_y > -1 && end_y < 10);

    //condshape : teste la forme du bateau (horizontal ou vertical)
    bool condshape = start_x == end_x || start_y == end_y;

    //condsize : teste taille bateau
    int longueur;
    if(start_x == end_x){longueur = abs(end_y - start_y) +1;}
    else{longueur = abs(start_x - end_x) +1;}
    bool condsize = (longueur == size_boat);

    //conduntouched : teste si c'est une case non touchee
    bool conduntouched = false;
    if (condgrid && condshape && condsize){
        for (int i=start_x; i<=end_x; i++){
            for(int j=start_y; j<=end_y; j++){ 
                conduntouched = (player_self(i, j) == 0);
            }
        }
    }
    return condgrid && condshape && condsize && conduntouched;
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
            if(test_coord_prepare(player1_self, start_x, start_y, end_x, end_y, sizes[i])){
                break;}
        }
        Bateau b(sizes[i], start_x, start_y, end_x, end_y);
        player1_self.placer(b);
        cout << player1_self;
        player2_rival.recupere_bat(player1_self);
    }

    // Setting the ships of IA
    IA ia;
    cout<<"Veuillez patientez, le joueur 2 place ses bateaux ..."<<endl;
    player2_self = ia.preparer_IA();
    player1_rival.recupere_bat(player2_self);
    cout<<"grille IA :"<<endl<<player2_self<<endl;

}

// Turn of player 1
void BatailleNavale::turn(int x, int y, const GrilleDepart &playeri_self, GrilleJeu &playerj_rival){
    switch(playeri_self(x, y)){
        case 0: // water
                cout << "A l'eau !" << endl;
                playerj_rival.actualiser(x, y, playeri_self);
                break;
        case 1: // nouvelle case bateau
                cout << "Touche !" << endl;
                playerj_rival.actualiser(x, y, playeri_self);
                break;
        default: // already touched (2) or sank (3)
            cout << "Case deja touchee !" << endl;
        }
}


void BatailleNavale::jouer(){
    //prepare_game();
    IA ia;
    
    player2_self = ia.preparer_IA();
    cout<<"player2_self ="<<endl<<player2_self<<endl;
    player1_rival.recupere_bat(player2_self);
    cout<<"player1_rival ="<<endl<<player1_rival<<endl;
    pair<int, int> p = ia.level_random(player1_rival);
    turn(p.first, p.second,player2_self,player1_rival);
    cout<<"player1_rival ="<<endl<<player1_rival<<endl;
    //il faut tout changer! bisous
    /* while(true){
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
    } */
    
}

