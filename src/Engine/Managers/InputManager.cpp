#include "InputManager.h"

std::unordered_map<int, bool> InputManager::keys;
std::unordered_map<std::string, Axis> InputManager::axes;

void InputManager::updateKeys(sf::Event e)
{
    if (e.type == sf::Event::EventType::KeyPressed) {
        if (keys.count(e.key.code) == 0) {
            keys[e.key.code] = true;
        }
    }
    if (e.type == sf::Event::EventType::KeyReleased) {
        if (keys.count(e.key.code) == 1) {
            keys.erase(e.key.code);
        }
    }
}

bool InputManager::isKeyDown(int keyCode)
{
    return (keys.count(keyCode) == 1);
}

void InputManager::createAxis(int minus, int add, std::string name)
{
    Axis axis(minus, add);
    axes[name] = axis;
}

float InputManager::getAxis(std::string name)
{
    Axis axis = axes[name];
    if(isKeyDown(axis.negativeKey))
    {
        axis.value = -1;
    }
    else if (isKeyDown(axis.positiveKey))
    {
        axis.value = 1;
    }
    return axis.value;
}
