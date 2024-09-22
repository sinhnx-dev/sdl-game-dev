#include <SDL3/SDL.h>
// #include <SDL3/SDL_oldnames.h>

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    // SDL_Window *Window{SDL_CreateWindow("Hello Window", 800, 400, 0)};
    SDL_Window *window = SDL_CreateWindow("SDL3 Game Demo", 800, 400, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    SDL_Event event;
    bool isRunning = true;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                if (event.key.key == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 100);
        // SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}