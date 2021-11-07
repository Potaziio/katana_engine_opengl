#include "../include/math/Vector.hpp"

Vector2f::Vector2f(float xPos, float yPos) :x(xPos), y(yPos) {}
Vector2f::Vector2f() :x(0.0f), y(0.0f) {}

void Vector2f::Print() {
    std::cout << x << ", " << y << std::endl;
}

Vector2f Vector2f::operator-(Vector2f vecToSubstract) {
    return Vector2f(x - vecToSubstract.x, y - vecToSubstract.y);
}  

Vector2d::Vector2d(double xPos, double yPos) :x(xPos), y(yPos) {}
Vector2d::Vector2d() :x(0.0f), y(0.0f) {}

void Vector2d::Print() {
    std::cout << x << ", " << y << std::endl;
}  

Vector2d Vector2d::operator-(Vector2d vecToSubstract) {
    return Vector2d(x - vecToSubstract.x, y - vecToSubstract.y);
}  
