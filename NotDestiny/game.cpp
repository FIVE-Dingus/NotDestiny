#include "game.h";
#include <iostream>;
#include <vector>;
#include "grid.h";


Tile::Tile(int x, int value) {
	this->x = x;
	this->value = value;
};
int Tile::GetId(int x) {
	return x;
};

int Tile::ValueFromId(int x, int value) {
	return value;
};
