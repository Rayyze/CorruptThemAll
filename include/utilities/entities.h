#pragma once
#include <math/math_utils.h>
#include <SDL.h>

class Entity {
private:
    Vector2D pos;
    Vector2D size;
    bool visible = true;
    SDL_Texture *texture;

public:
    virtual void update() = 0;
    virtual ~Entity() = default;
    
    bool getVisibility();
    void setVisibility(bool new_value);
    Vector2D getPosition();
    void setPosition(Vector2D new_value);
    Vector2D getSize();
    void setSize(Vector2D new_value);
    SDL_Texture *getTexture();
    void setTexture(SDL_Texture *new_value);
};

class Player : public Entity {
private:

public:

};