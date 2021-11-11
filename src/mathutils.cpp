#include "../include/math/MathUtils.hpp"

float MathUtils::clamp(float val, float min, float max) {
    if (val > max)
        return max;
    else if (val < min)
        return min;
    else 
        return val;
}

int MathUtils::clamp(int val, int min, int max) {
    if (val > max) 
        return max;
    else if (val < min) 
        return min;
    else
        return val;
}


double MathUtils::clamp(double val, double min, double max) {

    if (val > max)
        return max;
    else if (val < min)
        return min;
    else
        return val;
}

int MathUtils::Randomi(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min));
}

int MathUtils::Randomi(int max) {
    return rand() / (RAND_MAX / max);
}

float MathUtils::Randomf(float min, float max) {
    return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}
float MathUtils::Randomf(float max) {
    return static_cast <float> (rand() / (static_cast <float> (RAND_MAX / max)));
}
