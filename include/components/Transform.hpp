#ifndef TRANSFORM_H
#define TRANSFORM_H

#pragma once

#include <iostream>

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"

#include "../gameobject/Component.hpp"
#include "../gameobject/GameObject.hpp"

class Transform : public Component {
    public:
        GameObject gameObject;

        glm::vec3 position;
        glm::mat4 modelMatrix;
        Transform(glm::vec3 position);

        virtual ~Transform() {}
};
#endif
