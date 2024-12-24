#pragma once
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

#include "glm/vec2.hpp"

struct Axis
{
	Axis() : negativeKey(0), positiveKey(0), value(0.0f) { }
	Axis(int minus, int add) : negativeKey(minus), positiveKey(add), value(0.0f) { }
	Axis(const Axis& other) : positiveKey(other.positiveKey), negativeKey(other.negativeKey), value(other.value) { }
	Axis& operator=(const Axis& other)
	{
		if (this != &other) {
			positiveKey = other.positiveKey;
			negativeKey = other.negativeKey;
			value = other.value;
		}
		return *this;
	}
	int positiveKey;
	int negativeKey;
	float value;
};

class InputManager
{
private:
	static std::unordered_map<int, bool> keys;
	static std::unordered_map<std::string, Axis> axes;
public:
	static void updateKeys(const sf::Event &e);
	static bool isKeyDown(int keyCode);
	static void createAxis(int minus, int add, const std::string &name);
	static float getAxis(const std::string& name);

	static glm::vec2 getMousePosition();
	static glm::vec2 getMousePosition(const sf::RenderWindow& window);
	static bool isMousePressed(int button);
	static bool isMouseClicked(int button);
};