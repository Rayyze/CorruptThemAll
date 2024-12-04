#include <utilities/entities.h>

bool Entity::getVisibility() {
    return this->visible;
}

void Entity::setVisibility(bool new_value) {
    this->visible = new_value;
}

Vector2D Entity::getPosition() {
    return this->pos;
}

void Entity::setPosition(Vector2D new_value) {
    this->pos = new_value;
}

Vector2D Entity::getSize()  {
    return this->size;
}

void Entity::setSize(Vector2D new_value) {
    this->size = new_value;
}

SDL_Texture *Entity::getTexture() {
    return this->texture;
}

void Entity::setTexture(SDL_Texture *new_value) {
    this->texture = new_value;
}

Player::~Player()
{
    SDL_DestroyTexture(this->texture);
}