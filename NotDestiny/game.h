#pragma once


class Tile
{
private:
	int x;
	int value;
public:
	Tile(int x, int value);

	int GetId(int x);
	void ValueFromCoord(int x, int value);

};