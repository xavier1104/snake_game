#pragma once

class Coordinate;
class Food
{
public:
	Food(int score, shared_ptr<Coordinate> coord);
	~Food();

	shared_ptr<Coordinate> GetCoord() { return coord_; }
	int GetScore() { return score_; }
private:
	int score_;
	shared_ptr<Coordinate> coord_;
};