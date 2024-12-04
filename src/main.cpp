#include <SDL.h>
#include <SDL_image.h>
#include <utilities/entities.h>
#include <engines/render_engine.h>
#include <iostream>
#include <list>
#include <memory>

using EntityList = std::list<std::shared_ptr<Entity>>;

int main(int argc, char *argv[])
{

    bool running = true;
    SDL_Event event;
    int player_x = 0;
    int player_y = 0;
    int player_speed = 1000;
    Uint64 last_cycle_time = SDL_GetTicks();
    Uint64 current_time = SDL_GetTicks();
    double delta_time;
    EntityList entities;
    Render_engine render_engine;
    
    render_engine.start("CorruptThemAll", 0, 0, 0); //0 for both height and width for autodetect and 0 for the flag (not used yet)

    //register the player
    auto player = std::make_shared<Player>(0);;
    render_engine.registerTexture("../assets/player-idle-1.png");
    entities.push_back(player);

    while (running)
    {
        
        current_time = SDL_GetTicks();
        delta_time = (current_time - last_cycle_time);
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

        SDL_Delay(16); // Add a delay of 16 milliseconds for a controlled pace
    }

    return 0;
}