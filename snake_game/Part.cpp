#include <stdafx.h>
#include "Coordinate.h"
#include "Part.h"

Part::Part(shared_ptr<Coordinate> _coord)
	:coord_(_coord)
{
	
}

Part::~Part()
{
}
