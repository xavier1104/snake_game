#pragma once

#include "Part.h"

class Body : public Part
{
public:
	Body(shared_ptr<Coordinate> _coord);
	~Body();

	void Move(shared_ptr<Coordinate> _coord) override;
};