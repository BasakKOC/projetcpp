#include "BatailleNavale.hpp"
#include "Grille.hpp"
#include "Bateau.hpp"
#include "IA.hpp"

using std::cout;
using std::endl;
using std::vector;

int main(){
    BatailleNavale bataille;

    //Tests methodes privees
    test_BatailleNavale(bataille);

    // Test jouer
    bataille.jouer();

    return 0;
}