#include <stdafx.h>
#include "Coordinate.h"
#include "Head.h"

Head::Head(shared_ptr<Coordinate> _coord)
	:Part(_coord)
{
	dir_ = RIGHT;
}

Head::~Head()
{
}

void Head::Move(shared_ptr<Coordinate> _coord)
{
	if (dir_ == UP) {
		coord_->y_ -= 1;
	}
	else if (dir_ == DOWN) {
		coord_->y_ += 1;
	}
	else if (dir_ == LEFT) {
		coord_->x_ -= 1;
	}
	else if (dir_ == RIGHT) {
		coord_->x_ += 1;
	}
}

void Head::SetDirection(Direction dir)
{
	if (dir_ == LEFT && dir == RIGHT) {
		return;
	}

	if (dir_ == RIGHT && dir == LEFT) {
		return;
	}

	if (dir_ == UP && dir == DOWN) {
		return;
	}

	if (dir_ == DOWN && dir == UP) {
		return;
	}

	dir_ = dir;
}
