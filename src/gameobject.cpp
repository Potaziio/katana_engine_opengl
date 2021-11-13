#include "../include/gameobject/GameObject.hpp"

GameObject::GameObject(std::string name)
:name(name)
{
    if (!firstLoaded) {
        std::cout << name << ": Initialized" << std::endl; 
        id = '0';
        firstLoaded = true;
    }
}

GameObject::GameObject() {

}

std::string GameObject::getID() {
    return id;
}

std::string GameObject::getName() {
    return name;
}
