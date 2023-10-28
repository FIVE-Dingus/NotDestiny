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
    int getIdfromCoorinates(int x, int y);
    void changeValueWithCoordinates(int x, int y, int value);
    void tile();
    int value(int x, int y);
    void move(int x);
    void fusion(int x);

};