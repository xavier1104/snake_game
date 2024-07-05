#include <stdafx.h>
#include "SDLApp.h"

void DrawBoard(SDL_Renderer* renderer)
{
	static vector<SDL_Rect> boards = { { 0, 80, 640, 20 }, { 0, 460, 640, 20 },{ 0, 80, 20, 400 }, {620, 80, 20, 400} };

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (auto board : boards) {
		SDL_RenderFillRect(renderer, &board);
	}
}

void DrawScore(SDL_Renderer* renderer, int score)
{
	TTF_Font* font = TTF_OpenFont("corbel.ttf", 32);
	SDL_Surface* surfaceTxt = TTF_RenderText_Solid(font, "Score:100", { 255,255,255 });
	SDL_Texture* scoreTxt = SDL_CreateTextureFromSurface(renderer, surfaceTxt);
	SDL_FreeSurface(surfaceTxt);

	SDL_Rect scoreRect{30, 30, 100, 20};
	SDL_RenderCopy(renderer, scoreTxt, nullptr, &scoreRect);
}

void DrawGameName(SDL_Renderer* renderer)
{
	TTF_Font* font = TTF_OpenFont("corbel.ttf", 32);
	SDL_Surface* surfaceTxt = TTF_RenderText_Solid(font, "Snake Game", { 255,255,255 });
	SDL_Texture* textureTxt = SDL_CreateTextureFromSurface(renderer, surfaceTxt);
	SDL_FreeSurface(surfaceTxt);

	SDL_Rect rect{190, 30, 200, 20};
	SDL_RenderCopy(renderer, textureTxt, nullptr, &rect);
}

int main(int argc, char* argv[])
{
	SDLApp app;
	
	app.Init();

	app.Play();

	app.Finish();

	return 0;
}