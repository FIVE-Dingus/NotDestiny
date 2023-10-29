#pragma once
#include <vector>;
#include <iostream>;
//structure de la classe Grid
class Grid
{
    // methode privé 
private:
    int sizeX;
    int sizeY;
    int sizeMax;
    std::vector<int> tab;

    // methode publique 
public:
    Grid(int x, int y);

    void display();
    void randomTile();
    void move(int x);
    void fusion(int x);
    int result();

};