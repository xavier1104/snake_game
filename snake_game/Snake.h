#pragma once

#include "Head.h"

class Part;
class Head;
class Snake
{
public:
	Snake();
	~Snake();

	void Init();

	vector<shared_ptr<Part>> GetParts() { return parts_; }
	shared_ptr<Head> GetHead();
	void SetDirection(Head::Direction direction);
	void Move();
	void EatFood();
private:
	vector<shared_ptr<Part>> parts_;
};