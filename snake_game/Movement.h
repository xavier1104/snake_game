#pragma once

class Movement
{
public:
	static bool IsOut(shared_ptr<Snake> snake, shared_ptr<Board> board);
	static bool IsEatFood(shared_ptr<Snake> snake, shared_ptr<Food> food);
	static bool IsHitBody(shared_ptr<Snake> snake);
};