#pragma once

#include <iostream>

#include "../gameobject/Component.hpp"
#include "../gameobject/GameObject.hpp"
#include "../util/Texture.hpp"
#include "../Shader.hpp"

class SpriteRenderer : public Component {
    private:
        Texture texture;
        Shader shader;
    public:
        GameObject gameObject;

        Texture getTexture();
        Shader getShader();

        SpriteRenderer (Texture texture, Shader shaderToUse);

        virtual ~SpriteRenderer() {}
};
