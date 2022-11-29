# Projet CPP : Bataille Navale
### Affichage grille :
0 : case eau, 1 : case bateau intact, 2 : case bateau touché <br />
3 : coulé, 4 : inconnu (pour le joueur)

## To do list :

#### Semaine 27 novembre 2022 :
- Finir BatailleNavale : jeu qui marche
- Faire l'exception
- Faire l'IA

#### General :
- Dans placer, empêcher de placer start et end a l'envers
- Faire un operateur = pour les bat dans Grille
- Faire une exception au moment où un bateau est coulé, faire une exception COULE, qui appelera une methode coule qui va remonter le code blabla
- rajouter IA
- rajouter == pour grille

## Liste des fonctions :
#### Grille :
- get_bat() : t=renvoie le vecteurs contenant les bateau de la grille
- operateur () pour acceder a la grille
- gametocoord(char col,int ligne) : /transforme une coordonnee lettre en int compris entre 0 et 10

#### GrilleDepart:
- placer(bateau) : place un bateau sur la grille

#### GrilleJeu:
- recupere_bat(grilleDepart) : recupere le vecteur bateau et le recopie dans celui de la grille jeu
- actualiser(int,int,grilleDepart) : met a jour la grille ainsi que le vecteur bateau, renvoie un bool true si un bateau a ete touv=che ou coule
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

### Done :
- Tester méthode placer de Grille
- coder méthode actualiser() dans GrilleJeu
