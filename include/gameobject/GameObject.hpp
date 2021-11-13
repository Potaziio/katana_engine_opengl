#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#pragma once

#include <iostream>
#include <vector>

#include "../gameobject/Component.hpp"

class GameObject {
    private:
        bool firstLoaded = false;

        std::vector<Component*> components;

        std::string id;
        std::string name;
    public:
        GameObject(std::string name);
        GameObject();

        std::vector<Component*> getComponents() {
            return components;
        }

        template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr>
        T* getComponent() {
            for (Component* co : components) {
                if (dynamic_cast<T*>(co)) {
                    return dynamic_cast<T*>(co); 
                }
            }
        }

        template<typename T, typename std::enable_if<std::is_base_of<Component, T>::value>::type* = nullptr>
        void addComponent(T* component) {
            bool found = false;

            for (Component* co : components) {
                if (dynamic_cast<T*>(co)) {
                    found = true;
                    std::cout << " Found" << std::endl;
                    break;
                }
            }

            if (!found) {
                components.push_back(static_cast<T*>(component));
                component->gameObject = *this;
            }
        }

        std::string getName();
        std::string getID();

        void update();
};
#endif // GAMEOBJECT_H
