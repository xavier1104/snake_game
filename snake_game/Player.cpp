#include <stdafx.h>
#include "Snake.h"
#include "Head.h"
#include "Player.h"

Player::Player(shared_ptr<Snake> snake)
	:snake_(snake)
	,score_(0)
{
}

Player::~Player()
{
}

void Player::KeyPress(SDL_Event* e)
{
	switch (e->type) {
	case SDL_KEYDOWN:
	{
		if (e->key.keysym.sym == SDLK_LEFT) {
			snake_->SetDirection(Head::LEFT);
		}
		else if (e->key.keysym.sym == SDLK_RIGHT) {
			snake_->SetDirection(Head::RIGHT);
		}
		else if (e->key.keysym.sym == SDLK_UP) {
			snake_->SetDirection(Head::UP);
		}
		else if (e->key.keysym.sym == SDLK_DOWN) {
			snake_->SetDirection(Head::DOWN);
		}
	}
	}
}

void Player::AddScore(int score)
{
	score_ += score;
}
