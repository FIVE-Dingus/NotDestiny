#pragma once

class Grid
{
public:
    Grid::int fistarray[] = { 0,0,0,0 };
    Grid::int secarray[] = { 0,0,0,0 };
    Grid::printarray(fistarray, 4);
    Grid::printarray(secarray, 4);

private:

};

Grid::Grid()
{
}

Grid::~Grid()
{
}
	void printarray(int arg[], int length);