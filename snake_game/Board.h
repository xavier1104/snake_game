#pragma once

class Snake;
class Food;
class Board
{
public:
	Board(int w, int h, shared_ptr<Snake> snake);
	~Board();

	void GenerateFood();

private:
	int width_;
	int height_;
	
	vector<vector<int>> v_;
	shared_ptr<Snake> snake_;
	shared_ptr<Food> food_;
};