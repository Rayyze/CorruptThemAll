#pragma once

#include <SDL.h>
#include <SDL_image.h>

class render_engine
{
private:
    SDL_Window *main_window;
    SDL_Renderer *renderer;
public:
    render_engine();
    ~render_engine();

    int start(const char *window_name, int window_width, int window_height, Uint32 flag);
    int registerTexture(const char*texture_path);
    int updateEntities(EntityList entities);
};