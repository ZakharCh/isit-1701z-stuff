#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

int main(int, char**)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow(
                "Это у нас окно",
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                1920, 1080,
                SDL_WINDOW_SHOWN),
            SDL_DestroyWindow);
    if (window == nullptr) {
        std::cout << "Ошибка при создании окна: " <<
            SDL_GetError() << std::endl;
        return 1;
    }

    auto renderer = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(
                window.get(),
                -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
            SDL_DestroyRenderer);
    if (renderer == nullptr) {
        std::cout << "Ошибка при создании рендерера: " <<
            SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event event;
    int a = 0;
    for (;;) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                return 0;
            case SDL_KEYDOWN:
                a = (a + 1) % 3;
                break;
            default:
                ;
            }
        }


        if (a == 0)
            SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
        else if (a == 1)
            SDL_SetRenderDrawColor(renderer.get(), 0, 0, 255, 255);
        else
            SDL_SetRenderDrawColor(renderer.get(), 0, 255, 0, 255);


        SDL_RenderClear(renderer.get());
        SDL_RenderPresent(renderer.get());
    }

    return 0;
}

