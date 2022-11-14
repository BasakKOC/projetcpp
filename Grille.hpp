#include <iostream>
#include <cassert>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#ifndef GRILLEHEADERDEF
#define GRILLEHEADERDEF

class Grille{
private:
    vector<vector<int>> grid;

public:
    //constructeurs
    Grille ();
    
    Grille(const Grille &g);

    //getter
    int elem(int i, int j) const {assert(i>=0 && i<10 && j>=0 && j<10); return grid[i][j];}

    //operateurs
    double operator() (int i,int j) const { //retourne grid[i][j]
        assert(i>=0 && i<10 && j>=0 && j<10);
        return grid[i][j];}

    friend std::ostream& operator<<(std::ostream& out, const Grille &g);

   /*  double& operator()(int i, int j) { //version grille non constante
        assert(i>=0 && i<=10 && j>=0 && j<=10);
        return grid[i][j];}
 */
};

#endif