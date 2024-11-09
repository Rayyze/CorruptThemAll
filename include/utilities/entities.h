#pragma once
#include <math/math_utils.h>
#include <SDL.h>

class Entity {
public:
    virtual void update() = 0;
    virtual ~Entity() = default;
    
    virtual bool getVisibility() = 0;
    virtual void setVisibility(bool new_value) = 0;
    virtual Vector2D getPosition() = 0;
    virtual void setPosition(Vector2D new_value) = 0;
    virtual Vector2D getSize() = 0;
    virtual void setSize(Vector2D new_value) = 0;
    virtual SDL_Texture *getTexture() = 0;
    virtual void setTexture(SDL_Texture *new_value) = 0;
};

class Player : public Entity {
private:
    Vector2D pos;
    Vector2D size;
    bool visible = true;
    SDL_Texture *texture;

public:
    bool getVisibility() override;  // Make sure it's declared with the correct return type
    void setVisibility(bool new_value) override;
    Vector2D getPosition() override;
    void setPosition(Vector2D new_value) override;
    Vector2D getSize() override;
    void setSize(Vector2D new_value) override;
    SDL_Texture* getTexture() override;
    void setTexture(SDL_Texture* new_value) override;
};