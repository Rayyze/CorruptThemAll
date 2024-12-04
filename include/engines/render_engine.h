#pragma once

#include <SDL.h>
#include <SDL_image.h>

using EntityList = std::list<std::shared_ptr<Entity>>;

class Render_engine
{
private:
    SDL_Window *main_window;
    SDL_Renderer *renderer;
public:
    Render_engine();
    ~Render_engine();

    int start(const char *window_name, int window_width, int window_height, Uint32 flag);
    SDL_Texture *registerTexture(const char*texture_path);
    int updateEntities(EntityList entities);
};