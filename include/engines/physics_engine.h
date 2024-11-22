#pragma once

#include <math/math_utils.h>

class Hitbox {
private:
    Vector2D size;
    Vector2D position;

public:
    Hitbox();
    ~Hitbox();
    Vector2D getSize();
    Vector2D getPosition();
    void setSize(Vector2D value);
    void setPosition(Vector2D value);
};

/*class physics_engine {
private:
public:
}*/