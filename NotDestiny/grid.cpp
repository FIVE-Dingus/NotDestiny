#include "grid.h";
using namespace std;

Grid::void printarray(int arg[], int length) {
    for (int n = 0; n < length; ++n)
        cout << arg[n] << ' ';
    cout << '\n';
}