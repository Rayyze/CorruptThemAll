#include <render_engine.h>
#include <math/math_utils.h>
#include <utilities/entities.h>
#include <list>
#include <memory>
#include <iostream>


Render_engine::Render_engine() : main_window(nullptr), renderer(nullptr)
{
}

Render_engine::~Render_engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
    IMG_Quit();
    SDL_Quit();
}

int Render_engine::start(const char *window_name, int window_width, int window_height, Uint32 window_flag) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    SDL_Rect displayBounds;

    if (SDL_GetDisplayBounds(0, &displayBounds) == 0) {
        if (!window_width) window_width = displayBounds.w;
        if (!window_height) window_height = displayBounds.w;
    } else {
        if (!(window_height*window_width))
        std::cerr << "SDL_GetDisplayBounds Error: " << SDL_GetError() << std::endl;
    }

    main_window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN);
    if (!main_window)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(main_window);
        SDL_Quit();
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(main_window);
        SDL_Quit();
        return false;
    }

    return true;
}

SDL_Texture *Render_engine::registerTexture(const char*texture_path) {
    SDL_Texture *texture;

    SDL_Surface *surface = IMG_Load(texture_path);
    if (!surface)
    {
        std::cerr << "Unable to load image! IMG_Error: " << IMG_GetError() << std::endl;
        return NULL;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!texture)
        {
            return NULL;
        }
    }

    return texture;
}


int Render_engine::updateEntities(EntityList entities) {
    for (const auto& entity : entities) {
        if (entity->getVisibility()) {
            Vector2D pos = entity->getPosition();
            Vector2D size = entity->getSize();
            SDL_RenderClear(renderer);
            SDL_Rect dstRect = {pos.x, pos.y, size.x, size.y}; // x, y, width, height
            SDL_RenderCopy(renderer, entity->getTexture(), nullptr, &dstRect);
            SDL_RenderPresent(renderer);
        }
    }
}