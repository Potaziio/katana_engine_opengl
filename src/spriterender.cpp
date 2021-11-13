#include "../include/components/SpriteRenderer.hpp"

Texture SpriteRenderer::getTexture() {
    return texture;
}

Shader SpriteRenderer::getShader() {
    return shader;
}

SpriteRenderer::SpriteRenderer(Texture texture, Shader shaderToUse) :texture(texture), shader(shaderToUse) {

}
