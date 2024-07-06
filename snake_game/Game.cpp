#include <stdafx.h>
#include "Player.h"
#include "Board.h"
#include "Snake.h"
#include "Movement.h"
#include "Food.h"
#include "Game.h"

Game::Game()
	:isRunning_(true)
	,player_(nullptr)
	,board_(nullptr)
{
	snake_ = make_shared<Snake>();
	player_ = make_shared<Player>(snake_);
	board_ = make_shared<Board>(30, 18, snake_);
}

Game::~Game()
{
}

void Game::Init()
{
	snake_->Init();
	board_->GenerateFood();
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

	snake_->Move();

	if (Movement::IsOut(snake_, board_)) {
		isRunning_ = false;
	}
	else if (Movement::IsEatFood(snake_, board_->GetFood())) {
		snake_->EatFood();
		player_->AddScore(board_->GetFood()->GetScore());
		board_->GenerateFood();
	}
	else if (Movement::IsHitBody(snake_)) {
		isRunning_ = false;
	}
}
