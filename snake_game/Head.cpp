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
