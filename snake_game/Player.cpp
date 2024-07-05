#include <stdafx.h>
#include "Player.h"

Player::Player()
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
		if (e->key.keysym.sym == SDLK_0) {
			cout << "0 key down\n";
		}
	}
	}
}
