#include <stdafx.h>
#include "Player.h"
#include "Board.h"
#include "Snake.h"
#include "Game.h"

Game::Game()
	:isRunning_(true)
	,player_(nullptr)
	,board_(nullptr)
{
	snake_ = make_shared<Snake>();
	player_ = make_shared<Player>();
	board_ = make_shared<Board>(32, 20, snake_);
}

Game::~Game()
{
}

void Game::Update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.key.repeat != 0) {
			continue;
		}

		player_->KeyPress(&e);
	}
}
