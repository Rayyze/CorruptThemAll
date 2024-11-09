#include <math/math_utils.h>

// Constructor
Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

// Vector addition
Vector2D Vector2D::operator+(const Vector2D& other) {
    return Vector2D(x + other.x, y + other.y);
}

// Vector subtraction
Vector2D Vector2D::operator-(const Vector2D& other) {
    return Vector2D(x - other.x, y - other.y);
}

// Scalar multiplication
Vector2D Vector2D::operator*(float scalar) {
    return Vector2D(x * scalar, y * scalar);
}

// Calculate the length (magnitude) of the vector
float Vector2D::length() {
    return sqrt(x * x + y * y);
}

// Normalize the vector
Vector2D Vector2D::normalize() {
    float len = length();
    return (len > 0) ? Vector2D(x / len, y / len) : Vector2D(0, 0);
}