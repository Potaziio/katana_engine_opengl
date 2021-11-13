#pragma once

#include "Camera.hpp"
#include "../gameobject/GameObject.hpp"

#include <string>
#include <vector>

class Scene {
    private:
        std::vector<GameObject> gameObjects; 
    public:
        Camera camera;

        virtual void init() {}
        virtual void update() {}
       
        std::vector<GameObject> getGameObjects();
        void addObjectToScene(GameObject go);

        GameObject getGameObject(std::string name);

        static void freeResources() {}
};
