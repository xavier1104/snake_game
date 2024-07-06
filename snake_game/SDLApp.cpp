#include <stdafx.h>
#include "Player.h"
#include "Game.h"
#include "Snake.h"
#include "Part.h"
#include "Coordinate.h"
#include "Food.h"
#include "Board.h"
#include "SDLApp.h"

#define SIZE 20

SDLApp::SDLApp()
	:window_(nullptr)
	,renderer_(nullptr)
	,font_(nullptr)
	,surface_(nullptr)
	,scoreTexture_(nullptr)
	,gameNameTexture_(nullptr)
	,game_(nullptr)
{
	game_ = make_shared<Game>();
}

SDLApp::~SDLApp()
{
}

void SDLApp::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << SDL_GetError() << '\n';
		exit(1);
	}

	SDL_CreateWindowAndRenderer(640, 480, 0, &window_, &renderer_);
	if (SDL_RenderSetScale(renderer_, 1, 1) < 0) {
		cout << SDL_GetError() << '\n';
		exit(1);
	}

	if (TTF_Init() == -1) {
		cout << TTF_GetError() << '\n';
		exit(1);
	}

	font_ = TTF_OpenFont("corbel.ttf", 32);
	if (!font_) {
		cout << "load font failed\n";
		SDL_DestroyWindow(window_);
	}
}

void SDLApp::Finish()
{
	SDL_DestroyTexture(scoreTexture_);
	SDL_DestroyTexture(gameNameTexture_);
	SDL_DestroyWindow(window_);
	TTF_CloseFont(font_);

	SDL_Quit();
}

void SDLApp::Play()
{
	game_->Init();

	while (game_->IsRunning()) {
		game_->Update();
		
		DrawGame();

		SDL_Delay(100);
	}

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Msg", "Game Over", window_);
}

void SDLApp::DrawGame()
{
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer_);

	DrawScore();
	DrawBound();
	DrawGameName();
	DrawBoard();

	SDL_RenderPresent(renderer_);
}

void SDLApp::DrawBound()
{
	static vector<SDL_Rect> boards = { { 0, 80, 640, 20 }, { 0, 460, 640, 20 },{ 0, 80, 20, 400 }, {620, 80, 20, 400} };

	SDL_SetRenderDrawColor(renderer_, 255, 255, 255, SDL_ALPHA_OPAQUE);
	for (auto board : boards) {
		SDL_RenderFillRect(renderer_, &board);
	}
}

void SDLApp::DrawBoard()
{
	static SDL_Point topLeft = { 20, 100 };
	shared_ptr<Snake> snake = game_->GetSnake();
	
	SDL_SetRenderDrawColor(renderer_, 0, 255, 0, SDL_ALPHA_OPAQUE);
	SDL_Rect rect;
	for (auto& part : snake->GetParts()) {
		rect = { topLeft.x + SIZE * part->GetCoord()->x_, topLeft.y + SIZE * part->GetCoord()->y_, SIZE, SIZE };
		SDL_RenderFillRect(renderer_, &rect);
	}

	SDL_SetRenderDrawColor(renderer_, 255, 0, 0, SDL_ALPHA_OPAQUE);
	shared_ptr<Food> food = game_->GetBoard()->GetFood();
	rect = { topLeft.x + SIZE * food->GetCoord()->x_, topLeft.y + SIZE * food->GetCoord()->y_, SIZE, SIZE };
	SDL_RenderFillRect(renderer_, &rect);
}

void SDLApp::DrawScore()
{
	SDL_DestroyTexture(scoreTexture_);
	
	shared_ptr<Player> player = game_->GetPlayer();

	string msg = "Score:" + to_string(player->GetScore());
	surface_ = TTF_RenderText_Solid(font_, msg.c_str(), {255,255,255, SDL_ALPHA_OPAQUE});
	scoreTexture_ = SDL_CreateTextureFromSurface(renderer_, surface_);
	SDL_FreeSurface(surface_);

	SDL_Rect scoreRect{ 30, 30, 100, 20 };
	SDL_RenderCopy(renderer_, scoreTexture_, nullptr, &scoreRect);
}

void SDLApp::DrawGameName()
{
	SDL_DestroyTexture(gameNameTexture_);

	surface_ = TTF_RenderText_Solid(font_, "Snake Game", { 255,255,255, SDL_ALPHA_OPAQUE });
	gameNameTexture_ = SDL_CreateTextureFromSurface(renderer_, surface_);
	SDL_FreeSurface(surface_);

	SDL_Rect rect{ 190, 30, 200, 20 };
	SDL_RenderCopy(renderer_, gameNameTexture_, nullptr, &rect);
}