#include <utilities/entities.h>

bool Player::getVisibility() {
    return this->visible;
}

void Player::setVisibility(bool new_value) {
    this->visible = new_value;
}

Vector2D Player::getPosition() {
    return this->pos;
}

void Player::setPosition(Vector2D new_value) {
    this->pos = new_value;
}

Vector2D Player::getSize()  {
    return this->size;
}

void Player::setSize(Vector2D new_value) {
    this->size = new_value;
}

SDL_Texture *Player::getTexture() {
    return this->texture;
}

void Player::setTexture(SDL_Texture *new_value) {
    this->texture = new_value;
}