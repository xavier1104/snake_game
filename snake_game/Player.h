#pragma once

class Snake;
class Player
{
public:
	Player(shared_ptr<Snake> snake);
	~Player();

	void KeyPress(SDL_Event* e);
	void AddScore(int score);
	int GetScore() { return score_; }
private:
	shared_ptr<Snake> snake_;
	int score_;
};