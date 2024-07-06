#include <stdafx.h>
#include "Snake.h"
#include "Head.h"
#include "Coordinate.h"
#include "Board.h"
#include "Food.h"
#include "Movement.h"

bool Movement::IsOut(shared_ptr<Snake> snake, shared_ptr<Board> board)
{
	shared_ptr<Head> head = snake->GetHead();
	if (!head) {
		return true;
	}

	shared_ptr<Coordinate> coord = head->GetCoord();
	if (coord->x_ < 0 || coord->x_ >= board->GetWidth()) {
		return true;
	}
	
	if (coord->y_ < 0 || coord->y_ >= board->GetHeight()) {
		return true;
	}

	return false;
}

bool Movement::IsEatFood(shared_ptr<Snake> snake, shared_ptr<Food> food)
{
	shared_ptr<Head> head = snake->GetHead();
	shared_ptr<Coordinate> coordHead = head->GetCoord();
	shared_ptr<Coordinate> coordFood = food->GetCoord();

	return *coordHead == *coordFood;
}

bool Movement::IsHitBody(shared_ptr<Snake> snake)
{
	if (snake->GetParts().size() < 2) {
		return false;
	}

	auto head = snake->GetHead();
	auto parts = snake->GetParts();
	for (int i = 1; i < parts.size() - 1; ++i) {
		if (*head->GetCoord() == *parts[i]->GetCoord()) {
			return true;
		}
	}

	return false;
}
