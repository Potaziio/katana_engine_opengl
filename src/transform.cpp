#include "../include/components/Transform.hpp"

Transform::Transform(glm::vec3 position) : position(position) {
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
}
