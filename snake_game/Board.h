#pragma once

class Snake;
class Food;
class Board
{
public:
	Board(int w, int h, shared_ptr<Snake> snake);
	~Board();

	void GenerateFood();
	shared_ptr<Food> GetFood() { return food_; }
	int GetWidth() { return width_; }
	int GetHeight() { return height_; }

private:
	int width_;
	int height_;
	
	vector<vector<int>> v_;
	shared_ptr<Snake> snake_;
	shared_ptr<Food> food_;
};