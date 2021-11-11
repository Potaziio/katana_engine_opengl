#include "../include/scene/Camera.hpp"

Camera::Camera(glm::vec3 cameraPos, float nearPlanes, float farPlanes, float camFov) 
: cameraPos(cameraPos), nearPlanes(nearPlanes), farPlanes(farPlanes), camFov(camFov) {
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    viewMatrix = glm::mat4(1.0f);
    viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(camFov), 1400.0f / 1000.0f, nearPlanes, farPlanes);
}

Camera::Camera() : cameraPos(glm::vec3(0.0f, 0.0f, 0.0f)){}

void Camera::updateViewMatrix() {
    viewMatrix = glm::mat4(1.0f);
    viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}


glm::mat4 Camera::getProjectionMatrix() {
    return projectionMatrix;
}

glm::mat4 Camera::getViewMatrix() {
    return viewMatrix;
}

glm::mat4 Camera::getTransfomMatrix() {
    return transformMatrix;
}
