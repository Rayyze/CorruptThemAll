#include <engines/physics_engine.h>

Hitbox::Hitbox() {
}

Hitbox::~Hitbox() {
}

Vector2D Hitbox::getPosition() {
    return this->position;
}

Vector2D Hitbox::getSize() {
    return this->size;
}

void Hitbox::setPosition(Vector2D value) {
    this->position = value;
}

void Hitbox::setSize(Vector2D value) {
    this->size = value;
}