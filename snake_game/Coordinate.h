#pragma once

class Coordinate
{
public:
	Coordinate(int x, int y);
	~Coordinate();

	bool operator== (const Coordinate& other) const {
		return x_ == other.x_ && y_ == other.y_;
	}

	int x_;
	int y_;
};