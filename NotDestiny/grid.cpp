#include <iostream>
#include <vector>
#include <random>
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
};

void Grid::tile() {
	this->changeValueWithCoordinates(1,1, 2);

	this->changeValueWithCoordinates(2, 1, 2);
}

int Grid::value(int x, int y) {
	int id = getIdfromCoorinates(x, y);
	int valeur = this->tab[id - 1];
	

	return valeur;
}

void Grid::moov(int x) {
	if (x == 1) {
		for (int i = 4 - 1; i > 0; i--) {
			if (tab[i] == 0) 
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 1; y >= 0; y--)
				{
					if (tab[y] != 0) {
						other = tab[y];
						index = y;

						tab[i] = other;
						tab[index] = 0;
						break;
					}
				}
			}
		}
		for (int i = 8 - 1; i > 4; i--) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 1; y >= 4; y--)
				{
					if (tab[y] != 0) {
						other = tab[y];
						index = y;

						tab[i] = other;
						tab[index] = 0;
						break;
					}
				}
			}
		}
		for (int i = 12 - 1; i > 8; i--) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 1; y >= 8; y--)
				{
					if (tab[y] != 0) {
						other = tab[y];
						index = y;

						tab[i] = other;
						tab[index] = 0;
						break;
					}
				}
			}
		}
		for (int i = 16 - 1; i > 12; i--) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 1; y >= 12; y--)
				{
					if (tab[y] != 0) {
						other = tab[y];
						index = y;

						tab[i] = other;
						tab[index] = 0;
						break;
					}
				}
			}
		}
	}
	if (x == 2) {
		for (int i = 4 - 1; i > 0; i--) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 1; y >= 0; y--)
				{
					if (tab[y] != 0) {
						other = tab[y];
						index = y;

						tab[i] = other;
						tab[index] = 0;
						break;
					}
				}
			}
		}
	}
	if (x == 3) {
		for (int i = 4 - 1; i > 0; i--) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 1; y >= 0; y--)
				{
					if (tab[y] != 0) {
						other = tab[y];
						index = y;

						tab[i] = other;
						tab[index] = 0;
						break;
					}
				}
			}
		}
	}
	if (x == 4) {
		for (int i = 4 - 1; i > 0; i--) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 1; y >= 0; y--)
				{
					if (tab[y] != 0) {
						other = tab[y];
						index = y;

						tab[i] = other;
						tab[index] = 0;
						break;
					}
				}
			}
		}
	}
};

void Grid::fusion(int x) {
	if (x == 1) {
		for (int i = 4 - 1; i > 0; i--) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 1; y >= 0; y--)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}
				
			}

		}
		for (int i = 8 - 1; i > 4; i--) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 1; y >= 4; y--)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 12 - 1; i > 8; i--) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 1; y >= 8; y--)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 16 - 1; i > 12; i--) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 1; y >= 12; y--)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
	}
};

/* 
void generateRandomValue(std::vector<std::vector<int>>& grid) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(0, grid.size() - 1);
	int randomRow = distribution(gen);
	int randomCol = distribution(gen);

	// sa générer aléatoirement un 2 ou un 4 
	int value = (std::rand() % 10 == 0) ? 4 : 2;

	grid[randomRow][randomCol] = value;
}
*/