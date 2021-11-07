#include <iostream>

class Vector2f {
    public:
        float x;
        float y;

        Vector2f(float xPos, float yPos);
        Vector2f();

        void Print();

        Vector2f operator-(Vector2f vecToSubstract);
};

class Vector2d {
    public:
        double x;
        double y;

        Vector2d(double xPos, double yPos);
        Vector2d();

        void Print();

        Vector2d operator-(Vector2d vecToSubstract);
};
