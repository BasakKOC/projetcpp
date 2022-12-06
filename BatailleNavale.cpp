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
void BatailleNavale::prepare_game_auto(GrilleDepart& gd,GrilleJeu& gj){
    IA ia;
    gd = ia.preparer_IA();
    gj.recupere_bat(gd);
}

void BatailleNavale::prepare_game(){
    int start_x, end_x, start_y, end_y;
    int sizes [7] = {5, 4, 3, 3, 3, 2, 2};
    string ships [7] = {"porte-avion", "croiseur", "premier contre-torpilleur", "deuxieme contre-torpilleur", 
                        "troisieme contre-torpilleur", "premier torpilleur", "deuxieme torpilleur"};

    // Placement bateaux Joueur 1
    
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {   
        while(true){
            player1_rival.affiche();
            cout << "Entrez les 4 coordonnees du " << ships[i] << " (de taille " << sizes[i] << ")." << endl;
            cout << "Respectez cet ordre : ligne 1ere case, colonne 1ere case, ligne derniere case, colonne derniere case." << endl;
            cin >> start_x;
            cin >> start_y; 
            cin >> end_x;
            cin >> end_y;
            if(test_coord_prepare(player1_self, start_x, start_y, end_x, end_y, sizes[i])){
                break;}
        }
        Bateau b(sizes[i], start_x, start_y, end_x, end_y);
        cout<<endl<<"Bateau place avec succes !"<<endl;
        player1_self.placer(b);
        player1_self.affiche_depart();
        player2_rival.recupere_bat(player1_self);
    }

    // Placement bateaux IA
    
    cout<<"Veuillez patientez, je place mes bateaux ..."<<endl<<endl;
    //player2_self = ia.preparer_IA();
    //player1_rival.recupere_bat(player2_self);
    prepare_game_auto(player2_self,player1_rival);
    //cout<<"grille IA :"<<endl<<player2_self<<endl;
    cout<<"C'est bon j'ai fini ! Merci d'avoir patiente !"<<endl<<endl;
}


bool BatailleNavale::turn(int x, int y, const GrilleDepart &playeri_self, GrilleJeu &playerj_rival){
    bool rejouer = playerj_rival.actualiser(x, y, playeri_self);
        if (rejouer){
            cout << endl << "Touche ! Rejouez." << endl << endl;
        }
        else{
            cout<< endl <<"A l'eau !"<<endl<<endl;
        }
    playerj_rival.affiche();

    return rejouer;
}


void BatailleNavale::jouer(){
    IA ia;
    string nom="";
    int tours = 0;

    // Affichage
    cout<<endl<<endl;
    cout<<" _           _   _   _           _     _       "<<endl;
    cout<<"| |         | | | | | |         | |   (_)      "<<endl;
    cout<<"| |__   __ _| |_| |_| | ___  ___| |__  _ _ __  "<<endl;
    cout<<"| '_ \\ / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\ "<<endl;
    cout<<"| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |"<<endl;
    cout<<"|_.__/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/ "<<endl;
    cout<<"                                        | |    "<<endl;
    cout<<"                                        |_|    "<<endl;
    cout<< "o o..          "<<endl;
    cout<<"    o o.o        "<<endl;
    cout<<"     ...oo       "<<endl;
    cout<<"      __||__     "<<endl;
    cout<<"   __|_o_o_o\\__  "<<endl;
    cout<<"   \\''''''''''/  "<<endl;
    cout<<"    \\ ______ /   "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~"<<endl<<endl<<endl;


    cout<<"Entrez votre nom de joueur."<<endl;
    cin>>nom;
    cout<<endl<<endl<<"Bonjour, "<< nom <<" !"<<endl<<endl<< "Je suis l'IA, heureuse de jouer avec vous !"<<endl<<endl<< "Allez, la partie commence !"<<endl<<endl;

    int debut; // variable qui demande au joueur si il veut placer les bateau tout seul ou pas
    cout<<"voulez vous placer vous meme les bateaux ? tapez 0 pour oui, 1 pour generer une grille automatique"<<endl;
    cin>>debut;
    if (debut==1){
        cout<<"Veuillez patienter ..."<<endl<<endl;
        prepare_game_auto(player1_self,player2_rival);
        cout<<"Votre grille est :"<<endl;
        player1_self.affiche_depart();
        cout<<endl;
        cout<<"Veuillez patienter, je place mes bateaux ..."<<endl<<endl;
        prepare_game_auto(player2_self,player1_rival);
        cout<<"C'est bon j'ai fini ! Merci d'avoir patiente !"<<endl<<endl;
    }
    else{prepare_game();}
    

    while(true){ //boucle du jeu
        // Tour du 1er joueur
        cout << endl << "A votre tour " << nom << " !"<< endl <<endl;
        cout << "~~~ TOUR DE "<< nom << " ~~~" << endl;
        player1_rival.affiche();
        int tir1_row, tir1_column;
        while(not player1_rival.fin_bat()){ // boucle du tour joueur 1
            bool rejouer_1 = false; //indique si on rejoue ou non
            while(true){ // boucle d'entree des coordonnees
                cout << nom << " ! Entrez une ligne." << endl;
                cin >> tir1_row; 
                cout << nom << " ! Entrez une colonne." << endl;
                cin >> tir1_column;
                if (test_coord_tir(player1_rival, tir1_row, tir1_column)) { 
                    rejouer_1 = turn(tir1_row, tir1_column, player2_self, player1_rival);
                    tours+=1;
                    break; //arret quand les coordonnees sont bonnes et qu'on a actualise
                }
            }
            if(not rejouer_1){
                int c;
                cout<<"Entrez un chiffre pour continuer"<<endl;
                cin>>c;
                system("clear");
                break; //arret si on est a l'eau
            }
        }
    
        //condition d'arret joueur 1
        if(player1_rival.fin_bat()){ 
            cout << nom << " : WINNER!" << endl << "Nombre de tirs : " <<tours << ". C'est pas mal ! Essayez de faire mieux !"<<endl;
            break; //arret quand le joueur 1 coule tous les bateaux
        }
		
        // Turn of AI
        cout << endl << "A mon tour!" << endl;
        cout << endl << "~~~ TOUR DE L'IA ~~~" << endl;
        bool rejouer_2=false;
        while(not player2_rival.fin_bat()){ //boucle tour IA
            pair<int, int> tir2 = ia.level_random(player2_rival);
            rejouer_2=turn(tir2.first, tir2.second, player1_self, player2_rival);
            if(not rejouer_2){
                int i;
                cout<<"Veuillez tapper un chiffre pour continuer"<<endl;
                cin>>i;
                system("clear");
                break; // arret quand l'IA est l'eau
            }
        }
        
        //condition d'arret IA
        if (player2_rival.fin_bat()){ 
            cout << endl <<"------ GAME OVER :( ------" << endl;
            cout << endl <<"Try again!" << endl;
            break; //arret quand l'IA coule tous les bateaux
        }
    }
    
}

