#include <iostream>
#include <vector>
#include "grid.h";

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
		std::cout << " | " << this->tab[i] << " | ";
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

void Grid::tile() {
	this->changeValueWithCoordinates(1, 2, 2);
	this->changeValueWithCoordinates(1, 4, 2);
}

int Grid::value(int x, int y) {
	int id = getIdfromCoorinates(x, y);
	int valeur = this->tab[id - 1];
	

	return valeur;
}

int Grid::fusion(int x,int y) {

	for (int i = 4 - 1; i > 0; i--) {
		int current = tab[i];
		int other = current;
		int index = i;
		for (int y = i - 1; y >= 0; y--)
		{
			if (tab[y] != 0) {
				other = tab[y];
				index = y;
			}
		}
		tab[i] = other;
		tab[index] = current;

	}
	for (int i = 0; i < 4; i++) {
		printf("%d", tab[i]);
	}
};
