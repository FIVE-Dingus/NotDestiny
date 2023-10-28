#pragma once
#include <vector>;
#include <iostream>;

class Grid
{
private:
    int sizeX;
    int sizeY;
    int sizeMax;
    std::vector<int> tab;

public:
    Grid(int x, int y);

    void display();
    void randomTile();
    void move(int x);
    void fusion(int x);
    int result();

};