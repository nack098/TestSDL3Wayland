#include <SDL3/SDL.h>
#include <cstdio>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window =
        SDL_CreateWindow("Test SDL", 800, 640, SDL_WINDOW_TRANSPARENT);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    bool running = true;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_Delay(1);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
