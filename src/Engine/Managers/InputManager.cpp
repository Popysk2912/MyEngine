#include "InputManager.h"

std::unordered_map<int, bool> InputManager::keys;
std::unordered_map<std::string, Axis> InputManager::axes;

void InputManager::updateKeys(const sf::Event &e)
{
    if (e.type == sf::Event::EventType::KeyPressed) {
        if (!keys.contains(e.key.code)) {
            keys[e.key.code] = true;
        }
    }
    if (e.type == sf::Event::EventType::KeyReleased) {
        if (keys.count(e.key.code) == 1) {
            keys.erase(e.key.code);
        }
    }
}

bool InputManager::isKeyDown(const int keyCode)
{
    return (keys.count(keyCode) == 1);
}

void InputManager::createAxis(const int minus, const int add, const std::string &name)
{
    const Axis axis(minus, add);
    axes[name] = axis;
}

float InputManager::getAxis(const std::string& name)
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

glm::vec2 InputManager::getMousePosition()
{
    return {sf::Mouse::getPosition().x, sf::Mouse::getPosition().y};
}

glm::vec2 InputManager::getMousePosition(const sf::RenderWindow& window)
{
    return {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
}

bool InputManager::isMousePressed(int button)
{
    return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
}

bool InputManager::isMouseClicked(int button) {
    static std::unordered_map<int, bool> buttonState;
    const bool isPressed = sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
    if (isPressed && !buttonState[button]) {
        buttonState[button] = true;
        return true;
    }
    if (!isPressed) {
        buttonState[button] = false;
    }
    return false;
}
