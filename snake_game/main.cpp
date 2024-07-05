#include <stdafx.h>

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
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = TTF_OpenFont("corbel.ttf", 32);
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << SDL_GetError() << '\n';
		SDL_Quit();
	}
	
	SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
	if (SDL_RenderSetScale(renderer, 1, 1) < 0) {
		cout << SDL_GetError() << '\n';
		SDL_Quit();
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	if (TTF_Init() == -1) {
		cout << TTF_GetError() << '\n';
	}

	TTF_Font* font = TTF_OpenFont("corbel.ttf", 32);
	if (!font) {
		cout << "load font failed\n";
		exit(1);
	}
	
	while (1) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.key.repeat != 0) {
				continue;
			}

			switch (e.type) {
			case SDL_KEYDOWN:
			{
				cout << "Key press detected\n";
				break;
			}
			case SDL_KEYUP:
			{
				cout << "Key released detected\n";
				break;
			}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		DrawScore(renderer, 100);
		DrawBoard(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(scoreTxt);
	SDL_DestroyTexture(gameNameTxt);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);

	SDL_Quit();
	return 0;
}