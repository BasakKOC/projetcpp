# Projet CPP : Bataille Navale

### Affichage grille :
0 : case eau, 1 : case bateau intact, 2 : case bateau touché <br />
3 : coulé, 4 : inconnu (pour le joueur)

## To do list :

#### Semaine 27 novembre 2022 :
- Faire l'exception

## Liste des fonctions :
#### Grille :
- get_bat() : t=renvoie le vecteurs contenant les bateau de la grille
- operateur () pour acceder a la grille
- gametocoord(char col,int ligne) : /transforme une coordonnee lettre en int compris entre 0 et 10

#### GrilleDepart:
- placer(bateau) : place un bateau sur la grille

#### GrilleJeu:
- recupere_bat(grilleDepart) : recupere le vecteur bateau et le recopie dans celui de la grille jeu
- actualiser(int,int,grilleDepart) : met a jour la grille ainsi que le vecteur bateau, renvoie un bool true si un bateau a ete touv=che ou coule (/!\ il faut utiliser recupere_bat avant d'appeler actualiser une 1ere fois !)
- fin_bat() : bool qui indique si tout les bateau ont ete coule ou pas
- affiche() : affichage sans chiffre
 
#### Bateau :
- constructeur(taille, startx, starty,endx,endy)
- size() : renvoie la taille
- state(int i) : setter et getter du vecteur bateau
- get_y_start() : les getters des positions x et y
- get_allcoord() : coordonnees de tous les points dun bateau
- couler() : renvoie true ou false selon si le bateau est coulé ou pas
- toucher() : change le vecteur bateau
- affichage avec <<

#### IA :
- coord_bateau(int size) : choisist aléatoirement les coord d'un bateau de taille size
- preparer_IA() : grille depar de l'IA
- level_random(GrilleJeu) : choisit des coord aléatoirement que l'IA peut jouer aleatoirement

#### BatailleNavale :
- prepare_game() : initlaise les grilles du joueur 1 et de l'IA
- test_coord_prepare(GrilleDepart, 4 int, taillebateau) : teste validités coordonnées pour prepare_game du joueur 1.
- test_coord_tir(GrilleJeu, int, int) : test validité coordonnées de tir entrées par la joueur 1 (teste si c'est dans la grille et si il l'a pas déjà touchée)
- turn(x, y, GrilleDepart self, GrilleJeu rival) : retourne un booleen (touche ou non) et actualise la grille jeu rivale
- jouer() : fonction principale qui fait tourner la partie

#### Change in BatailleNavale :

if(player2_rival.fin_bat()) {
    try {
        throw WinException("YOU WIN!");
    } catch (WinException win) {
        cout << "Tu as coulé tous mes bateaux..." << endl;
        cout << win.what() << endl;
    }  
}


if (player1_rival.fin_bat()) {
    try {
        throw LoseException("YOU LOSE!");
    } catch (LoseException los) {
        cout << "J'ai coulé tous tes bateaux..." << endl;
        cout << los.what() << endl;
    }
}
