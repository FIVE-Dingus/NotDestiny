#include "game.h";
#include <iostream>;
#include <vector>;
#include "grid.h";


Tile::Tile(int x, int value) {
	this->x = x;
	this->value = value;
};
/*int Tile::GetId(int x) {
	
};

void Tile::ValueFromCoord(int x, int value) {

};*/

Grid::Grid(int x, int y) {
	this->sizeX = x;
	this->sizeY = y;
	this->sizeMax = this->sizeX * this->sizeY;
	for (int i = 0; i < this->sizeY; i++) {
		for (int j = 0; j < this->sizeX; j++) {
			this->tab.push_back(0);
		}
	}
};

void Grid::display() {
	for (int i = 0; i < this->sizeMax; i++) {
		if (i % this->sizeY == 0 && i != 0)
		{
			std::cout << " | \n";
		}
		std::cout << " | " << this->tab[i];
	}
	std::cout << " | \n\n";
};

int Grid::getIdfromCoorinates(int x, int y) {
	int id = (x - 1) * this->sizeX + y;
	return id;
};

void Grid::changeValueWithCoordinates(int x, int y, int value) {
	int id = this->getIdfromCoorinates(x, y);
	this->tab[id - 1] = value;
	this->display();
};
