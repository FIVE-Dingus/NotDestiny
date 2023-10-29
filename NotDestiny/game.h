#pragma once

//structure de la classe Tile
class Tile
{
private:
	int x;
	int value;
public:
	Tile(int x, int value);

	int GetId(int x);
	int ValueFromId(int x, int value);

};