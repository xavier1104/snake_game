#pragma once

class Game;
class SDLApp
{
public:
	SDLApp();
	~SDLApp();

	void Init();
	void Finish();
	void Play();

private:
	void DrawGame();
	void DrawBoard();
	void DrawScore(int score);
	void DrawGameName();

private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	TTF_Font* font_;
	SDL_Surface* surface_;
	SDL_Texture* scoreTexture_;
	SDL_Texture* gameNameTexture_;
	
	shared_ptr<Game> game_;
};