#include <stdafx.h>
#include "Snake.h"
#include "Food.h"
#include "Part.h"
#include "Coordinate.h"
#include "Board.h"

Board::Board(int w, int h, shared_ptr<Snake> snake)
{
	width_ = w;
	height_ = h;
	
	v_.resize(h, vector<int>(w, 0));
	snake_ = snake;
}

Board::~Board()
{
}

void Board::GenerateFood()
{
	int x = 0;
	int y = 0;

	bool success = false;
	while (!success) {
		x = rand() % width_;
		y = rand() % height_;

		success = true;
		for (auto& part : snake_->GetParts()) {
			if (part->GetCoord()->x_ == x && part->GetCoord()->y_ == y) {
				success = false;
				break;
			}
		}
	}

	food_ = make_shared<Food>(1, make_shared<Coordinate>(x, y));
}

