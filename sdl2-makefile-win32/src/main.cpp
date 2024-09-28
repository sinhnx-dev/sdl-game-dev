#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argv, char **args)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow(
		"SDL create Windows Demo",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		687, 417, 0);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	bool isRunning = true;
	SDL_Event event;

	SDL_Surface *lettuce_sur = IMG_Load("res/images/jungle.png");
	if (lettuce_sur == NULL)
	{
		std::cout << "Error loading image: " << IMG_GetError();
		return 5;
	}

	SDL_Texture *background = SDL_CreateTextureFromSurface(renderer, lettuce_sur);
	if (background == NULL)
	{
		std::cout << "Error creating texture";
		return 6;
	}
	SDL_FreeSurface(lettuce_sur);

	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					isRunning = false;
				}
			}
		}
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 100, 100);
		SDL_RenderCopy(renderer, background, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}