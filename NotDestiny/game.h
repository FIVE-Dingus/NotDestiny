#pragma once


class Tile
{
private:
	int x;
	int y;
	int value;
public:
	Tile(int x, int y);

	int GetId(int x, int y);
	void ValueFromCoord(int x, int y, int value);

};