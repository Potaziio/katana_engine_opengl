#include "../include/scene/Scene.hpp"

GameObject Scene::getGameObject(std::string name) {
    for (GameObject go : gameObjects) {
        if (go.getName() == name) {
            return go;
            break;
        }
    }
}

std::vector<GameObject> Scene::getGameObjects() {
    return gameObjects;
}

void Scene::addObjectToScene(GameObject go) {
    gameObjects.push_back(go);  
}
