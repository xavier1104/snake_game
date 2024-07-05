#pragma once

class SDLApp
{
public:
	SDLApp();
	~SDLApp();

	void Init();
	void Finish();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
};