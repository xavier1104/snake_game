#include <stdafx.h>
#include "Body.h"

Body::Body(shared_ptr<Coordinate> _coord)
	:Part(_coord)
{
}

Body::~Body()
{
}

void Body::Move(shared_ptr<Coordinate> _coord)
{
	coord_ = _coord;
}
