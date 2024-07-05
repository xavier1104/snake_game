#pragma once

class Coordinate;
class Food
{
public:
	Food(int score, shared_ptr<Coordinate> coord);
	~Food();

private:
	int score_;
	shared_ptr<Coordinate> coord_;
};