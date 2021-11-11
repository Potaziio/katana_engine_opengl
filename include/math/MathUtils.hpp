#include <iostream>
#include <stdlib.h>
#include <cmath>

struct MathUtils {
   static float clamp(float val, float min, float max);
   static int clamp(int val, int min, int max);
   static double clamp(double val, double min, double max);

   static int Randomi(int min, int max);
   static int Randomi(int max);

   static float Randomf(float min, float max);
   static float Randomf(float max);
};
