#pragma once
#include <math.h>

struct Vector2D {
    float x;
    float y;

    // Constructor
    Vector2D(float x = 0, float y = 0);

    // Vector addition
    Vector2D operator+(const Vector2D& other);

    // Vector subtraction
    Vector2D operator-(const Vector2D& other);

    // Scalar multiplication
    Vector2D operator*(float scalar);

    // Calculate the length (magnitude) of the vector
    float length();

    // Normalize the vector
    Vector2D normalize();
};