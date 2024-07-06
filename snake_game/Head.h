#pragma once

#include "Part.h"

class Coordinate;
class Head : public Part
{
public:
	enum Direction
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

public:
	Head(shared_ptr<Coordinate> _coord);
	~Head();

	void Move(shared_ptr<Coordinate> _coord) override;
	void SetDirection(Direction dir);
private:
	Direction dir_;
};