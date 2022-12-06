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


class WinException : public exception {
    private:
        char * message;

    public:
        WinException(char * msg) : message(msg) {}
        char * what () {
            return message;
        }
};



