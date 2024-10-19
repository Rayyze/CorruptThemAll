#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 960, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    bool running = true;
    SDL_Texture *texture;
    SDL_Event event;
    int player_x = 0;
    int player_y = 0;
    int player_speed = 1000;
    Uint64 last_cycle_time = SDL_GetTicks();
    Uint64 current_time = SDL_GetTicks();
    double delta_time;  

    SDL_Surface *surface = IMG_Load("../assets/player-idle-1.png");
    if (!surface)
    {
        std::cerr << "Unable to load image! IMG_Error: " << IMG_GetError() << std::endl;
        running = false;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!texture)
        {
            running = false;
        }
    }

    while (running)
    {
        
        current_time = SDL_GetTicks();
        delta_time = (current_time - last_cycle_time);
        //std::cout << current_time << "-" << last_cycle_time << "=" << delta_time << std::endl;
        last_cycle_time = current_time;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            }
        }

        //Handle inputs
        const Uint8* state = SDL_GetKeyboardState(nullptr);

        // Check if specific keys are pressed
        if (state[SDL_SCANCODE_ESCAPE]) {
            running = false;
        }
        if (state[SDL_GetScancodeFromKey(SDLK_z)]) {
            player_y -= player_speed*delta_time/1000.0f;
        }
        if (state[SDL_GetScancodeFromKey(SDLK_q)]) {
            player_x -= player_speed*delta_time/1000.0f;
        }
        if (state[SDL_GetScancodeFromKey(SDLK_s)]) {
            player_y += player_speed*delta_time/1000.0f;
        }
        if (state[SDL_GetScancodeFromKey(SDLK_d)]) {
            player_x += player_speed*delta_time/1000.0f;
        }

        SDL_RenderClear(renderer);
        SDL_Rect dstRect = {player_x, player_y, 100, 100}; // x, y, width, height
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // Add a delay of 16 milliseconds for a controlled pace
    }

    SDL_DestroyTexture(texture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 0;
}