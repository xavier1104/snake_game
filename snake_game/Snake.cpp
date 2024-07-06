#include <stdafx.h>
#include "Head.h"
#include "Body.h"
#include "Coordinate.h"
#include "Snake.h"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::Init()
{
	parts_.clear();

	shared_ptr<Head> head = make_shared<Head>(make_shared<Coordinate>(2, 1));
	shared_ptr<Body> body = make_shared<Body>(make_shared<Coordinate>(1, 1));

	parts_.emplace_back(head);
	parts_.emplace_back(body);
}

shared_ptr<Head> Snake::GetHead()
{
	if (parts_.size() <= 0) {
		return nullptr;
	}

	if (shared_ptr<Head> head = dynamic_pointer_cast<Head>(parts_[0])) {
		return head;
	}

	return nullptr;
}

void Snake::SetDirection(Head::Direction direction)
{
	if (parts_.size() <= 0) {
		return;
	}

	if (shared_ptr<Head> head = dynamic_pointer_cast<Head>(parts_[0])) {
		head->SetDirection(direction);
	}
}

void Snake::Move()
{
	for (int i = (int)parts_.size() - 1; i >= 0; --i) {
		if (i == 0) {
			parts_[i]->Move(nullptr);
		}
		else {
			shared_ptr<Coordinate> coord = parts_[i - 1]->GetCoord();
			parts_[i]->Move(coord);
		}
	}
}

void Snake::EatFood()
{
	if (parts_.size() < 2) {
		return;
	}

	auto& tail = parts_.back();
	auto& beforeTail = parts_[parts_.size() - 2];

	shared_ptr<Coordinate> coord;

	if (tail->GetCoord()->x_ > beforeTail->GetCoord()->x_) {
		coord = make_shared<Coordinate>(tail->GetCoord()->x_ + 1, tail->GetCoord()->y_);
	}
	else if (tail->GetCoord()->x_ < beforeTail->GetCoord()->x_) {
		coord = make_shared<Coordinate>(tail->GetCoord()->x_ - 1, tail->GetCoord()->y_);
		
	}
	else if (tail->GetCoord()->y_ > beforeTail->GetCoord()->y_) {
		coord = make_shared<Coordinate>(tail->GetCoord()->x_, tail->GetCoord()->y_ + 1);
	}
	else if (tail->GetCoord()->y_ < beforeTail->GetCoord()->y_) {
		coord = make_shared<Coordinate>(tail->GetCoord()->x_, tail->GetCoord()->y_ - 1);
	}

	shared_ptr<Body> body = make_shared<Body>(coord);
	parts_.emplace_back(body);
}

