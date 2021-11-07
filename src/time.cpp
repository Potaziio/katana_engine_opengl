#include "../include/util/Time.hpp"

float Time::GetMilliseconds() {
    return (float)glfwGetTime();
}

float Time::DeltaTime() {

    Time::endTime = Time::GetMilliseconds();
    Time::dt = Time::endTime - Time::beginTime;
    Time::beginTime = Time::endTime;

    return dt;
}
 
float Time::dt = -1;
float Time::beginTime = Time::GetMilliseconds();
float Time::endTime = Time::GetMilliseconds();

