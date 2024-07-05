#include <stdafx.h>
#include "Food.h"

Food::Food(int score, shared_ptr<Coordinate> coord)
	:score_(score)
	,coord_(coord)
{
	
}

Food::~Food()
{
}
