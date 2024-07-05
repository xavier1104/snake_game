#include <stdafx.h>
#include "Head.h"
#include "Body.h"
#include "Coordinate.h"
#include "Snake.h"

Snake::Snake()
{
	shared_ptr<Head> head = make_shared<Head>(make_shared<Coordinate>(2, 1));
	shared_ptr<Body> body = make_shared<Body>(make_shared<Coordinate>(1, 1));
	
	parts_.emplace_back(head);
	parts_.emplace_back(body);
}

Snake::~Snake()
{
}
