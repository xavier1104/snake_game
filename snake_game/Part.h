#pragma once

class Coordinate;
class Part
{
public:
	Part(shared_ptr<Coordinate> _coord);
	~Part();

	virtual void Move(shared_ptr<Coordinate> _coord) = 0;
	
	shared_ptr<Coordinate> GetCoord() { return coord_; }
protected:
	shared_ptr<Coordinate> coord_;
};