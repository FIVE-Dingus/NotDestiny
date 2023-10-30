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
	std::cout << "\n";
	std::cout << "---------------------------------------\n";
	std::cout << "\n";
	for (int i = 0; i < this->sizeMax; i++) {
		if (i % this->sizeY == 0 && i != 0) 
		{
			std::cout << " ° \n\n";
		}
		if (tab[i] < 10) {
			std::cout << "  |  " << this->tab[i] << "  |  ";
		} else if (tab[i] < 100) {
			std::cout << "  |  " << this->tab[i] << "  | ";
		} else if (tab[i] < 1000) {
			std::cout << "  | " << this->tab[i] << " |  ";
		} else if (tab[i] < 10000) {
			std::cout << "  | " << this->tab[i] << " | ";
		}
	}
	std::cout << " ° \n\n";
	std::cout << "---------------------------------------\n";
};

void Grid::randomTile() {
	// sa génère des nombres aléatoires 
	std::random_device rd;  
	std::mt19937 gen(rd()); 

	// Distribue les indices aléatoirement
	std::uniform_int_distribution<int> distribution(0, sizeMax - 1); 

	// Variable int emptyCells
	int emptyCells = 0;
	for (int i = 0; i < sizeMax; i++) {
		if (tab[i] == 0) {
			emptyCells++;
		}
	}
	
	// si aucune cellule est vide, alors aucunes tuiles aléatoire ne peut être placée.
	if (emptyCells == 0) {
		return;
	}
	// Sa génère un indice aléatoire
	int randomIndex = distribution(gen); 

	// Trouve un index vide
	while (tab[randomIndex] != 0) {
		randomIndex = distribution(gen); 
	}
	// Variable de probabilité : générer aléatoirement 2 avec 90% de chance ou 4 avec 10% de chance.
	int value = (rand() % 100 < 90) ? 2 : 4; 
	tab[randomIndex] = value;

}

void Grid::move(int x) {
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
		for (int i = 0; i < 4; i++) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 1; y < 4; y++)
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
		for (int i = 4; i < 8; i++) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 1; y < 8; y++)
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
		for (int i = 8; i < 12; i++) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 1; y < 12; y++)
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
		for (int i = 12; i < 16; i++) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 1; y < 16; y++)
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
		for (int i = 12; i >= 4; i-=4) {
				if (tab[i] == 0)
				{
					int current = tab[i];
					int other = current;
					int index = i;
					for (int y = i - 4; y >= 0; y-=4)
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
		for (int i = 13; i >= 5; i -= 4) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 4; y >= 1; y -= 4)
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
		for (int i = 14; i >= 6; i -= 4) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 4; y >= 2; y -= 4)
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
		for (int i = 15; i >= 7; i -= 4) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i - 4; y >= 3; y -= 4)
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
		for (int i = 0; i < 12; i+=4) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 4; y <=12 ; y+=4)
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
		for (int i = 1; i < 13; i+=4) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 4; y <= 13; y+=4)
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
		for (int i = 2; i < 14; i += 4) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 4; y <= 14; y += 4)
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
		for (int i = 3; i < 15; i += 4) {
			if (tab[i] == 0)
			{
				int current = tab[i];
				int other = current;
				int index = i;
				for (int y = i + 4; y <= 15; y += 4)
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
	else if (x == 2) {
		for (int i = 0; i < 4; i++) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i + 1; y < 4; y++)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 4; i < 8; i++) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i + 1; y < 8; y++)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 8; i < 12; i++) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i + 1; y < 12; y++)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 12 ; i < 16; i++) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i + 1; y < 16; y++)
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
	else if (x == 3) {
		for (int i = 12; i >= 4; i -= 4) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 4; y >= 0; y -=4 )
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 13; i >= 5; i -= 4) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 4; y >= 1; y -= 4)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 14; i >= 6; i -= 4) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 4; y >= 2; y -= 4)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}

		}
		for (int i = 15; i >= 7; i -= 4) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i - 4; y >= 3; y -= 4)
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
	else if (x == 4) {
		for (int i = 0; i < 12; i += 4) {
			int current = tab[i];
			int other = current;
			int index = i;
			if (tab[i] != 0) {
				for (int y = i + 4; y <= 12; y += 4)
				{
					if (tab[y] == current) {
						tab[i] = tab[y] * 2;
						tab[y] = 0;
						break;
					}
				}

			}
			for (int i = 1; i < 13; i += 4) {
				int current = tab[i];
				int other = current;
				int index = i;
				if (tab[i] != 0) {
					for (int y = i + 4; y <= 13; y += 4)
					{
						if (tab[y] == current) {
							tab[i] = tab[y] * 2;
							tab[y] = 0;
							break;
						}
					}

				}

			}
			for (int i = 2; i < 14; i += 4) {
				int current = tab[i];
				int other = current;
				int index = i;
				if (tab[i] != 0) {
					for (int y = i + 4; y <= 14; y += 4)
					{
						if (tab[y] == current) {
							tab[i] = tab[y] * 2;
							tab[y] = 0;
							break;
						}
					}

				}

			}
			for (int i = 3; i < 15; i += 4) {
				int current = tab[i];
				int other = current;
				int index = i;
				if (tab[i] != 0) {
					for (int y = i + 4; y <= 15; y += 4)
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
	}
};

int Grid::result() {
	int emptyCells = 0;
	for (int i = 0; i < sizeMax; i++) {
		if (tab[i] == 2048) {
			return 1;
		}
		else if (tab[i] == 0) {
			emptyCells++;
		}
	}

	// si aucune cellule est vide, alors aucunes tuiles aléatoire ne peut être placée.
	if (emptyCells == 0) {
		std::vector<int> copyTab = tab;
		this->fusion(1);
		this->fusion(2);
		this->fusion(3);
		this->fusion(4);
		if (copyTab == tab) {
			return 2;
		}
		else {
			tab = copyTab;
			return 0;
		}
	}
}