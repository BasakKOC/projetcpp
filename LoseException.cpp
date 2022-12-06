#include <iostream>
#include "Grille.hpp"
#include "Bateau.hpp"
#include "BatailleNavale.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;
using std::exception;


class LoseException : public exception {
    private:
        char * message;

    public:
        LoseException(char * msg) : message(msg) {}
        char * what () {
            return message;
        }
};



