#include <iostream>
#include "Bateau.hpp"
#include "Grille.hpp"

using std::cout;
using std::endl;

class Exception_ouverture_fichier {
private:
    string name_file;
public:
    Exception_ouverture_fichier(string name) : name_file(name) {}
    string get_name() const {return name_file;}
};
try{
             open_file_ex(argv[1]);
        }
        catch(Exception_ouverture_fichier &ex)
        {
            cout << "erreur d'ouverture du fichier " << ex.get_name() << endl;
            cout << "ecrivez un nouvau nom de fichier (tapez enter pour valider)" << endl;
            string s;
            cin >> s;
            cout << "ouverture du nouveau fichier : " << s << endl;
            open_file_ex(s); // on appelle la fonction d'ouverture avec le nouveau nom de fichier
        }

class Exception_Bateau_Grille {
private:
    Bateau bat_dehors;
public:
    Exception_Bateau_Grille(Bateau b) : bat_dehors(b) {}
};

