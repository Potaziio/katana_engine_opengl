#include "../include/util/Time.hpp"

float Time::GetMilliseconds() {
    return (float)glfwGetTime();
}

float Time::DeltaTime() {
    return dt;
}
 
float Time::dt = -1;
float Time::beginTime = Time::GetMilliseconds();
float Time::endTime = Time::GetMilliseconds();

