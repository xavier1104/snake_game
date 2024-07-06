#include <stdafx.h>
#include "Coordinate.h"
#include "Body.h"

Body::Body(shared_ptr<Coordinate> coord)
	:Part(coord)
{
}

Body::~Body()
{
}

void Body::Move(shared_ptr<Coordinate> coord)
{
	*coord_ = *coord;
}
