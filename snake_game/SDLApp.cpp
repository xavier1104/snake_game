#include <stdafx.h>
#include "SDLApp.h"

SDLApp::SDLApp()
{
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

	SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
	if (SDL_RenderSetScale(renderer, 1, 1) < 0) {
		cout << SDL_GetError() << '\n';
		exit(1);
	}

	if (TTF_Init() == -1) {
		cout << TTF_GetError() << '\n';
		exit(1);
	}

	font = TTF_OpenFont("corbel.ttf", 32);
	if (!font) {
		cout << "load font failed\n";
		SDL_DestroyWindow(window);
	}
}

void SDLApp::Finish()
{
}
